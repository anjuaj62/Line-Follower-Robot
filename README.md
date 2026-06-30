# Line Follower Robot 🤖

A line-following robot built with Arduino Uno and a single IR sensor, using PWM-controlled DC motors to track a black line on a white surface.

> Built as part of my embedded systems training — first hands-on experience with PWM motor control and real-time sensor feedback loops.

---

## Demo

<img width="400" height="533" alt="line-follower-demo" src="https://github.com/user-attachments/assets/f50706b4-ef26-4cc0-bfae-1d358c0a3e71" />


---

## How It Works

The robot uses a single IR sensor to detect contrast between a black line and a white surface. Based on the sensor reading, it steers by independently controlling left and right motor speed via PWM signals.

```
IR detects BLACK (line)  →  Left motor runs   →  Robot steers left
IR detects WHITE (no line) →  Right motor runs  →  Robot steers right
```

This creates a simple bang-bang control loop that keeps the robot centred on the line.

**Why PWM?** Pulse Width Modulation lets us control motor speed by varying the duty cycle — full duty = full speed, 50% duty = half speed. Arduino's `analogWrite()` generates the PWM signal on pins 3, 5, 6, and 9.

---

## Hardware

| Component | Quantity | Purpose |
|---|---|---|
| Arduino Uno | 1 | Microcontroller |
| IR Sensor Module | 1 | Line detection |
| DC Motor | 2 | Locomotion |
| Motor Driver (L298N or similar) | 1 | Motor current amplification |
| Chassis + wheels | 1 set | Physical structure |
| Battery pack | 1 | Power supply |

---

## Pin Configuration

```
Arduino Uno
├── Pin 2   → IR Sensor (Digital Input)
├── Pin 3   → Left Motor  — Forward  (PWM)
├── Pin 5   → Left Motor  — Backward (PWM)
├── Pin 6   → Right Motor — Forward  (PWM)
└── Pin 9   → Right Motor — Backward (PWM)
```

---

Key logic in `line_follower.ino`:

```cpp
int sensorValue = digitalRead(IR_PIN);

if (sensorValue == LOW) {   // Line detected (IR reflects off black)
    moveLeft();
} else {                    // No line
    moveRight();
}
```

Motor control uses `analogWrite()` for PWM-based speed control, keeping motor driver inputs within safe switching limits.

---

## What I Learned

- PWM fundamentals and how `analogWrite()` maps duty cycle to motor speed
- Interfacing digital sensors (IR) with Arduino GPIO
- Basic feedback control — sensor input driving actuator output in a loop
- Importance of power isolation between motor driver and Arduino logic supply

---
## Tools Used

`Arduino IDE` · `Proteus (simulation)` · `C++`

---
