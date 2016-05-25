#include <stdio.h>
#include <stdlib.h>

#ifndef _EVENTH_
#define _EVENTH_

typedef struct Event Event;
struct Event {
  char* name;
  char* description;
  char* location;
  char* begin;
  char* end;
};

#endif


Event createEvent();

void freeEvent(Event event);

char* convertDate(char* date);
