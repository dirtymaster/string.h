#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t count = 0;
    for (s21_size_t i = 0; str1[i] != '\0'; i++) {
        for (s21_size_t j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                i = 404;
            }
        }
        if (i == 404) {
            break;
        }
        count++;
    }
    return count;
}
