#include "event.h"

#ifndef _AGENDAH_
#define _AGENDAH_

typedef struct Agenda Agenda;
struct Agenda {
  char* name;
  int nbEvenement;
  Event* tab_event;
};

#endif


Agenda createAgenda(char *name);

Agenda addEvent(Agenda agenda, Event event);

void deleteAgenda(Agenda agenda);

int export(Agenda agenda, char* filename);

void deleteEvent(Agenda agenda, char* nameEvent);
