# Challenges Faced

Throughout the eight weeks of working in these project, we faced many challenges and difficulties. In this part of the documentation, we will address these challenges and discuss the solutions we found. The goal is to document the process and provide a small troubleshooting guide. 

## Finding the Right Motors Controllers
<ul>
    <li>Having a brushless setup means that the controllers must be very expensive to accomplish the level of control we need. A brushed one doesn't need any fancy controller, has constant torque and is much cheaper</li>
</ul>

## Obtaining a Stable and Precise Angles from the MPU6050

We struggled a lot to get reliable and correct angle measurement from the MPU6050. At the beginning, we thought is could be due to a mechanical or electromagnetic interference. We quickly discarded the possibility of electromagnetic interference, as we still experienced the problem if the motors were not turned on. For the mechanical interference issue, we tried adding cushioning under the MPU6050 to improve the readings. This helped, but it did not solve the problem. 

The problem seemed to be that the MPU6050 was sending to much data to quickly to the MPU6050. So, in the end, something that helped was increasing the frequency of the NodeMCu. By doing so, the microcontroller was able to process the data quicker and more reliably. Also, decreasing the sample speed of the MPU6050 improved the readings.


## Using the PID Implementation Incorrectly 

For two whole weeks, we did not realize that we were using the PID controller library wrongly. Back then, we has been working with an ESC whose neutral value (no motor spinning) was 1500; above 1500 corresponded to a turning direction, and under 1500 corresponded to the other direction. However, the PID controller's output ranged around 0. That is, for the controller, 0 meant neutral, positive meant spinning in one direction, and negative in the other. 

Before realizing this was the problem, we tried changing to another PID implementation, writing our own PID controller, making the ESC skip its neutral range to increase responsiveness, we tried to continue tuning thinking that maybe we had incorrect parameters, etc. 

In the end, we realized that the only thing to do was shifting the PID output so that it oscillates around 1500 instead of 0. 

## Maximizing the Torque From the Motor

In our search to make the robot stabilize, we tried different pulley reductions. We started with a $4\times$ reduction, went on to do a $5\times$ and ended up with a ... By doing so, we managed to increase the torque of the wheel and make the robot stabilize more easily.   

## Dynamically Shifting the Setpoint

About one week before the deadline, we were managing to stabilize the robot for a few seconds. Nonetheless, it would quickly start to oscillate and fall. We noticed that often, the setpoint we found felt "off", as if it was not really the robot's setpoint. By re-watching James Bruton's [video](https://youtu.be/pJfMFUcquWM) on the subject, we realized that shifting the setpoint dynamically was the way to go (see the explanation [here](../software/usage.md)) for more information.

## Collaboration

For many of us, this was the first time working on such a big project and with so many team members. As such, collaboration was a a significant challenge right from the beginning. All of the team members were really motivated and invested in the project. Hence, when there were different opinions about how to do something, it was often hard to reconcile the different viewpoints. Often, when the opinions differed, they led to significant internal discussions. A notable example is what motors we should use. Some of us believed that a brushed would be the best option, while others believed that a brushless one would be more adequate. In the end, we often solved such conflicts by testing both options and finding which would be "objectively" the best. 

It is interesting to reflect back on this project, since a considerable part of the difficulty was not conceiving the robot in itself, but the collaboration. This is why, not only did we acquire more knowledge, practical and technical skills, but we also learned to collaborate. We found out that collaboration is a mix between stating what you as individual wants to do, while keeping in mind what others want to do, and finally discussing a solution that suits both parties. It is for this reason that we are happy to have embarked on such a project, since we strongly believe it will help us in our future professional and personal lives.

