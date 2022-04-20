#include <stdio.h>
int main()
{
    int arr1[] = {2, 3, 4, 5, 6};
    char array_of_strings[10][10] = {}, ch;
    int arr[10] = {};
    int count = 0;
    do{
        scanf(" %s", &array_of_strings[count]);
        scanf("%d", &arr[count]);
        count++;
    }while((ch = getchar()) != EOF && count < 11);
    for(int i=0; i<count; i++){
        if(arr[i] < 10) continue;
        printf("%s %d\n", array_of_strings[i], arr[i]);
    }
    return 0;
}
