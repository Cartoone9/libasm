#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char* s);

int main(void) {

    const char* t[] = {"", "a", "hi", "hello world", NULL};

    for (int i = 0; t[i]; i++)
        printf("%zu vs %zu\n", ft_strlen(t[i]), strlen(t[i]));

    return (0);
}
