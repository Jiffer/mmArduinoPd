//////////////////////////////////////
// ArduinoToPd
// sends digital data to Pd
// NOTE: all the data sent to Pd uses Serial.println()
//
// Jiffer Harriman
// These files are licensed under a Creative Commons Attribution Share-Alike license
// modular-muse.com
//////////////////////////////////////

// variables to capture how many pins of each are being used
int numDigitals;
int numAnalogs;

int digitalPins[] = {2, 4, 7}; // digital inputs: pins 2, 4, 7
int analogPins[] = {A0, A1, A2}; // analog pins A0, A1, A2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  // figure out how many pins
  numDigitals = sizeof(digitalPins) / sizeof(int);
  numAnalogs = sizeof(analogPins) / sizeof(int);
  
  // initialize digital input pins
  for (int i = 0; i < numDigitals; i++)
  {
    pinMode(digitalPins[i], INPUT);
  }

}

// main loop
void loop() {
  /////////////////////
  // Send digital data
  /////////////////////
  // send a 'D' to indicate digital data packet start
  Serial.println('D');

  // loop through all the digital pins.
  for (int i = 0; i < numDigitals; i++)
  { // read the value and send it to the serial port
    Serial.println(digitalRead(digitalPins[i]));
  }
  // a small 'd' indicates end of digital packet
  Serial.println('d');
  
  /////////////////////
  // Send analog data
  /////////////////////
  // send a 'A' to indicate analog data packet start
  Serial.println('A');
  // loop through all the analog pins.
  for (int i = 0; i < numDigitals; i++)
  { // read the value and send it to the serial port
    Serial.println(analogRead(analogPins[i]));
  }
  // a small 'a' indicates end of analog packet
  Serial.println('a');

  // short break
  delay(10);
} 
