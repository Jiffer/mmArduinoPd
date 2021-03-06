//////////////////////////////////////
// PdToArduino2
// for basic communication with Pure Data (Pd)
// NOTE: all the data sent to Pd uses Serial.println()
//
// Jiffer Harriman
// These files are licensed under a Creative Commons Attribution Share-Alike license
// modular-muse.com
//////////////////////////////////////

// for incoming serial data;
// expecting an output # then the value
int incomingByte[2];  

int numOutputs;

int outputPins[] = {3, 5, 6}; // PWM outputs: pins 3, 5 and 6


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  numOutputs = sizeof(outputPins) / sizeof(int);
  
  // initialize output pins
  for (int i = 0; i < numOutputs; i++)
  {
    pinMode(outputPins[i], OUTPUT);
  }

}

// main loop
void loop() {

  /////////////////////
  // read from Pd
  /////////////////////
  // Check if we've collected new data from Pd
  // Here it looks for 2 values, the first is the output port
  // the second is the new value to write to that output
    if (Serial.available() > 1) {
  
      for ( int i = 0; i < 2; i++) {
        incomingByte[i] = Serial.read();
      }
      analogWrite(outputPins[incomingByte[0]], incomingByte[1]);
    }

/*
  // look for 3 bytes of data and write them to the 3 output pins
  if (Serial.available() > 2) {
    for ( int i = 0; i < 3; i++) {
      incomingByte[i] = Serial.read();
      analogWrite(outputPins[i], incomingByte[i]);
    }
  }
*/
  // short break
  delay(10);
}
