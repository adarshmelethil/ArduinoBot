
#ifndef ConstantPart_h
#define ConstantPart_h 

#include "Bot.h"

class ConstantPart: public Part {
	public:
		ConstantPart(const char* const_out, int val);
		ConstantPart(const char* const_out, float val);
		void Update(); 
		void* getOutputValue( char* name );
	private:
		char* constant_out_name;
		int const_val_int;
		bool usingInt;
		float const_val_float;
};

#endif