#include <stdio.h>
#include "../headers/event.h"

Event createEvent(char name[],char description[], int begin, int end) {
  Event newEvent;
  newEvent.begin = begin;
  newEvent.end = end;
  int i;
  for (i = 0; i < 140; i++) {
    newEvent.description[i] = description[i];
    newEvent.name[i] = name[i];
  }
  return newEvent;
}
