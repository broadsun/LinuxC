#include "get_num.h"
#include <stdio.h>
int main(int argc, char* argv[]) {
    int xx = getInt(argv[1], 0100, "xxx") ;
    printf("%d\n", xx);
    return 0;
}
