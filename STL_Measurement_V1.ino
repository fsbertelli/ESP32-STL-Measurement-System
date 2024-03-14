/*
  ESP32 Starlink Measurement System
  Authors: 
    - Felipe Bertelli dos Santos (felipe.bertelli@solinftec.com)
    - Idalberto Cardoso (idalberto.junior@solinftec.com)
  Solinftec Row Crops Development
*/

#include "EmonLib.h" 

#define CURRENT_CAL 22.80
const int pinoSensor = A2;
float ruido = 0.08;

EnergyMonitor emon1;

void setup(){  
  Serial.begin(9600);
  emon1.current(pinoSensor, CURRENT_CAL);
}

void loop(){
  emon1.calcVI(17,100);
  double currentDraw = emon1.Irms; 
  currentDraw = currentDraw-ruido; 
  
  if(currentDraw < 0.05){ 
      currentDraw = 0; 
  }
    Serial.print("$CURRENT,");
    Serial.println(currentDraw); 
    //Serial.println("A"); 
    delay(1000);
}