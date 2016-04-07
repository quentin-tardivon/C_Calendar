#include <stdio.h>

typedef struct Event Event;

struct Event {
  char name[40];
  char description[140];
  int begin;
  int end;
};

Event create(char name[],char description[], int begin, int end) {
    Event newEvent;
    newEvent.name = name;
    for (int i = 0; i < sizeof(name); i++)
        scanf("%d", &name[i]); //A voir, c'est chelou
    newEvent.description = description;
    newEvent.begin = begin;
    newEvent.end = end;
    return newEvent;
}