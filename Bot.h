/*
	Bot.h - Main bot to bring together parts
	- Adarsh Melethil	
*/

#ifndef Bot_h
#define Bot_h 

#include "Part.h"

class Bot
{
	public:
		void UpdateParts();
		int AddPart(Part* p);

		void* GetMemVal(char* part_name);
		void* GetMemVal(const char* part_name);

		unsigned int getNumOfParts(){ return num_of_parts; };
		unsigned int getCurIteration(){ return iteration_counter; };

		void Debug();

	private:
		unsigned int iteration_counter = 0;

		unsigned int num_of_parts = 0;
		Part** parts;

		unsigned int num_mem_entries;
		char** mem_names;
		void** mem_values;

		bool debug = false;

		bool compareName(char* a, char* b);
		void Initialize();
		void* appendMemEntry(char* name, ValueType type);
		void appendPart(Part* p);
};

#endif 