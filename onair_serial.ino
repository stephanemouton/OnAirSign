// Control "On Air" sign using Blynk App

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Your BLYNK Token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "your WiFi SSID";
char pass[] = "your WiFi password";

void setup()
{
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(250);  
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(250);
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

