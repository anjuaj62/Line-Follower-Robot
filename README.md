# Line Follower Robot 🤖

A simple line following robot built using Arduino Uno and IR sensor,
controlled via PWM signals.

## Components Used
- Arduino Uno
- IR Sensor
- DC Motors (x2)
- Motor Driver

## How It Works
The IR sensor reads the surface below the robot.
- If it detects the line (black) → left motor runs
- If it doesn't detect the line → right motor runs
This keeps the robot following the line continuously.

## Pin Configuration

**Motors**
- Pin 3 → Left Motor (Forward)
- Pin 5 → Left Motor (Backward)
- Pin 6 → Right Motor (Forward)
- Pin 9 → Right Motor (Backward)

**Sensor**
- Pin 2 → IR Sensor (Input)
![Demo](images/demo.gif)
