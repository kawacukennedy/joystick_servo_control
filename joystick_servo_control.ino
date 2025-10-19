#include <Servo.h>

// Pin configuration
const int servoPin = 9;
const int joystickXPin = A0;
const int joystickYPin = A1;

// Calibration constants
const int CENTER = 512;  // Center position of joystick (0-1023 range)
const int DEAD_ZONE = 10;  // Dead zone around center (±10 units)

// Servo object
Servo servo;

// Function to apply dead zone to joystick value
int applyDeadZone(int value) {
  if (abs(value - CENTER) < DEAD_ZONE) {
    return CENTER;  // Return center if within dead zone
  }
  return value;  // Return original value if outside dead zone
}

// Function to normalize joystick value to 0-1 range
float normalizeValue(int value) {
  return (float)value / 1023.0;
}

// Function to map normalized value (0-1) to servo angle (0-180 degrees)
int mapNormalizedToAngle(float normalized) {
  return (int)(normalized * 180.0);
}

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Attach servo to pin
  servo.attach(servoPin);

  // Set initial servo position to center (90 degrees)
  servo.write(90);
}

void loop() {
  // Read raw analog values from joystick
  int rawX = analogRead(joystickXPin);
  int rawY = analogRead(joystickYPin);

  // Apply calibration (dead zone)
  int calibratedX = applyDeadZone(rawX);
  int calibratedY = applyDeadZone(rawY);

  // Normalize values to 0-1 range
  float normalizedX = normalizeValue(calibratedX);
  float normalizedY = normalizeValue(calibratedY);

  // Map normalized values to servo angles (0-180 degrees)
  int angleX = mapNormalizedToAngle(normalizedX);
  int angleY = mapNormalizedToAngle(normalizedY);

  // Control servo with X-axis (you can change to Y if preferred)
  servo.write(angleX);

  // Serial output for debugging
  Serial.print("Raw X: ");
  Serial.print(rawX);
  Serial.print(", Raw Y: ");
  Serial.print(rawY);
  Serial.print(", Calibrated X: ");
  Serial.print(calibratedX);
  Serial.print(", Calibrated Y: ");
  Serial.print(calibratedY);
  Serial.print(", Normalized X: ");
  Serial.print(normalizedX, 3);
  Serial.print(", Normalized Y: ");
  Serial.print(normalizedY, 3);
  Serial.print(", Angle X: ");
  Serial.print(angleX);
  Serial.print(", Angle Y: ");
  Serial.println(angleY);

  // Small delay to prevent overwhelming serial output
  delay(100);
}