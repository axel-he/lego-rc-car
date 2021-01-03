#include <Arduino.h>

#include "rc-handler.h"

namespace rc {

// pinout configuration
static const int GPIO_SPEED_PWM = 5; // 0..1023
static const int GPIO_SPEED_DIR = 0; // 0=forward 1=reverse
static const int GPIO_STEER_PWM = 4; // 0..1023
static const int GPIO_STEER_DIR = 2; // 0=left 1=right

// convert percentage value to absolute PWM
static inline int PWM_ABS(const float& percentage) {
    return abs(static_cast<int>(1023.0f * percentage));
}

RC_Handler& RC_Handler::Instance() {
    static RC_Handler handler;
    return handler;
}

RC_Handler::RC_Handler() {
    reset();
}

void RC_Handler::reset() {
    digitalWrite(GPIO_SPEED_PWM, 0);
    digitalWrite(GPIO_STEER_PWM, 0);
    digitalWrite(GPIO_SPEED_DIR, 1);
    digitalWrite(GPIO_STEER_DIR, 1);
}

void RC_Handler::setup() { 
    pinMode(GPIO_SPEED_PWM, OUTPUT);
    pinMode(GPIO_STEER_PWM, OUTPUT);
    pinMode(GPIO_SPEED_DIR, OUTPUT);
    pinMode(GPIO_STEER_DIR, OUTPUT);

    reset();
}

void RC_Handler::setSteering(float value) {
    digitalWrite(GPIO_STEER_DIR, (value > 0) ? STEERING_DIRECTION::RIGHT : STEERING_DIRECTION::LEFT);
    analogWrite(GPIO_STEER_PWM, PWM_ABS(value));
}

void RC_Handler::setMotorSpeed(float value) {
    digitalWrite(GPIO_SPEED_DIR, (value > 0) ? MOTOR_DIRECTION::FORWARD : MOTOR_DIRECTION::REVERSE);
    analogWrite(GPIO_SPEED_PWM, PWM_ABS(value));
}

};
