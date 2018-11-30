
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

void Part::setDebug(bool d){
  debug = d;
}