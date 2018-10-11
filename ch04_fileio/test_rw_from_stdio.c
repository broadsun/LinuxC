#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#define MAX_BUFFER 10

int main(int argc, char * argv[]) {
    char buffer[MAX_BUFFER+1] = {1};
    ssize_t numRead = read(STDIN_FILENO,  buffer, MAX_BUFFER);
    write(STDOUT_FILENO, buffer, numRead);
    return 0;
}
