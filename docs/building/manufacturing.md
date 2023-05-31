


# **Manufacturing**


## **Preliminaries**

In this section you will find the information related to the realization of the 3D designs,the specification about the printing of our parts and the blueprints of the parts. This section will be separated in **3 parts** : the first presenting the parts that can be used for both one and two axis, then the parts specific to the one axis design and finally the parts for the two axis model. For the designs we used **Fusion 360** and **Prusa 3D printers**. Note that every dimension reported on the blueprint are given in **millimeters (mm)**.

1.   **How to design a GT-2 pulley with Fusion 360**

2. **Common parts :**

    - 1.1 The reaction wheel and the spacers

    - 1.2 The teethed pulley
    - 1.3 The motor coupler
    - 1.4 The motor pulley


3. **First prototype**
    - 3.1 Main platform
    - 3.2 Motor shaft holder
    - 3.3 Reaction wheel holder

4. **Second prototype :** 
   - 4.1 Main plateform

   - 4.2 The Stick 
   - 4.3 the motor support
   - 4.4 the motor shaft holder
   - 4.5 the reaction wheel holder


## **how to design a GT-2 parametric design of a pulley**

 * **What is a GT-2 pulley ?**

A GT-2 pulley is a type of standard for belts and pulleys, it is defined mostly by the pitch of the teeth and the distance between the edges of two teeth. Here's the description of the parameters we're interested in for designing the teethed pulley. 

First the value R1 is the inner pitch of the teeth of our pulley, we can think about it as if we small circles of this diameter at the same position at both side of one of the pulley's teeth.

Then the R3 parameter if the tooth radius, in the case of the design of the pulley.

The parameter P is really important since it is the distance between two teeth (**in mm**). Therefore the diameter is defined by : (P*N)/Pi, with N, the number of teeth we want, therefore by doing basic algebra we can find the perimeter of such a pulley as a function of N and P.

![Alt text](images/belt-tolerence.jpg)

 * **How to create the parametric design using fusion parametric design option ?**

## **1. Common parts**

### 1.1 The reaction wheel and the spacers 

* **The reaction wheel**

In order to achieve the maximum moment of inertia for the reaction wheel, our objective was to maximize the diameter of the wheel. Since the moment of inertia is the sum of the squared distances to the mass, the farther the mass is from the axis, the larger the moment will be. However, we faced a constraint due to the size of the printing bed of the printer we used for the distance to the axis.

Our experimentation demonstrated that a wheel with a thin design could easily break if the model were to fall. This is why the model we have implemented here is highly robust and should not break, provided it is used correctly in the application of this project. **Note that the reaction wheel has 32 holes for the screws used to add weight far from the axis.**

![](images/ReactionWheel.png)



The most crucial aspect of printing this part is to use an appropriate perimeter setting. Increasing the perimeter setting enables us to reinforce the piece without significantly increasing the infill. It is essential for the holes where we will insert screws, nuts, and the location where the ball bearing will be placed to be sufficiently strong. This ensures that they do not break during rotation or when inserting the ball bearing. Here we used a perimeter of 4 and an infill of :


* **The spacers**

As you can observe in the section explaining the assembly of the model, we needed spacers with the same inner diameter as the ball bearing to ensure a good fit between the ball bearings.

The accompanying design picture, illustrates the dimensions of one of these spacers. **Please note that we used spacers of various sizes, but we are presenting only one blueprint as the only difference lies in the height of the spacers.**
//todo add the list of size of the spacer we use

![Alt text](images/general_spacer.png)

* **The plates spacers :** 

In order to avoid that the belt hits the nuts from the reaction wheel while working, we needed spacer plates to increase the distance between the teethed pulley therefore we designed the spacing plates here bellow is the design and the dimensions of those spacers.


### **1.2. The teethed pulley**

We used GT-2 belts, which necessitated the design of GT-2 pulleys. To achieve this, we employed a functionality in **Fusion 360** that enabled us to create parametric designs of the pulleys. This approach facilitated the rapid design of the desired pulley variations and also facilitated testing different gear reduction options. The creation of this design is explained step by steps just bellow

The GT-2 pulley follows a specific standard for the teeth, which includes the pitch of the teeth on the pulleys and belts. Therefore, the parametric design of **the pulley size depend on the desired number of teethAlt text that's why there is no informations about the diamater of the pulley**. In our specific application, the number of teeth required is determined by the desired gear reduction.

![Alt text](images/GT2_7_REDUCTION%20Drawing%20v1-1.png)


//todo : add parameter list with the explanation of what they correspond to for pulley
//todo : explain parameters explain step by step the creation of the parametric design 

For this particular printing, the most important setting to consider is the **precision**. Given that we are printing pulleys with small teeth, it is essential for the printing to be as accurate and precise as possible. Here we used the option : **10mm Quality** preset from **Prusa Slicer**. To prevent the belt to skip, we need plates to help the belt stay straight in on the pulley, here's the blueprint of those plates : 

![Alt text](images/GT2_7_REDUCTION_plates%20Drawing%20v1-1.png)

### **1.3. Motor coupler**

For the motor coupler, we machined them using the tools available to us. This approach enabled us to create a high-quality coupler specifically designed for the motor we had. We were unable to find any suitable couplers for purchase online that could be delivered within a reasonable time frame, which is why we resorted to machining our own. Here's the blueprint we created for this coupler

//todo : modify drawing, 3mm of thickness

![Alt text](images/Metal%20shaft%20coupler%20Drawing%20v3-1.png)

### **1.4. The motor pulley :**

To do the gear reduction we wanted we needed to fix a small teethed pulley to the motor coupler. We needed this pulley to be small enough to avoid printing enormous pulley if we wanted to modify the gears reduction. Increasing the reduction means modifying the height of the reaction wheel it could also mean buying new belts if the diameter of the pulley is too big. The minimum diameter of the pulley (which is in fact a constraint on the number of teeth) is limited by the screwholes position of the motor coupler. 

//todo : add the function that allows to calculate the radius of the pulley

**! again there is no informations about the pulley's diameter on the blueprint since it depends on the number of teeth !**

![Alt text](images/Motor%20pulley%20Drawing%20v1-1.png)

## **2. First prototype :** 

   <font size = "3">1. Support plate :</font> 

<font size = "3">As the first prototype purpose is to balance in one axis of freedom, we needed a plate where we could fit the motor, the ESC, the breadboard and the esp8266. **Note that for the first prototype we did all the tests without the battery mounted.** </font>

![Alt text](images/One%20axis%20bottom%20Drawing%20v1-1.png)


## First prototype : reaction wheel older : 
 
The part here bellow is designed to hold the threaded rod to hold the reaction wheel.
   
![Alt text](images/One%20axis%20wheel%20holder%20Drawing%20v3-1.png)



## Sources of the images

GT pulley informations taken from : https://openbuildspartstore.com/ 



