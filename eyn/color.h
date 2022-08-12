#include <stdio.h>
#include <string.h>

void win_color(){
    system("color 3f");
}

void unix_color(){

}

void color(char platform[10]){
    if(! strcmp(platform, "win")){
        win_color();
    }else{
        unix_color();
    }
}
