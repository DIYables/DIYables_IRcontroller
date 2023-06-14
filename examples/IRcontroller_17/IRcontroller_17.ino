/*
   Created by DIYables

   This example code is in the public domain

   Product page: https://diyables.io/products/infrared-ir-remote-control-kit-with-17-key-controller-and-receiver
*/

#include <DIYables_IRcontroller.h> // DIYables_IRcontroller library
#define IR_RECEIVER_PIN 7 // The Arduino pin connected to IR controller

DIYables_IRcontroller_17 irController(IR_RECEIVER_PIN, 200); // debounce time is 200ms

void setup() {
  Serial.begin(9600);
  irController.begin();
}

void loop() {
  Key17 command = irController.getKey();
  if (command != Key17::NONE) {
    switch (command) {
      case Key17::KEY_1:
        Serial.println("1");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_2:
        Serial.println("2");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_3:
        Serial.println("3");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_4:
        Serial.println("4");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_5:
        Serial.println("5");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_6:
        Serial.println("6");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_7:
        Serial.println("7");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_8:
        Serial.println("8");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_9:
        Serial.println("9");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_STAR:
        Serial.println("*");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_0:
        Serial.println("0");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_SHARP:
        Serial.println("#");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_UP:
        Serial.println("UP");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_DOWN:
        Serial.println("DOWN");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_LEFT:
        Serial.println("LEFT");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_RIGHT:
        Serial.println("RIGHT");
        // TODO: YOUR CONTROL
        break;

      case Key17::KEY_OK :
        Serial.println("OK");
        // TODO: YOUR CONTROL
        break;

      default:
        Serial.println("WARNING: undefined command:");
        break;
    }
  }
}