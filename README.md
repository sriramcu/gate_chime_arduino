# gate_chime_arduino
Arduino based system that raises a custom alarm when the gate is opened, by using metallic contacts.

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

<img width="597" alt="circuit_diagram" src="https://user-images.githubusercontent.com/67961190/134155146-3c88c725-7d40-482c-8a99-6ddd421136c1.png">

Fritzing diagram will be added in the near future.  


## Instructions  

1. Make the connections as shown in the above circuit diagram. For the gate contacts, put one end of the breadboard wire into A0 and the other into 5V pin as shown. Solder the other ends of these wires to conventional low-resistance, long electrical wires that run all the way to your gate.
2. Attach each of the two wires to a metallic contact. Stick/tape one metallic contact on the moving latch and another contact on the bottom surface on which the latch rests when closed. The gate latch looks like this when **open**:

![gate_contact_open](https://user-images.githubusercontent.com/67961190/134157341-daf0c5e7-3300-40df-ba08-491c1f506c6c.jpg)




https://user-images.githubusercontent.com/67961190/134155049-d0c94e4e-a152-4968-8f4b-b50a6d17e486.mp4

