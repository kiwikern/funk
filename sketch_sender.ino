#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
char input;

void setup() {
  Serial.begin(115200);  
  mySwitch.enableTransmit(4);  // Der Sender wird an Pin 10 angeschlossen
}
void loop() {
  if(Serial.available()){
        input = Serial.read();
        switch(input) {
          case 'a': mySwitch.send(1066321, 24); break;
          case 'b': mySwitch.send(1066324, 24); break;
          case 'c': mySwitch.send(1069393, 24); break;
          case 'd': mySwitch.send(1069396, 24); break;
          case 'e': mySwitch.send(1070161, 24); break;
          case 'f': mySwitch.send(1070164, 24); break;
          case 'g': mySwitch.send(1070353, 24); break;
          case 'h': mySwitch.send(1070356, 24); break;
          default: Serial.println(input); break;
        }
    }
}  
