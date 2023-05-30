# Reaction Wheel Robot Project


## Index
1. Building the Prototype
    - 1.1 [Underlying Physics](buidling/physics.md)
    - 1.2 [Components Used](building/components.md)
    - 1.3 [Manufacturing](building/manufacturing.md)
    - 1.4 [Assembly Instructions](building/assembly.md)
    - 1.5 [Wiring Instructions](building/wiring.md)

2. Software Instructions
    - 2.1 [Controller Explanation](software/controller.md)
    - 2.2 [Software Environment Setup](software/setup.md)
    - 2.3 [Software Usage](software/usage.md)
    - 2.4 [Tuning Guide](software/tuning.md)

3. Process
    - 3.1 [Challenges Faced](process/challenges.md)
    - 3.2 [Future Improvements](process/improvements.md)
    - 3.3 [Conclusion](process/conclusion.md)

## Introduction

Welcome to the EPFL Reaction Wheel Robot Project which was realized by a team of 5 Computer Science students during the 2023 summer semester. Through this complete documentation, we will guide you through the manufacturing and software installation process of the robot. We will also provide you with a detailed description of the software architecture and the different components of the robot, empowering you to further develop the prototype and add new features to it.

<iframe width="850" height="520" src="https://www.youtube.com/embed/n_6p-1J551Y" title="The Cubli: a cube that can jump up, balance, and &#39;walk&#39;" frameborder="0"; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

## Project Description
Our practical requirements focus on stabilizing a robot holding itself on a pole or an actuated wheel to the ground, having 2 axis of freedom. The requirements include the following: stabilizing the robot along one first axis, then a second perpendicular axis and therefore apply real-time corrections on the linear combinations of the torque along both axis, allowing the whole to self-balance on the pole or the wheel.

## Physics Background
How are we going to produce the necessary force required to stabilize the robot? The answer is by using reaction wheels. A reaction wheel is a type of flywheel used primarily by spacecraft for attitude control without using fuel for rockets or other reaction devices. They are particularly useful when the spacecraft must be rotated by very small amounts, such as keeping a telescope pointed at a star. Reaction wheels can rotate a spacecraft only around its center of mass (see torque). This is compared to the maneuvering thrusters used on many spacecraft, which can also translate the spacecraft, and are therefore located at various places on the spacecraft. Reaction wheels work around a nominal zero rotation speed. However, external torques on the spacecraft may require a change in the angular momentum vector of the spacecraft, and the wheels' rotation rate will change in response. To reactivate zero rotation speed, the wheel is accelerated in the direction opposite to its rotation. The momentum of the wheel opposes the momentum of the spacecraft, slowing the spacecraft. To rotate the spacecraft in a given direction, the wheel is accelerated in that direction. This causes the spacecraft to rotate in the opposite direction, according to Newton's third law. Due to conservation of angular momentum, the rotation of the spacecraft will accelerate, whether or not the wheel is subsequently slowed back down to its nominal speed. To desaturate the reaction wheel, the direction of rotation of the reaction wheel is reversed for a short time. This transfers angular momentum from the spacecraft to the reaction wheel to slow the rotation of the spacecraft.

## First Draft of the Prototype