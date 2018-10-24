

#ifndef Part_h
#define Part_h  

enum ValueType { 
	INVALID,
	BOOLEAN, 
	CHAR, UNSIGNED_CHAR, 
	INT, UNSIGNED_INT, 
	LONG, UNSIGNED_LONG,
	FLOAT, 
	DOUBLE,
	CHAR_PTR
};
class Part{
	// Used by Bot instance or by user to debug
	public :
		// Called on each loop, should not contain infinte loops
		virtual void Update() = 0; 

		unsigned int getNumOfInputs() { return num_of_inputs; }
		char* getInputName( int index );
		void setInputPtr( int index, void* val );
		void setInputPtr( char* name, void* val );

		void* getInputValue( int index );
		void* getInputValue( char* name );

		unsigned int getNumOfOutputs() { return num_of_outputs; }
		char* getOutputName( int index );
		void setOutputPtr( int index, void* val );
		void setOutputPtr( char* name, void* val );
		ValueType getType( int index );
		ValueType getType( char* name );

		void* getOutputValue( int index );
		void* getOutputValue( char* name );
		
		void Debug();
	// Used by derived classes
	protected:
		unsigned int num_of_inputs = 0;
		char** input_names;
		void** inputs;

		unsigned int num_of_outputs = 0;
		char** output_names;
		ValueType* output_types;
		void** outputs;
		
		bool debug = false;

		void setInputs(char** names, unsigned int num_of_inputs);
		void setOutputs(char** names, unsigned int num_of_outputs, ValueType* types);

	private:
		int getIndex(char** list, unsigned int list_length, char* name);
		void* getValSafe(void** list, unsigned int length, int index);
		char* getNameSafe(char** name_list, unsigned int list_length, int index);
		bool compareName(char* a, char* b);
};	

#endif