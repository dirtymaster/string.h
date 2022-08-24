#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *res = s21_NULL;
    if (src) {
        if (s21_strlen(src) >= start_index) {
            if (str) {
                s21_size_t src_len = s21_strlen(src);
                s21_size_t str_len = s21_strlen(str);
                s21_size_t len = src_len + str_len;
                res = (char *)calloc(len, SIZE_CHAR);
                if (res != s21_NULL) {
                    s21_size_t j = 0;
                    for (s21_size_t i = 0; i < len; i++) {
                        if (i == start_index) {
                            for (s21_size_t str_i = 0; str_i < str_len;
                                 str_i++) {
                                res[j] = str[str_i];
                                j++;
                            }
                        }
                        res[j] = src[i];
                        j++;
                    }
                }
            }
        }
    }
    return res;
}
