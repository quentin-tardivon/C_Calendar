#include "event.c"
#include "../headers/agenda.h"

Agenda createAgenda(char *name) {
  Agenda newAgenda;
  strcpy(newAgenda.name,name);
  newAgenda.nbEvenement = 0;
  newAgenda.tab_event = malloc(sizeof(Event)*newAgenda.nbEvenement);
}

Agenda addEvent(Agenda agenda, Event event) {
  agenda.nbEvenement +=1;
  agenda.tab_event = realloc(agenda.tab_event, agenda.nbEvenement * sizeof(Event));
}

void deleteAgenda(Agenda agenda) {
  free(agenda.tab_event);
}

void deleteEvent(Agenda agenda, Event event) { //TODO
  agenda.nbEvenement -=1 ;
  for (size_t i = 0; i < agenda.nbEvenement; i++) {
    if (agenda.tab_event[i] == event) {
      for (size_t j = 0; j < agenda.nbEvenement -i; j++) {
        agenda.tab_event[j] = agenda.tab_event[j+1];
      }
    }
  }
}

int export(Agenda agenda) {
  FILE* fichier;
  fichier = fopen("../ressources/calendrier.ics","w+");
  if (fichier == NULL) {
    printf("Impossible de continuer, le fichier n'a pas pu être créer\n");
    return 1;
  }
  else {
    fputs("BEGIN:VCALENDAR\nVERSION:2.0\nPRODID:-//hacksw/handcal//NONSGML v1.0//EN", fichier);
  }
  int i;
  for (i = 0; i < Agenda.taille; i++) {
    /* code */
  }

}
