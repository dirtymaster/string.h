#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    unsigned char *buff1 = (unsigned char *)str1;
    unsigned char *buff2 = (unsigned char *)str2;
    int result = 0;
    for (s21_size_t i = 0; i < n; i++) {
        if (buff1[i] != buff2[i]) {
            if (buff1[i] > buff2[i]) {
                result = 1;
            } else {
                result = -1;
            }
            i = n + 1;
        }
    }
    return result;
}
