#include <stdio.h>

int main() {
    char ch;
    int spaces=0, lines=0;
    FILE *fp=fopen("input.c","r");

    while((ch=fgetc(fp))!=EOF) {
        if(ch==' ') spaces++;
        if(ch=='\n') lines++;
    }
    printf("Spaces=%d\nLines=%d",spaces,lines);
    fclose(fp);
}

