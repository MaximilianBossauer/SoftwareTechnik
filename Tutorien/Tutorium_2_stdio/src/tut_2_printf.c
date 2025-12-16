#include <stdio.h>
#include <stdlib.h>

int main() {

    int a = 255;
    double pi = 3.1415927;
                               // Ausgabe:
    printf("... \n");          // Hello World!
    printf("%d \n", ...);      // 10
    printf(...);               // 255
    printf("...\n", 1,2,3);    // 000100020003
    printf(...);               //    1   2   3
    printf("...", pi);         // 3.145927
    printf(...);               // 3.14
    printf("%c", ...);         // c (Hinweis: %c erwartet als Parameter ein Einzelzeichen in einfachen Anführungszeichen: 'c')
    printf("%s %c%d \n", ...); // Airbus A380

    return EXIT_SUCCESS;
}
