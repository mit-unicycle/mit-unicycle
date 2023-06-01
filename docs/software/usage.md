# Software Explanation and Usage

The software structure is simple. There is a folder named _classes_ which contains all the c++ classes used in the main *Self_balancing.ino* file. We decided to use classes to improve the reusability and modularity of the code. 

## Self_balancing.ino

This is the main file that combines together all the other classes. 

## FSM.cpp

This class models ha finite state machine for the balancing robot. It has different states it can be set to, in order to facilitate the control of the robot. 

## Gyro.cpp

This class is used to interface with the MPU6050 and retrieve the roll, pitch and yaw angles. 

## mpuCalibration.cpp

This is a very important class to calibrate the MPU6050. Every time the MPU6050's angle readings appear incorrect, it means it must be calibrated. This class is therefore used to find the offsets for the MPU6050. 

## mqttClient.cpp

This class is used for the MQTT connection and messages. 

## MyPIDController 

This was a class we created while trying to get the first prototype to work. It is an implementation of a PID Controller following [Phil’s Lab video](https://youtu.be/zOByx3Izf5U). 

## pidautotuner.cpp

This is another class we created while trying to get the prototype to work. We were having lots of problems with the tunning of the gains, so we tried to use an autotuner. In the end, the problem was that the setpoint must had been dynamically shifted. Once we implemented that, it was much easier to find the parameters manually. 

## PIDControl.cpp

This is a wrapper class for the excellent [PID library](https://playground.arduino.cc/Code/PIDLibrary/) created by Brett Beauregard. This is the one we ended up using. 

## Scheduler.cpp

## VESC.cpp

This class is used to interface with the FSESC.