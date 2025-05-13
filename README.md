<img src="assets/peter-tingle.gif" alt="Peter Tingle" width="100%" height="auto" />

# MCU: Spider-Man Electronic Faceshell

---
---

# Introduction

This project brings to life the iconic MCU Spider-Man moving lenses faceshell using Arduino-based electronics and custom mechanical components. The faceshell features independently articulating lenses that react to facial movements, mimicking the expressive eyes from Marvel's Spider-Man suits. All shell components, lenses, gears, and mechanical rods were custom 3D printed, with white perforated vinyl used for the eye material to complete the authentic look.

---
---

# The Electronics

#### Components Used
- Arduino Nano microcontroller
- 2× MG90S servo motors
- 2× IR sensors (HW-201)
- 2× IR diodes (Tcrt5000L)
- 2× Toggle switches
- 4× AAA batteries (2× battery cases)
- 10K resistor
- Connecting wires

## a. System Operation

> **DETECTION**  
  - IR proximity sensors placed beneath each cheek detect facial movement
  - When a cheek moves, the corresponding sensor triggers the lens mechanism

> **CONTROL**  
  - Toggle switch #1: Master power ON/OFF for the entire system
  - Toggle switch #2: Controls operation mode (independent vs. synchronised lenses)
    - When ON: Both lenses move together in response to either sensor
    - When OFF: Each lens operates independently based on its own sensor

> **ACTUATION**  
  - Servo motors drive mechanical linkages to open/close each lens smoothly
  - The system creates a 94° servo rotation to achieve full lens articulation
  - All movement timing and responsiveness is configurable in the code

## b. Power & Enclosure

- The entire system is powered by 2 battery packs (4× AAA batteries total)
- All electronic components are fully enclosed within the faceshell
- No external wires or components visible when worn
- Interior padding and component isolation ensures safe operation and comfort

---
---

# Hardware Design

#### Mechanical Components

  - Custom-designed servo mounts precisely positioned within the shell
  - Mechanical linkage system with push/pull rods connecting servos to lenses
  - Gear mechanisms for smooth lens articulation
  - Internal cable management system to maintain clean aesthetics
  - White perforated vinyl for the eye lenses providing visibility while maintaining the iconic look

All mechanical components were 3D printed to fit within the confined space of the faceshell while allowing for smooth operation and easy maintenance. The IR sensors were strategically placed to detect cheek movements without impeding comfort.

---
---

# The Arduino Code

The Arduino sketch controls the system, processing sensor input and controlling servo output. Key features include:

```cpp
// Configuration parameters (user-adjustable)
const int switch_pin = 4;    // Toggle switch for mode selection
const int sensor1_pin = 2;   // IR sensor #1 input
const int sensor2_pin = 3;   // IR sensor #2 input
const int servo1_pin = 8;    // Servo #1 output
const int servo2_pin = 9;    // Servo #2 output
const int servo_angle = 94;  // Angle of servo rotation
const int rotate_time = 140; // Timing for servo rotation
```

The code handles both operating modes:
1. **Independent mode**: Each lens responds to its corresponding sensor
2. **Synchronised mode**: Both lenses respond together to either sensor

The system uses state tracking to ensure smooth transitions and prevent rapid lens oscillation:
- Servos only attach when movement is needed and detach afterwards to conserve power
- Built-in debounce logic ensures reliable sensor readings
- Servo direction is tracked and alternated with each activation

---
---

# Project Build Process

### Tools & Skills Employed
- 3D modeling and printing
- Basic soldering
- Arduino programming
- Mechanical design

### Materials Used
- Arduino Nano
- 2× MG90S micro servo motors
- 2× IR sensors (HW-201)
- 2× IR diodes (Tcrt5000L)
- 10K resistor
- 2× Toggle switches (SS12D00G3)
- 2× AAA battery holders
- 4× AAA batteries (1100mAh rechargeable batteries)
- Connecting wires
- 3D printer filament
- White perforated vinyl sheet for eyes

### Build Process
1. Modelled (in Blender) and 3D printed all mechanical components (faceshell, lenses, gears and rods)
2. Installed servos in their designated mounts
3. Connected linkage system to lenses
4. Wired all electronics according to the pin configuration in the code
5. Applied white perforated vinyl to the eye lenses (any clear plastic can be used)
6. Uploaded the Arduino sketch
7. Tested operation and adjusted sensor sensitivity
8. Installed all components in the faceshell
9. Secured battery packs and switches

The only thing left to do is install fabric mask between the faceshell and the lenses!

---
---

# Final Product

<img src="assets/video.gif" alt="Working Demonstration" width="100%" height="auto" /> 