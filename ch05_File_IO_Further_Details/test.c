#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"
int main(int argc, char *argv[]) {
    if (argc < 2 || strcmp(argv[1], "--help") == 0) {
        usageErr("%s file\n", argv[0]);
    }
    
    int fd = open(argv[1], O_RDWR, S_IRUSR|S_IWUSR);
    if (fd == -1) {
        errExit("open");
    }

    int flags = fcntl(fd, F_GETFL);
    printf("flags:%d\n", flags);
    flags |= O_APPEND;
    if (fcntl(fd, F_SETFL, flags) == -1) {
        errExit("fcntl");
    }
    printf("flags:%d\n", flags);
    //复制文件描述符
    int new_fd = dup(fd); 
    int new_fd2 = dup2(fd, 1234); //new_fd2==1234
    int new_fd_fcntl = fcntl(fd, F_DUPFD, 10240); // new_fd_fcntl >= 10240
    //#define _GNU_SOURCE
    //int new_fd3 = dup3(fd, 1234, O_CLOEXEC);
    printf("oldfd:%d, new_fd:%d, new_fd2:%d, new_fd_fcntl:%d\n", fd, new_fd, new_fd2, new_fd_fcntl);
    
    char tmp[10240] = {0};
    off_t ori_off = lseek(fd, 0, SEEK_CUR);
    pread(fd, tmp, 10, 2);
    off_t aft_off = lseek(fd, 0, SEEK_CUR);
    printf("read buf:%s, off:%ld,%ld", tmp, ori_off, aft_off);
    
    exit(EXIT_SUCCESS);
}
