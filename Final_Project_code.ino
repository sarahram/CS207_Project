#include <AudioFrequencyMeter.h>

/*
 * Reference code found at:
 * https://create.arduino.cc/projecthub/Oniichan_is_ded/music-reactive-led-strip-with-microphone-module-f0f7c6
 * https://www.arduino.cc/en/Tutorial/SimpleAudioFrequencyMeter
 * 
 * Code has been modified to suit our projects objective.
 */

int soundSensor = A0;
int LED1 = 11, LED2 = 12;

AudioFrequencyMeter meter;

void setup()
{
  pinMode(soundSensor,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);

  meter.setBandwidth(70.00, 1500);
  meter.begin(A0, 45000);
}
void loop()
{
  int statusSensor = digitalRead (soundSensor);

  if (statusSensor == 1)
  {
      float frequency = meter.getFrequency();

      if (frequency <= 170.00)
      {
          digitalWrite(LED2,HIGH); 
      }
      else
      {
          digitalWrite(LED1,HIGH);
      }
   }
   else
   {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
   }
}
