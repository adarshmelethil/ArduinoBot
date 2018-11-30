
#ifndef TimePart_H
#define TimePart_H

#include "Bot.h"

class TimePart: public Part {
	public:
		TimePart(const char* time_name);
		void Update(); 
		void* getOutputValue( char* name );
	private:
		char* time_name;
		unsigned long cur_time;
};

#endif