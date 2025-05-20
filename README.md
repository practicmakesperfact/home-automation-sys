1. Introduction

This project demonstrates an IoT-based home automation system using a real-time embedded platform. The objective is to simulate a smart home environment where multiple home appliances can be controlled either through simulated sound detection (via a pushbutton) or via serial commands that mimic API inputs. The system enhances accessibility and energy efficiency.

2. System Design and Circuit Diagram

The system uses an Arduino Uno microcontroller to simulate the control of three appliances:

Light (Yellow LED)

Air Conditioner (Blue LED)

Fridge (Green LED)

A pushbutton simulates sound input (clap detection). Pressing the button toggles the light on or off. All three appliances can be independently controlled through serial commands.

Circuit Components:

Arduino Uno

3 LEDs (Yellow, Blue, Green)

3 Resistors (220 ohms)

1 Pushbutton

Jumper wires



3. Pin Mapping

Component         Arduino Pin
Pushbutton         D2
Light LED          D3
AC LED             D4
Fridge LED         D5

4. Command List

These commands are entered through the Serial Monitor. They are case-insensitive and trimmed.

Command                      Action
light on                     Turns the light ON
light off                    Turns the light OFF
ac on                        Turns the AC ON
ac off                       Turns the AC OFF
fridge on                    Turns the fridge ON
fridge off                   Turns the fridge OFF

System Feedback:

When the pushbutton is pressed, the light toggles ON/OFF.

Serial monitor provides feedback for each command (e.g., "AC turned ON").

Commands are case-insensitive, demonstrated by commands like AC ON or Fridge OFF still working.


6. Conclusion and Recommendations

The project successfully simulates a real-time embedded IoT home automation system. 
It fulfills the requirement to control one device through simulated sound and others via typed serial commands.
