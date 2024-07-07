////////////////////////////////////////////////////////////////////////////////
// This is ___ authored by ___ for sumobots. ...// incomplete
////////////////////////////////////////////////////////////////////////////////



// TODO: Define ultrasonic and infrared sensor pins
// REFER TO ARDUINO BASICS WORKSHOP ON HOW TO CODE SENSORS

// Ultrasonic sensor pins
#define echoPin 1 // CHANGE THIS
#define trigPin 2 // CHANGE THIS

// Infrared sensor pins
#define IRPin 3 // CHANGE THIS



// TODO: Define constants/variables for motors (workshop 4)
/*
*
*
*
*/

// TODO: Define other constants to be used in your sumobot
#define SEARCHING 1
#define ATTACKING 2

// TODO: Initialise global variable to be used


////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Setup Function /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
 
void setup() {
  // TODO: Set pinmodes for every pin defined above - you will have to determine
  // whether the pins will be input or output (or you could look at the workshop
  // slides)


  // TODO: Setup serial communication at 9600 baudrate to allow testing for
  // input/output of the sumobot


  // TODO: Setup starting phase, where sumobot waits 5 seconds until it starts
  // attacking
}

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// Loop Function /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// This function is where all your logic will go. The provided template uses the 
// 'states model' discussed in week 5's build session.
void loop() {

    // If the IR doesnt detect white, the bot wil only run this while loop
    while (checkBorder(IRPin) == 0) {
        
        int currentState = 1; // starting state is set to SEARCHING

        switch (currentState) {
        case SEARCHING:
            // TODO: Add code to search for another bot
            // (e.g., rotate or move in a pattern)
            
            
            // if another bot is found, what should the new currentState be?
            
        case ATTACKING:
            // TODO: Add code to move forward aggressively towards the
            // detected bot
            

            // If the other bot is lost, what should the new currentState be?
            
        default:
            // This is for if the currentState is neither SEARCHING or ATTACHING
            break;
        }

        // Small delay for stability
        delay(100);
    }

    // The bot will run this code if the IR detects white

    // What movement should the bot do in this situation?
    
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////// More Functions //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*  Function: Example Function
/   parameters: x, y
/   returns: distance
/   summary: this is an example function
*/
int exampleFunction(int x, int y) {
    int distance = x + y; // logic inside the function
    return distance; // this returns to where the function was called
}

/*  Function: Example Function 2 (Addition function)
/   parameters: x, y
/   returns: whether the sum of x and y is greater than 10
*/
bool add(int x, int y) {
	int sum = x + y;
	if (sum > 10) {
		return true;
	} else {
		return false;
	}
}

/////////////////////////// Sensor Functions ///////////////////////////////////

/*  Function: Get Distance
/   parameters: trigPin, EchoPin
/   returns: distance
/   summary: uses ultrasonic sensor to get distance of object in front
*/
int getDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration * 0.0340 / 2) + 2;
    return distance;
}

/*  Function: Check Border
/   parameters: IRPin
/   returns: 1 if white is detected, 0 if not detected
/   summary: uses IR sensor to detect edge of arena
*/
int checkBorder(int IRPin) {
	int statusSensor = digitalRead(irSensorPin);
	if (statusSensor == HIGH) {
		return 1;
	} else {
		return 0;
	}
}

// What if you have more than 1 ultrasonic or infrared sensor? Do you need more
// reading functions or can the same ones be used?

////////////////////////////// Move Functions //////////////////////////////////

/*  Function: Drive forward
/   parameters: none
/   returns: none
/   summary: this function drives sumobot forward
*/
void driveForwards()
{
	analogWrite(LEFT_SPEED, MAX_SPEED);
	analogWrite(RIGHT_SPEED, MAX_SPEED);

	digitalWrite(LEFT_F, HIGH);
	digitalWrite(LEFT_R, LOW);
	digitalWrite(RIGHT_F, HIGH);
	digitalWrite(RIGHT_R, LOW);
}

// What other movement functions might we need?
// TODO: Create some of your own movement functions.

// Don't forget to ask questions on the DISCORD if you need any help!