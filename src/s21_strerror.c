#include "s21_string.h"

char *s21_strerror(int errnum) {
    static char res[100] = {0};
    ARRAY;
    int flag = 0;
    for (int i = 0; i < ERR_MAX; i++) {
        if (errnum == i) {
            s21_strcpy(res, errlist[i]);
            flag = -1;
        }
    }
    if (flag == 0) {
        char str[100] = ERROR;
        char errnum_str[100];
        itoa(errnum, errnum_str);
        char *tmp = s21_strcat(str, errnum_str);
        s21_strcpy(res, tmp);
    }
    return res;
}
