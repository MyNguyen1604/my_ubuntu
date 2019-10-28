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
#include "ArClientDataReceiver.h"

class TestTarget {
public:
    void printInt(const int& i) { printf("Subscriber got %d\n", i); }
};

int main(int argc, char **argv)
{
  Aria::init();
  ArClientBase client;
  ArArgumentParser parser(&argc, argv);
  ArClientSimpleConnector clientConnector(&parser);

  /* Check command-line parameters: */
  parser.loadDefaultArguments();
  if (!Aria::parseArgs() || !parser.checkHelpAndWarnUnparsed())
  {
    Aria::logOptions();
    exit(0);
  }

  /* Connect to server: */
  if (!clientConnector.connectClient(&client))
  {
    if (client.wasRejected())
      printf("Server '%s' rejected connection, exiting\n", client.getHost());
    else
      printf("Could not connect to server '%s', exiting\n", client.getHost());
    exit(1);
  } 
  printf("Connected to server.\n");
  client.setRobotName(client.getHost()); // include server name in log messages


  /* Request "test_pub" data from the server.  This data will be
   * automatically requested every 1000ms, and when any response is received, then
   * the printInt() method of the 'test' object will be called. 
   * The template parameters <TestTarget, int> indicate the type of the target
   * object, and the type of the value to be obtained from the responses from
   * the server and passed to the target method printInt() as an argument (by
   * reference).  For this to work, the server must have "test_pub" data
   * available, and responses must include values of the correct type 
   * (integer).
   * See the definition of the TestTarget class above.
  */
  TestTarget test;
  ArClientDataReceiver<TestTarget, int> receiver(&client, "test_pub", &test, &TestTarget::printInt, 1000);

  /* Begin communicating with the server. run() will exit if disconnected for
   * any reason. */
  client.run();
  client.disconnect();
  Aria::exit(0);
}
