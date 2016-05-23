#include "../headers/event.h"
#include "../headers/agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Agenda createAgenda(char *name) {
  Agenda newAgenda;
  newAgenda.name = name;
  newAgenda.nbEvenement = 0;
  newAgenda.tab_event = malloc(sizeof(Event)*newAgenda.nbEvenement);
  return newAgenda;
}

Agenda addEvent(Agenda agenda,Event event) {
  agenda.nbEvenement = agenda.nbEvenement + 1;
  agenda.tab_event = realloc(agenda.tab_event, agenda.nbEvenement * sizeof(Event));
  agenda.tab_event[agenda.nbEvenement-1] = event;
  return agenda;
}

void deleteEvent(Agenda agenda,char* nameEvent) {
  for (size_t i = 0; i < agenda.nbEvenement; i++) {
    if (strcmp(agenda.tab_event[i].name,nameEvent) == 0) {
      freeEvent(agenda.tab_event[i]);
      printf("Evènement supprimé\n");
    }
  }
}

void deleteAgenda(Agenda agenda) {
  free(agenda.tab_event);
  free(agenda.name);
}


int export(Agenda agenda, char* filename) {
  FILE* file = NULL;
  file = fopen(filename,"w+");
  if (file == NULL) {
    printf("Impossible de continuer, le fichier n'a pas pu être créer\n");
    return 1;
  }
  else {
    fputs("BEGIN:VCALENDAR\nVERSION:2.0\nPRODID:-//hacksw/handcal//NONSGML v1.0//EN\n", file);
  }
  int i;
  for (i = 0; i < agenda.nbEvenement; i++) {
    fputs("BEGIN:VEVENT\n", file);
    fprintf(file,"DTSTART:%s\n",agenda.tab_event[i].begin);
    fprintf(file, "DTEND:%s\n",agenda.tab_event[i].end);
    fprintf(file, "SUMMARY:%s\n",agenda.tab_event[i].name);
    fprintf(file, "DESCRIPTION:%s\n",agenda.tab_event[i].description);
    fputs("END:VEVENT\n", file);
  }
  fputs("END:VCALENDAR", file);
  fclose(file);
  return 0;
}
