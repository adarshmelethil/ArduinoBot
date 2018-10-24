

#include "ConstantPart.h"
#include <Arduino.h>


ConstantPart::ConstantPart(const char* constant_out, int val){
	const_val_int = val;
	constant_out_name = (char *)constant_out;
	char* my_outputs[1] = {constant_out_name};
	const_type = INT;
	ValueType my_output_types[1] = {const_type};
	setOutputs(my_outputs, 1, my_output_types);
}

ConstantPart::ConstantPart(const char* constant_out, float val){
	const_val_float = val;
	const_type = FLOAT;

	constant_out_name = (char *)constant_out;
	char* my_outputs[1] = {constant_out_name};
	ValueType my_output_types[1] = {const_type};
	setOutputs(my_outputs, 1, my_output_types);
}


void ConstantPart::Update(){
	switch(const_type){
		case INT: {
			int* int_val_pt  = (int *)getOutputValue(constant_out_name);
			*int_val_pt = const_val_int;
			if (debug) {
				Serial.print("Updating int constant: ");
				Serial.println(const_val_int);
			}
			break;
		}
		case FLOAT: {
			float* float_val_pt  = (float *)getOutputValue(constant_out_name);
			*float_val_pt = const_val_float;
			if (debug) {
				Serial.print("Updating float constant: ");
				Serial.println(const_val_float);
			}
			break;
		}	
	}
}
