//Code authored by:


int ledPin = 13;                // choose the pin for the LED
int inputPin = 8;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(9600);
}

/*
for every 100 inputs from the sensor, if a certain number of "motion detected" occurs, output "detected" signal
*/
int count = 0;  //count how many inputs have been received from sensor
int detected = 0;  //count how many motions have been detected out of number of inputs
void loop(){
  delay(30);  //give 30ms delay between each input from sensor

  val = digitalRead(inputPin);  // read input value
  
  if(count <= 100) {  //only execute once every 100 counts
    count++;
    if(val == HIGH) {  //check if motion detected
      detected++;
    }
  } else {
    count = 0;  //reset count
    if(detected >= 10) {  //check out of 100 times, if more than 10 motions detected, output on (calibration)
      digitalWrite(ledPin, HIGH);
      Serial.println("Motion detected!");
      delay(3000);
    } else {
      digitalWrite(ledPin, LOW);
      Serial.println("No Motion detected");
      count = 1400;  //set delay to 3 seconds if no motion is detected
    }
    detected = 0;  //reset detected times
  }

  
  // if (val == HIGH)	// check if the input is HIGH
  // {            
  //   digitalWrite(ledPin, HIGH);  // turn LED ON
	
  // //   if (pirState == LOW) 
	// // {
  //     Serial.println("Motion detected!");	// print on output change
  //   //   pirState = HIGH;
  //   // }
  // } 
  // else 
  // {
  //   digitalWrite(ledPin, LOW); // turn LED OFF
	
  // //   if (pirState == HIGH)
	// // {
  //     Serial.println("Motion ended!");	// print on output change
  //   //   pirState = LOW;
  //   // }
  // }
}









/* Old not functioning code 
bool Human_detected = 0;
int IR_State = LOW;

void setup() {
  // put your setup code here, to run once:

 //IR Sensor (on pin D2) is an input
 pinMode(D2, INPUT);    
 //pinMode(D13, OUTPUT);     //LED Test
 Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 Human_detected = digitalRead(D2);

  if (Human_detected){
    Serial.println("Human Detected");
    //digitalWrite(D13, LOW);

  } else {
    Serial.println("Human Not Detected");
    //digitalWrite(D13, LOW);
  }
  

}
*/
