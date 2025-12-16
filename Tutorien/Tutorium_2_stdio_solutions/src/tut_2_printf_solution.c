#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int a = 255;
    double pi = 3.1415927;
                                                // Ausgabe:
    printf("Hello World!\n");                   // Hello World!
    printf("%d\n", 10);                         // 10
    printf("%d\n", a);                          // 255
    printf("%04d%04d%04d\n", 1, 2, 3);          // 000100020003
    printf("%4d%4d%4d\n", 1, 2, 3);             //    1   2   3
    printf("%.7lf\n", pi);                      // 3.415927
    printf("%.2lf\n", pi);                      // 3.14
    printf("%c\n", 'c');                        // c
    printf("%s %c%d\n", "Airbus", 'A', 380);    // Airbus A380

    return EXIT_SUCCESS;
}
