
// 
#include "TimePart.h"
#include <Arduino.h>

TimePart::TimePart(const char* time_out){
	time_out_name = (char *)time_out;

	char* my_outputs[1] = {time_out_name};
	ValueType my_output_types[1] = {UNSIGNED_LONG};


	setOutputs(my_outputs, 1, my_output_types);
}

void TimePart::Update(){
	unsigned long *val_pt  = (unsigned long *)getOutputValue(time_out_name);
	unsigned long cur_time = millis();
	
	if (debug){
		char buffer [64];
		sprintf (buffer, "Updating time: %lu -> %lu \n", *val_pt, cur_time);
		Serial.print(buffer);
		Serial.flush();
	}

	*val_pt = cur_time;	
}
