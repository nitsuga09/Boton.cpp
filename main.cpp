#include <Arduino.h>
#include <boton.h>

boton miBoton1(18);
boton miBoton2(19);

void setup() {
  Serial.begin(9600);
  Serial.print("Iniciando programa");
}

void loop() {
  miBoton1.Refresh();
  miBoton2.Refresh();
  if(miBoton1.GetPressType() == miBoton1.Press){
    Serial.print("\n Boton 1 presionado");
  }
  if(miBoton2.GetPressType() == miBoton2.Press){
    Serial.print("\n Boton 2 presionado");
  }
  // put your main code here, to run repeatedly:
}
