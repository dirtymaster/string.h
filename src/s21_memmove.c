#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    unsigned char *dest_str = (unsigned char *)dest;
    unsigned char *src_str = (unsigned char *)src;
    unsigned char tmp_str[n];
    for (s21_size_t i = 0; i < n; i++) {
        tmp_str[i] = src_str[i];
    }
    for (s21_size_t i = 0; i < n; i++) {
        dest_str[i] = tmp_str[i];
    }
    return dest_str;
}
