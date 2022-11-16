void setup() {
  // put your setup code here, to run once:

 pinMode(D2, INPUT);       //IR Sensor
 pinMode(D13, OUTPUT);     //LED Test
 Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor_detection = digitalRead(D2);

  if (sensor_detection == HIGH){
    Serial.println("Human Detected");
    digitalWrite(D13, HIGH);
    delay(3000);

  } else {
    Serial.println("Human Not Detected");
    digitalWrite(D13, LOW);
    delay(3000);
  }
}
