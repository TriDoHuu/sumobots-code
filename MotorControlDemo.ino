// Motor A pins
int RIGHT_SPEED = 9;  // Speed pin, ranges from 0 to 255 (ENA)
int RIGHT_F = 14;     // Pin to move motor forwards (IN1)
int RIGHT_R = 15;     // Pin to move motor backwards (IN2)

// Motor B pins
int LEFT_SPEED = 10;  // Speed pin, ranges from 0 to 255 (ENB)
int LEFT_F = 16;      // Pin to move motor forwards (IN3)
int LEFT_R = 17;      // Pin to move motor backwards (IN4)

int motorSpeed = 0;   // Variable to store motor speed
char input;           // Variable to store user input

void setup() {
  Serial.begin(9600);        // Initialize serial communication at 9600 baud
  Serial.println("Setting pins for motors");

  // Setup all the motor control pins to outputs
  pinMode(RIGHT_SPEED, OUTPUT);
  pinMode(RIGHT_F, OUTPUT);
  pinMode(RIGHT_R, OUTPUT);

  pinMode(LEFT_SPEED, OUTPUT);
  pinMode(LEFT_F, OUTPUT);
  pinMode(LEFT_R, OUTPUT);

  // Initialize motor speed to 0
  analogWrite(RIGHT_SPEED, 0);
  analogWrite(LEFT_SPEED, 0);
}

void loop() {
  if (Serial.available() > 0) {
    input = Serial.read();    // Read the input from serial monitor

    // Set speed based on number input
    if (input >= '1' && input <= '5') {
      motorSpeed = map(input - '0', 1, 5, 51, 255); // Map '1'-'5' to speed values 51-255
      analogWrite(RIGHT_SPEED, motorSpeed);
      analogWrite(LEFT_SPEED, motorSpeed);
      Serial.print("Motor speed set to: ");
      Serial.println(motorSpeed);
    }

    // Set direction based on 'w', 'a', 's', 'd' input
    if (input == 'w') {
      driveForward();
    } else if (input == 's') {
      driveBackward();
    } else if (input == 'a') {
      stopMotors();
    } else if (input == 'd') {
      brakeMotors();
    }
  }
}

// Function to drive motors forward
void driveForward() {
  Serial.println("Driving forwards");
  digitalWrite(RIGHT_F, HIGH);
  digitalWrite(RIGHT_R, LOW);
  digitalWrite(LEFT_F, HIGH);
  digitalWrite(LEFT_R, LOW);
}

// Function to drive motors backward
void driveBackward() {
  Serial.println("Driving backwards");
  digitalWrite(RIGHT_F, LOW);
  digitalWrite(RIGHT_R, HIGH);
  digitalWrite(LEFT_F, LOW);
  digitalWrite(LEFT_R, HIGH);
}

// Function to stop motors
void stopMotors() {
  Serial.println("Motors stopped");
  digitalWrite(RIGHT_F, LOW);
  digitalWrite(RIGHT_R, LOW);
  digitalWrite(LEFT_F, LOW);
  digitalWrite(LEFT_R, LOW);
}

// Function to brake motors
void brakeMotors() {
  Serial.println("Motors braking");
  digitalWrite(RIGHT_F, HIGH);
  digitalWrite(RIGHT_R, HIGH);
  digitalWrite(LEFT_F, HIGH);
  digitalWrite(LEFT_R, HIGH);
}