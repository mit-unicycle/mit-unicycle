# Components Used

In this section, we will list the components we used and the reason for choosing them. 

## List of Components

1. NodeMCU esp8266
2. MPU6050 Gyroscope and Accelerometer Module
3. Dilwe 540 Sensored Brushless DC Motor
4. FSESC 4.12 50A Motor Driver
5. GT2 9mm width, 700mm long toothed belt
6. 1m long, M8 threaded rod
7. M8 bolts and nuts for the structure of the robot
6. M5 bolts and nuts for increasing the moment of inertia of the reaction wheel

## NodeMCU esp8266

We chose to use the NodeMCU esp8266 for various reasons. First and foremost, the NodeMCU has a maximal clock speed of 160 MHz. In comparison to the Arduino Uno's 16 MHz, the NodeMCU is extremely fast. This suits our robot well, since for it to balance, it must react as quickly as possible. Moreover, the NodeMCU has a WiFi card embedded. This is really convenient for tunning the PID parameters, as it allows us to avoid flashing the nodeMCU every time we change change the parameters. 

## MPU6050 Gyroscope and Accelerometer

The MPU6050 is a cheap and readily available gyroscope and accelerometer. As we will discuss in the [Challenges](/docs/process/challenges.md) section, it was not easy to get it to work properly from the beginning. 

## Dilwe 540 Sensored Brushless DC Motor

This motor was an excellent choice for our robot for the following reasons: it is posses hall sensors that help the ESC to accurately control it 

## FSESC 4.12 50A Motor Driver

The FSESC is an amazing motor driver that is often used in electric skateboards, bikes and many more applications. It ships with a software to extensively tune the behavior of the ESC. For instance, it is even possible to modify the speed curves of the ESC. Moreover,it is possible to connect the motors' hall sensors to it, allowing very precise control at all speeds. 

