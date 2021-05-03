#include <Arduino.h>
#include <boton.h>

boton miBoton1(18);
boton miBoton2(19);

void setup() {
  Serial.begin(9600):
  Serial.print("Iniciando programa");
}

void loop() {
  miBoton1.Refresh();
  if(miBoton1.GetPressType() == miBoton1.Press){
    Serial.print("Boton 1 presionado");
  }
  // put your main code here, to run repeatedly:
}
