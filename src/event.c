#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/event.h"
#include <time.h>

Event createEvent() {
  Event newEvent;
  newEvent.begin = malloc(sizeof(char)*16);
  newEvent.end = malloc(sizeof(char)*16);
  newEvent.name = malloc(sizeof(char)*40);
  newEvent.description = malloc(sizeof(char)*140);
  return newEvent;
}

void freeEvent(Event event) {
  free(event.begin);
  free(event.description);
  free(event.end);
  free(event.name);
}

char* convertDate(char* date) { //Jjj Mmm jm hh:mm:ss aaaa
  char* result = NULL;
  result = malloc(sizeof(char)*16);
  result[0] = '\0';
  //Année
  sprintf(result, "%s%c",result,date[20]);
  sprintf(result, "%s%c",result,date[21]);
  sprintf(result, "%s%c",result,date[22]);
  sprintf(result, "%s%c",result,date[23]);

  char* month = NULL;
  month = malloc(sizeof(char)*3);
  month[0] = '\0';

  //Mois
  sprintf(month, "%s%c",month,date[4]);
  sprintf(month, "%s%c",month,date[5]);
  sprintf(month, "%s%c",month,date[6]);

  if (strcmp(month,"Jan") == 0) {
    strcat(result, "01");
  }
  else if (strcmp(month,"Feb") == 0){
    strcat(result, "02");
  }
  else if (strcmp(month,"Mar") == 0){
    strcat(result, "03");
  }
  else if (strcmp(month,"Apr") == 0){
    strcat(result, "04");
  }
  else if (strcmp(month,"May") == 0){
    strcat(result, "05");
  }
  else if (strcmp(month,"Jun") == 0){
    strcat(result, "06");
  }
  else if (strcmp(month,"Jul") == 0){
    strcat(result, "07");
  }
  else if (strcmp(month,"Aug") == 0){
    strcat(result, "08");
  }
  else if (strcmp(month,"Sep") == 0){
    strcat(result, "09");
  }
  else if (strcmp(month,"Oct") == 0){
    strcat(result, "10");
  }
  else if (strcmp(month,"Nov") == 0){
    strcat(result, "11");
  }
  else {
    strcat(result, "12");
  }
  //Jour
  sprintf(result, "%s%c",result,date[8]);
  sprintf(result, "%s%c",result,date[9]);
  strcat(result, "T");
  //Heure
  sprintf(result, "%s%c",result,date[11]);
  sprintf(result, "%s%c",result,date[12]);
  sprintf(result, "%s%c",result,date[14]);
  sprintf(result, "%s%c",result,date[15]);
  strcat(result,"00");
  strcat(result, "Z");
  return result;
}
