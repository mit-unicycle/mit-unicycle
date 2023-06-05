# Components Used

In this section, we will list the components we used and the reason for choosing them. 

## List of Components

1. 1x NodeMCU esp8266
2. 1x MPU6050 Gyroscope and Accelerometer Module
3. 2x Dilwe 540 Sensored Brushless DC Motor
4. 2x FSESC 4.12 50A Motor Driver
5. 1x 3S Lipo battery
6. 2x GT2 9mm wide, 700mm long timing belt
7. 2x 1m long, M8 threaded rod
8. 11x M8 bolts, washers, O-rings and nuts for the structure of the robot
9. 16x M6 bolts and nuts for increasing the moment of inertia of the reaction wheel
10. 4x M3 "Grub" screws for the motor coupler 
11. Zipties, elastic bands, double sided tape and velcro

## NodeMCU esp8266

<div class="component-block">
    <img src="https://mit-unicycle.github.io/mit-unicycle/images/nodemcu.png" alt="NodeMCU">

    <div>
        We chose to use the NodeMCU esp8266 for various reasons. First and foremost, the NodeMCU has a maximal clock speed of 160 MHz. In comparison to the Arduino Uno's 16 MHz, the NodeMCU is extremely fast. This suits our robot well, since for it to balance, it must react as quickly as possible. 
        <br> Moreover, the NodeMCU has a WiFi card embedded on it. This is really convenient for tuning the PID parameters, as it allows us to avoid flashing the nodeMCU every time we change change the parameters.
    </div>

</div>

## MPU6050 Gyroscope and Accelerometer

<div class="component-block">
    <img src="https://mit-unicycle.github.io/mit-unicycle/images/mpu6050.png" alt="MPU6050">

    <div> The MPU6050 is a cheap and readily available gyroscope and accelerometer. 
        It comes with a built-in DMP processor that allows for the fusion of the gyroscope and accelerometer 
        data for obtaining the roll/pitch/yaw of the sensor. 
        As we discuss in the <a href="/process/challenges/#obtaining-a-stable-and-precise-angles-from-the-mpu6050">challenges</a>, 
        it was not easy to get it to work properly. 
    </div>

</div>

## Dilwe 540 Sensored Brushless DC Motor (13.5T)
<br>
<div class="component-block">
    <img src="https://mit-unicycle.github.io/mit-unicycle/images/dilwe.png" alt="Motor">
    <div>
        This motor was our best option for the following reasons. <br>
        <ul>
            <li>It is a sensored motor, this means ESC to accurately control it and have good torque at low RPMs (this is very important)</li>
            <li>It was the cheapes option of it's kind and so was able to fit our budget</li>
            <li>It has enough power to do what we need it to do</li>
        </ul>
        It has a lot of inconveniences though, which we dicuss further <a href="/process/challenges/#finding-the-right-motors-controllers">here</a> <br>
    </div>
</div>
<br>

## FSESC 4.12 50A Motor Driver
<br>
<div class="component-block">
    <img src="https://mit-unicycle.github.io/mit-unicycle/images/FSEC.png" alt="FSESC">
    <div>
        The FSESC 4.12 is based on the <a href="vesc-project.com">VESC project</a>, an excellent Open Source ESC platform that is often used in electric skateboards, bikes and many more applications. 
        It comes with a <a href="https://vesc-project.com/vesc_tool">software</a> to extensively tune the behavior of the motor driver. 
        We can also connect the motor's hall sensors to it, allowing for very precise control at all speeds, and communicate via UART at high speeds.
    </div>
</div>


