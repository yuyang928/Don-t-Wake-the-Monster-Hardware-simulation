
#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("Don't Wake the Monster!");
}

void loop() {
    delay(1000);
    Serial.println("The monster is sleeping...");
}
