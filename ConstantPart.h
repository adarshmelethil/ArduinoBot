
#ifndef ConstantPart_h
#define ConstantPart_h 

#include "Part.h"

class ConstantPart: public Part {
	public:
		ConstantPart(const char* const_out, int val);
		ConstantPart(const char* const_out, float val);
		void Update(); 
	private:
		char* constant_out_name;
		int const_val_int;
		ValueType const_type; 
		float const_val_float;
};

#endif