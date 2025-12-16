#include <stdio.h> 
#include <stdlib.h> 
#include "out.h"
#include <unistd.h> 
#include <time.h> 
 
char airplane[4][70]={ 
  "/------------------------\\          |~\\________/~~\\________   |", 
  "| FROHE WEIHNACHTEN      |___________\\________========_____)--+", 
  "| UND EINEN GUTEN RUTSCH |                   ~~~|/~~          |", 
  "\\------------------------/                     (o)              ", 
}; 


int main(void){ 

    int x = 2, y = 0; 

    srand(time(0)); 

    while(x<25-4){ 
        while(y<80){ 
            clrscr(); 
            /*Code einfügen*/                       //Aufgabe 4: Funktionen aufrufen
            y++; 
            usleep(50000);
        } 
        y = 0; 
        x++; 
    } 
    return EXIT_SUCCESS; 
}

void Draw_Snow(void){ 
    /*Code einfügen*/                               //Aufgabe 1: Variablen initialisieren
 
    /*Code einfügen*/{                              //Aufgabe 2: Schleife einfügen
        x_coordinate = rand() % 25;
        y_coordinate = rand() % 80;
        gotoxy(x_coordinate, y_coordinate);
        printf(".");
        fflush(stdout);
    }
} 

/*Code einfügen*/{                                  //Aufgabe 3: Funktionskopf einfügen
    int i;
    for(i = 0; i < 4; i++){
        gotoxy(x+i, y);
        printf("%s", airplane[i]);
        fflush(stdout);
    }
}