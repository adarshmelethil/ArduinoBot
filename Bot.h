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
		void AddPart(Part* p);
		
		// Get named varibale from the first part 
		// with an output with said name
		void* getValue(char* name);
		void* getValue(const char* name);

		unsigned int getNumOfParts(){ return num_of_parts; };
		unsigned int getCurIteration(){ return iteration_counter; };

		void setDebug(bool d);


	private:
		unsigned int iteration_counter = 0;

		unsigned int num_of_parts = 0;
		Part** parts;

		bool debug = false;

		void Initialize();
};

#endif 