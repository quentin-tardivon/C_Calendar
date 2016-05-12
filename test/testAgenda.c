#include "testAgenda.h"
#include "../headers/event.h"

int main(int argc, char const *argv[]) {
  testCreateAgenda();

  return 0;
}

void testCreateAgenda() {

  Event newEvent = createEvent("Test", "Ceci est un évènement test", "23/01/1995", "24/01/1995");

}
