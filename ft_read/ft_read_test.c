#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ERROR -1
#define SIZE 42

ssize_t ft_read(int fd, void* buf, size_t count);

int open_file(void) {

    int fd = open("example.txt", O_RDONLY);
    if (fd == ERROR) {
        char* err = "open failed";
        write(2, err, strlen(err));
        exit(1);
    }
    return (fd);
}

int close_file(int fd) {

    close(fd);
    if (fd == ERROR) {
        char* err = "close failed";
        write(2, err, strlen(err));
        exit(1);
    }

    return (0);
}

int clear_buffer(char* buffer) {

    for (int i = 0; i < SIZE; i++) {
        buffer[i] = 0;
    }
    return (0);
}

int main(void) {

    char buffer[SIZE];
    int fd = open_file();

    clear_buffer(buffer);

    printf("orig:\n");
    printf("read: %zd bytes\n", read(fd, buffer, SIZE));
    printf("buffer: '%s'\n\n", buffer);

    close_file(fd);
    fd = open_file();

    clear_buffer(buffer);

    printf("asm:\n");
    printf("read: %zd bytes\n", ft_read(fd, buffer, SIZE));
    printf("buffer: '%s'\n", buffer);

    return (0);
}
