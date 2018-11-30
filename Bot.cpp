/*
	Bot.h - Main bot to bring together parts
	- Adarsh Melethil	
*/

#include "Bot.h"
#include <Arduino.h>

// Once all parts are added, the inputs need to be connected to outputs
void Bot::Initialize(){
	if (debug) {
		Serial.println("Initializing");
	}
}
void* Bot::getValue( char* name ){
	void* val;
	if(debug){
		Serial.print("Starting search for '");
		Serial.print(name);
		Serial.println("'");
	}
	for(unsigned int i = 0; i < num_of_parts; i++){
		val = parts[i]->getOutputValue(name);
		if(val != nullptr) {
			return val;
		}
	}
	return nullptr;
}
void* Bot::getValue(const char* name){
	return this->getValue((char *)name);
}
void Bot::UpdateParts(){
	if (iteration_counter == 0) {
		Initialize();
	}
	
	if (debug) {
		Serial.print(iteration_counter);
		Serial.print(": Updating ");
		Serial.print(num_of_parts);
		Serial.println(" Parts");
	}
	
	for(unsigned int i = 0; i < num_of_parts; i++){
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
}
void Bot::setDebug( bool d ){
	debug = d;
}
