#include <stdio.h>
#include <ctype.h>
#include <string.h>
void UP(){
    int c;
    printf("Enter a sentence: ");
    while ((c = getchar()) != EOF){
        putchar(toupper(c));
    }
}
void LOW(){
    int c;
    printf("Enter a sentence: ");
    while ((c = getchar()) != EOF){
        putchar(tolower(c));
    }
}
int main(int argc, const char * argv[]){
    if(strstr(argv[0], "upper") != NULL){
        UP();
    }else{
        LOW();
    }
}