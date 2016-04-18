#include "../headers/event.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  Event newEvent = createEvent("Test", "Ceci est un évènement test", 12, 123);
  printf("Nom: %s\n",newEvent.name);
  printf("Description: %s\n",newEvent.description);
  printf("Début: %d\n",newEvent.begin);
  printf("Fin: %d\n",newEvent.end);
  return 0;
}
