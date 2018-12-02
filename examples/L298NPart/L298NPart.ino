//
#include <Time.h>
#include "Bot.h"
#include "Part.h"
#include "ConstantPart.h"
#include "L298NPart.h"

Bot bot;
void setup() {
  Serial.begin(9600);
  bot.setDebug(true);
  
  ConstantPart cp_left = ConstantPart("left", 0.2f);
  cp_left.setDebug(true);
  bot.AddPart(&cp_left);
  
  ConstantPart cp_right = ConstantPart("right", 0.3f);
  cp_right.setDebug(true);
  bot.AddPart(&cp_right);
  
  L298NPart hbridge = L298NPart("left", "right", 6, 7, 8, 9, 2, 3);
  hbridge.setDebug(true);
  bot.AddPart(&hbridge);

  bot.UpdateParts();
}

float* left;
float* right;
void loop() {
  bot.UpdateParts();
  left = (float*)bot.getValue((char* )"left");
  right = (float*)bot.getValue((char *)"right");

  Serial.print("left: ");
  if(left == nullptr){
    Serial.print("null");
  }else{
    Serial.print(*left);
  }

  Serial.print(", right: ");
  if(right == nullptr){
    Serial.println("null");
  }else{
    Serial.println(*right);
  }
  
  
  delay(1000);
}
