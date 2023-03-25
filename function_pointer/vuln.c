#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void backdoor(){
    printf("Function pointer overwritten!\n");
    int fd;
    char buf[0x04];
    fd = open("./data", O_RDONLY);
    read(fd, buf, 0x04);
    write(1, buf, 0x04);
};

void func(){
    printf("Hello World!\n");
};

void vuln(){
    volatile void (*fp)() = &func;
    char buf[0x10];

    read(0, buf, 0x20); // bof

    fp();
}

void main(){
    setvbuf(stdin, 0, _IONBF, 0);
    setvbuf(stdout, 0, _IONBF, 0);
    
    vuln();
}
