# Underlying physics
In this section, we will explain the physics behind the balancing robot, and how we used it to design the robot.

## Physics concept
In order to build a functioning balancing robot, it is really important to understand the physics that make it work. In this section, we will address this.

The self-balancing capability of our robot relies on the  conservation of angular momentum.
When the robot tilts, the reaction wheel is accelerated in a controlled manner in order to apply a reactive torque on the system, thus countering the torque caused by gravity. 
By exerting an opposing force, the reaction wheel helps restore the robot to an upright position. This continuous adjustment and counteraction of tilting forces enable the robot to maintain its balance in real time.
<br><br> We can consider the following simplified model of an inverted pendulum: <br>

![Simplified model illustrations](../images/manufacturing/../Manufacturing_images/Model%20drawing.png)

We can derive the equations of motion of the system using **rotational mechanics**, which will help us understand what kind of forces we are dealing with. 
Please check the <a href="https://drive.google.com/file/d/1Ae1CPihRvgqLchlg4Ux5KGsnINjBrRcP/view?usp=sharing" target=”_blank”>full development</a> for more details on notation and derivation. <br>
Here are some of the important formulas we derived:

Torque:
$$\tau_w = I_s\alpha_s - h_gMgsin(\phi)$$
Angular acceleration:
$$\alpha_w(\phi)=\frac{I_s}{I_w}\alpha_s - \frac{h_gMgsin(\phi)}{I_w}$$
Power:
$$P_w = \tau_w\omega_w$$

You can find the Graphs of the equations of motion in our <a href="https://www.desmos.com/calculator/29tuxbyqqt" target=”_blank”>Desmos Project</a>, and play around with the parameters to see how they affect the system.

We found out in our initial estimations that a quite large output torque is required to stabilize the 2 axis robot with the parts that were available to us, about 2Nm and 25W of *mechanical power* at least,
which is why we chose to use a brushless motor and a speed reduction of 7 times.

####Remarks: 
<ul>
    <li>We don't consider friction and inefficiency for the sake of simplicity</li>
    <li>We didn't solve the differential equations as we don't really need to, so we don't take into account time, just the current angle relative to the vertical.</li>
</ul>

## References
We used the following papers to fact check our calculations:

- <a href="https://mit-unicycle.github.io/mit-unicycle/pdfs/ResearchGate.pdf" target=”_blank” rel="noopener noreferrer">Researchgate: Design and implementation of a self-balancing robot</a>
- <a href="https://mit-unicycle.github.io/mit-unicycle/pdfs/KTH.pdf" target="_blank" rel="noopener noreferrer">KTH: Reaction Wheel Stabilized Stick</a>
