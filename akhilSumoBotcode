// BUTTON PIN
#define button_PIN A3

// ULTRASONIC SENSOR PINS - HC-SR04
#define echoUltraSonic1_PIN A1
#define trigUltraSonic1_PIN 4

#define echoUltraSonic2_PIN 11
#define trigUltraSonic2_PIN 12

#define echoUltraSonic3_PIN 8
#define trigUltraSonic3_PIN A0

// IR SENSOR PINS
#define irSensor2_PIN A4
#define irSensor2_PIN2 A5

#define irSensor1_PIN A2

// MOTOR PINS
#define RIGHT_F 7
#define RIGHT_R 6
#define LEFT_F 3
#define LEFT_R 2

#define RIGHT_SPEED 10
#define LEFT_SPEED 9

// MAX_SPEED
#define MAX_SPEED 255 // 255
#define SPIN_SPEED 80

// ARENA FEATURES
#define ARENA_RADIUS 60 // in cm
#define MIN_RADIUS 3 // in cm
#define WHITE 1
#define BLACK 0

long duration; // variable for the duration of sound wave travel
int distance;  // variable for the distance measurement

void setup()
{
  // BUTTON
  pinMode(button_PIN, INPUT);

  // ULTRASONIC SENSOR 1
  pinMode(trigUltraSonic1_PIN, OUTPUT);
  pinMode(echoUltraSonic1_PIN, INPUT);

  // ULTRASONIC SENSOR 2
  pinMode(trigUltraSonic2_PIN, OUTPUT);
  pinMode(echoUltraSonic2_PIN, INPUT);

  // ULTRASONIC SENSOR 3
  pinMode(trigUltraSonic3_PIN, OUTPUT);
  pinMode(echoUltraSonic3_PIN, INPUT);

  // IR SENSOR
  pinMode(irSensor1_PIN, INPUT);

  // IR SENSOR
  pinMode(irSensor2_PIN, INPUT);

  // MOTORS
  pinMode(LEFT_F, OUTPUT);
  pinMode(LEFT_R, OUTPUT);
  pinMode(RIGHT_F, OUTPUT);
  pinMode(RIGHT_R, OUTPUT);
  pinMode(LEFT_SPEED, OUTPUT);
  pinMode(RIGHT_SPEED, OUTPUT);

  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed

  // once button is pressed, wait 5 seconds, then start

  Serial.print("Waiting for button press to START.\n");

  // turn off motors
  driveStop();

  
  bool buttonPressed = false;
  while (buttonPressed == false)
  {
    delay(1);
    if (digitalRead(button_PIN) == 1)
    { // button pin
      Serial.print("BUTTON PRESSED.\n");
      Serial.print("Starting...\n\n");
      buttonPressed = true;
    }
  }
  
  delay(5000);
}
void loop()
{
  //test();
  
  // spin and go
  //spinClockwise();
  //analogWrite(LEFT_SPEED, MAX_SPEED / 3 * 2);
  //analogWrite(RIGHT_SPEED, MAX_SPEED / 3 * 2);

  //driveForwards();

  // while on a loop,
    // if reading from back infrared sensor = edge of area
      // go forwards

    // if reading from front infrared sensor = edge of area
      // go backwards

    // if reading from front sonic sensor < radius of arena
      // go forwards

    // else if reading from left sonic sensor < radius of arena
      // turn left

    // else if reading from right sonic sensor < radius of arena
      // turn right

    // else
      // rotate on the spot?

  //test();

  bool buttonPressed = false;
  while (buttonPressed == false) {

    // if front sensor is on edge
    /*if (getIRSensorReading(irSensor1_PIN, 1) == WHITE) {
      Serial.print("EDGE OF ARENA IN FRONT!!!\n");
      driveBackwards();
      delay(200);
    } else if (getIRSensorReading(irSensor2_PIN, 2) == WHITE) {
      Serial.print("EDGE OF ARENA BEHIND!!!\n");
      driveForwards();
      delay(200);
    } else {*/
      int front = getUltraSonicReading(trigUltraSonic1_PIN, echoUltraSonic1_PIN);
      int left = getUltraSonicReading(trigUltraSonic2_PIN, echoUltraSonic2_PIN);
      int right = getUltraSonicReading(trigUltraSonic3_PIN, echoUltraSonic3_PIN);
      
      if (front <= left && front <= right && front <= ARENA_RADIUS) {
        Serial.print("BOT DETECTED IN FRONT\n");
        driveForwards();
        delay(200);
      } else if (left <= right && left <= ARENA_RADIUS) {
        Serial.print("BOT DETECTED LEFT\n");
        driveLeftSoft();
        delay(200);
      } else if (right <= ARENA_RADIUS) {
        Serial.print("BOT DETECTED RIGHT\n");
        driveRightSoft();  
        delay(200);
      } else {
        Serial.print("SEARCHING FOR BOT\n");
        spinClockwise();
      }
    /*}*/

    
    // should we end?
    if (digitalRead(button_PIN) == 1) { // button pin
      Serial.print("BUTTON PRESSED.\n");
      Serial.print("Stopping...\n\n");
      buttonPressed = true;
    }
    

    delay(300);
  }

  driveStop();

  //setup();
  
  exit(0);
  
  while (true) {
    // in case exit(0) doesn't work, make arduino get stuck in an infinite loop
    delay(1000);
  }
}

void test()
{
  //spinClockwise();
  // TEST CODE
  Serial.print("Distance for SONIC SENSOR 1: ");
  Serial.print(getUltraSonicReading(trigUltraSonic1_PIN, echoUltraSonic1_PIN));
  Serial.println(" cm");
  delay(200);
  Serial.print("Distance for SONIC SENSOR 2: ");
  Serial.print(getUltraSonicReading(trigUltraSonic2_PIN, echoUltraSonic2_PIN));
  Serial.println(" cm");
  delay(200);
  Serial.print("Distance for SONIC SENSOR 3: ");
  Serial.print(getUltraSonicReading(trigUltraSonic3_PIN, echoUltraSonic3_PIN));
  Serial.println(" cm");
  delay(200);
  Serial.print("Colour for IR SENSOR 1: ");
  Serial.print(getIRSensorReading(irSensor1_PIN, 1)); // 1 = white, 0 = black
  Serial.print("\n");
  delay(200);
  Serial.print("Colour for IR SENSOR 2: ");
  Serial.print(getIRSensorReading(irSensor2_PIN, 2));
  Serial.print("\n");
  delay(200);

  /*
  driveForwards();
  delay(5000);
  driveBackwards();
  delay(5000);
  driveStop();
  delay(5000);
  driveForwards();
  driveRightSoft();
  delay(5000);
  driveLeftSoft();
  delay(5000);
  driveStop();
  delay(5000);
  */
}
/*
int decide()
{
  int a = getUltraSonicReading(trigUltraSonic1_PIN, echoUltraSonic1_PIN);
  int b = getIRSensorReading(irSensor1_PIN, 1);
  if (a < ARENA_RADIUS && b == WHITE)
  {
    return 1;
  }
}
*/

int getUltraSonicReading(int trigUltraSonicPin, int echoUltraSonicPin)
{
  digitalWrite(trigUltraSonicPin, LOW); // turn off pin
  delayMicroseconds(2);
  digitalWrite(trigUltraSonicPin, HIGH); // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigUltraSonicPin, LOW);
  duration = pulseIn(echoUltraSonicPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = (duration * 0.0340 / 2) + 2;      // Speed of sound wave divided by 2 (go and back)

  if (distance < MIN_RADIUS) {
    return ARENA_RADIUS + 1000;  
  }
  
  return distance;
}

int getIRSensorReading(int irSensorPin, int pinNumber)
{
  int statusSensor = digitalRead(irSensorPin);
  if (statusSensor == 1) { // 1 = white, 0 = black
    if (pinNumber == 1) {
      return WHITE;
    } else {
      return BLACK;
    }
  }
  else {
    if (pinNumber == 1) {
      return BLACK;
    } else {
      return WHITE;  
    }
  }
}

void driveForwards()
{
  analogWrite(LEFT_SPEED, MAX_SPEED);
  analogWrite(RIGHT_SPEED, MAX_SPEED);

  digitalWrite(LEFT_F, HIGH);
  digitalWrite(LEFT_R, LOW);
  digitalWrite(RIGHT_F, HIGH);
  digitalWrite(RIGHT_R, LOW);
}

void driveBackwards()
{
  analogWrite(LEFT_SPEED, MAX_SPEED);
  analogWrite(RIGHT_SPEED, MAX_SPEED);

  digitalWrite(LEFT_F, LOW);
  digitalWrite(LEFT_R, HIGH);
  digitalWrite(RIGHT_F, LOW);
  digitalWrite(RIGHT_R, HIGH);
}

void driveStop()
{
  analogWrite(LEFT_SPEED, 0);
  analogWrite(RIGHT_SPEED, 0);

  digitalWrite(LEFT_F, HIGH);
  digitalWrite(LEFT_R, LOW);
  digitalWrite(RIGHT_F, HIGH);
  digitalWrite(RIGHT_R, LOW);
}

void driveLeftSoft()
{
  analogWrite(LEFT_SPEED, 0);
  analogWrite(RIGHT_SPEED, MAX_SPEED);

  digitalWrite(LEFT_F, HIGH);
  digitalWrite(LEFT_R, LOW);
  digitalWrite(RIGHT_F, HIGH);
  digitalWrite(RIGHT_R, LOW);
}

void driveRightSoft()
{
  analogWrite(LEFT_SPEED, MAX_SPEED);
  analogWrite(RIGHT_SPEED, 0);

  digitalWrite(LEFT_F, HIGH);
  digitalWrite(LEFT_R, LOW);
  digitalWrite(RIGHT_F, HIGH);
  digitalWrite(RIGHT_R, LOW);
}

void spinClockwise()
{
  analogWrite(LEFT_SPEED, SPIN_SPEED);
  analogWrite(RIGHT_SPEED, SPIN_SPEED);
  
  digitalWrite(LEFT_F, HIGH);
  digitalWrite(LEFT_R, LOW);
  digitalWrite(RIGHT_F, LOW);
  digitalWrite(RIGHT_R, HIGH);
}

void spinCounterClockwise()
{
  analogWrite(LEFT_SPEED, SPIN_SPEED);
  analogWrite(RIGHT_SPEED, SPIN_SPEED);
  
  digitalWrite(LEFT_F, LOW);
  digitalWrite(LEFT_R, HIGH);
  digitalWrite(RIGHT_F, HIGH);
  digitalWrite(RIGHT_R, LOW);
}
