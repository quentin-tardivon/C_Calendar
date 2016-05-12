#include "../headers/event.h"
#include "testEvent.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  testCreateEvent();

  return 0;
}

void testCreateEvent() {
  Event newEvent = createEvent("Test", "Ceci est un évènement test", "23/01/1995", "24/01/1995");
  printf("Nom: %s\n",newEvent.name);
  printf("Description: %s\n",newEvent.description);
  printf("Début: %s\n",newEvent.begin);
  printf("Fin: %s\n",newEvent.end);
  printf("Bienvenue dans la gestion de calendrier!\n");
}
