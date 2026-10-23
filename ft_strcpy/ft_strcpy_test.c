#include <stdio.h>
#include <string.h>

char* ft_strcpy(char* dest, const char* src);

int main(void) {

    const char* src = "hello world";
    char a[64], b[64];

    char* ptr_a = strcpy(a, src);
    char* ptr_b = ft_strcpy(b, src);

    printf("orig[%s] vs asm[%s]\n", a, b);
    printf("both func returns correct ptr ? %d\n", ptr_a == a && ptr_b == b);

    return (0);
}
