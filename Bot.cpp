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
	for(unsigned int part_index = 0; part_index < num_of_parts; part_index++){
		unsigned int num_inputs = parts[part_index]->getNumOfInputs();
		if (debug) {
			Serial.print("Num of inputs: ");
			Serial.println(num_inputs);
		}
		for(unsigned int input_index = 0; input_index < num_inputs; input_index++){
			char* input_name = parts[part_index]->getInputName(input_index);
			if (!input_name) {
				if (debug) {
					Serial.print("Part ");
					Serial.print(input_index);
					Serial.println(" has nullptr input_name.");
				}
				continue;
			}
			void* ptr = GetMemVal(input_name);

			parts[part_index]->setInputPtr(input_index, ptr);
			if (debug) {
				Serial.print("Got mem val for ");
				Serial.println(input_name);
			}
		}
	}
}

void Bot::appendPart(Part* p){
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

int Bot::AddPart(Part* p){
	appendPart(p);

	unsigned int outputs = p->getNumOfOutputs();
	for(int i = 0; i < (int)outputs; i++){
		char* cur_name = p->getOutputName(i);
		void* ptr = GetMemVal(cur_name);
		if(!ptr){
			ptr = appendMemEntry(cur_name, p->getType(i));
		}
		p->setOutputPtr(i, ptr);
	}

	return 0;
}

void* Bot::appendMemEntry(char* name, ValueType type){
	void** new_mem_values = new void*[++num_mem_entries];
	char** new_mem_names = new char*[num_mem_entries];
	for(unsigned int i = 0; i < num_mem_entries-1; i++){
		new_mem_values[i] = mem_values[i];
		new_mem_names[i] = mem_names[i];
	}
	new_mem_names[num_mem_entries-1] = name;
	if (num_mem_entries-1 > 0){
		delete[] mem_names;
	}
	mem_names = new_mem_names;

	void* new_val; 
	switch (type) {
		case BOOLEAN: 
			new_val = new bool();
			break;
		case CHAR:
			new_val = new char();
			break;
		case UNSIGNED_CHAR:
			new_val = new unsigned char();
			break;
		case INT:
			new_val = new int();
			break;
		case UNSIGNED_INT:
			new_val = new unsigned int();
			break;
		case LONG:
			new_val = new long();
			break;
		case UNSIGNED_LONG:
			new_val = new unsigned long();
			break;
		case FLOAT:
			new_val = new float();
			break;
		case DOUBLE:
			new_val = new double();
			break;
		case CHAR_PTR:
			new_val = new char*();
			break;
		default:
			return nullptr;
	}
	new_mem_values[num_mem_entries-1] = new_val;
	if (num_mem_entries-1 > 0){
		delete[] mem_values;
	}
	mem_values = new_mem_values;
	return mem_values[num_mem_entries-1];
}

void* Bot::GetMemVal(char* part_name) {
	int index = -1;
	for(unsigned int i = 0; i < num_mem_entries; i++){
		if (compareName(part_name, mem_names[i])){
			return mem_values[i];
		}
	}
	if (debug) {
		Serial.print("Could not find mem for: ");
		Serial.println(part_name);
	}
	return nullptr;
}
void* Bot::GetMemVal(const char* part_name) {
	return GetMemVal((char *) part_name);
}

// Private
bool Bot::compareName(char* a, char* b){
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

void Bot::Debug(){
	debug = true;
}
