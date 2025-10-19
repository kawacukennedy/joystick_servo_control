# Joystick-Servo Motor Control System

This Arduino-based project controls a servo motor using a 2-axis joystick module. The system reads joystick inputs, normalizes the values, and maps them to servo angles for precise control.

## Components Required
- Arduino Uno
- Servo Motor
- 2-axis Joystick Module
- Breadboard
- Jumper Wires

## Circuit Diagram

### Pin Connections:
- **Servo Motor:**
  - Signal (Orange/Yellow wire) → Arduino Pin 9
  - VCC (Red wire) → Arduino 5V
  - GND (Brown/Black wire) → Arduino GND

- **Joystick Module:**
  - VCC → Arduino 5V
  - GND → Arduino GND
  - X-axis (VRx) → Arduino Analog Pin A0
  - Y-axis (VRy) → Arduino Analog Pin A1
  - SW (Switch) → Not used in this project

### Wiring Instructions:
1. Connect the servo motor to the breadboard.
2. Wire the servo signal pin to Arduino digital pin 9.
3. Connect servo VCC to Arduino 5V and GND to Arduino GND.
4. Place the joystick module on the breadboard.
5. Connect joystick VCC to Arduino 5V and GND to Arduino GND.
6. Wire joystick X-axis to Arduino A0 and Y-axis to A1.
7. Ensure all connections are secure before powering the Arduino.

## Usage Instructions

1. **Setup:**
   - Upload the `joystick_servo_control.ino` sketch to your Arduino Uno using the Arduino IDE.
   - Ensure all components are connected as per the circuit diagram.

2. **Operation:**
   - Power on the Arduino.
   - Move the joystick along the X-axis to control the servo motor position.
   - The servo will rotate from 0° to 180° based on joystick position.
   - Open the Serial Monitor in Arduino IDE (9600 baud) to view real-time data:
     - Raw joystick values (0-1023)
     - Calibrated values (after dead zone application)
     - Normalized values (0.000-1.000)
     - Mapped servo angles (0-180°)

3. **Calibration:**
   - The system includes a dead zone around the joystick center (approximately ±10 units around 512).
   - This prevents jittery movement when the joystick is at rest.

4. **Troubleshooting:**
   - If the servo doesn't respond, check wiring connections.
   - Verify that the Servo library is installed in Arduino IDE.
   - Ensure the joystick is properly centered when at rest.

## Code Features

- **Normalization:** Converts analog readings (0-1023) to normalized values (0-1).
- **Mapping:** Maps normalized values to servo angles (0-180°).
- **Calibration:** Handles joystick dead zones for stable operation.
- **Serial Monitoring:** Provides debugging information via serial output.

## Files
- `joystick_servo_control.ino`: Main Arduino sketch
- `calibration.h`: Dead zone calibration functions
- `normalization.h`: Value normalization and mapping functions
- `README.md`: This documentation file