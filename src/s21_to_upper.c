#include "s21_string.h"

void *s21_to_upper(const char *str) {
    char *res = s21_NULL;
    if (str != s21_NULL) {
        int size = s21_strlen(str) + 1;
        res = malloc(size * sizeof(char));
        int i;
        for (i = 0; str[i]; i++) {
            if (str[i] >= 97 && str[i] <= 122) {
                res[i] = str[i] - 32;
            } else {
                res[i] = str[i];
            }
        }
        res[i] = '\0';
    }
    return res;
}
