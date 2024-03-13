/*
  ESP32 Starlink Measurement System
  Authors: 
    - Felipe Bertelli dos Santos (felipe.bertelli@solinftec.com)
    - Idalberto Cardoso (idalberto.junior@solinftec.com)
  Solinftec Row Crops Development
*/

const int pinoSensorCorrente = A0;

void setup() {
  Serial.begin(115200);

}

void loop() {

}


void measureAmps(){
  int valorAnalogico = analogRead(pinoSensorCorrente);

  float corrente = (valorAnalogico / 1023.0) * 3300.0;
  corrente = corrente / 185.0; //185mV -> sensibilidade 

  Serial.print("Corrente: ");
  Serial.print(corrente);
  Serial.println(" mA")

  delay(1000);

}