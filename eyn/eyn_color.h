#include <stdio.h>
#include <conio.h>

void set_color(char bg, char fg){
    char out[10];

    sprintf(out, "color %c%c", bg, fg);

    system(out);
}

void main_color(char *os){
    if(! strcmp(os, "win")){
        char bg;
        char fg;
        char colors[] = "0123456789ABCDEFabcdef";

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
        scanf(" %c", &bg);

        printf("enter foreground color:");
        scanf(" %c", &fg);

        int flag = 0;
        int flag2 = 0;

        for(int i = 0;i <= sizeof(colors);i++){
            if(bg == colors[i]){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            printf("incorrect input!\n");
            printf("enter a key for continue");
            getch();
            return;
        }

        for(int i = 0;i <= sizeof(colors);i++){
            if(fg == colors[i]){
                flag2 = 1;
                break;
            }
        }

        if(flag2 == 0){
            printf("incorrect input!\n");
            printf("enter a key for continue");
            getch();
            return;
        }

        set_color(bg, fg);
    }
}
