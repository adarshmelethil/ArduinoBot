//
#include <Time.h>
#include "Bot.h"
#include "TimePart.h"

Bot bot;
void setup() {
  Serial.begin(9600);
  TimePart tp = TimePart((char *)"time");
  tp.setDebug(true);
  bot.AddPart(&tp);
  bot.setDebug(true);
}

unsigned long* t;
void loop() {
  bot.UpdateParts();
  t = (unsigned long*)bot.getValue("time");
  Serial.print("Time: ");
  if(t == nullptr){
    Serial.println("null"); 
  }else{
    Serial.println(*t); 
  }
  delay(1000);
}
