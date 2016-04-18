
typedef struct Event Event;
struct Event {
  char name[40];
  char description[140];
  int begin;
  int end;
};

Event createEvent(char name[],char description[], int begin, int end);
