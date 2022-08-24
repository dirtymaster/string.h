#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *string = (unsigned char *)str;
    unsigned char *res = s21_NULL;
    for (unsigned long i = 0; i != n; i++) {
        string[i] = c;
    }
    res = string;
    return res;
}
