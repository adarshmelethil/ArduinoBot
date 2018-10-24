

#ifndef TimePart_H
#define TimePart_H

#include "Part.h"

class TimePart: public Part {
	public:
		TimePart(const char* time_out);
		void Update(); 
	private:
		char* time_out_name;
};

#endif