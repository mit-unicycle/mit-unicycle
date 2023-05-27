

![Alt text](images/logo-epfl-1024x576.png)


# Manufacturing


## Preliminaries

In this section you will find the informations related to the realisation of the 3D designs,the specification about the printing of our parts and the blueprints of the parts. For the designs we used Fusion 360 Prusa 3D printers

1. The reaction wheel and spacers
2. The theeted pulleys
3. The motor coupler
4. First prototype : main plateform
5. First prototype : motor shaft holder
6. First prototype : reaction wheel holder
 
## The reaction wheel and spacers

-The reaction wheel : 

In order to achieve the maximum moment of inertia for the reaction wheel, our objective was to maximize the diameter of the wheel. Since the moment of inertia is the sum of the squared distances to the mass, the farther the mass is from the axis, the larger the moment will be. However, we faced a constraint due to the size of the printing bed of the printer we used for the distane to the axis.

Our experimentation demonstrated that a wheel with a thin design could easily break if the model were to fall. This is why the model we have implemented here is highly robust and should not break, provided it is used correctly in the application of this project.

//todo : add image and blueprint of the reaction wheel

//todo : add the model of prusa printer we use
The most crucial aspect of printing this part is to use an appropriate perimeter setting. Increasing the perimeter setting enables us to reinforce the piece without significantly increasing the infill. It is essential for the holes where we will insert screws, nuts, and the location where the ball bearing will be placed to be sufficiently strong. This ensures that they do not break during rotation or when inserting the ball bearing. Here we used a perimeter of 4 and an infill of :


-The ball bearing spacers : 

As you will see in the section where the assembly of the model is explained, we required spacers with the same diameter as the inner diameter of the ball bearing to ensure a tight fit between the ball bearings.

The following design shows the dimension you should have for those spacers

-The plates spacers : 

In order to avoid that the belt hits the nuts from the reaction wheel while working, we needed spacer plates to increase the distance between the teethed pulley therefore we designed the spacing plates here bellow is the design and the dimensions of those spacers.


## The teethed pulley

We used GT-2 belts, which necessitated the design of GT-2 pulleys. To achieve this, we employed a functionality in Fusion 360 that enabled us to create parametric designs of the pulleys. This approach facilitated the rapid design of the desired pulley variations and also facilitated testing different gear reduction options. The creation of this design is explained step by steps just bellow

The GT-2 pulley is a type of standard for the teeth of the pulley (or the belts), it is defined by the pitch of the teeth of the pulleys. Therefore the parametric design depends on the number of teeth desired for the pulley. In our application the number of teeth needed depends on the reduction we wanted, ( //todo : add the number of teeth we used for the different reductions).

//todo : add parameter list with the explaination of what they correspond to for pulley
//todo : explain parameters explain step by step the creation of the parametric design 

For this printing, the most important setting is the precision, since we are printing the pulley which have small teeth, we need the printing to be as precise as possible


## Motor coupler

For the motor coupler we machined them with the tools we had at our diposition which allowed us to create a really good coupler for the motor



## First prototype : Support plate : 

As the first prototype purpose is to balance in one axis of freedom, we needed a plate where we could fit the motor, the ESC, the breadboard and the esp8266. For the first prototype we did all the tests without the batterie mounted.

## First prototype : reaction wheel older : 


