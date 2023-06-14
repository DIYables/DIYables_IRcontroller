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

#ifndef DIYables_IRcontroller_h
#define DIYables_IRcontroller_h

#include <Arduino.h>

// KEY-CODE TABLE FOR 17-KEY IR REMOTE CONTROLLER:
#define KEY17_1     69  //  1
#define KEY17_2     70  //  2
#define KEY17_3     71  //  3
#define KEY17_4     68  //  4
#define KEY17_5     64  //  5
#define KEY17_6     67  //  6
#define KEY17_7     7   //  7
#define KEY17_8     21  //  8
#define KEY17_9     9   //  9
#define KEY17_STAR  22  //  *
#define KEY17_0     25  //  0
#define KEY17_SHARP 13  //  #
#define KEY17_UP    24  //  UP
#define KEY17_LEFT  8   //  LEFT
#define KEY17_OK    28  //  OK
#define KEY17_RIGHT 90  //  RIGHT
#define KEY17_DOWN  82  //  DOWN

// KEY-CODE TABLE FOR 21-KEY IR REMOTE CONTROLLER:
#define KEY21_CH_MINUS   69  //  CH-
#define KEY21_CH         70  //  CH
#define KEY21_CH_PLUS    71  //  CH
#define KEY21_PREV       68  //  <<
#define KEY21_NEXT       64  //  >>
#define KEY21_PLAY_PAUSE 67  //  >||
#define KEY21_VOL_MINUS      7   //  –
#define KEY21_VOL_PLUS       21  //  +
#define KEY21_EQ         9   //  EQ
#define KEY21_100_PLUS   25  //  100+
#define KEY21_200_PLUS   13  //  200+
#define KEY21_0          22  //  0
#define KEY21_1          12  //  1
#define KEY21_2          24  //  2
#define KEY21_3          94  //  3
#define KEY21_4          8   //  4
#define KEY21_5          28  //  5
#define KEY21_6          90  //  6
#define KEY21_7          66  //  7
#define KEY21_8          82  //  8
#define KEY21_9          74  //  9


enum class Key17 {
  NONE      = 0,  // NONE
  KEY_1     = 69, // 1
  KEY_2     = 70, // 2
  KEY_3     = 71, // 3
  KEY_4     = 68, // 4
  KEY_5     = 64, // 5
  KEY_6     = 67, // 6
  KEY_7     = 7,  // 7
  KEY_8     = 21, // 8
  KEY_9     = 9,  // 9
  KEY_STAR = 22, // *
  KEY_0     = 25, // 0
  KEY_SHARP = 13, // #
  KEY_UP    = 24, // UP
  KEY_LEFT  = 8,  // LEFT
  KEY_OK    = 28, // OK
  KEY_RIGHT = 90, // RIGHT
  KEY_DOWN  = 82, // DOWN
  UNKNOWN   = 255 // UNKNOWN
};

enum class Key21 {
  NONE           = 0,  // NONE
  KEY_CH_MINUS   = 69, // CH-
  KEY_CH         = 70, // CH
  KEY_CH_PLUS    = 71, // CH
  KEY_PREV       = 68, // <<
  KEY_NEXT       = 64, // >>
  KEY_PLAY_PAUSE = 67, // >||
  KEY_VOL_MINUS  = 7,  // –
  KEY_VOL_PLUS   = 21, // +
  KEY_EQ         = 9,  // EQ
  KEY_100_PLUS   = 25, // 100+
  KEY_200_PLUS   = 13, // 200+
  KEY_0          = 22, // 0
  KEY_1          = 12, // 1
  KEY_2          = 24, // 2
  KEY_3          = 94, // 3
  KEY_4          = 8,  // 4
  KEY_5          = 28, // 5
  KEY_6          = 90, // 6
  KEY_7          = 66, // 7
  KEY_8          = 82, // 8
  KEY_9          = 74, // 9
  UNKNOWN        = 255 // UNKNOWN
};

class DIYables_IRcontroller
{
  private:
    int _pin;
    unsigned long _debounce_time;
    unsigned long _last_time;
    uint16_t command;

  protected:
    uint16_t loop();

  public:
    DIYables_IRcontroller(int pin, int debounceTime);

    void begin();
};

class DIYables_IRcontroller_17 : public DIYables_IRcontroller
{
  public:
    Key17 getKey();
    using DIYables_IRcontroller::DIYables_IRcontroller; // Inherit the base class constructor
};


class DIYables_IRcontroller_21 : public DIYables_IRcontroller
{
  public:
    Key21 getKey();
    using DIYables_IRcontroller::DIYables_IRcontroller; // Inherit the base class constructor
};

#endif
