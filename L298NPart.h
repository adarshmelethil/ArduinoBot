

#ifndef L298NPart_h
#define L298NPart_h

#include "Part.h"

class L298NPart: public Part {
	public:
		L298NPart(const char* left, const char* right, int enA, int in1, int in2, int in3, int in4, int enB);

		void Update();

	private: 
		// range from -1 to 1
		char* left_input;
		char* right_input;

};

#endif