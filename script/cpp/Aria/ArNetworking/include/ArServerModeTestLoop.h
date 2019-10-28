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
#ifndef ARNETMODETESTLOOP_H
#define ARNETMODETESTLOOP_H

#include "ariaTypedefs.h"
#include "Aria.h"
#include "ArNetworking.h"
#include "ArServerMode.h"

/** This mode uses the most simple robot control commands to drive back and
 * forth along a line repeatedly. It can be activated by an ArNetworking
 * "testloop" request, or by a user using custom text commands interface (if
 * command handler is passed in constructor or addCommands() is called).
 * Some options are added to the configuration if addToConfig() is called or 
 * an ArConfig object is given in the constructor.
 */
class ArServerModeTestLoop : public ArServerMode
{
public:
  AREXPORT ArServerModeTestLoop(ArServerBase *server, ArRobot *robot, ArConfig *config = NULL, ArServerHandlerCommands *cmds = NULL);
  AREXPORT virtual ~ArServerModeTestLoop();
  AREXPORT virtual void activate(void);
  AREXPORT virtual void deactivate(void);
  AREXPORT void addToConfig(ArConfig *config);
  AREXPORT void addCommands(ArServerHandlerCommands *cmds);
private:
  void netTestLoop(ArServerClient *client, ArNetPacket *packet);
  virtual void userTask(void);
  virtual void checkDefault(void) { activate(); }
protected:
  ArFunctor2C<ArServerModeTestLoop, ArServerClient *, ArNetPacket *> myNetTestLoopCB;
  int myPadding, myStopDist, mySpeed, myDriveDist, myRotSpeed;
  int myRotAccel, myRotDecel, myObsDecel;
  ArPose myStartPos;
  enum {Trans, Stop, Rot, Deactivated} myState;
  ArFunctorC<ArServerModeTestLoop> myActivateCB;
};

#endif // ARNETMODETESTLOOP_H
