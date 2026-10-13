#include <stdio.h>
#include <string.h>

char* ft_strcpy(char* dest, const char* src);

int main(void) {

    const char* src = "hello world";
    char a[64], b[64];

    char* ra = ft_strcpy(a, src);
    char* rb = strcpy(b, src);

    printf("[%s] vs [%s]\n", a, b);
    printf("ret %d\n", ra == a && rb == b);

    return (0);
}
