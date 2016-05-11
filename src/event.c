#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/event.h"

Event createEvent(char name[40],char description[140], int begin, int end) {
  Event newEvent;
  newEvent.begin = begin;
  newEvent.end = end;
  strcpy(newEvent.name,name);
  strcpy(newEvent.description,description);
  return newEvent;
}
