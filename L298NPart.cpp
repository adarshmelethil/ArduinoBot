

#include "L298NPart.h"
#include "Part.h"
#include <Arduino.h>


L298NPart::L298NPart(const char* left, const char* right, int enA, int in1, int in2, int in3, int in4, int enB){
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(enB, OUTPUT);

	left_input = (char *)left;
	right_input = (char *)right;
	char* my_inputs[2] = {left_input, right_input};
	setInputs(my_inputs, 2);
}

void L298NPart::Update(){
	float left_throttle = *(float *)getInputValue(left_input);
	float right_throttle = *(float *)getInputValue(right_input);
	if (debug) {
		Serial.print("Updating L298N: ");
		Serial.print(left_input);
		Serial.print(":");
		Serial.print(left_throttle);
		Serial.print(", ");
		Serial.print(right_input);
		Serial.print(":");
		Serial.println(right_throttle);
	}	
}