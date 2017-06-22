
int firstSensor = 0;    // first analog sensor
int secondSensor = 0;   // second analog sensor
int thirdSensor = 0;    // digital sensor
int inByte = 0;         // incoming serial byte
bool start = false;
bool startok = false;

void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  pinMode(2, INPUT);   // digital sensor is on digital pin 2
  establishContact(); 
}

void loop() {
   Serial.print(":test#");
   delay(1000);
}

void establishContact() {
  while (!start && !startok) {
    if(Serial.find(":START#")) start = true;
    if(Serial.find(":START@OK#")) startok = true;
    
    if(start) Serial.write(":START@OK#");

    if(!startok) Serial.write(":START#");

  }
  
}

