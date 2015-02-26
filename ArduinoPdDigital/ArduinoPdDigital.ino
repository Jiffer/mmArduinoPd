//////////////////////////////////////
// ArduinoToPd
// sends digital data to Pd
// NOTE: all the data sent to Pd uses Serial.println()
//
// Jiffer Harriman
// These files are licensed under a Creative Commons Attribution Share-Alike license
// modular-muse.com
//////////////////////////////////////

int numDigitals;
int digitalPins[] = {2, 4, 7}; // digital inputs: pins 2, 4, 7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  numDigitals = sizeof(digitalPins) / sizeof(int);

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

  // short break
  delay(10);
} 
