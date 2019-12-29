#include <CapacitiveSensor.h>   // activating the capacitive sensor library
#include "pitches.h"            // activating the pitch library

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */

//THE CAPACITIVE SENSOR CODE

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);          // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
//CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
//CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

//INPUT OUTPUT PRE-DEFINE CODE
#define speaker 11

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    /* 
    long total2 =  cs_4_6.capacitiveSensor(30);
    long total3 =  cs_4_8.capacitiveSensor(30);
    */
    

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.println(total1);                  // print sensor output 1 . // I have added the ln, should be removed if there is more pins
    /*
    Serial.print("\t");
    Serial.print(total2);                  // print sensor output 2
    Serial.print("\t");
    Serial.println(total3);                // print sensor output 3
    */

    // When hand is touched the sensor, the speaker will produce a tone.
  // I set a threshold for it, so that the sensor won't be too sensitive.
    if (total1 < 5) tone(speaker,523);
     // When hand didn't touch on it, no tone is produced.
  if (total1 > 5){
    noTone(speaker);}
   /*
    if (total2 > 150) tone(speaker,587);
    if (total3 > 1000) tone(speaker,659);
    if (total4 > 1000) tone(speaker,698);
    if (total5 > 150) tone(speaker,784);
    if (total6 > 150) tone(speaker,880);
    if (total7 > 150) tone(speaker,988);
    */

    delay(100);                             // arbitrary delay to limit data to serial port 
}