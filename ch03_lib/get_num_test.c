#include "get_num.h"
#include "get_num.c"
#include "error_functions.h"
#include <stdio.h>
int main(int argc, char* argv[]) {
    //fatal("%s,xxoo,%s", "sgb", "syc");
    errMsg("%s,xxoo,%s", "sgb", "syc");   
    printf("%d\n", EXIT_SUCCESS);
    gnFail("fname1", "msg1", argv[1], "name1"); 
    int xx = getInt(argv[1], 0100, "xxx") ;
    printf("%d\n", xx);
    return 0;
}
