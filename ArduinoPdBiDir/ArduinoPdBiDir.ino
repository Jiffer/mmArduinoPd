//////////////////////////////////////
// Arduino-Pd-comms
// for basic communication with Pure Data (Pd)
// NOTE: all the data sent to Pd uses Serial.println()
//
// Jiffer Harriman
// These files are licensed under a Creative Commons Attribution Share-Alike license
// modular-muse.com
//////////////////////////////////////

// number of bytes  sent by Pd in a "packet"
#define NUMBYTES 3

int incomingByte[NUMBYTES]; // for incoming serial data

int numDigitals;
int numAnalogs;
int numOutputs;

int digitalPins[] = {2, 4, 7}; // digital inputs: pins 2, 4, 7
int analogPins[] = {A0, A1, A2}; // analog pins A0, A1, A2
int outputPins[] = {3, 5, 6}; // PWM outputs: pins 3, 5 and 6


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  numDigitals = sizeof(digitalPins) / sizeof(int);
  numAnalogs = sizeof(analogPins) / sizeof(int);
  numOutputs = sizeof(outputPins) / sizeof(int);

  for (int i = 0; i < numDigitals; i++)
  {
    pinMode(digitalPins[i], INPUT);
  }

  for (int i = 0; i < numOutputs; i++)
  {
    pinMode(outputPins[i], OUTPUT);
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
  for (int i = 0; i < numAnalogs; i++)
  { // read the value and send it to the serial port
    Serial.println(analogRead(analogPins[i]));
  }
  // a small 'a' indicates end of analog packet
  Serial.println('a');


  /////////////////////
  // read from Pd
  /////////////////////
  // Check if we've collected new data from Pd
  // Here it looks for 2 values, the first is the output port
  // the second is the new value to write to that output
  /*
    if (Serial.available() > 1) {
  
      for ( int i = 0; i < 2; i++) {
        incomingByte[i] = Serial.read();
      }
      analogWrite(outputPins[incomingByte[0]], incomingByte[1]);
    }*/


  // look for 3 bytes of data and write them to the 3 output pins
  if (Serial.available() > NUMBYTES-1) {
    for ( int i = 0; i < NUMBYTES; i++) {
      incomingByte[i] = Serial.read();
      analogWrite(outputPins[i], incomingByte[i]);
    }
  }

  // short break
  delay(10);
}
