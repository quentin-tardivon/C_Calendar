#include <stdio.h>
#include <stdlib.h>

#ifndef _EVENTH_
#define _EVENTH_

typedef struct Event Event;
struct Event {
  char* name;
  char* description;
  char* begin;
  char* end;
};

#endif


Event createEvent();

char* convertDate(char* year,char* day, char* month, char* hours);
