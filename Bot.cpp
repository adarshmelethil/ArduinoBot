/*
	Bot.h - Main bot to bring together parts
	- Adarsh Melethil	
*/

#include "Bot.h"
#include <Arduino.h>

// Once all parts are added, the inputs need to be connected to outputs
void Bot::Initialize(){
	if (this->debug) {
		Serial.println("Initializing");
	}
}
void* Bot::getValue(char* name){
	void* val;
	if(this->debug){
		Serial.print("Starting search for '");
		Serial.print(name);
		Serial.println("'");
	}
	for(unsigned int i = 0; i < num_of_parts; i++){
		val = parts[i]->getOutputValue(name);
		if(val != nullptr) {
			if(this->debug){
				Serial.print("Found value for '");
				Serial.print(name);
				Serial.print("': ");
				Serial.print(*(float*)val);
				Serial.println("");
			}
			return val;
		}
	}
	return nullptr;
}

void Bot::getValue(char* name, void** ret_pointer){
	void* val = this->getValue(name);
	
	if(this->debug){
		Serial.print("getValue '");
		Serial.print(name);
		Serial.print("': ");
		if(val == nullptr){
			Serial.print("null");
		}else{
			Serial.print(*(float*)val);
		}
		Serial.println("");	
	}

	*ret_pointer = val;
}

void Bot::UpdateParts(){
	if (iteration_counter == 0) {
		Initialize();
	}
	
	if (this->debug) {
		Serial.print(iteration_counter);
		Serial.print(": Updating ");
		Serial.print(num_of_parts);
		Serial.println(" Parts");
		Serial.flush();
	}
	
	for(unsigned int i = 0; i < num_of_parts; i++){ 
		if(this->debug){
			Serial.print("Updating part #");
			Serial.print(i);
			Serial.println("");
		}
		parts[i]->Update();
	}

	iteration_counter++;
}
void Bot::AddPart(Part* p){
	Part** new_parts = new Part*[++num_of_parts];

	for(unsigned int i = 0; i < num_of_parts-1; i++){
		new_parts[i] = parts[i];
	}
	new_parts[num_of_parts-1] = p;
	if (num_of_parts-1 > 0){
		delete[] parts;
	}
	parts = new_parts;
	new_parts[num_of_parts-1]->setInputFunc(funcForwarder, this);

	if(this->debug){
		Serial.print("Added part - ");
		Serial.print(num_of_parts);
		Serial.println("");
	}
}

void* funcForwarder(void* context, char* name) {
	void* val;
	static_cast<Bot*>(context)->getValue(name, &val);
	
	float* v = (float *)val;
	Serial.print("funcForwarder: ");
	if(v == nullptr){
		Serial.print("null");
	}else{
		Serial.print(*v);
	}
	Serial.println("");

    return val;
}
