# Tuning Guide

In this section we will briefly discuss the method we used to tune the PID controller. It is very helpful to understand how the PID controller works, and for that we recommend reading the [controller explanation](../software/controller.md). 

## Manual Tuning

Most of the part of the tuning was done manually. Be aware that tuning is a very tedious and time-consuming process. Some say, modern Sisyphus is not pushing a rock uphill, but tuning a PID controller for eternity. 

The method we recommend is the one [found](https://en.wikipedia.org/wiki/PID_controller#Manual_tuning) in Wikipedia. As a general rule of thumb, one parameter should be modified at a time with small increments. However, sometimes following a hunch and changing multiple parameters at once proves useful. 

1. Start by only using the proportional channel and increase the value until the responsiveness of the robot is fast enough. Normally, if you let go the robot at this point, it will start oscillating and then fall. 
2. Continue by using the integral channel too. This will increase the responsiveness and the robot will be able to better correct the error. At the end of this step, the robot should be able to balance, but it will keep oscillating.  
3. Finally, start using the derivative path. The goal of the derivative path is to reduce the oscillations of the robot and help it stabilize around the setpoint.
