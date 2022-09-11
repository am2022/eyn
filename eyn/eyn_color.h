#include <stdio.h>

void set_color(char bg, char fg){
    char out[10];

    sprintf(out, "color %c%c", bg, fg);

    system(out);
}

void main_color(char *os){
    char bg;
    char fg;

    printf("color menu:\n");
    printf("0 = Black       8 = Gray\n");
    printf("1 = Blue        9 = Light Blue\n");
    printf("2 = Green       A = Light Green\n");
    printf("3 = Aqua        B = Light Aqua\n");
    printf("4 = Red         C = Light Red\n");
    printf("5 = Purple      D = Light Purple\n");
    printf("6 = Yellow      E = Light Yellow\n");
    printf("7 = White       F = Bright White\n");

    printf("enter background color:");
    scanf("%c", &bg);

    printf("enter foreground color:");
    scanf("%c", &fg);

    set_color(bg, fg);
}
