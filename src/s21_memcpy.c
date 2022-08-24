#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    unsigned char *dest_str = (unsigned char *)dest;
    unsigned char *src_str = (unsigned char *)src;
    if (dest_str != s21_NULL && src_str != s21_NULL) {
        for (s21_size_t i = 0; i < n; i++) {
            dest_str[i] = src_str[i];
        }
    }
    return dest_str;
}
