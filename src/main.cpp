#include <Arduino.h>
#include "LED.h"

LED led1(5);
String cmd;

void setup() {
  Serial.begin(115200);
  led1.begin();
  // analogWrite(5, 100);
}

void loop() {
  led1.startLoop();
  if (Serial.available()) {
    cmd = Serial.readStringUntil('\n');
    Serial.printf("cmd=%s", cmd);
    if (cmd == "q") {
      Serial.println("led1 on");
      led1.on();
    }
    else if (cmd == "e") {
      led1.blink(1000, 0.5);
    }
    else if (cmd == "i") {
      led1.blink(500, 0.1);
    }
    else if (cmd == "r") {
      led1.aSet(50);
    }
    else if (cmd == "t") {
      led1.aSet(200);
    }
    else if (cmd == "y") {
      led1.toggle();
    }
    else if (cmd == "u") {
      led1.set(1);
    }
    else {
      led1.off();
    }
  }
}
