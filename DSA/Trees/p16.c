#include<stdio.h>
int ret(int num){
    while(num > 0){
        return (num + ret(num-2));
    }
    return num;
}
int main() {
    char wish[] = "harikesh";
    char *p;
    p = wish;
    p+=2;
    printf("%s", p);
    char name[3][10] = {"maruti", "BMW", "bugati"};
    for(int i = 0; i < 3; i++)
        printf(name[i]);
    
    printf(ret(10));
    return 0;
}