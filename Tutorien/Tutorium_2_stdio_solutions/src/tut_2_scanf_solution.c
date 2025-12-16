#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Variablen für die Geradengleichung (1)

    double y = 0;
    double m = 0;
    double x = 0;
    double c = 0;

    // Einlesen der Parameter:
    // - Eingabeaufforderung
    // - Einlesen und Speichern
    
    printf("Steigung m: ");
    scanf("%lf", &m);
    printf("Y-Achsenversetzung c: ");
    scanf("%lf", &c);
    

    // Einlesen der Stelle x:

    printf("Auszuwertende Stelle x: ");
    scanf("%lf", &x);

    // Ausgabe gerundet auf 2 Nachkommastellen:

    y = m * x + c;
    printf("\nDer Funktionswert y an der Stelle x = %.2lf ist: %.2lf", x, y);
    printf("\nDer Punkt auf der Geraden ist: P = (%.2lf|%.2lf)\n", x, y);

}
