#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
    int res = 0;
    while (*str1 == *str2 && (*str1 != '\0' || *str2 != '\0')) {
        str1 += 1;
        str2 += 1;
    }
    if (*str1 != *str2) res = *str1 - *str2;
    return res;
}
