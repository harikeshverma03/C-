#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char array_of_strings[10][10] = {}, ch;
    int count = 0;
    do{
        scanf(" %s", &array_of_strings[count]);
        count++;
    }while((ch = getchar()) != EOF && count < 11);
    printf("%d\n", count);
    char temp[30];
    for(int i=0; i<count; i++){
        for(int j=0; j<count-1-i; j++){
            if(strcmp(array_of_strings[j], array_of_strings[j+1]) > 0){
            //swap array_of_strings[j] and array_of_strings[j+1]
            strcpy(temp, array_of_strings[j]);
            strcpy(array_of_strings[j], array_of_strings[j+1]);
            strcpy(array_of_strings[j+1], temp);
            }
        }
    }
    for(int i=0; i<count; i++){
        printf("%s \n", array_of_strings[i]);
    }
    return 0;
}