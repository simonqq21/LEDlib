#include <Arduino.h>
#include "LED.h"

LED led1(18);
String cmd;
bool loopseq[100];

void setup() {
  Serial.begin(115200);
  led1.begin();
  // analogWrite(5, 100);
}

void f1(int n) {
  led1.setLoopUnitDuration(100);
  // 1,0,1,0,1,0,0,0,0,0,0,0
  int i=0;
  for (int j=0;j<3;j++) {
    if (j<n) loopseq[i] = 1;
    else loopseq[i] = 0; 
    i++;
    for (int k=0;k<3;k++)
      loopseq[i] = 0;
    i++;
  }
  for (int j=0;j<40;j++) { 
    loopseq[i] = 0;
    i++;
  }
  led1.setLoopSequence(loopseq, i);
  led1.startLoop();
}

void loop() {
  led1.loop();
  if (Serial.available()) {
    cmd = Serial.readStringUntil('\n');
    Serial.printf("cmd=%s", cmd);
    if (cmd == "q") {
      Serial.println("led1 on");
      led1.on();
    }
    else if (cmd == "e") {
      led1.startTimer(1000, false);
      led1.blink(1000, 0.5);
    }
    else if (cmd == "i") {
      // test the on timer
      led1.startTimer(3000, true);
      led1.blink(100, 0.5);
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
    else if (cmd == "a") {
      f1(1);
    }
    else if (cmd == "s") {
      f1(2);
    }
    else if (cmd == "d") {
      f1(3);
    }
    else {
      led1.off();
    }
  }
}
