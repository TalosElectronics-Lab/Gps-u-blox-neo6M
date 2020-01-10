/*
   Ejemplo para obtener lectura en crudo u-blox NEO-6M
   protocolo NMEA
*/
#include <SoftwareSerial.h>

const byte RX = 2;
const byte TX = 3;

SoftwareSerial gps(RX, TX);

void setup()
{
  Serial.begin(9600);
  gps.begin(9600);
}

void loop()
{
  if (gps.available())
  {
    
    char data;
    data = gps.read();
    Serial.print(data);
    
  }

}
