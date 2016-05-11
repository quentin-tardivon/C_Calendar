#include "event.h"

typedef struct Agenda Agenda;
struct Agenda {
  char* name;
  int nbEvenement;
  Event* tab_event;
} agenda;
