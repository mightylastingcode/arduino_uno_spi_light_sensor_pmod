

/************************************************************************
*
* Test of Pmod ALS
*
*************************************************************************
* Description: Pmod_ALS
* The value of the amount of light is displayed on the serial monitor.
* (The sensor is saturated to a value of about 125)
*
*
* Material
* 1. Arduino Uno
* 2. Pmod ALS module
*
************************************************************************/


#define CS 33 // Assignment of the CS pin
//#define CS 10 // Assignment of the CS pin

/*
 * CS D10
 * NC D11
 * SDO D12
 * SCK D13
 * GND GND
 * VCC 3.3
 * 
 */

#include <SPI.h> // call library
int i;
int recu[2]; // Storage of module data
int lumiere;

void setup()
{
 Serial.begin(9600); // initialization of serial communication
 SPI.begin(); // initialization of SPI port
 SPI.setDataMode(SPI_MODE0); // configuration of SPI communication in mode 0
 SPI.setClockDivider(SPI_CLOCK_DIV16); // configuration of clock at 1MHz
 pinMode(CS, OUTPUT);
}

void loop()
{
 digitalWrite(CS, LOW); // activation of CS line
 for (i=0;i<2;i=i+1)
    {
    recu[i] = SPI.transfer(0); // Acquisition of the 2 bytes of data
    }
 digitalWrite(CS, HIGH); // deactivation of CS line
 for (i=0;i<2;i=i+1) // Send in serial monitor
    {
    Serial.print("i");
    Serial.print(i);
    Serial.print("=");
    Serial.println(recu[i]);
    }
 lumiere=(recu[0]<<3)|(recu[1]>>4); // Reconstitution of the 8-bit light variable
 Serial.print("Lumiere=");
 Serial.println(lumiere);
 delay(1000);
}
