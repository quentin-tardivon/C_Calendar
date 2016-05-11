
typedef struct Event Event;
struct Event {
  char name[40];
  char description[140];
  char* begin;
  char* end;
};

Event createEvent(char name[40],char description[140], char* begin, char* end);

char* convertDate(char* year,char* day, char* month, char* hours);
