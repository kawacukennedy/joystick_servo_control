# Joystick-Servo Motor Control System

This Arduino-based project controls a servo motor using a 2-axis joystick module. The system reads analog inputs from the joystick, applies calibration to handle dead zones, normalizes the values, and maps them to servo angles for precise motor control. Real-time serial output provides debugging information.

## Prerequisites
- Arduino IDE (version 1.8.0 or later)
- Basic understanding of Arduino programming and electronics
- Servo library (built-in with Arduino IDE)

## Components Required
- Arduino Uno (or compatible board)
- Standard servo motor (e.g., SG90 or MG996R)
- 2-axis analog joystick module
- Breadboard
- Jumper wires (male-to-male and male-to-female as needed)

## Circuit Diagram

### ASCII Circuit Representation:
```
Arduino Uno                    Breadboard
+------------+                +-----------------+
|            |                |                 |
|  5V  ------>----------------| VCC (Joystick)  |
|  GND ------>----------------| GND (Joystick)  |
|            |                |                 |
|  A0  ------>----------------| VRx (X-axis)    |
|  A1  ------>----------------| VRy (Y-axis)    |
|            |                |                 |
|  Pin 9 ---->----------------| Signal (Servo)  |
|            |                |                 |
|  5V  ------>----------------| VCC (Servo)     |
|  GND ------>----------------| GND (Servo)     |
+------------+                +-----------------+
```

### Detailed Pin Connections:
- **Servo Motor:**
  - Signal wire (usually orange/yellow) → Arduino Digital Pin 9
  - VCC wire (red) → Arduino 5V
  - GND wire (brown/black) → Arduino GND

- **Joystick Module:**
  - VCC pin → Arduino 5V
  - GND pin → Arduino GND
  - VRx (X-axis output) → Arduino Analog Pin A0
  - VRy (Y-axis output) → Arduino Analog Pin A1
  - SW (button switch) → Not connected (optional for future extensions)

### Wiring Instructions:
1. Place the Arduino Uno, servo motor, and joystick module on the breadboard.
2. Connect power: Arduino 5V and GND to the breadboard power rails.
3. Wire the servo: Signal to Pin 9, VCC and GND to power rails.
4. Wire the joystick: VCC and GND to power rails, VRx to A0, VRy to A1.
5. Double-check all connections before powering the Arduino.

## Usage Instructions

### Setup:
1. Download or clone this repository.
2. Open `joystick_servo_control.ino` in Arduino IDE.
3. Select "Arduino Uno" as the board and choose the correct COM port.
4. Upload the sketch to your Arduino Uno.
5. Assemble the circuit as described in the Circuit Diagram section.

### Operation:
1. Power on the Arduino (via USB or external power).
2. Move the joystick along the X-axis to control the servo motor.
3. The servo rotates from 0° (full left) to 180° (full right) based on joystick position.
4. For debugging, open Serial Monitor in Arduino IDE (Tools > Serial Monitor, set baud rate to 9600).
5. Monitor real-time output showing raw, calibrated, normalized values, and servo angles.

### Calibration Notes:
- Dead zone: ±10 units around center (512) to prevent jitter.
- Center position corresponds to 90° servo angle.
- Adjust `CENTER` and `DEAD_ZONE` constants if needed for your joystick.

### Troubleshooting:
- **Servo not moving:** Check wiring, ensure servo is powered, verify pin connections.
- **Erratic behavior:** Confirm joystick is centered at ~512 when at rest.
- **Serial no output:** Check baud rate (9600), COM port selection.
- **Compilation errors:** Ensure Arduino IDE is updated, Servo library is available.
- **Power issues:** Use external power for servo if drawing too much current from Arduino.

## Code Overview

The Arduino sketch consists of the following key components:

- **Constants:** Pin assignments, center value (512), dead zone threshold (10).
- **Functions:**
  - `applyDeadZone(int value)`: Applies dead zone to prevent small movements.
  - `normalizeValue(int value)`: Converts 0-1023 to 0.0-1.0.
  - `mapNormalizedToAngle(float normalized)`: Maps 0-1 to 0-180 degrees.
- **Setup:** Initializes serial (9600 baud), attaches servo, sets initial position.
- **Loop:** Reads joystick, processes values, controls servo, outputs to serial.

The system uses the X-axis for servo control; modify `servo.write(angleX)` to `servo.write(angleY)` for Y-axis control.

## Code Features

- **Analog Input Reading:** Captures joystick X and Y positions.
- **Dead Zone Calibration:** Stabilizes output around center position.
- **Value Normalization:** Scales readings for consistent mapping.
- **Angle Mapping:** Converts normalized values to servo-compatible angles.
- **Real-time Serial Output:** Displays all processing steps for debugging.
- **Modular Functions:** Easy to modify or extend functionality.

## Files
- `joystick_servo_control.ino`: Main Arduino sketch with all functions
- `README.md`: Project documentation and usage guide