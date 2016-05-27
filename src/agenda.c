#include "../headers/agenda.h"
#include "../headers/function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Permet la création d'un agenda
Agenda createAgenda(char *name) {
  Agenda newAgenda;
  newAgenda.name = name;
  newAgenda.nbEvenement = 0;
  newAgenda.tab_event = malloc(sizeof(Event)*newAgenda.nbEvenement);
  return newAgenda;
}

//Permet l'ajout d'un évènement à un agenda
Agenda addEvent(Agenda agenda,Event event) {
  agenda.nbEvenement = agenda.nbEvenement + 1;
  agenda.tab_event = realloc(agenda.tab_event, agenda.nbEvenement * sizeof(Event));
  agenda.tab_event[agenda.nbEvenement-1] = event;
  return agenda;
}

//Permet la suprression d'un évènement dans un agenda
void deleteEvent(Agenda agenda,char* nameEvent) {
  int i = 0;
  int compt = 0;
  int* indice = malloc(sizeof(agenda.tab_event));
  char ans;
  for (i = 0; i < agenda.nbEvenement; i++) {
    if (strcmp(agenda.tab_event[i].name,nameEvent) == 0) {
      indice[compt] = i;
      compt +=1;
    }
  }
  if (compt>1) {
    printf("Il y a plus d'un évènement avec ce nom\nVoulez-vous tous les supprimer? (y/n)");
    fgets(&ans, sizeof(&ans),stdin);
    clean(&ans);
    if (ans == 'y') {
      int j = 0;
      for (j = 0; j < compt; j++) {
        freeEvent(agenda.tab_event[indice[j]]);
        agenda.tab_event[indice[j]].begin = 0;
      }
      printf("Il y a eu %d évènements supprimés\n",compt);
    }
    else if (ans == 'n') {
      int yd = 0;
      int md = 0;
      int dd = 0;
      int h = 0;
      int m = 0;
      struct tm date_begin;
      time_t secondes;
      struct tm instant;
      time(&secondes);
      char* date = NULL;
      date = malloc(sizeof(char)*30);
      instant = *localtime(&secondes);
      date_begin = instant;
      char* date_delete = malloc(sizeof(char)*16);

      printf("Quel est la date de début? (Format JJ/MM/AAAA)\n");
      purge();
      scanf("%d/%d/%d",&dd,&md,&yd);
      date_begin.tm_year = yd - 1900;
      date_begin.tm_mon = md -1;
      date_begin.tm_mday = dd;
      printf("Heure de début de l'évènement? (Format HH:MM)\n");
      purge();
      scanf("%d:%d",&h,&m);
      date_begin.tm_hour = h;
      date_begin.tm_min = m;


      if (date_begin.tm_isdst == 1) {
        date_begin.tm_hour = h-2 ;
      }
      else {
        date_begin.tm_hour = h-1;
      }
      date = asctime(&date_begin);
      date_delete = convertDate(date);
      int j;
      for (j = 0; j < compt; j++) {
        if (strcmp(agenda.tab_event[indice[j]].name,nameEvent) == 0 && strcmp(agenda.tab_event[indice[j]].begin, date_delete) == 0) {
          freeEvent(agenda.tab_event[indice[j]]);
          agenda.tab_event[indice[j]].begin = 0;
          printf("Evènement supprimé\n");
        }
        else {
          printf("Aucun évènement supprimé\n");
        }
      }
    }
  }
  else if (compt == 1) {
    freeEvent(agenda.tab_event[indice[0]]);
    agenda.tab_event[indice[0]].begin = 0;
    printf("Evènement supprimé\n");
  }
  else {
    printf("Aucun évènement supprimé\n");
  }
}

//Permet la suppression d'un agenda
void deleteAgenda(Agenda agenda) {
  free(agenda.tab_event);
  free(agenda.name);
}

//Exporte un agenda au format ICalendar
int export(Agenda agenda, char* filename) {
  FILE* file = NULL;
  file = fopen(filename,"w+");
  if (file == NULL) {
    printf("Impossible de continuer, le fichier n'a pas pu être créer\n");
    return 1;
  }
  else {
    fputs("BEGIN:VCALENDAR\nVERSION:2.0\nPRODID:-//hacksw/handcal//NONSGML v1.0//EN\n", file);
  }
  int i;
  for (i = 0; i < agenda.nbEvenement; i++) {
    if (agenda.tab_event[i].begin != 0) {
      fputs("BEGIN:VEVENT\n", file);
      fprintf(file,"DTSTART:%s\n",agenda.tab_event[i].begin);
      fprintf(file, "DTEND:%s\n",agenda.tab_event[i].end);
      fprintf(file, "SUMMARY:%s\n",agenda.tab_event[i].name);
      fprintf(file, "DESCRIPTION:%s\n",agenda.tab_event[i].description);
      fprintf(file, "LOCATION:%s\n",agenda.tab_event[i].location);
      fputs("END:VEVENT\n", file);
    }
  }
  fputs("END:VCALENDAR", file);
  fclose(file);
  return 0;
}
