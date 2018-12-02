
#include "Part.h"

bool Part::sameName(char* a, char* b){
  unsigned int index = 0;
  while (true){
    if(a[index] != b[index]){
      return false;
    }

    if( a[index] == 0x00 && b[index] == 0x00 ){
      return true;
    }
    if( a[index] == 0x00 || b[index] == 0x00 ){
      return false;
    }
    index++;
  }
  return false;
}

void Part::setInputFunc(void* (*fptr)(void*, char*), void* bot){
	this->getValueFromBot = fptr;
	this->bot = bot;
}
void* Part::getInputValue(char* name) {
	return this->getValueFromBot(this->bot, name);
}
