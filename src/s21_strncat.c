#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    int last = s21_strlen(dest);
    for (s21_size_t i = 0; i < n; i++) {
        dest[last] = src[i];
        last++;
    }
    dest[last] = '\0';
    return dest;
}
