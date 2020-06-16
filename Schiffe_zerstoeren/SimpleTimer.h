#ifndef _SIMPLETIMER_H
#define _SIMPLETIMER_H

#include "Arduino.h"

class SimpleTimer {
  unsigned long startTime;
  unsigned long duration;
  bool running;

public:
  SimpleTimer();
  void set(unsigned long duration);
  bool elapsed();
};

#endif
