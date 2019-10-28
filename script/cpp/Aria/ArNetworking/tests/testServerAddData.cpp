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

#include "Aria.h"
#include "ArNetworking.h"
#include <string>
#include <assert.h>

// Test object providing values via accessor methods
class Test
{
public:
  int getInt()
  {
    return 23;
  }

  float getFloat()
  {
    return 3.14159;
  }

  double getDouble()
  {
    return 3.14159;
  }

  bool getBool()
  {
    return false;
  }

  char getChar()
  {
    return 255;
  }

  unsigned char getUChar()
  {
    return 42;
  }

  unsigned int getUInt()
  {
    return 23;
  }

  short getShort()
  {
    return 23;
  }

  unsigned short getUShort()
  {
    return 23;
  }

  std::string getString()
  {
    return "Hello world";
  }
};


int packetcounter = 0;

void handleIntPacket(ArNetPacket *pkt)
{
  printf("Got test_int packet with: %d\n", (int) pkt->bufToByte4());
  ++packetcounter;
}


void handleFloatPacket(ArNetPacket *pkt)
{
  printf("Got test_float packet with: %f\n", (float) pkt->bufToByte4() / 1000.0);
  ++packetcounter;
}


int main(int argc, char **argv)
{
  Aria::init();
  ArServerBase server;

  //server.addData("test", "some wierd test", &testCB, "none", "none");
  //server.addData("test2", "another wierd test", &testCB, "none", "none");
  //server.addData("test3", "yet another wierd test", &testCB, "none", "none");

  Test test;

  int i = 23;
  bool r = false;

  r = server.addDataRequest<int>("test_int_1", "test int", &i);
  assert(r);
  r = server.addDataRequest<int>("test_int_2", "test int", new ArRetFunctorC<int, Test>(&test, &Test::getInt));
  assert(r);

  float f = 3.14159;
  r = server.addDataRequest<float>("test_float_1", "test float", &f);
  assert(r);
  r = server.addDataRequest<float>("test_float_2", "test float from func", new ArRetFunctorC<float, Test>(&test, &Test::getFloat));
  assert(r);

  if (!server.open(7279))
  {
    printf("Could not open server on port 7279\n");
    Aria::exit(1);
  }
  printf("Starting server at localhost:7279\n");
  server.runAsync();

  ArClientBase client;
  if(!client.blockingConnect("localhost", 7279))
  {
    printf("could not connect to our test server (localhost:7279)\n");
    Aria::exit(1);
  }

  client.addHandler("test_int_1", new ArGlobalFunctor1<ArNetPacket*>(&handleIntPacket));
  client.request("test_int_1", 1000);
  client.addHandler("test_int_2", new ArGlobalFunctor1<ArNetPacket*>(&handleIntPacket));
  client.request("test_int_2", 1000);
  client.addHandler("test_float_1", new ArGlobalFunctor1<ArNetPacket*>(&handleFloatPacket));
  client.request("test_float_1", 1000);
  client.addHandler("test_float_2", new ArGlobalFunctor1<ArNetPacket*>(&handleFloatPacket));
  client.request("test_float_2", 1000);

  client.runAsync();
  
//  while (server.getRunningWithLock())
//  {
//    ArUtil::sleep(1000);
//    //server.broadcastPacketTcp(&packet, "test3");
//  }

  ArUtil::sleep(30000);

  assert(packetcounter >= 4);

  Aria::exit(0);
}
