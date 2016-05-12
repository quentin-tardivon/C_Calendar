#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/event.h"

Event createEvent() {
  Event newEvent;
  newEvent.begin = malloc(sizeof(char)*16);
  newEvent.end = malloc(sizeof(char)*16);
  newEvent.name = malloc(sizeof(char)*40);
  newEvent.description = malloc(sizeof(char)*140);
  return newEvent;
}

char* convertDate(char* year,char* day, char* month, char* hours) { //23/01/1995 13:23
  char* result = malloc(sizeof(char)*16);
  strcat(result, year);
  strcat(result, month);
  strcat(result, day);
  strcat(result, "T");
  sprintf(result, "%s%c",result,hours[0]);
  sprintf(result, "%s%c",result,hours[1]);
  sprintf(result, "%s%c",result,hours[3]);
  sprintf(result, "%s%c",result,hours[4]);
  strcat(result,"00");
  strcat(result, "Z");
  return result;
}
