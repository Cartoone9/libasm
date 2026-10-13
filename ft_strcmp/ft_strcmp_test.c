#include <stdio.h>
#include <string.h>

int ft_strcmp(const char* s1, const char* s2);

int main(void) {

    const char* s1 = "hello world";
    const char* s2 = "goodbye spacecowboy";

    printf("s1 vs s1: orig[%i] asm[%i]\n", strcmp(s1, s1), ft_strcmp(s1, s1));
    printf("s2 vs s2: orig[%i] asm[%i]\n", strcmp(s2, s2), ft_strcmp(s2, s2));
    printf("s1 vs s2: orig[%i] asm[%i]\n", strcmp(s1, s2), ft_strcmp(s1, s2));

    return (0);
}
