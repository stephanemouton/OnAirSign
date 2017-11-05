# OnAirSign
Information to remotely pilot "On Air" lamp using Arduino compatible board and a smartphone.

![On Air lamp](./Doc/onairlamp1.jpg)

## Preliminary setup
Please refer to [associated documentation](Doc/README.md) in the `Doc` directory

## Electronics
The following schematic has been used:

 _Schematic missing, to be completed_ 

Its goal is to add a few conveniences in use the sign and of the ESP8266
* Batteries can still be used to power the sign, though a standard 5V power is recommended.
* Two buttons (PROG and RESET) allow easy restart and programming of the ESP8266


## Using Blynk service, with setup by serial port
### Prepare for use of Blynk

In the Arduino IDE, install the `Blynk` library with Library Manager via menu Sketch->Include Library->Manage Libraries

Blynk allows to directly pilot GPIO port of the ESP8266, as explained following the link below, with an example based on IFTT.
https://community.blynk.cc/t/blynk-ifttt-details-guide-how-to-connect-both/5772

In our case, we connected "On Air" sign LEDs command to port 4 (D4)

We need then to send a PUT request on http://blynk-cloud.com/{AUTH}/pin/D4 with ["1"] or ["0"] in  request BODY to switch ON or OFF the sign.

_Note_: {AUTH} is to be replaced by the value of your blynk token.

### Arduino code to use Blynk service

Code of ![onair_serial.ino](./onair_serial.ino) show how to make the ESP8266 react to action on Blynk App.

This version briefly blinks twice at boot to indicate that everything is running normally.

### Install Arduino sketch

The ESP8266 module used must be put in download mode prior to start download from the Arduino IDE.
With the schematic used, please follow the steps below. The snapshot of a mounted sign can also help you.

* Connect the serial port. In the case of the picture of our mounted Sign, Black is ground, Yellow is for TX and Orange for RX.
* A new port should appear in your Arduino IDE
* **Maintain the PROG button pressed**. In the picture, it is the lower button, on the left of the serial connection / ESP8266 axis
* Briefly press the RESET button (upper button in the picture) while PROG is still pressed
* **Continue to press the PROG button for at least 2 seconds** after release of the RESET button
* ESP8266 module is now in download mode, awaiting sketch. Push on the "download" arrow of the Arduino IDE to send the sketch.
* At the end of download, **press again on the RESET button** so that the ESP8266 leaves download mode and restart in operation mode.
* Enjoy!

![On AIr Sketch Installation](./Doc/OnAIrSketchInstallation.png)

### Create a Blynk application

Add a button in your Blynk project with the following settings :
* output is GPIO port 4 (GP4)
* use "switch" mode
![Blynk button configuration](./Doc/Blynk_button_configuration.png)

Once everything is ready, run you app and your Blynk app should look like screenshot below.
![Blynk application running](./Doc/Blynk_button_running.png)

### Using Blynk service, with OTA ESP8266 configuration

Procedure described above is the same, except that download of updates of the Arduino sketch can be performed using WiFi connection.

Initial download must still be done using serial connection. 

Corresponding code in in the ![onair_OTA.ino](./onair_OTA.ino) file.
