## DIYables IR Remote Controller Library for Arduino - DIYables_IRcontroller
This library is designed for Arduino, ESP32, ESP8266... to received the controlled key from the DIYables IR Remote Controller.


![DIYables IR Remote Controller Module](https://diyables.io/images/products/infrared-ir-remote-control-kits-with-controller-and-receiver-1.jpg)


Product Link
----------------------------
* [DIYables 17-key IR Remote Controller](https://diyables.io/products/infrared-ir-remote-control-kit-with-17-key-controller-and-receiver)
* [DIYables 21-key IR Remote Controller](https://diyables.io/products/infrared-ir-remote-control-kit-with-21-key-controller-and-receiver)


Features
----------------------------
* Easy to use
* Configurable debouce time for key press


Available Functions
----------------------------
* DIYables_IRcontroller_17(int pin, int debounceTime);
* DIYables_IRcontroller_21(int pin, int debounceTime);
* void begin();
* Key17 getKey();
* Key21 getKey();

Return from DIYables_IRcontroller_17::getKey()
* Key17::NONE
* Key17::KEY_1
* Key17::KEY_2
* Key17::KEY_3
* Key17::KEY_4
* Key17::KEY_5
* Key17::KEY_6
* Key17::KEY_7
* Key17::KEY_8
* Key17::KEY_9
* Key17::KEY_STAR
* Key17::KEY_0
* Key17::KEY_SHARP
* Key17::KEY_UP
* Key17::KEY_LEFT
* Key17::KEY_OK
* Key17::KEY_RIGHT
* Key17::KEY_DOWN
* Key17::UNKNOWN

Return from DIYables_IRcontroller_21::getKey()
* Key21::NONE
* Key21::KEY_CH_MINUS
* Key21::KEY_CH
* Key21::KEY_CH_PLUS
* Key21::KEY_PREV
* Key21::KEY_NEXT
* Key21::KEY_PLAY_PAUSE
* Key21::KEY_VOL_MINUS
* Key21::KEY_VOL_PLUS
* Key21::KEY_EQ
* Key21::KEY_100_PLUS
* Key21::KEY_200_PLUS
* Key21::KEY_0
* Key21::KEY_1
* Key21::KEY_2
* Key21::KEY_3
* Key21::KEY_4
* Key21::KEY_5
* Key21::KEY_6
* Key21::KEY_7
* Key21::KEY_8
* Key21::KEY_9
* Key21::UNKNOWN





Available Examples
----------------------------
* IRcontroller_17
* IRcontroller_21



References
----------------------------
* [DIYables_IRcontroller Library Reference](https://arduinogetstarted.com/reference/library/diyables-ir-controller-library)


Tutorials
----------------------------
* [Arduino - DIYables IR Remote Controller](https://arduinogetstarted.com/tutorials/arduino-ir-remote-control)
* [ESP32 - DIYables IR Remote Controller](https://esp32io.com/tutorials/esp32-ir-remote-control)
* [ESP8266 - DIYables IR Remote Controller](https://newbiely.com/tutorials/esp8266/esp8266-ir-remote-control)

