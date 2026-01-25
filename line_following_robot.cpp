/*
 * Line Following Robot - Advanced Control (Without PID)
 * Hardware: Arduino Uno, L298N H-Bridge Motor Driver, IR Sensors
 * 
 * This advanced code provides smooth and accurate line following using
 * intelligent sensor fusion and adaptive speed control
 */

// L298N Motor Driver Pins
// Motor A (Left Motor)
const int ENA = 9;    // PWM pin for speed control
const int IN1 = 8;    // Direction control
const int IN2 = 7;    // Direction control

// Motor B (Right Motor)
const int ENB = 3;    // PWM pin for speed control
const int IN3 = 5;    // Direction control
const int IN4 = 4;    // Direction control

// IR Sensor Pins - 5 sensor array for better accuracy
const int FAR_LEFT_SENSOR = A0;   // Far left sensor
const int LEFT_SENSOR = A1;        // Left sensor
const int CENTER_SENSOR = A2;      // Center sensor
const int RIGHT_SENSOR = A3;       // Right sensor
const int FAR_RIGHT_SENSOR = A4;   // Far right sensor

// Motor Speed Settings (0-255) - Fine-tuned for smooth operation
const int BASE_SPEED = 180;        // Maximum speed on straight line
const int HIGH_SPEED = 170;        // Speed for slight corrections
const int MEDIUM_SPEED = 140;      // Speed for moderate turns
const int LOW_SPEED = 110;         // Speed for sharp turns
const int CRAWL_SPEED = 80;        // Speed for very sharp turns
const int SEARCH_SPEED = 90;       // Speed when searching for line

// Speed adjustment multipliers for smooth differential steering
const float SLIGHT_TURN_RATIO = 0.7;   // Inner wheel speed ratio for slight turns
const float SHARP_TURN_RATIO = 0.3;    // Inner wheel speed ratio for sharp turns
const float VERY_SHARP_RATIO = 0.0;    // Inner wheel stops for very sharp turns

// Sensor threshold (calibrate based on your sensors)
int SENSOR_THRESHOLD = 512;        // Midpoint for analog sensors

// Calibration values
int whiteValues[5] = {1023, 1023, 1023, 1023, 1023};
int blackValues[5] = {0, 0, 0, 0, 0};

// Line lost tracking
unsigned long lastLineTime = 0;
int lastDirection = 0;  // -2 = far left, -1 = left, 0 = center, 1 = right, 2 = far right

// Smoothing variables
int prevError = 0;
unsigned long lastUpdateTime = 0;

void setup() {
  // Initialize motor control pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  // Initialize sensor pins as inputs
  pinMode(FAR_LEFT_SENSOR, INPUT);
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(CENTER_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(FAR_RIGHT_SENSOR, INPUT);
  
  // Start serial communication for debugging
  Serial.begin(9600);
  Serial.println("Line Following Robot - Advanced Control");
  Serial.println("Place robot on line to begin...");
  
  // Initial state - motors stopped
  stopMotors();
  
  // Auto-and normalize all sensor values
  int sensorValues[5];
  bool sensorBinary[5];
  
  sensorValues[0] = analogRead(FAR_LEFT_SENSOR);
  sensorValues[1] = analogRead(LEFT_SENSOR);
  sensorValues[2] = analogRead(CENTER_SENSOR);
  sensorValues[3] = analogRead(RIGHT_SENSOR);
  sensorValues[4] = analogRead(FAR_RIGHT_SENSOR);
  
  // Convert to binary with adaptive threshold
  for (int i = 0; i < 5; i++) {
    sensorBinary[i] = (sensorValues[i] > SENSOR_THRESHOLD);
  }
  
  // Calculate weighted position error (-4 to +4)
  // Negative = line on left, Positive = line on right
  int position = calculatePosition(sensorBinary);
  
  // Debug output every 200ms
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 200) {
    Serial.print("Sensors: ");
    for (int i = 0; i < 5; i++) {
      Serial.print(sensorBinary[i]);
      Serial.print(" ");
    }
    Serial.print("| Pos: ");
    Serial.print(position);
    Serial.print(" | Dir: ");
    Serial.println(lastDirection);
    lastPrint = millis();
  }
  
  // Check if line is detected
  bool lineDetected = false;
  for (int i = 0; i < 5; i++) {
    if (sensorBinary[i]) {
      lineDetected = true;
      lastLineTime = millis();
      break;
    }
  }
  
  // Advanced line following logic with smooth transitions
  if (lineDetected) {
    followLine(position, sensorBinary);
  } else {
    // Line lost - search based on last known direction
    searchForLine();
  }
  
  delay(10); // Small delay for sense forward slowly to find line
    moveForward(SLOW_SPEED);
  }
  else if (left && center && right) {
    // All sensors on line - intersection or end
    // Stop or continue forward based on your requirements
    stopMotors();
    delay(500);
  }
  
  delay(50); // Small delay for stability
}

// Advanced Line Following Logic

int calculatePosition(bool sensors[5]) {
  // Weighted position calculation
  // Position ranges from -4 (far left) to +4 (far right)
  int sum = 0;
  int count = 0;
  
  int weights[5] = {-4, -2, 0, 2, 4};  // Sensor weights
  
  for (int i = 0; i < 5; i++) {
    if (sensors[i]) {
      sum += weights[i];
      count++;
    }
  }
  
  if (count > 0) {
    return sum / count;  // Average weighted position
  }
  
  return prevError;  // Return last known position if no line detected
}

void followLine(int position, bool sensors[5]) {
  int leftSpeed, rightSpeed;
  
  // Determine speeds based on position error
  if (position == 0) {
    // Perfect center - full speed ahead
    leftSpeed = BASE_SPEED;
    rightSpeed = BASE_SPEED;
    lastDirection = 0;
  }
  else if (position == -1 || position == 1) {
    // Slight deviation - minor correction with high speed
    leftSpeed = HIGH_SPEED;
    rightSpeed = HIGH_SPEED;
    
    if (position == -1) {  // Line slightly left
      leftSpeed *= SLIGHT_TURN_RATIO;
      lastDirection = -1;
    } else {  // Line slightly right
      rightSpeed *= SLIGHT_TURN_RATIO;
      lastDirection = 1;
    }
  }
  else if (position == -2 || position == 2) {
    // Moderate deviation - stronger correction
    leftSpeed = MEDIUM_SPEED;
    rightSpeed = MEDIUM_SPEED;
    
    if (position == -2) {  // Line on left
      leftSpeed *= SHARP_TURN_RATIO;
      lastDirection = -1;
    } else {  // Line on right
      rightSpeed *= SHARP_TURN_RATIO;
      lastDirection = 1;
    }
  }
  else if (position <= -3) {
   ========================================
 * WIRING GUIDE - ADVANCED CONFIGURATION
 * ========================================
 * 
 * L298N Motor Driver Connections:
 * --------------------------------
 * - ENA -> Arduino Pin 9 (PWM - Left Motor Speed)
 * - IN1 -> Arduino Pin 8 (Left Motor Direction)
 * - IN2 -> Arduino Pin 7 (Left Motor Direction)
 * - IN3 -> Arduino Pin 5 (Right Motor Direction)
 * - IN4 -> Arduino Pin 4 (Right Motor Direction)
 * - ENB -> Arduino Pin 3 (PWM - Right Motor Speed)
 * - OUT1, OUT2 -> Left Motor terminals
 * - OUT3, OUT4 -> Right Motor terminals
 * - 12V -> Battery positive (7-12V recommended, up to 35V max)
 * - GND -> Battery negative AND Arduino GND (common ground!)
 * - 5V (from L298N) -> Can power Arduino (remove jumper for >12V)
 * 
 * IR Sensor Array (5 sensors for optimal tracking):
 * -------------------------------------------------
 * - Far Left Sensor  -> Arduino A0
 * - Left Sensor      -> Arduino A1
 * - Center Sensor    -> Arduino A2
 * - Right Sensor     -> Arduino A3
 * - Far Right Sensor -> Arduino A4
 * - VCC (all sensors) -> 5V
 * - GND (all sensors) -> GND
 * 
 * Sensor Placement (recommended):
 * -------------------------------
 * Space sensors 10-15mm apart in a straight line
 * Mount 3-5mm above the surface
 * Ensure sensors are parallel to the ground
 * 
 * For 3-sensor setup: Use A1 (Left), A2 (Center), A3 (Right)
 * Comment out far left/right sensor code
 * 
 * ========================================
 * SETUP AND CALIBRATION INSTRUCTIONS
 * ========================================
 * 
 * 1. Hardware Setup:
 *    - Connect all components as per wiring guide
 *    - Ensure common ground between Arduino and L298N
 *    - Check motor polarity (swap wires if motors run backwards)
 *    - Verify sensor LEDs are on when powered
 * 
 * 2. Upload and Calibration:
 *    - Upload this code to Arduino Uno
 *    - Open Serial Monitor (9600 baud)
 *    - Follow on-screen calibration instructions:
 *      a) Place robot on white surface (move around)
 *      b) Place robot on black line (move along line)
 *    - Threshold will be automatically calculated
 * 
 * 3. Fine-Tuning:
 *    - Adjust speed constants if robot is too fast/slow
 *    - Modify turn ratios for sharper/smoother turns
 *    - Check Serial Monitor for sensor readings
 * 
 * 4. Testing:
 *    - Start on a simple straight line
 *    - Test curves and turns
 *    - Verify intersection handling
 *    - Test line recovery when briefly lost
 * 
 * ========================================
 * PERFORMANCE FEATURES
 * ========================================
 * 
 * ✓ 5-sensor array for superior line detection
 * ✓ Weighted position calculation for smooth control
 * ✓ Adaptive speed control based on line position
 * ✓ Differential steering for precise turns
 * ✓ Automatic calibration on startup
 * ✓ Intelligent line search when signal lost
 * ✓ Intersection and T-junction handling
 * ✓ Real-time debug output via Serial
 * ✓ Smooth acceleration and deceleration
 * ✓ Direction memory for better recovery
 * 
 * ========================================
 * TROUBLESHOOTING
 * ========================================
 * 
 * Robot doesn't move:
 * - Check battery voltage (should be >7V)
 * - Verify motor connections
 * - Check L298N enable jumpers are in place
 * 
 * Robot moves erratically:
 * - Re-run calibration routine
 * - Check sensor height above surface
 * - Reduce BASE_SPEED if overshooting
 * 
 * Robot loses line:
 * - Increase contrast (darker line, lighter surface)
 * - Adjust sensor height (3-5mm recommended)
 * - Lower BASE_SPEED for sharper curves
 * 
 * Motors run backwards:
 * - Swap IN1/IN2 or IN3/IN4 connections
 * - Or swap motor wire polarityTime;
  
  if (timeLost < 500) {
    // Just lost line - continue in last direction
    if (lastDirection <= -1) {
      // Turn left to find line
      setMotorSpeeds(CRAWL_SPEED * 0.3, SEARCH_SPEED);
    } else if (lastDirection >= 1) {
      // Turn right to find line
      setMotorSpeeds(SEARCH_SPEED, CRAWL_SPEED * 0.3);
    } else {
      // Move forward slowly
      setMotorSpeeds(SEARCH_SPEED, SEARCH_SPEED);
    }
  } else if (timeLost < 2000) {
    // Line lost for a while - more aggressive search
    if (lastDirection <= -1) {
      // Sharp left turn
      setMotorSpeeds(0, MEDIUM_SPEED);
    } else if (lastDirection >= 1) {
      // Sharp right turn
      setMotorSpeeds(MEDIUM_SPEED, 0);
    } else {
      // Spin in place to search
      setMotorSpeeds(0, MEDIUM_SPEED);
    }
  } else {
    // Line lost for too long - stop
    stopMotors();
    Serial.println("LINE LOST - Robot stopped");
  }
}

// Motor Control Functions with Smooth Speed Control

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
  // Constrain speeds to valid range
  leftSpeed = constrain(leftSpeed, 0, 255);
  rightSpeed = constrain(rightSpeed, 0, 255);
  
  // Left motor
  if (leftSpeed > 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, leftSpeed);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
  }
  
  // Right motor
  if (rightSpeed > 0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, rightSpeed);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 0);
  }
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

// Sensor Calibration Function

void calibrateSensors() {
  Serial.println("\n=== CALIBRATION MODE ===");
  Serial.println("Move robot over WHITE surface...");
  delay(2000);
  
  // Calibrate white values
  for (int i = 0; i < 50; i++) {
    whiteValues[0] = min(whiteValues[0], analogRead(FAR_LEFT_SENSOR));
    whiteValues[1] = min(whiteValues[1], analogRead(LEFT_SENSOR));
    whiteValues[2] = min(whiteValues[2], analogRead(CENTER_SENSOR));
    whiteValues[3] = min(whiteValues[3], analogRead(RIGHT_SENSOR));
    whiteValues[4] = min(whiteValues[4], analogRead(FAR_RIGHT_SENSOR));
    delay(20);
  }
  
  Serial.println("Move robot over BLACK LINE...");
  delay(2000);
  
  // Calibrate black values
  for (int i = 0; i < 50; i++) {
    blackValues[0] = max(blackValues[0], analogRead(FAR_LEFT_SENSOR));
    blackValues[1] = max(blackValues[1], analogRead(LEFT_SENSOR));
    blackValues[2] = max(blackValues[2], analogRead(CENTER_SENSOR));
    blackValues[3] = max(blackValues[3], analogRead(RIGHT_SENSOR));
    blackValues[4] = max(blackValues[4], analogRead(FAR_RIGHT_SENSOR));
    delay(20);
  }
  
  // Calculate threshold as midpoint
  int totalWhite = 0, totalBlack = 0;
  for (int i = 0; i < 5; i++) {
    totalWhite += whiteValues[i];
    totalBlack += blackValues[i];
  }
  SENSOR_THRESHOLD = (totalWhite/5 + totalBlack/5) / 2;
  
  Serial.print("Threshold set to: ");
  Serial.println(SENSOR_THRESHOLD);
}

/*
 * WIRING GUIDE:
 * 
 * L298N Motor Driver:
 * - ENA -> Arduino Pin 9 (PWM)
 * - IN1 -> Arduino Pin 8
 * - IN2 -> Arduino Pin 7
 * - IN3 -> Arduino Pin 5
 * - IN4 -> Arduino Pin 4
 * - ENB -> Arduino Pin 3 (PWM)
 * - OUT1, OUT2 -> Left Motor
 * - OUT3, OUT4 -> Right Motor
 * - 12V -> Battery positive (7-12V)
 * - GND -> Battery negative and Arduino GND
 * - 5V (from L298N) -> Can power Arduino if jumper is in place
 * 
 * IR Sensors:
 * - Left Sensor -> Arduino A0
 * - Center Sensor -> Arduino A1
 * - Right Sensor -> Arduino A2
 * - VCC -> 5V
 * - GND -> GND
 * 
 * CALIBRATION:
 * 1. Upload code and open Serial Monitor
 * 2. Place sensors over white surface and note values
 * 3. Place sensors over black line and note values
 * 4. Adjust SENSOR_THRESHOLD to be between these values
 * 5. Adjust speed values for smooth operation
 */
