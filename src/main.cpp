
#include <Arduino.h>
//define variables 
class Monster{
    public:
        bool AWAKE{false};
        void wakeUP() {
            AWAKE = true;
        }
        void sleep(){
            AWAKE = false;
        }
        bool isAwake() {
            return AWAKE;
        }
};
Monster monster;
const int SOUND=0; //will modify this to the correct pin for sound sensor
const int MOVE=0;
const int RLED=0; //will modify this to the correct pin for red LED
const int START=0; //will modify this to the correct pin for start button
unsigned long start_time {0};
bool game_started{false};
const int tolerable_sound{100}; //define the tolerable sound level
const int tolerable_movement{100}; //define the tolerable movement level
const unsigned long sleep_delay{10000}; //define the sleep delay in milliseconds

void setup() {
    Serial.begin(115200);
    Serial.println("Don't Wake the Monster!");
    pinMode(START, INPUT);
    pinMode(SOUND, INPUT);
    pinMode(MOVE, INPUT);
    pinMode(RLED, OUTPUT);
}

void loop() {
    delay(1000);
    game_started = digitalRead(START);
    if (game_started) {
        start_time = millis();

        if (monster.isAwake()) {
//think about how to guard the treasure
            Serial.println("The monster is awake!");
            digitalWrite(RLED, HIGH); //turn on red LED when monster is awake
            if (analogRead(SOUND)<tolerable_sound && analogRead(MOVE)<tolerable_movement){
//think about how to wait 10 seconds before putting the monster to sleep.
                delay(sleep_delay);// this does not check if during this time the sound or movement exceeds the tolerable levels
                monster.sleep();
            }

        } else {
            if (analogRead(SOUND)>tolerable_sound ||analogRead(MOVE)>tolerable_movement){
                monster.wakeUP();
            }
            Serial.println("The monster is sleeping...");
        }
    }
    
// think about how to show the time elapsed since the game started

}
