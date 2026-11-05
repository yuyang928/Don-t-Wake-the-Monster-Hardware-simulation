#include <Arduino.h>

const int TRIG_PIN = 5; // GPIO pin for the trigger
const int ECHO_PIN = 18; // GPIO pin for the echo

void Ultrasonic_init();
double Ultrasonic_get_distance();
double player_velocity();

void Ultrasonic_init() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

double Ultrasonic_get_distance() {
    // Send a 10 microsecond pulse to trigger the ultrasonic sensor
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Read the echo pin and calculate the distance
    unsigned long duration = pulseIn(ECHO_PIN, HIGH);
    if (duration == 0) {
        // No echo received, return a large distance
        return -1.0; // Indicate an error or out of range
    }
    double distance = duration * 0.034 / 2; // Convert to centimeters

    return distance;
}

double player_velocity(){
    double distance1{-1};
    while (distance1 < 0) {
        distance1 = Ultrasonic_get_distance();
    }
    unsigned long start_time = millis();
    delay(100); // Wait for 100 milliseconds
    double distance2{-1};
    while (distance2 < 0) {
        distance2 = Ultrasonic_get_distance();
    }
    unsigned long end_time = millis();
    return (distance1 - distance2) / ((end_time - start_time) / 1000.0); // Velocity in cm/s
}//problem with this func is that it will wait 100 milliseconds which prevents esp32 from doing other tasks. 
