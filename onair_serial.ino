// Control "On Air" sign using Blynk App, Over The Air (OTA) version

#define BLYNK_PRINT Serial
#define OTA_NAME "onair"
#define OTA_PWD  ""

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ArduinoOTA.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourBlynkAuthToken";

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

  //BLYNK
  Blynk.begin(auth, ssid, pass);

  //OTA
  ArduinoOTA.onStart([]() {
    Serial.println("Start OTA");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd OTA");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("OTA Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("OTA Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("OTA Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("OTA Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("OTA Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("OTA End Failed");
  });
  ArduinoOTA.setHostname((const char *)OTA_NAME);
  ArduinoOTA.setPassword((const char *)OTA_PWD);
  ArduinoOTA.begin();
}

void loop()
{
  //blynk loop
  Blynk.run();

  //ota loop
  ArduinoOTA.handle();
}
