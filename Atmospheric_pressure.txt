#include <SFE_BMP180.h>
#include <Wire.h>
 
SFE_BMP180 pressure;
 
#define ALTITUDE 1655.0 // Replace with your altitude
 
void setup()
{
  Wire.begin(21, 22); // Set the I2C pins for ESP32 if needed (SDA, SCL)
  Serial.begin(9600);
  Serial.println("REBOOT");
 
  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {
    Serial.println("BMP180 init fail\n\n");
    while(1); 
  }
}
 
void loop()
{
  char status;
  double T, P, p0, a;  
  Serial.println();
  Serial.print("Provided Altitude: ");
  Serial.print(ALTITUDE, 0);
  Serial.print(" meters, ");
  Serial.print(ALTITUDE * 3.28084, 0);
  Serial.println(" feet");
 
  status = pressure.startTemperature();
  if (status != 0)
  {
    delay(status);
 
    status = pressure.getTemperature(T);
    if (status != 0)
    {
      Serial.print("Temperature: ");
      Serial.print(T, 2);
      Serial.print(" °C, ");
      Serial.print((9.0/5.0) * T + 32.0, 2);
      Serial.println(" °F");
      
      status = pressure.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = pressure.getPressure(P, T);
        if (status != 0)
        {
          Serial.print("Absolute Pressure: ");
          Serial.print(P, 2);
          Serial.print(" mb, ");
          Serial.print(P * 0.0295333727, 2);
          Serial.println(" inHg");
 
          p0 = pressure.sealevel(P, ALTITUDE); 
          Serial.print("Relative Pressure (Sea Level): ");
          Serial.print(p0, 2);
          Serial.print(" mb, ");
          Serial.print(p0 * 0.0295333727, 2);
          Serial.println(" inHg");
          
          a = pressure.altitude(P, p0);
          Serial.print("Altitude: ");
          Serial.print(a, 0);
          Serial.print(" meters, ");
          Serial.print(a * 3.28084, 0);
          Serial.println(" feet");
        }
        else Serial.println("error retrieving pressure measurement\n");
      }
      else Serial.println("error starting pressure measurement\n");
    }
    else Serial.println("error retrieving temperature measurement\n");
  }
  else Serial.println("error starting temperature measurement\n");
 
  delay(5000);  
}
