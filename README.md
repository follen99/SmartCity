# Smart City
This references the `International Competition On Embedded Systems`

## What Are Smart Cities?
A **smart city** is a place where traditional networks and services are made more **efficient** with the use of **digital solutions** for the benefit of its inhabitants and business.

A smart city goes beyond the use of digital technologies for **better resource** use and **less emissions**. It means smarter urban transport networks, upgraded water supply and waste disposal facilities and more efficient ways to light and heat buildings. It also means a more interactive and responsive city administration, safer public spaces and meeting the needs of an ageing population.

## My Goal
As we can see from the **Smart City** definition, the main goal is to have a **safer** and **cleaner** city.
A way to achieve that is by monitoring the `CO2` in the air and using `using less resources`, turning lights down when we do not need them or limiting car traffic when the `CO2` levels are too high.

A really important factor is to `understand` **when** and **why** some levels are too high, so a method to fix too high `CO2` values is by **logging** whenever there is an event, to **analyze** the data later.

## The Code

### Air Control
We can **monitor** the **air quality** via a `CO2` detector: 

![circuit](https://github.com/follen99/SmartCity/blob/main/Screenshots/airQualityCircuit.png)
And we can control it via the code:

![air quality](https://github.com/follen99/SmartCity/blob/main/Screenshots/airQuality.png)

Of course, we need a way to interface with the circuit: 

![interface](https://github.com/follen99/SmartCity/blob/main/Screenshots/airQualityInterface.png)

When the air gets gradually worse, a bunch of `LEDs` gradually turns on;
on the last stage, when the air is not safe, a `PIEZO` starts beeping, acting as an alarm.

---

### Turning off lights when we do not need them
We could use a circuit to turn off road lights when there is no one near by, to **save electricity**.
This goal is achieved by using an **array** of standalone sensors: 
![array](https://github.com/follen99/SmartCity/blob/main/Screenshots/CarDetectorCircuit.png)

Every **sensor** is **powered** by a `Solar Cell`, to save even more power.
Anyway,  the first **sensor** is connected to the `Controller` (arduino) to know when a car passes by.
We need this **feature** to **LOG** the event:

![car pass](https://github.com/follen99/SmartCity/blob/main/Screenshots/carPass.png) 

---

### LOGS
Whenever a car passes by, it's identified as an **event**, and a `Logger` saves it.
We should save events (`logs`) to a **file** or a **database**,  but `TinkerCad` does not have this function yet. 
We instead simply print to a console the **log** in a **json** form:
![logs](https://github.com/follen99/SmartCity/blob/main/Screenshots/log.png)

We can see how the **log** will be writed: 
![enter image description here](https://github.com/follen99/SmartCity/blob/main/Screenshots/log_example.png)
