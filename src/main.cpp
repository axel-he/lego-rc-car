#include "rc-handler.h"
#include <Arduino.h>

// Status LED
static const int STATUS_LED_PIN = 16;
static inline void StatusBlink() {
    digitalWrite(STATUS_LED_PIN, !digitalRead(STATUS_LED_PIN));
}

// RC control object
rc::RC_Handler& rcHandler = rc::RC_Handler::Instance();

void setup() {
    Serial.begin(9600);
    Serial.println("");

    // GPIO pinout setup
    pinMode(STATUS_LED_PIN, OUTPUT);

    // RC car setup
    rcHandler.setup();
}

void loop() {
    StatusBlink();
    
    char c = static_cast<char>(Serial.read());

    // Example Serial control for WASD + SPACE
    if(c) {
        if(c == ' ') { rcHandler.stop(); rcHandler.setSteering(); }
        else if(c == 'w')   rcHandler.forward();
        else if(c == 's')   rcHandler.reverse();
        else if(c == 'a')   rcHandler.left();
        else if(c == 'd')   rcHandler.right();
    }

    delay(10);
}
