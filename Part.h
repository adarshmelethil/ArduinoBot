
#ifndef PART_H
#define PART_H 

class Part{
	// Used by Bot instance or by user to debug
	public :
		// Called on each loop, should not contain infinte loops
		virtual void Update() = 0; 
		// Values that this part creates
		virtual void* getOutputValue(char* name);

		void setDebug(bool d){ this->debug=d; }

		// Called by the bot to set itself as the bot
		void setInputFunc(void* (*fptr)(void*, char*), void* bot);

	// Used by derived classes
	protected:
		void* (*getValueFromBot) (void* ctx, char* name);
		void* getInputValue(char* name);
		bool sameName(char* a, char* b);

		void* bot;
		bool debug = false;
	private:
		
};

#endif