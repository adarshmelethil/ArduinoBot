
#ifndef PART_H
#define PART_H 

class Part{
	// Used by Bot instance or by user to debug
	public :
		// Called on each loop, should not contain infinte loops
		virtual void Update() = 0; 
		// Values that this part creates
		virtual void* getOutputValue(char* name);

		void setDebug(bool d);

		// Called by the bot to set itself as the bot
		void setInputFunc(void* (*fptr)(char*)){ this->getInputValue=fptr; }

	// Used by derived classes
	protected:
		void* (*getInputValue)(char* name);
		bool sameName(char* a, char* b);

		bool debug = false;
	private:
		
};

#endif