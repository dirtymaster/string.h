#include "s21_string.h"

void *s21_to_lower(const char *str) {
    char *res = s21_NULL;
    if (str != s21_NULL) {
        int size = s21_strlen(str) + 1;
        int i;
        res = malloc(size * sizeof(char));
        for (i = 0; str[i]; i++) {
            if (str[i] <= 90 && str[i] >= 65) {
                res[i] = str[i] + 32;
            } else {
                res[i] = str[i];
            }
        }
        res[i] = '\0';
    }
    return res;
}
