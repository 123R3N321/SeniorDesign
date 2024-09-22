#include <Adafruit_CircuitPlayground.h>
#include "Keyboard.h"

bool leftButtonPressed;
bool rightButtonPressed;

void setup() {
    Serial.begin(9600);

    CircuitPlayground.begin();

    // initialize control over the keyboard:
    Keyboard.begin();

    CircuitPlayground.setAccelRange(LIS3DH_RANGE_4_G);  //max detect 4G, prof does not like high range anyways
    //candidate vals:
    //2, 4, 8 and 16G
}

void loop() {

    CircuitPlayground.clearPixels();

    bool lock = true;
    leftButtonPressed = CircuitPlayground.leftButton();
    rightButtonPressed = CircuitPlayground.rightButton();

    Serial.print("Left Button: ");
    if (leftButtonPressed) {
        Serial.print("DOWN");
        Serial.print(CircuitPlayground.motionZ());
    }
    Serial.print("   Right Button: ");
    if (rightButtonPressed) {
        Serial.print("DOWN");
        if(CircuitPlayground.motionZ()>20.0f && lock){
            Keyboard.write(KEY_LEFT_ARROW);
            lock = false;
            CircuitPlayground.setPixelColor(5, 0xFF0000);
            delay(1000);
        }else if(CircuitPlayground.motionZ()<-20.0f && lock){
            Keyboard.write(KEY_RIGHT_ARROW);
            lock = false;
            CircuitPlayground.setPixelColor(5, 0x00FF00);
            delay(1000);
        }

    }
    Serial.println();

    delay(1);
}


////#include "Keyboard.h"
//
//void setup() {
//    Keyboard.begin();
//    delay(2000); // Wait for 2 seconds to ensure the board is ready
//    Keyboard.write('a');
//}
//
//void loop() {
//}