#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
    char *res = s21_NULL;
    if (src != s21_NULL && trim_chars != s21_NULL) {
        int size = s21_strlen(src) + 1;
        res = malloc(size * sizeof(char));
        int i = 0, k = size - 2, flag = 1, l;
        while (src[i] && flag) {
            flag = 0;
            for (int j = 0; trim_chars[j]; j++) {
                if (src[i] == trim_chars[j]) {
                    flag = 1;
                    i++;
                    break;
                }
            }
        }
        flag = 1;
        while (k >=0 && flag) {
            flag = 0;
            for (int j = 0; trim_chars[j]; j++) {
                if (src[k] == trim_chars[j]) {
                    flag = 1;
                    k--;
                    break;
                }
            }
        }
        k = k - i;
        for (l = 0; l <= k; i++, l++)
            res[l] = src[i];
        res[l] = '\0';
    }
    return res;
}
