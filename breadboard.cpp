# include <Arduino.h>

int GREEN_LED = 26;
int RED_LED = 27;

int START= 19;
int RESET= 23;

void LED_init();
void monster_asleep();
void monster_awake();
void Button_init();
bool START_pressed();
bool RESET_pressed();

void LED_init(){
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT); 

    monster_asleep();
}

void monster_asleep(){
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
}
void monster_awake(){
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
}

void Button_init(){
    pinMode(START, INPUT_PULLUP);
    pinMode(RESET, INPUT_PULLUP);
}

bool START_pressed(){
    return digitalRead(START) == LOW;
}
bool RESET_pressed(){
    return digitalRead(RESET) == LOW;
}