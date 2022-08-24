#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    struct token tok;
    const char *start = str;
    char *f = (char *)format;
    while (*f != '\0') {
        if (*f != '%') {
            *str = *f;
            str++;
            f++;
        } else {
            init(&tok);
            f++;
            while (*f == '-' || *f == '+' || *f == ' ' || *f == '#' ||
                    *f == '0') {
                if (*f == '-')
                    tok.flag_minus = 1;
                else if (*f == '+')
                    tok.flag_plus = 1;
                else if (*f == ' ')
                    tok.flag_space = 1;
                else if (*f == '#')
                    tok.flag_grid = 1;
                else if (*f == '0')
                    tok.flag_zero = 1;
                f++;
            }
            while ((*f >= '0' && *f <= '9') || *f == '*') {
                if (*f >= '0' && *f <= '9')
                    tok.wight = tok.wight * 10 + (*f - '0');
                else if (*f == '*')
                    tok.wight = va_arg(args, int);
                f++;
            }
            if (*f == '.') {
                tok.accur = 0;
                f++;
                while ((*f >= '0' && *f <= '9') || *f == '*') {
                    if (*f >= '0' && *f <= '9')
                        tok.accur = tok.accur * 10 + (*f - '0');
                    else if (*f == '*')
                        tok.accur = va_arg(args, int);
                    f++;
                }
            }
            if (*f == 'h' || *f == 'l' || *f == 'L') tok.lenght = *f++;
            if (*f == 'c' || *f == 'd' || *f == 'i' || *f == 'e' || *f == 'E' ||
                *f == 'f' || *f == 'g' || *f == 'G' || *f == 'o' || *f == 's' ||
                *f == 'u' || *f == 'x' || *f == 'X' || *f == 'p' || *f == 'n') {
                tok.spec = *f++;
            } else if (*f == '%') {
                *str = *f;
                str++;
                f++;
            }
            badflags(&tok);
            if (tok.spec == 'c') {
                if (tok.lenght == 'l')
                    str = c_sprintf(&tok, str, (int)va_arg(args, wchar_t));
                else
                    str = c_sprintf(&tok, str, va_arg(args, int));
            } else if (tok.spec == 'd' || tok.spec == 'i') {
                if (tok.lenght == 'l')
                    str = ld_sprintf(&tok, str, va_arg(args, long int));
                else
                    str = d_sprintf(&tok, str, va_arg(args, int));
            } else if (tok.spec == 's') {
                if (tok.lenght == 'l') {
                    wchar_t *y = va_arg(args, wchar_t *);
                    str = ls_sprintf(&tok, str, y);
                } else {
                    char *x = va_arg(args, char *);
                    str = s_sprintf(&tok, str, x);
                }
            } else if (tok.spec == 'n') {
                n_sprintf(str, start, va_arg(args, int *));
            } else if (tok.spec == 'o' || tok.spec == 'x' || tok.spec == 'X') {
                if (tok.lenght == 'l')
                    str = loxX_sprintf(&tok, str, va_arg(args, long int));
                else
                    str = oxX_sprintf(&tok, str, va_arg(args, int));
            } else if (tok.spec == 'u') {
                str = u_sprintf(&tok, str, va_arg(args, s21_size_t));
            } else if (tok.spec == 'f') {
                str = f_sprintf(&tok, str, va_arg(args, double));
            } else if (tok.spec == 'p') {
                str = p_sprintf(str, va_arg(args, void *));
            }
        }
    }
    int result = str - start;
    va_end(args);
    return result;
}

void utoa(s21_size_t n, char *str) {
    int i = 0;
    if (n == 0) {
        str[i] = n + '0';
        i++;
    } else {
        while (n > 0) {
            str[i] = n % 10 + '0';
            i++;
            n /= 10;
        }
    }
    str[i] = '\0';
    reverse(str);
}

void ltoa(long int n, char *str, struct token *tok) {
    int i = 0;
    if (n < 0) {
        n = n * -1;
    }
    while (n > 0) {
        str[i++] = n % 10 + '0';
        n /= 10;
    }
    if (tok->negative == 1) {
        str[i++] = '-';
    }
    str[i] = '\0';
    reverse(str);
}

void flag_grid(char *c, struct token *tok, int i) {
    c[i++] = '0';
    if (tok->spec == 'x')
        c[i++] = 'x';
    else if (tok->spec == 'X')
        c[i++] = 'X';
}

void flag_minus(char *c, struct token *tok) {
    char temp[1024] = {};
    int i = 0;
    if (tok->accur > -1) {
        if (tok->flag_plus && c[0] != '-' && !tok->minus) temp[i++] = '+';
        tok->flag_plus = 0;
    }
    if (tok->flag_grid && !tok->flag_zero &&
        (tok->spec == 'o' || tok->spec == 'x' || tok->spec == 'X')) {
        int x = i;
        flag_grid(temp, tok, x);
    }
    if (tok->minus) {
        temp[i++] = '-';
        s21_strcat(temp, c);
    } else if (tok->flag_plus) {
        tok->flag_space = 0;
        temp[i++] = '+';
        s21_strcat(temp, c);
    } else if (tok->flag_space) {
        temp[i++] = ' ';
        s21_strcat(temp, c);
    } else {
        s21_strcat(temp, c);
    }
    int len = s21_strlen(temp);
    if (tok->wight < len) tok->wight = len;
    while (len < tok->wight) temp[len++] = ' ';
    temp[len] = '\0';
    s21_strcpy(c, temp);
}

void flag_plus_spase(char *c, struct token *tok) {
    char buf[1024] = {};
    int i = 0;
    if (tok->flag_grid && (tok->spec == 'o' || tok->spec == 'x' || tok->spec == 'X'))
        flag_grid(buf, tok, i);
    i = 0;
    if (tok->flag_plus) {
        tok->flag_space = 0;
        buf[i++] = '+';
    }
    if (tok->flag_space) buf[i++] = ' ';
    s21_strcat(buf, c);
    i = 0;
    while (buf[i]) *c++ = buf[i++];
    *c = '\0';
}

void accur_s(char *c, struct token *tok) {
    char buf[1024] = {};
    int len = s21_strlen(c);
    int i = 0;
    if (tok->accur < len) {
        len = tok->accur;
    }
    while (len > 0) {
        buf[i++] = *c++;
        len--;
    }
    s21_strcpy(c, buf);
    *c = '\0';
}

void accur_d(char *str, struct token *tok) {
    tok->accur_spec_d = 1;
    tok->flag_zero = 0;
    char temp_in[1024] = {};
    char *c = temp_in;
    s21_strcpy(c, str);
    int len = s21_strlen(temp_in);
    int min = 0;
    char temp[1024] = {};
    char *b = temp;
    if (c[0] == '-') {
        min = 1;
        c[0] = '0';
    }
    if (tok->accur > len) {
        int i = 0;
        if (tok->flag_grid && tok->spec == 'o') len++;
        if (min && tok->accur >= len + 1) {
            b[i++] = '-';
        }
        while (len != tok->accur) {
            b[i++] = '0';
            len++;
        }
        b[i] = '\0';
        s21_strcat(b, c);
        s21_strcpy(str, b);
    }
}

void wight(char *c, struct token *tok) {
    char buf[1024] = {};
    int len = s21_strlen(c);
    int i = 0;
    int W = tok->wight;
    if ((tok->minus || tok->flag_plus) && tok->wight <= len) {
        if (tok->minus)
            buf[i++] = '-';
        else if (tok->flag_plus)
            buf[i++] = '+';
    }
    if (tok->flag_space && !tok->minus && !tok->flag_plus) {
        buf[i++] = ' ';
        W--;
    }
    if (tok->minus && tok->flag_zero) {
        buf[i++] = '-';
        W--;
    }
    if (tok->flag_plus && !tok->minus && tok->flag_zero) {
        buf[i++] = '+';
        W--;
    }
    while (W-- > len) {
        if (tok->flag_zero && tok->spec != 'c' && tok->spec != 's' &&
            tok->spec != 'n' && tok->spec != 'p')
            buf[i++] = '0';
        else
            buf[i++] = ' ';
    }
    if (tok->minus && !tok->flag_zero) buf[i - 1] = '-';
    if (tok->flag_plus && !tok->minus && !tok->flag_zero) {
        if (tok->accur > -1 && c[0] != '-')
            buf[i - 1] = '+';
        else
            buf[i - 1] = '+';
    }
    s21_strcat(buf, c);
    i = 0;
    while (buf[i]) *c++ = buf[i++];
    *c = '\0';
}

void wight_oxX(char *c, struct token *tok) {
    char buf[1024] = {};
    int len = s21_strlen(c);
    int i = 0;
    int W = tok->wight;
    if (tok->flag_grid) {
        if (tok->spec == 'o') W--;
        if (tok->spec == 'x' || (tok->spec == 'X')) W -= 2;
    }
    if (!tok->flag_zero) {
        while (W-- > len) buf[i++] = ' ';
    }
    if (tok->flag_grid) {
        flag_grid(buf, tok, i);
        if (tok->spec == 'o')
            i += 1;
        else if (tok->spec == 'x' || tok->spec == 'X')
            i += 2;
    }
    if (tok->flag_zero) {
        while (W-- > len) buf[i++] = '0';
    }
    s21_strcat(buf, c);
    i = 0;
    while (buf[i]) *c++ = buf[i++];
}

void lenght(int x, char *str, struct token *tok) {
    if (tok->lenght == 'h') x = (short)x;
    itoa((int)x, str);
}

void format(struct token *tok, char *str) {
    if (tok->spec == 's') {
        if (tok->accur > 0) accur_s(str, tok);
        if (tok->accur == 0) *str = '\0';
    } else if (tok->accur > 0) {
        accur_d(str, tok);
    }
    if (tok->wight > 0 && !tok->flag_minus &&
        (tok->spec == 'o' || tok->spec == 'x' || tok->spec == 'X'))
        wight_oxX(str, tok);
    else if (tok->wight > 0 && !tok->flag_minus)
        wight(str, tok);
    else if (tok->flag_minus && tok->wight > 0)
        flag_minus(str, tok);
    if (!tok->wight && tok->negative == 0 && (tok->flag_plus || tok->flag_space))
        flag_plus_spase(str, tok);
    if (!tok->wight && tok->flag_grid &&
        (tok->spec == 'o' || tok->spec == 'x' || tok->spec == 'X'))
        flag_plus_spase(str, tok);
}

void format_f(struct token *tok, char *str, int num) {
    if (tok->wight > 0 && !tok->flag_minus)
        wight(str, tok);
    else if (tok->flag_minus && tok->wight > 0)
        flag_minus(str, tok);
    if (!tok->wight && num >= 0 && (tok->flag_plus || tok->flag_space))
        flag_plus_spase(str, tok);
}

char *d_sprintf(struct token *tok, char *str, int num) {
    char arr[1024];
    char *c = arr;
    if (num < 0 && tok->wight && tok->accur == -1) {
        tok->minus = 1;
        num *= -1;
    }
    if (tok->lenght == 'h')
        lenght(num, arr, tok);
    else
        itoa(num, arr);
    if (tok->accur == 0 && num == 0) *c = '\0';
    format(tok, arr);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

char *ld_sprintf(struct token *tok, char *str, long int num) {
    char arr[1024];
    char *c = arr;
    if (num == LLONG_MIN) {
        c = "-9223372036854775808";
    } else {
        if (num < 0) tok->negative = 1;
        ltoa(num, arr, tok);
    }
    format(tok, arr);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

char *oxX_sprintf(struct token *tok, char *str, int num) {
    char arr[1024] = {};
    char *c = arr;
    if (num == 0) {
        int i = 0;
        arr[i++] = num + '0';
        tok->flag_grid = 0;
    } else if (tok->spec == 'o') {
        convert(num, 8, tok, c);
        if (num < 0 && tok->lenght == 'h') {
            c += 5;
            *c = '1';
        }
    } else if (tok->spec == 'x' || tok->spec == 'X') {
        convert(num, 16, tok, c);
        if (num < 0 && tok->lenght == 'h') c += 4;
    }
    if (tok->accur == 0 && num == 0) *c = '\0';
    format(tok, arr);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

void convert(unsigned int num, int x, struct token *tok, char *str) {
    const char arr[] = "0123456789abcdef";
    const char arr1[] = "0123456789ABCDEF";
    int i = 0;
    char buf[1024] = {};
    if (tok->spec == 'x' || tok->spec == 'o') {
        while (num != 0 && x != 0) {
            buf[i++] = arr[num % x];
            num /= x;
        }
    }
    if (tok->spec == 'X') {
        while (num != 0 && x != 0) {
            buf[i++] = arr1[num % x];
            num /= x;
        }
    }
    buf[i] = '\0';
    reverse(buf);
    s21_strcat(str, buf);
}

char *loxX_sprintf(struct token *tok, char *str, long int num) {
    char arr[1024] = {};
    char *c = arr;
    if (tok->spec == 'o' && num != 0) {
        convert_f_long(num, 8, tok, c);
    } else if ((tok->spec == 'x' || tok->spec == 'X') && num != 0) {
        convert_f_long(num, 16, tok, c);
    }
    format(tok, arr);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

void convert_f_long(unsigned long int num, int x, struct token *tok, char *str) {
    const char arr[] = "0123456789abcdef";
    const char arr1[] = "0123456789ABCDEF";
    int i = 0;
    char buf[1024] = {};
    if (tok->spec == 'x' || tok->spec == 'o') {
        while (num != 0 && x != 0) {
            buf[i++] = arr[num % x];
            num /= x;
        }
    }
    if (tok->spec == 'X') {
        while (num != 0 && x != 0) {
            buf[i++] = arr1[num % x];
            num /= x;
        }
    }
    buf[i] = '\0';
    reverse(buf);
    s21_strcat(str, buf);
}

char *c_sprintf(struct token *tok, char *str, int C) {
    char arr[1024] = {};
    char *c = arr;
    *c = (char)C;
    if (tok->wight > 0 && !tok->flag_minus)
        wight(c, tok);
    else if (tok->flag_minus && tok->wight > 0)
        flag_minus(c, tok);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

char *s_sprintf(struct token *tok, char *str, char *C) {
    char arr[1024] = {};
    int i = 0;
    while (*C) arr[i++] = *C++;
    char *c = arr;
    format(tok, c);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

char *ls_sprintf(struct token *tok, char *str, wchar_t *C) {
    char arr[1024] = {};
    char temp[1024] = {};
    char *c = temp;
    int i = 0;
    while (C[i] != '\0') {
        arr[i] = (char)C[i];
        i++;
    }
    int len = s21_strlen(arr);
    i = 0;
    while (len) {
        c[i] = arr[i];
        i++;
        len--;
    }
    format(tok, c);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

char *u_sprintf(struct token *tok, char *str, s21_size_t num) {
    if (tok->accur > tok->wight) {
        tok->wight = tok->accur;
        tok->flag_zero = 1;
    }
    char arr[1024];
    char *c = arr;
    utoa(num, arr);
    format(tok, arr);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

char *p_convert(long x, int hex) {
    long num = x;
    const char arr[] = "0123456789abcdef";
    static char buffer[1024];
    char *ptr = buffer;
    while (num != 0 && hex != 0) {
        *--ptr = arr[num % hex];
        num /= hex;
    }
    return (ptr);
}

void *p_sprintf(char *str, void *ptr) {
    static char string_pointer[1024] = "0x";
    char *p = string_pointer;
    long x = (long)ptr;
    char *buf = p_convert(x, 16);
    s21_strcat(string_pointer, buf);
    while (*p) *str++ = *p++;
    *str = '\0';
    return str;
}

void n_sprintf(const char *str, const char *start, int *path) {
    *path = str - start;
}

void init(struct token *tok) {
    tok->flag_plus = 0;
    tok->flag_minus = 0;
    tok->flag_space = 0;
    tok->flag_grid = 0;
    tok->flag_zero = 0;
    tok->wight = 0;
    tok->accur = -1;
    tok->accur_spec_d = 0;
    tok->minus = 0;
    tok->lenght = '0';
    tok->spec = '0';
    tok->negative = 0;
}

void badflags(struct token *tok) {
    if (tok->spec == 'c') {
        tok->flag_plus = tok->flag_space = tok->flag_grid = tok->flag_zero = 0;
        tok->accur = -1;
        if (tok->lenght == 'h' || tok->lenght == 'L') tok->lenght = '0';
    } else if (tok->spec == 'd' || tok->spec == 'i') {
        tok->flag_grid = 0;
        if (tok->lenght == 'L') tok->lenght = '0';
        if (tok->flag_minus && tok->flag_zero) tok->flag_minus = tok->flag_zero = 0;
        if (tok->flag_space && tok->flag_plus) tok->flag_space = 0;
    } else if (tok->spec == 's') {
        tok->flag_plus = tok->flag_space = tok->flag_grid = tok->flag_zero = 0;
        if (tok->lenght == 'h' || tok->lenght == 'L') tok->lenght = '0';
    } else if (tok->spec == 'o' || tok->spec == 'x' || tok->spec == 'X') {
        tok->flag_plus = tok->flag_space = 0;
        if (tok->flag_minus && tok->flag_zero) tok->flag_minus = tok->flag_zero = 0;
        if (tok->lenght == 'L') tok->lenght = '0';
    } else if (tok->spec == 'u') {
        tok->flag_plus = tok->flag_grid = tok->flag_space = 0;
        if (tok->lenght == 'L') tok->lenght = '0';
    } else if (tok->spec == 'p') {
        tok->flag_plus = tok->flag_grid = tok->flag_space = tok->flag_zero = 0;
    }
}

char *f_sprintf(struct token *tok, char *str, long double num) {
    if (tok->accur == -1) tok->accur = 6;
    if (num < 0 && tok->wight) {
        tok->minus = 1;
        num *= -1;
    }
    char arr[1024] = {};
    char *c = arr;
    int celoe = 0;
    celoe = !tok->accur ? (int)round(num) : (int)num;
    itoa(celoe, c);
    if (tok->flag_grid || tok->accur) s21_strcat(c, ".");
    if (tok->accur) {
        long double ostatok = num - (int)num;
        int acc = tok->accur;
        while (acc--) ostatok *= 10;
        char fl[1024] = {};
        char *f = fl;
        itoa(abs((int)round(ostatok)), f);
        int len = s21_strlen(f);
        while (len++ < tok->accur) s21_strcat(c, "0");
        s21_strcat(c, f);
    }
    format_f(tok, c, num);
    while (*c) {
        *str = *c;
        str++;
        c++;
    }
    *str = '\0';
    s21_strcat(str, c);
    return str;
}

void itoa(int n, char *str) {
    int i = 0;
    long int x = n;
    if (n < 0) x *= -1;
    if (!x) str[i++] = '0';
    while (x > 0) {
        str[i] = x % 10 + '0';
        i++;
        x /= 10;
    }
    if (n < 0) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    reverse(str);
}

void reverse(char *str) {
    int k, j;
    for (k = 0, j = s21_strlen(str) - 1; k < j; k++, j--) {
        char buf = str[k];
        str[k] = str[j];
        str[j] = buf;
    }
}

