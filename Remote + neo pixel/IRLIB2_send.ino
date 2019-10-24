#include <Wire.h>
#include <IRLibDecodeBase.h>
#include <IRLib_P01_NEC.h>
#include <IRLibCombo.h>

IRdecode myDecoder;
#include <IRLibRecv.h>
IRrecv myReceiver(2);

void setup() {
  Serial.begin(9600);
  myReceiver.enableIRIn(); // Start the receiver
  Wire.begin(8); // join i2c bus (address optional for master)
}

void loop() {
  if (myReceiver.getResults()) {
    myDecoder.decode();
    if (myDecoder.value > 0 && myDecoder.value != 4294967295)
    {
      Wire.beginTransmission(8); // transmit to device #8
      Wire.write(myDecoder.value);              // sends one byte
      Wire.endTransmission();    // stop transmitting
      Serial.println(myDecoder.value);
    }
    myReceiver.enableIRIn();
  }
}
