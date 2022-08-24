#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t res = 0;
    for (; *str1; str1++, res++) {
        const char *p;
        p = str2;
        while (*p != *str1 && *p) p++;
        if (!*p) return res;
    }
    return res;
}
