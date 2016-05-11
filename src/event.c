#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/event.h"

Event createEvent(char name[40],char description[140], char* begin, char* end) {
  Event newEvent;
  strcpy(newEvent.begin,begin);
  strcpy(newEvent.end,end);
  strcpy(newEvent.name,name);
  strcpy(newEvent.description,description);
  return newEvent;
}

char* convertDate(char* year,char* day, char* month, char* hours) { //23/01/1995 13:23
  char* result = "";
  strcat(result, year);
  strcat(result, month);
  strcat(result, day);
  strcat(result, "T");
  strcat(result, &hours[0]);
  strcat(result, &hours[1]);
  strcat(result, &hours[3]);
  strcat(result, &hours[4]);
  return result;
}
