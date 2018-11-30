 
#include "TimePart.h"
#include <Arduino.h>

TimePart::TimePart(const char* time_name){
	this->time_name = (char *)time_name;
	this->cur_time = millis();
}

void* TimePart::getOutputValue( char* name ){
	if(debug){
		Serial.print("Checking timepart for '");
		Serial.print(name);
		Serial.println("'");
	}
	if(this->sameName(name, this->time_name)){
		if(debug){
			Serial.print("Output match found for '");
			Serial.print(name);
			Serial.print("': ");
			Serial.println(this->cur_time);
		}
		return &this->cur_time;
	}
	return nullptr;
}

void TimePart::Update(){
	this->cur_time = millis();
	
	if (debug){
		char buffer [64];
		sprintf (buffer, "Updated time: %lu \n", this->cur_time);
		Serial.print(buffer);
		Serial.flush();
	}
}
