/*
   Copyright (c) 2023, DIYables.io. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.

   - Neither the name of the DIYables.io nor the names of its
     contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY DIYABLES.IO "AS IS" AND ANY EXPRESS OR
   IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL DIYABLES.IO BE LIABLE FOR ANY DIRECT,
   INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
   STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
   IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
*/
#include <IRremote.hpp>
#include <DIYables_IRcontroller.h>

//extern IRrecv IrReceiver;

DIYables_IRcontroller::DIYables_IRcontroller(int pin, int debounceTime) {
  _pin          = pin;
  _debounce_time = debounceTime;
  _last_time    = 0;
}

void DIYables_IRcontroller::begin() {
  IrReceiver.begin(_pin, ENABLE_LED_FEEDBACK);
}

uint16_t DIYables_IRcontroller::loop() {
  uint16_t command = 0;
  if (IrReceiver.decode()) {
    IrReceiver.resume(); // Enable receiving of the next value
    unsigned long current_time = millis();
    if ((current_time - _last_time) >= _debounce_time) {
      command = IrReceiver.decodedIRData.command;
      _last_time = current_time;
    }
  }

  return command;
}

Key17 DIYables_IRcontroller_17::getKey() {
  uint16_t command = loop();

  switch (command) {
    case 0:           return Key17::NONE;
    case KEY17_1:     return Key17::KEY_1;
    case KEY17_2:     return Key17::KEY_2;
    case KEY17_3:     return Key17::KEY_3;
    case KEY17_4:     return Key17::KEY_4;
    case KEY17_5:     return Key17::KEY_5;
    case KEY17_6:     return Key17::KEY_6;
    case KEY17_7:     return Key17::KEY_7;
    case KEY17_8:     return Key17::KEY_8;
    case KEY17_9:     return Key17::KEY_9;
    case KEY17_STAR:  return Key17::KEY_STAR;
    case KEY17_0:     return Key17::KEY_0;
    case KEY17_SHARP: return Key17::KEY_SHARP;
    case KEY17_UP:    return Key17::KEY_UP;
    case KEY17_LEFT:  return Key17::KEY_LEFT;
    case KEY17_OK:    return Key17::KEY_OK;
    case KEY17_RIGHT: return Key17::KEY_RIGHT;
    case KEY17_DOWN:  return Key17::KEY_DOWN;
    default:  return Key17::UNKNOWN;
  }
}

Key21 DIYables_IRcontroller_21::getKey() {
  uint16_t command = loop();

  switch (command) {
    case 0:                return Key21::NONE;
    case KEY21_CH_MINUS:   return Key21::KEY_CH_MINUS;
    case KEY21_CH:         return Key21::KEY_CH;
    case KEY21_CH_PLUS:    return Key21::KEY_CH_PLUS;
    case KEY21_PREV:       return Key21::KEY_PREV;
    case KEY21_NEXT:       return Key21::KEY_NEXT;
    case KEY21_PLAY_PAUSE: return Key21::KEY_PLAY_PAUSE;
    case KEY21_VOL_MINUS:  return Key21::KEY_VOL_MINUS;
    case KEY21_VOL_PLUS:   return Key21::KEY_VOL_PLUS;
    case KEY21_EQ:         return Key21::KEY_EQ;
    case KEY21_100_PLUS:   return Key21::KEY_100_PLUS;
    case KEY21_200_PLUS:   return Key21::KEY_200_PLUS;
    case KEY21_0:          return Key21::KEY_0;
    case KEY21_1:          return Key21::KEY_1;
    case KEY21_2:          return Key21::KEY_2;
    case KEY21_3:          return Key21::KEY_3;
    case KEY21_4:          return Key21::KEY_4;
    case KEY21_5:          return Key21::KEY_5;
    case KEY21_6:          return Key21::KEY_6;
    case KEY21_7:          return Key21::KEY_7;
    case KEY21_8:          return Key21::KEY_8;
    case KEY21_9:          return Key21::KEY_9;
    default:               return Key21::UNKNOWN;
  }
}