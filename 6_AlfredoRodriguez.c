#include <stdio.h>
#include <string.h>
void make_array(FILE * in, char * lines[]){
    int i = 0;
    char * line_buff = NULL;
    size_t bufsize = 0;
    int sizer = getline(&line_buff, &bufsize, in);
    while(sizer >= 0){
        lines[i++] = strdup(line_buff);
        sizer = getline(&line_buff, &bufsize, in);
    }
}
int main(int argc, const char * argv[]){
    FILE * left = fopen(argv[1], "r");
    FILE * right = fopen(argv[2], "r");
    char * left_lines[100];
    char * right_lines[100];
    make_array(left, left_lines);
    make_array(right, right_lines);
    int i;
    while(left_lines[i] && right_lines[i]){
        if(strcmp(left_lines[i],right_lines[i])!= 0){
            printf("They differ at line %d:\n %s %s",i+1, left_lines[i], right_lines[i]);
            return 0;
        }
        i++;
    }
    //if no difference
    printf("There was no difference betweeen them...\n");
    return 0;
}