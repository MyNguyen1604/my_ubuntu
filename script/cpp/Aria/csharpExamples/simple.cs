
/* A simple example of connecting to and driving the robot with direct
 * motion commands.
 *
 * Note: Since "lock()" and "unlock()" are reserved words in C#, "lock()" and
 * "unlock()" methods in all ARIA objects (e.g. ArRobot) have been renamed 
 * to "lockObj()" and "unlockObj()".
 */

using System;
using AriaCS;


public class simple {


  public static void Main(String[] argv) {
    Console.WriteLine("Starting Test");

    Aria.init();

Console.WriteLine("argumentparser...");
    ArArgumentBuilder argBuilder = new ArArgumentBuilder();
    ArArgumentParser parser = new ArArgumentParser(argBuilder);
    parser.loadDefaultArguments();
Console.WriteLine("arrobot...");
    ArRobot robot = new ArRobot();
    ArRobotConnector conn = new ArRobotConnector(parser, robot);

    Console.WriteLine("Connecting to robot...");
    if (!conn.connectRobot())
    {
      Console.WriteLine("Error: Could not connect to robot, exiting.");
      Aria.exit(1);
    }

    Console.WriteLine("Connected to robot.");
 
    if(!Aria.parseArgs())
    {
      Aria.logOptions();
      Aria.exit(2);
    }

    robot.runAsync(true);
    robot.lockObj();
    Console.WriteLine("Sending command to move forward 1 meter...");
    robot.enableMotors();
    robot.move(1000);
    robot.unlockObj();
    Console.WriteLine("Sleeping for 5 seconds...");
    ArUtil.sleep(5000);
    robot.lockObj();
    Console.WriteLine("Sending command to rotate 90 degrees...");
    robot.setHeading(90);
    robot.unlockObj();
    Console.WriteLine("Sleeping for 5 seconds...");
    ArUtil.sleep(5000);
    robot.lockObj();
    Console.WriteLine("Robot coords: robot.getX()=" + robot.getX() + ", robot.getY()=" + robot.getY() + ", robot.getTh()=" + robot.getTh()); 
    ArPose p = robot.getPose();
    Console.WriteLine("               pose.getX()=" + p.getX() +     ", pose.getY()="  + p.getY() +     ",  pose.getTh()=" + p.getTh());
    robot.unlockObj();
    robot.lockObj();
    Console.WriteLine("exiting.");
    robot.stopRunning(true);
    robot.unlockObj();
    robot.lockObj();
    robot.disconnect();
    robot.unlockObj();

    robot.Dispose();
    conn.Dispose();

  }
}
