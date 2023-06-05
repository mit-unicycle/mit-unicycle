# Challenges Faced

Throughout the eight weeks of working in these project, we faced many challenges and difficulties. 
In this part of the documentation, we will address these challenges and discuss the solutions we found. The goal is to document the process and provide a small troubleshooting guide. 

## MPU6050

The MPU6050 is cheap accelerometer and gyroscope that is readily available, and it is able to get very precise readings if configured correctly.
However, we struggled a lot to get reliable and correct angle measurement from it. 

It would sometimes start spitting random values for no apparent reason, sometimes the readings just freeze and other times the angle changes on it's own once the motor is spinning.
Note that we used the integrated [DMP](https://mjwhite8119.github.io/Robots/mpu6050) of the mpu6050, as it provides a much more accurate reading and even provides [quaternions](https://en.wikipedia.org/wiki/Quaternion) that can avoid [gimbal lock](https://en.wikipedia.org/wiki/Gimbal_lock).

For each of these problems we pinpointed the problem and found a solution:

- The **loop frequency** of the NodeMcu was very slow (see below), so the integrated buffer was overflowing, which is the cause of random values.
- The **mechanical vibrations** were causing the accelerometer to fluctuate too much and were interfering with the reading. We added dampeners and attached the mpu with velcros instead of screws to fix the issue
- The **I2C bus of the esp8266 is not very stable**, so sometimes is freezes which turned out to be a known issue. We solved it by adding a timout for the bus which restarts it in case it fails.
- A lot of these MPU6050 chips are made in China at very high volumes, so a good proportion of them don't function properly, so try multiple ones to isolate this if you are having issues.

## ESP8266
We used the NodeMcu 0.9 for our project, which is excellent for it's cost! It is based on the esp8266 chip, which makes it 10 times less expensive and 10 times faster than
other options like the AVR arduino Uno (160Mhz instead of 16Mhz). However, this comes at a cost : **stability**, **predictability** and **code availability**. 

A lot of code other people used is not compatible with this device, for instance interrupts are
handled differently, which forced us to rewrite some existing code. Some libraries were just bad, such as the integrated Servo.h library, which uses blocking code and slows down
the whole loop to 50Hz! This is what caused the MPU6050 to act bizarrely and took a lot of time to debug.
And finally the I2C bus is unstable which also made the IMU readings unreliable.

Here are some of the solutions we implemented over time:

- Add **Schedulers** (timers) to run different parts of the code at different times, solving the blocking issue of Servo.
- Play with the **frequency of the I2C bus** and **timeout** for it to be more predictable
- Overclock to **160Mhz** instead of the default **80Mhz**
- To increase the speed of the loop even more, we **minimised the number of Serial prints** and **increased the baud rate to 250000**

We tried to squeeze as much performance as possible out of it, and the difference it makes is really impressive, as we do need as much responsiveness as possible.

## Motor Controller
First we got a cheap RC Car sensored ESC from amazon and thought it would do the trick. This was not the case, as these ESC's are **not intended for robotics and are not very precise**. 
They are a "black box" in a sense that the settings are ambiguous, and we don't know what the curves it uses are for setting the RPM which could be making the system non-linear (no good for our controller). 
They are also controlled by a standard RC PWM signal (Servo style), which is 50Hz, but we need to update the speed of the motor at a much higher frequency to be able to balance the robot (at least 120Hz), which is not possible with these ESC's.

The solution:

- We got a new controller, the **VESC**, which is a very powerful and precise controller, which can be controlled by a **serial interface (UART)**, and can be configured to use a much higher frequency. It is also open source and has a large community, but is **twice as expensive**.
- Having a brushless setup means that the controllers must be **very expensive** to accomplish the level of control we need. A **brushed** one doesn't need any fancy controller, has constant torque, can be controlled at high frequency and is much cheaper.

## Heat
With great power comes great heat. The motors we used are very powerful and can draw up to 40A each at full power (~450W), which is a lot of current. This means that the motors get very hot, so we can not run them for long periods if the load is too large without damaging them.

Solutions:

- Current is **directly proportional** to the torque of the motor, so we can reduce the current by reducing the torque. This is what we did by adding a **pulley reduction** to the motors, which reduced the torque by a factor of 7, which means that the current is also reduced by a factor of 7 and so is the speed. This means that the motors can run for longer periods without overheating.
- We also added a **computer fan** to cool down the motors, which is effective and can be turned on and off with a switch.

## Tuning

For three whole weeks, we did not realize that we were using the PID controller library wrongly. Setting **only a proportional gain** wasn't doing what we expected, which was to increase the output of the PID controller as the error increased and **oscillate around the set-point**. 
Instead, the output was oscillating around another seemingly random value.

After a lot of debugging and trying custom PID controllers, we were able to fix it:

- Use the **flag P_ON_E** which means proportional on error instead of the default **P_ON_M** which is proportional on measurement. This means that the **error is used to calculate the proportional gain** instead of the measurement, which is what we want.
- **Reset the PID controller** after changing the set-point while running so that is completely forgets the previous state and starts from scratch.
- Tune the PID controller with the **Ziegler-Nichols method**, which is a simple and effective method to tune PID controllers.

## Collaboration

For many of us, this was the first time working on such a big project and with so many team members. As such, collaboration was a a significant challenge right from the beginning. 
All the team members were really motivated and invested in the project. Hence, when there were different opinions about how to do something, it was often hard to reconcile the different viewpoints. 
Often, when the opinions differed, they led to significant internal discussions. 

A notable example is what motors we should use. Some of us believed that a brushed would be the best option, while others believed that a brushless one would be more adequate. 
In the end, we often solved such conflicts by testing both options and finding which would be "objectively" the best. 

It is interesting to reflect back on this project, since a considerable part of the difficulty was not conceiving the robot in itself, but the collaboration. 
This is why, not only did we acquire more knowledge, practical and technical skills, but we also learned to collaborate. 
We found out that collaboration is a mix between stating what you as individual wants to do, while keeping in mind what others want to do, and finally discussing a solution that suits both parties. 
It is for this reason that we are happy to have embarked on such a project, since we strongly believe it will help us in our future professional and personal lives.

