# Bicycle-GPS

Bicycle-GPS's goal is to provide LED based directions for people using a GPS system on a bike. 

While it is possible to use a handlebar mounted smartphone and GPS, the screen is often hard to read because of the sunlight and the screen is usually overloaded with a lot of information. So the alternative is to use LED to display directions. The Bicycle-GPS project use sound to communicate with the GPS application. For the moment it has only been tested with OpenStreetMap based [OSMAnd](http://osmand.net).


Hardware:
---------

The code runs on an Arduino micro board, if you want to use bluetooth instead of an audio jack, you'll need to find a bluetooth headset.
A 24 Leds Adafruit ring is used for teh display, and you can find all the components on the Hackaday page : https://hackaday.io/project/12225-bicycle-gps 


Compilation
-----------

The project builds on Arduino IDE and requires the AdaFruit NeoPixel library provided.
To include this library in the Arduino IDE, in the toolbar, go on "Sketch/Include Library/Add .ZIP Library.." and choose "Adafruit_NeoPixel-master.zip".


Installation
------------

Upload the code on the Arduino board and copy the audio files on your smartphone/GPS.

For OSMAnd, you need at least to download a voice pack, not a TTS one, but one with recorded voices. Then you just copy all the freq_osmand files to ./osmand/voice/<your language> on your Android device. Feel free to backup the original file to restore them after. The easiest way is to download an obscure language pack that you only use for Bicycle-GPS, so you can just switch to this language when you use it on your bike.


Building
--------

You can see all the steps to make a Bike GPS on the Hackaday page : https://hackaday.io/project/12225-bicycle-gps


3D parts
--------

The .stl files are the files for the packaging made with a 3D printer.
* Garmin-Mount.stl is to fix the packaging on the bicycle handlebar
* Garmin_Quarter_turn_Plate.stl allows to fix the packaging on the handlebar piece
* Top.stl is the top of the packaging
* Bottom.stl is the bottom of the packaging

Velo.grl is the  CharlyRobot file to create a plexiglass cover to protect the LEDs. But it is possible to make it with a 3D printer, you just have to create the file.


License
-------

The project files except explicitely stated are under GPLv3 license.

AdaFruit NeoPixel Lib is under LGPLv2

Garmin_Quarter_Turn_Plate.stl is under  Creative Commons-Attribution-Share Alike license




