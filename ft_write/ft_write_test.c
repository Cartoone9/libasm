#include <stdio.h>
#include <string.h>
#include <unistd.h>

int ft_write(int fd, const char* str, size_t size);

int main(void) {

    int ret = 0;
    const char* s[] = {"hello world\n", "goodbye spacecowboy\n", "abcdef 123\n"};
    const int len = sizeof(s) / sizeof(s[0]);

    printf("orig: \n");
    for (int i = 0; i < len; i++) {
        ret = write(1, s[i], strlen(s[i]));
        printf("ret: %i\n", ret);
    }

    printf("\nasm: \n");
    for (int i = 0; i < len; i++) {
        ret = ft_write(1, s[i], strlen(s[i]));
        printf("ret: %i\n", ret);
    }

    return (0);
}
