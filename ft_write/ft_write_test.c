#include <stdio.h>
#include <unistd.h>

int ft_write(int fd, const char* str, size_t size);

int main(void) {

    int ret = 0;
    const char* str = "hello world\n";

    printf("orig: \n");
    ret = write(1, str, 12);
    printf("ret: %i\n\n", ret);

    printf("asm: \n");
    ret = ft_write(1, str, 12);
    printf("ret: %i\n", ret);

    return (0);
}
