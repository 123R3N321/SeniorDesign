#Senior Design repo

## how to clone
- set up platformio on your machine
- create a platformio project, hardware select Adafruit Playgorund Classic
- go into this project, git clone the project

## dependencies
I have those included in the repo, but if they don't work:
- delete HID, SoftwareSerial, SPI, and Wire
- go to platformio.ini file, which is the equivalent of config
- make sure the following is there:

```ini
lib_deps =
# three libraries
    adafruit/Adafruit Circuit Playground @ ^1.12.0
    fittyfu/HID@^1.0
    arduino-libraries/Keyboard@^1.0.6

```
build the .ini and the dependencies will auto install.