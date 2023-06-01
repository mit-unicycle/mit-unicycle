# Software Explanation and Usage

The software structure is simple. There is a folder named _classes_ which contains all the c++ classes used in the main *Self_balancing.ino* file. We decided to use classes to improve the reusability and modularity of the code. Although we will briefly discuss each class here, we invite you to read the code to have a better understanding of it. 

## Self_balancing.ino

This is the main file that combines together all the other classes. It setups the MQTT communication, namely retrieving the parameters from the web app. It also loops over the finite state machine (FSM).

## FSM.cpp

This class models a FSM for the balancing robot. It has different states it can be set to, in order to facilitate the control of the robot. The most important function in this class is called *loop()*. It is in charge of updating the FSM. Most importantly, it calls the computation of the PID output. The different states are: 

- Disabled: If the robot has fallen beyond a certain angle, it will turn off the motors to avoid any harm to us or the wheels. 
- Balance
- Debug: Similar to *Balance*, but it will print useful information. 
- Tuning: Used to calibrating the MPU6050's offsets. 

## Gyro.cpp

This class is used to interface with the MPU6050 and retrieve the roll, pitch and yaw angles. 

## mpuCalibration.cpp

This is a very useful class to calibrate the MPU6050. Every time the MPU6050's angle readings appear incorrect, it means it must be calibrated. This class is therefore used to find the offsets for the MPU6050. 

## mqttClient.cpp

This class is used for the MQTT connection and messages. We used the MQTT protocol to update the tunings of the robot, like the gains and the setpoint, without having to reupload the code. 

## MyPIDController 

This was a class we created while trying to get the first prototype to work. It is an implementation of a PID Controller following [Phil’s Lab video](https://youtu.be/zOByx3Izf5U), but without using any external libraries.

## pidautotuner.cpp

This is another class we created while trying to get the prototype to work. We were having lots of problems with the tunning of the gains, so we tried to use an autotuner. In the end, the problem was that the setpoint must had been dynamically shifted. Once we implemented that, it was much easier to find the parameters manually. 

## PIDControl.cpp

This is a wrapper class for the excellent [PID library](https://playground.arduino.cc/Code/PIDLibrary/) created by Brett Beauregard. This is the one we ended up using, as it has many useful features as integration clamping, derivative-on-measurement and many more. See [this link](http://brettbeauregard.com/blog/category/pid/coding/) to find out more. 

## Scheduler.cpp

The scheduler is a sort of timer that allows us to run different parts of the code at different frequencies. 

## VESC.cpp

This class is used to interface with the FSESC.