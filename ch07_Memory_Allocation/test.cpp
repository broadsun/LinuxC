#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct myStruct {
    int a;
    int b;
};
int main(int argc, char *argv[]) {
    printf("current program break is %p\n", sbrk(0));
    struct myStruct *p;
    p = (myStruct*)calloc(10000, sizeof(myStruct)); 
    printf("current program break is %p\n", sbrk(0));
    p = (myStruct*)alloca(sizeof(myStruct));
    printf("current program break is %p\n", sbrk(0));
    return 0;
}

