#include "s21_string.h"

char *s21_strrchr(const char *str, s21_size_t c) {
    int i = 1;
    char *res = s21_NULL;
    while (str[i - 1] != 0) i++;
    while (i-- != 0) {
        if (str[i] == (char)c) {
            res = (char *)str + i;
            break;
        }
    }
    return res;
}
