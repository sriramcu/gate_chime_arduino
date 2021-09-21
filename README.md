# Arduino Gate Chime
An Arduino based system that raises an alarm when the gate is opened, by using metallic contacts on the gate latch.

## Requirements  

1. A gate with a latch
2. Arduino Uno with 10 bits resolution and 5 Volts operating voltage, with the relevant power supply.
3. At least 10 breadboard wires. 
4. 2 long electrical wires of low-resistance of length 1 metre each.
5. Two metallic contacts (to be attached to the gate latch)
6. One 5V Piezo speaker
7. Two 3.3k ohm resistors (to be used as pulldown resistors)
8. 1 one-way/two-way switch
9. Any small plastic box to enclose the system
10. Soldering iron and wire cutter


## Circuit Diagram  

<p align="center"><img width="550" alt="gate_open" src="https://user-images.githubusercontent.com/67961190/134167819-6976f00f-e9ca-47a0-996d-01f595a7d616.png"></p>

Fritzing diagram will be added in the near future.  


## Instructions  

1. Make the connections as shown in the above circuit diagram. For the gate contacts, put one end of the breadboard wire into A0 and the other into 5V pin as shown. Solder the other ends of these wires to conventional low-resistance, long electrical wires that run all the way to your gate.
2. Attach each of the two wires to a metallic contact. Stick/tape one metallic contact on the moving latch and another contact on the bottom surface on which the latch rests when closed. The gate latch looks like this when **open**:
<p align="center"><img width="550" alt="gate_open" src="https://user-images.githubusercontent.com/67961190/134157722-0c917eef-16a6-4a16-a2bc-e0738d2fd0dc.jpg"></p>

The gate looks like this when **closed**:  

<p align="center"><img width="550" alt="gate_open" src="https://user-images.githubusercontent.com/67961190/134165928-d94c1e2b-a9a2-44a7-8ec3-a5c169d0efdb.jpg"></p>


3. Follow a similar process to connect the switch.
4. Pull down A0 and A5 using the pulldown resistors.  
5. Attach one terminal of a piezo speaker to any resistor (to reduce the noise). The other end of the resistor goes into the GPIO pin 9 and the other terminal of the piezo speaker is connected to ground.  
6. Enclose the Arduino in a box and make appropriate holes for the wires and the piezo speakers terminals. Stick the piezo speaker to the case. The system is shown below:

<p align="center"><img width="550" alt="gate_open" src="https://user-images.githubusercontent.com/67961190/134166884-5f34a980-6e97-489b-91f5-740d274bab2e.jpg"></p>  

7. When the gate is opened, the following alarm is played until the gate is closed again. The alarm can be disabled or snoozed for 10 minutes by clicking the switch. This is done when you are expecting the gate to be opened frequently at a certain time and you want to silence the alarm without turning off the system.



https://user-images.githubusercontent.com/67961190/134155049-d0c94e4e-a152-4968-8f4b-b50a6d17e486.mp4

