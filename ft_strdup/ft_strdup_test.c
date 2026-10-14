#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ft_strdup(const char* str);

int main(void) {

    const char* str = "Hello world !";

    char* dup1 = strdup(str);
    printf("orig: %s\n", dup1);
    free(dup1);

    char* dup2 = ft_strdup(str);
    printf("asm: %s\n", dup2);
    free(dup2);

    return (0);
}
