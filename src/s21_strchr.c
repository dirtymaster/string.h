#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
    char *res = NULL;
    c = (char)c;
    for (int i = 0; i < (int)s21_strlen(str) + 1; i++) {
        if (str[i] == c) {
            res = (char *)&str[i];
            break;
        }
    }
    return res;
}
