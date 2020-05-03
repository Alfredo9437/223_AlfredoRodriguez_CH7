#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]){
    int lines;
    printf("How many lines per page: ");
    scanf("%d", &lines);
    int c;
    int files = 1;
    while(argc-- != 1){
        int nline_counter = 0;
        int page_counter = 1;
        FILE * Reading = fopen(argv[files],"r");
        printf("-----%s-----\n", argv[files]);
        printf("-----Page 1-----\n");
        while( (c = fgetc(Reading)) != EOF){
            if(c == '\n'){
                nline_counter++;
                if(nline_counter % lines == 0){
                    page_counter++;
                    printf("\n-----Page %d-----", page_counter);
                }
            }
            putchar(c);
        }
        printf("\n");
        files++;
    }
   
    printf("\n");
    return 0;
}