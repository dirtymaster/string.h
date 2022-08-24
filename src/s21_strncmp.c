#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    for (s21_size_t i = 0; *str1 == *str2 && i < n - 1; i++) {
        str1++;
        str2++;
    }
    return n == 0 ? 0 : (*str1 - *str2);
}
