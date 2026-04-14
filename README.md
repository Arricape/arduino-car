## Neccessary Parts
--- 
* 1x Arduino
* 2x micro controller (Front & Rear Axle)
* 4x Motors
* 4x Wheels
* 2x FC-03 IF Sensor
* 1x HC-SR04 Ultrasonic Sensor Rangefinder 

## Following Pins are used by the Mikrocontroller
---
Motor 1 & 3 are using Pin 3 & 9
Motor 2 & 4 use 10 & 11 

The Sensor operates on Pin 12 & 13

## Program schedule
---
       +-----------------------+
       |        Start           |
       +-----------------------+
                |
                v
      +---------------------+
      | Initialising Motors |
      +---------------------+
                |
                v
     +------------------------+
     | Measuring Distance     |      <------------------
     +------------------------+                        |
                |                                      |
                v                                      |
     +-----------------------------+           +-----------------+           
     | Distance < 20 cm?           | -- No --> | [Drive Forward] |
     +-----------------------------+           +-----------------+ 
                |
            Yes v
    +---------------------------+
    |    Stop all Motors        |
    +---------------------------+
                |
                v
       +---------------------+
       | Drive backwards     |
       +---------------------+
                |
                v
       +---------------------+
       |    Drive left       |
       +---------------------+
                |
                v
     +----------------------------------------+
     | Recheck if Obsticle is out of the way  | 
     +----------------------------------------+
                |                            |
            Yes v                         No v
       +---------------------+      +----------------------+
       |    Turn Right       |      | Keep going Backwards |
       +---------------------+      +----------------------+
                |                               |
                v                               v
       +---------------------+      +----------------------+
       |   Drive forward     |      |    Stop all Motors   |
       +---------------------+      +----------------------+
                |
                v
       +---------------------+
       |   Stop all Motors   |
       +---------------------+
                |
                v
       +---------------------+
       |      Repeat         |
       +---------------------+
