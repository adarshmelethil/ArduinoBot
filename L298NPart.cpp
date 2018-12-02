

#include "L298NPart.h"
#include "Bot.h"
#include <Arduino.h>


L298NPart::L298NPart(const char* left, const char* right, int enA, int in1, int in2, int enB, int in3, int in4){
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(enB, OUTPUT);

	left_input = (char *)left;
	right_input = (char *)right;
}

void* L298NPart::getOutputValue( char* name ){
	return nullptr;
}

void L298NPart::Update(){
	float* left_throttle = (float*)this->getInputValue(left_input);
	float* right_throttle = (float*)this->getInputValue(right_input);
	if (debug) {
		Serial.print("L298N: ");
		Serial.print(left_input);
		Serial.print(":");
		if(left_throttle == nullptr){
			Serial.print("null");
		}else{
			Serial.print(*left_throttle);
		}
		Serial.print(", ");
		Serial.print(right_input);
		Serial.print(":");
		if(right_throttle == nullptr){
			Serial.println("null");
		}else{
			Serial.println(*right_throttle);
		}
		Serial.flush();
	}
	// TODO: set pwm and pins
}