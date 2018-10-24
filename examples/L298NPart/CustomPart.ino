//
#include <Time.h>
#include "Bot.h"
#include "Part.h"
#include "ConstantPart.h"
#include "L298NPart.h"

Bot bot;
void setup() {
  Serial.begin(9600);
//  bot.Debug();
  
  ConstantPart cp_left = ConstantPart("left", 0.2f);
//  cp_left.Debug();
  bot.AddPart(&cp_left);
  
  ConstantPart cp_right = ConstantPart("right", 0.3f);
//  cp_right.Debug();
  bot.AddPart(&cp_right);
  
  L298NPart hbridge = L298NPart("left", "right", 6, 7, 8, 9, 2, 3);
  hbridge.Debug();
  bot.AddPart(&hbridge);
}

float* left;
float* right;
void loop() {
  bot.UpdateParts();
  left = (float*)bot.GetMemVal("left");
  right = (float*)bot.GetMemVal("right");
  Serial.print("left: ");
  Serial.print(*left);
  Serial.print(", right: ");
  Serial.println(*right);
  delay(1000);
}
