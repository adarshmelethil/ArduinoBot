//
#include <Time.h>
#include "Bot.h"
#include "Part.h"
#include "TimePart.h"

Bot bot;
void setup() {
  Serial.begin(9600);
  TimePart tp = TimePart("time");
  tp.Debug();
  bot.AddPart(&tp);
  bot.Debug();
}

unsigned long* t;
void loop() {
  bot.UpdateParts();
  t = (unsigned long*)bot.GetMemVal("time");
  char buffer [64];
  Serial.print("Time: ");
  Serial.println(*t);
  delay(1000);
}
