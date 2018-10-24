
#include "Part.h"
#include <Arduino.h>


char* Part::getInputName( int index ) {
	char * ptr = getNameSafe(input_names, num_of_inputs, index);
	if (ptr) return ptr;
	
	return nullptr;
}
// void* Part::getInput(int index) { 
// 	return getValSafe(inputs, num_of_inputs, index);
// }
// void* Part::getInput( char* name ){
// 	return getInput(getIndex(input_names, num_of_inputs, name));
// }
void Part::setInputPtr( int index, void* val ){
	inputs[index] = val;
}
void Part::setInputPtr( char* name, void* val ){
	setInputPtr(getIndex(input_names, num_of_inputs, name), val);
}


char* Part::getOutputName( int index ) { 
	char * ptr = getNameSafe(output_names, num_of_outputs, (int)index);
	if (ptr) {
		return ptr;
	}
	return nullptr;
}

void* Part::getOutputValue(int index) {
	return getValSafe(outputs, num_of_outputs, index);
}
void* Part::getOutputValue(char* name){
	return getOutputValue(getIndex(output_names, num_of_outputs, name));
}

void* Part::getInputValue(int index) {
	return getValSafe(inputs, num_of_inputs, index);
}
void* Part::getInputValue(char* name){
	return getInputValue(getIndex(input_names, num_of_inputs, name));
}

void Part::setOutputPtr( int index, void* val ){
	outputs[index] = val;
}
void Part::setOutputPtr( char* name, void* val ){
	setOutputPtr(getIndex(output_names, num_of_outputs, name), val);
}
ValueType Part::getType( int index ){
	if (index >= num_of_outputs || index < 0){
		return ValueType::INVALID;
	}
	return output_types[index];
}
ValueType Part::getType( char* name ){
	return getType(getIndex(output_names, num_of_outputs, name));
}

// Protected functions for derived classes
void Part::setInputs(char** names, unsigned int arr_size) {
	num_of_inputs = arr_size;
	input_names = new char*[num_of_inputs];
	for(unsigned int i = 0; i < num_of_inputs; i++){
		input_names[i] = (char *)names[i];
		if (debug) {
			Serial.print("Setting input: ");
			Serial.println(input_names[i]);	
		}
	}
	inputs = new void*[num_of_inputs];

	return;
}
void Part::setOutputs(char** names, unsigned int arr_size, ValueType* types) {
	num_of_outputs = arr_size;
	unsigned int num_of_types = sizeof(types)/sizeof(ValueType*);
	if (num_of_outputs != num_of_types) {
		num_of_outputs = 0;
		return;
	}

	// output_names = names;
	output_names = new char*[num_of_outputs];
	output_types = new ValueType[num_of_outputs];
	for (unsigned int i = 0; i < num_of_outputs; i++){
		output_names[i] = (char *)names[i];
		output_types[i] = *types;
		if (debug) {
			Serial.print("Setting output: ");
			Serial.println(output_names[i]);	
		}
	}
	// output_types = types;

	outputs = new void*[num_of_outputs];
	return;
}

// Private Helper functions
int Part::getIndex(char** list, unsigned int list_length, char* name){
	for(int i = 0; i < (int)list_length; i++){
		if (compareName(name, list[i])){
			if (debug){
				Serial.print("Found '");
				Serial.print(name);
				Serial.println("' in mem");
			}
			return i;
		}
	}
	return -1;
}
char* Part::getNameSafe(char** name_list, unsigned int list_length, int index){
	if (index >= (int)list_length || index < 0) {
		return nullptr;
	}
	return name_list[index];
}
void* Part::getValSafe(void** list, unsigned int list_length, int index){
	if (index >= (int)list_length || index < 0) {
		return nullptr;
	}
	return list[index];
}
bool Part::compareName(char* a, char* b){
  unsigned int index = 0;
  while (true){
    if(a[index] != b[index]){
      return false;
    }

    if (a[index] == 0x00){
      return true;
    }
    index++;
  }
}

void Part::Debug(){
	debug = true;
}

