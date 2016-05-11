
typedef struct Event Event;
struct Event {
  char name[40];
  char description[140];
  int begin;
  int end;
  int id;
};

Event createEvent(char name[40],char description[140], int begin, int end);
