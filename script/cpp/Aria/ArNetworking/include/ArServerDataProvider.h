/*
Adept MobileRobots Robotics Interface for Applications (ARIA)
Copyright (C) 2004-2005 ActivMedia Robotics LLC
Copyright (C) 2006-2010 MobileRobots Inc.
Copyright (C) 2011-2015 Adept Technology, Inc.
Copyright (C) 2016-2018 Omron Adept Technologies, Inc.

     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.

     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with this program; if not, write to the Free Software
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

If you wish to redistribute ARIA under different terms, contact 
Adept MobileRobots for information about a commercial version of ARIA at 
robots@mobilerobots.com or 
Adept MobileRobots, 10 Columbia Drive, Amherst, NH 03031; +1-603-881-7960
*/

#ifndef NLDATAPROVIDER_H
#define NLDATAPROVIDER_H

#include "Aria.h"
#include "ArServerBase.h"
#include "ArPacketUtil.h"
#include <assert.h>

/** Tool to easily obtain and provide changing data values from an acessor method of a
 * class.   The data item is added to the server, and
 * when clients make requests, this object will call a lock method on a target
 * object (if provided), then obtain a value to reply with by
 * calling the given accessor method on the target object, then call the
 * unlock method (if provided).  You can supply these methods either as function
 * pointers (within the class of the target object), or ArFunctor objects.
 * 
 * 
 * Client programs can use ArClientDataReceiver to request and receive updates
 * on the value.
 *
 * @note This object must remain in scope and not be destroyed to remain
 * active. If this object is deleted (explicitly or if execution leaves 
 * scope in which the object was created)
 * then the data item is removed from the server and clients
 * will no longer receive updates.
 *
 * Replies with data are sent via TCP. @todo change to UDP.
 *
 * @sa ArClientDataReceiver
 *
 * @todo provide data logger and/or string info group to add data to as well
 * @todo option to provide mutex to lock/unlock
 * @todo alternate with pointer to variable
 * @todo option for udp
 *
 * @since 2.9.3
 * @unstable
 */
template <class C, typename T>
class ArServerDataProvider
{
  ArServerBase *myServer;
  const char *myReqName;
  ArFunctor2C<ArServerDataProvider, ArServerClient*, ArNetPacket*> *myPackFunctor;
  ArRetFunctor<T> *myAccessFunctor;
  ArFunctor *myLockFunctor;
  ArFunctor *myUnlockFunctor;
  bool myDeleteFunctors;

  void packAndSend(ArServerClient *client, ArNetPacket *req)
  {
    // TODO flag to select TCP or UDP
    ArNetPacket pkt;
    if(myLockFunctor) myLockFunctor->invoke();
    const T val = myAccessFunctor->invokeR();
    if(myUnlockFunctor) myUnlockFunctor->invoke();
    ArPacketUtil::addField<T>(pkt, val);
    client->sendPacketTcp(&pkt);
  }

  bool init(ArServerBase *server, const char *name, const char *description, ArRetFunctor<T> *accessFunctor, ArFunctor *lockFunctor, ArFunctor *unlockFunctor)
  {
    myServer = server;
    myReqName = name;
    const char *type_name = typeid(T).name();
    myAccessFunctor = accessFunctor;
    myLockFunctor = lockFunctor;
    myUnlockFunctor = unlockFunctor;
    myPackFunctor = new ArFunctor2C<ArServerDataProvider, ArServerClient*, ArNetPacket*>(this, &ArServerDataProvider::packAndSend);
    bool r = server->addDataAdvanced(
      name, 
      description, 
      myPackFunctor,
      "none", // argDesc, todo
      type_name ? type_name : "unknown", // return description
      "", // commandGroup TODO
      "RETURN_SINGLE", // dataFlags 
      0,    // commandNumber
      NULL,    // requestChangedFunctor TODO
      NULL    // requestOnceFunctor TODO
    );
    if(r)
      ArLog::log(ArLog::Verbose, "\"%s\" ArPublisher: Created", name);
    else
      ArLog::log(ArLog::Terse, "\"%s\" ArPublisher: Error adding data request to base server!", name);
    return r;
  }

public:
  /** If this constructor is used, then access data by invoking the @a
  * accessFunctor ArRetFunctor<T> object. If @a lockFunctor and
  * @a unlockFunctor are provided (not NULL), then these are invoked before and
  * after invoking @a accessFunctor.
  */
  ArServerDataProvider(ArServerBase *server, const char *name, const char *description, ArRetFunctor<T>* accessFunctor, ArFunctor* lockFunctor = NULL, ArFunctor *unlockFunctor = NULL) :
    myDeleteFunctors(false)
  {
    assert((lockFunctor && unlockFunctor) || (!lockFunctor && !unlockFunctor));
    init(server, name, description, accessFunctor, lockFunctor, unlockFunctor);
  }

  /** If this constructor is used, then access data by calling @a method on
  * object instance @a obj. If @a lockMethod and
  * @a unlockMethod are provided (not NULL), then these are called before and
  * after calling @a method.
  */
  ArServerDataProvider(ArServerBase *server, const char *name, const char *description, C* obj, T (C::*method)(void), void (C::*lockMethod)(void)= NULL, void (C::*unlockMethod)(void) = NULL) : 
    myDeleteFunctors(true)
  {
    ArRetFunctorC<T, C> *accessFunctor = new ArRetFunctorC<T, C>(obj, method);
    assert((lockMethod && unlockMethod) || (!lockMethod && !unlockMethod));
    ArFunctorC<C> *lockFunctor, *unlockFunctor;
    if(lockMethod) lockFunctor = new ArFunctorC<C>(obj, lockMethod);
    if(unlockMethod) unlockFunctor = new ArFunctorC<C>(obj, unlockMethod);
    init(server, name, description, accessFunctor, lockFunctor, unlockFunctor);
  }

  /** If this constructor is used, then access data by calling @a method on
  * object instance @a obj. If @a lockMethod and
  * @a unlockMethod are provided (not NULL), then these are called before and
  * after calling @a method.  This version allows @a method to be
  * <tt>const</tt>.
  */
  ArServerDataProvider(ArServerBase *server, const char *name, const char *description, C* obj, T (C::*method)(void) const, void (C::*lockMethod)(void) = NULL, void (C::*unlockMethod)(void) = NULL) :
    myDeleteFunctors(true)
  {
    ArConstRetFunctorC<T, C>* accessFunctor = new ArConstRetFunctorC<T, C>(obj, method);
    assert((lockMethod && unlockMethod) || (!lockMethod && !unlockMethod));
    ArFunctorC<C> *lockFunctor, *unlockFunctor;
    if(lockMethod) lockFunctor = new ArFunctorC<C>(obj, lockMethod);
    if(unlockMethod) unlockFunctor = new ArFunctorC<C>(obj, unlockMethod);
    init(server, name, description, accessFunctor, lockFunctor, unlockFunctor);
  }

  virtual ~ArServerDataProvider() 
  {
    if(myLockFunctor) myLockFunctor->invoke();
    if(myServer) myServer->remData(myReqName);
    if(myUnlockFunctor) myUnlockFunctor->invoke();
    if(myDeleteFunctors && myLockFunctor) delete myLockFunctor;
    if(myDeleteFunctors && myUnlockFunctor) delete myUnlockFunctor;
    if(myPackFunctor) delete myPackFunctor;
    if(myDeleteFunctors && myAccessFunctor) delete myAccessFunctor;
    ArLog::log(ArLog::Verbose, "%s ArPublisher: Deleted");
  }
};

#endif
