#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {

    int openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    int filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH;      /* rw-rw-rw- */
    int fd = open(argv[1], openFlags, filePerms);
    char buffer[10240] = "123abc";
    ssize_t numWrite = write(fd, buffer, 10240);
    lseek(fd, 100, SEEK_END);

    write(fd, buffer, 10240);
    

    close(fd);
    
    fd = open(argv[1], O_RDONLY);
    ssize_t numRead = 0;
    int fw = open(argv[2], openFlags, filePerms);
    char tmp[10240] = {0};
    while ((numRead = read(fd, tmp, 10240))!=0) {
        write(fw, tmp, numRead);
    }
    close(fd);
    close(fw);

    return 0;

}
