/*
 * Ejemplo obtención de posición con gps 
 * Taloselectronics.com
 * Rafael Lozano Rolon
 */
#include <SoftwareSerial.h>//incluimos SoftwareSerial
#include <TinyGPS.h>//incluimos TinyGPS

const byte RX = 2;
const byte TX = 3;

SoftwareSerial serialgps(RX, TX);
TinyGPS gps;//Declaramos el objeto gps

//Declaramos la variables para la obtención de datos
int year;
byte month, day, hour, minute, second, hundredths;
unsigned long chars;
unsigned short sentences, failed_checksum;

void setup()
{
  Serial.begin(9600);//Iniciamos el puerto serie
  serialgps.begin(9600);//Iniciamos el puerto serie del gps
  
}

void loop()
{
  while (serialgps.available())
  {
    int c = serialgps.read();

    if (gps.encode(c))
    {
      float latitude, longitude;
      gps.f_get_position(&latitude, &longitude);
      Serial.print("Latitud/Longitud: ");
      Serial.print(latitude, 5);
      Serial.print(", ");
      Serial.println(longitude, 5);


      gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths);
      Serial.print("Fecha: "); Serial.print(day, DEC); Serial.print("/");
      Serial.print(month, DEC); Serial.print("/"); Serial.print(year);
      Serial.print(" Hora: "); Serial.print(hour, DEC); Serial.print(":");
      Serial.print(minute, DEC); Serial.print(":"); Serial.print(second, DEC);
      Serial.print("."); Serial.println(hundredths, DEC);
      Serial.print("Altitud (metros): ");
      Serial.println(gps.f_altitude());
      Serial.print("Rumbo (grados): "); Serial.println(gps.f_course());
      Serial.print("Velocidad(kmph): ");
      Serial.println(gps.f_speed_kmph());
      Serial.print("Satelites: "); Serial.println(gps.satellites());
      Serial.println();
      gps.stats(&chars, &sentences, &failed_checksum);
    }
  }
}
