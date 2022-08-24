#include <check.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "s21_string.h"

START_TEST(memchr_test) {
    char *s1 = "This is a s21_memchr test";

    ck_assert_ptr_eq(s21_memchr(s1, 's', 0), memchr(s1, 's', 0));
    ck_assert_ptr_eq(s21_memchr(s1, 's', 2), memchr(s1, 's', 2));
    ck_assert_ptr_eq(s21_memchr(s1, 's', 50), memchr(s1, 's', 50));
    ck_assert_ptr_eq(s21_memchr(s1, 'u', 50), memchr(s1, 'u', 50));
    ck_assert_ptr_eq(s21_memchr(s1, 'u', 32), memchr(s1, 'u', 32));
}
END_TEST

START_TEST(memcmp_test) {
    char *s1 = "This is a 1st string s21_memcmp test";
    char *s2 = "This is a 2nd string s21_memcmp test";

    ck_assert_msg(s21_memcmp(s1, s2, 256) == memcmp(s1, s2, 256),
                  "1st memcmp test failed.");
    ck_assert_msg(s21_memcmp(s1, s2, 2) == memcmp(s1, s2, 2),
                  "2nd memcmp test failed.");
    ck_assert_msg(s21_memcmp(s1, s2, 123) == memcmp(s1, s2, 123),
                  "3rd memcmp test failed.");
    ck_assert_msg(s21_memcmp(s1, s2, 36) == memcmp(s1, s2, 36),
                  "4rth memcmp test failed.");
}
END_TEST

START_TEST(memcpy_test) {
    char *src1 = "schesrdsfdsfdsfesr";
    int len = s21_strlen(src1);
    char dest1[100] = {0};
    char dest2[100] = {0};
    char dest3[100] = {0};
    char dest4[100] = {0};
    char dest5[100] = {0};
    char dest6[100] = {0};
    char dest7[100] = {0};
    char dest8[100] = {0};
    char dest9[100] = {0};
    char dest10[100] = {0};

    s21_memcpy(dest1, src1, len + 1);
    memcpy(dest2, src1, len + 1);

    s21_memcpy(dest3, src1, 5);
    memcpy(dest4, src1, 5);

    s21_memcpy(dest5, src1, 0);
    memcpy(dest6, src1, 0);

    s21_memcpy(dest7, src1, 18);
    memcpy(dest8, src1, 18);

    s21_memcpy(dest9, src1, 1);
    memcpy(dest10, src1, 1);

    ck_assert_str_eq(dest1, dest2);
    ck_assert_str_eq(dest3, dest4);
    ck_assert_str_eq(dest5, dest6);
    ck_assert_str_eq(dest7, dest8);
    ck_assert_str_eq(dest9, dest10);
}
END_TEST

START_TEST(memmove_test) {
    char *src1 = "schesrdsfdsfdsfesr";
    int len = s21_strlen(src1);
    char dest1[100] = {0};
    char dest2[100] = {0};
    char dest3[100] = {0};
    char dest4[100] = {0};
    char dest5[100] = {0};
    char dest6[100] = {0};
    char dest7[100] = {0};
    char dest8[100] = {0};
    char dest9[100] = {0};
    char dest10[100] = {0};

    s21_memmove(dest1, src1, len + 1);
    memmove(dest2, src1, len + 1);

    s21_memmove(dest3, src1, 5);
    memmove(dest4, src1, 5);

    s21_memmove(dest5, src1, 0);
    memmove(dest6, src1, 0);

    s21_memmove(dest7, src1, 18);
    memmove(dest8, src1, 18);

    s21_memmove(dest9, src1, 1);
    memmove(dest10, src1, 1);

    ck_assert_msg(memcmp(dest1, dest2, len) == 0, "1st memmove test failed.");
    ck_assert_msg(memcmp(dest3, dest4, 5) == 0, "2nd memmove test failed.");
    ck_assert_msg(memcmp(dest5, dest6, 0) == 0, "3rd memmove test failed.");
    ck_assert_msg(memcmp(dest7, dest8, 18) == 0, "4rth memmove test failed.");
    ck_assert_msg(memcmp(dest9, dest10, 1) == 0, "5rth memmove test failed.");
}
END_TEST

START_TEST(memset_test) {
    char str1[] = "School is cool";
    char str2[] = "School-21";
    char str3[] = "amogus";
    char str4[] = "This is a string!";
    char str5[] = "Shrek";
    char res1[] = "School is cool";
    char res2[] = "School-21";
    char res3[] = "amogus";
    char res4[] = "This is a string!";
    char res5[] = "Shrek";

    s21_memset(str1, '_', 5);
    s21_memset(str2, '_', 4);
    s21_memset(str3, 'M', 2);
    s21_memset(str4, '-', 1);
    s21_memset(str5, 'S', 1);

    memset(res1, '_', 5);
    memset(res2, '_', 4);
    memset(res3, 'M', 2);
    memset(res4, '-', 1);
    memset(res5, 'S', 1);

    ck_assert_msg(memcmp(str1, res1, sizeof(str1)) == 0,
                  "1st memset test failed");
    ck_assert_msg(memcmp(str2, res2, sizeof(str2)) == 0,
                  "2nd memset test failed");
    ck_assert_msg(memcmp(str3, res3, sizeof(str3)) == 0,
                  "3rd memset test failed");
    ck_assert_msg(memcmp(str4, res4, sizeof(str4)) == 0,
                  "4rth memset test failed");
    ck_assert_msg(memcmp(str5, res5, sizeof(str5)) == 0,
                  "5rth memset test failed");
}
END_TEST

START_TEST(strcat_test) {
    char str1[21] = "TEST";
    char str2[8] = "strcat";
    char str3[9] = "function";
    char str4[1] = "";
    char str5[2] = " ";

    s21_strcat(str1, str5);
    ck_assert_msg(!memcmp(str1, "TEST ", 6), "1st strcat test failed");

    s21_strcat(str1, str2);
    ck_assert_msg(!memcmp(str1, "TEST strcat", 12), "2nd strcat test failed");

    s21_strcat(str1, str5);
    ck_assert_msg(!memcmp(str1, "TEST strcat ", 13), "3rd strcat test failed");

    s21_strcat(str1, str3);
    ck_assert_msg(!memcmp(str1, "TEST strcat function", 21),
                  "4rth strcat test failed");

    s21_strcat(str1, str4);
    ck_assert_msg(!memcmp(str1, "TEST strcat function", 21),
                  "5th strcat test failed");
}
END_TEST

START_TEST(strncat_test) {
    char str1[25] = "TEST";
    char str2[8] = "strncat";
    char str3[35] = "function";
    char str4[1] = "";
    char str5[30] = "amogus";

    s21_strncat(str1, str2, 3);
    ck_assert_msg(!memcmp(str1, "TESTstr", 8), "1st strncat test failed");

    s21_strncat(str1, str4, 3);
    ck_assert_msg(!memcmp(str1, "TESTstr", 8), "2nd strncat test failed");

    s21_strncat(str2, str4, 1);
    ck_assert_msg(!memcmp(str2, "strncat", 8), "3rd strncat test failed");

    s21_strncat(str5, str3, 3);
    ck_assert_msg(!memcmp(str5, "amogusfun", 10), "4rth strncat test failed");
}
END_TEST

START_TEST(strchr_test) {
    char *str1 = "TEST";
    char *str2 = "strchr";
    char *str3 = "function";
    char *str4 = "";
    char *str5 = "amogus";
    ck_assert_str_eq(s21_strchr(str1, 'E'), strchr(str1, 'E'));
    ck_assert_str_eq(s21_strchr(str3, 'i'), strchr(str3, 'i'));
    ck_assert_str_eq(s21_strchr(str5, 'a'), strchr(str5, 'a'));
    ck_assert_str_eq(s21_strchr(str1, 'E'), strchr(str1, 'E'));
    ck_assert_ptr_eq(s21_strchr(str2, 'E'), strchr(str2, 'E'));
    ck_assert_str_eq(s21_strchr(str3, 'i'), strchr(str3, 'i'));
    ck_assert_ptr_eq(s21_strchr(str4, ' '), strchr(str4, ' '));
    ck_assert_str_eq(s21_strchr(str5, 'a'), strchr(str5, 'a'));
}
END_TEST

START_TEST(strcmp_test) {
    char t1[] = "Sample Text";
    char t2[] = "Sample Text Plus Some Text";
    ck_assert_msg(s21_strcmp(t1, t2) == -32, "1st strcmp test failed");

    char t3[] = "AAA";
    char t4[] = "B";
    ck_assert_msg(s21_strcmp(t3, t4) == -1, "2nd strcmp test failed");

    char t5[] = "A\0BCD";
    char t6[] = "A";
    ck_assert_msg(s21_strcmp(t5, t6) == 0, "3rd strcmp test failed");

    char t7[] = "amogus";
    char t8[] = "m";
    ck_assert_msg(s21_strcmp(t7, t8) == -12, "4rth strcmp test failed");

    char t9[] = "shrek";
    char t10[] = "as";
    ck_assert_msg(s21_strcmp(t9, t10) == 18, "5th strcmp test failed");

    char t11[] = "бг";
    char t12[] = "бг";
    ck_assert_msg(s21_strcmp(t11, t12) == 0, "5th strcmp test failed");
}
END_TEST

START_TEST(strncmp_test) {
    char *t1 = "Sample Text";
    char *t2 = "Sample Text Plus Some Text";
    ck_assert_msg(!s21_strncmp(t1, t2, 10) && !strncmp(t1, t2, 10),
                  "1st strncmp test failed");

    ck_assert_msg(s21_strncmp(t1, t2, 14) < 0 && strncmp(t1, t2, 14) < 0,
                  "2nd strncmp test failed");
    char *t3 = "";
    char *t4 = "A";
    ck_assert_msg(s21_strncmp(t3, t4, 0) == 0 && strncmp(t3, t4, 0) == 0,
                  "3rd strncmp test failed");
    ck_assert_msg(s21_strncmp(t3, t4, 1) < 0 && strncmp(t3, t4, 1) < 0,
                  "3rd strncmp test failed");
    char *t5 = "ShrekAmogus";
    char *t6 = "Shr";
    ck_assert_msg(s21_strncmp(t5, t6, 5) > 0 && strncmp(t5, t6, 5) > 0,
                  "4rth strncmp test failed");
    ck_assert_msg(s21_strncmp(t5, t6, 0) == 0 && strncmp(t5, t6, 0) == 0,
                  "5th strncmp test failed");
}
END_TEST

START_TEST(strcpy_test) {
    char s1[50] = "Sample Text";
    char d1[50] = "";
    s21_strcpy(d1, s1);
    ck_assert_msg(!strcmp(d1, s1), "1st  strcpy test failed");

    char s2[50] = "AAAAA";
    char d2[50] = "NO";
    s21_strcpy(d2, s2);
    ck_assert_msg(!strcmp(d2, s2), "2nd strcpy test failed");

    char s3[50] = "";
    char d3[50] = "HELLO";
    s21_strcpy(d3, s3);
    ck_assert_msg(!strcmp(d3, s3), "3rd strcpy test failed");

    char s4[50] = "amogus";
    char d4[50] = "HELLO";
    s21_strcpy(d4, s4);
    ck_assert_msg(!strcmp(d4, s4), "4rth strcpy test failed");

    char s5[50] = "Shrek";
    char d5[50] = "what";
    s21_strcpy(d5, s5);
    ck_assert_msg(!strcmp(d5, s5), "5th strcpy test failed");
}
END_TEST

START_TEST(strncpy_test) {
    char s1[50] = "Sample Text";
    char d1[50] = "";
    s21_strncpy(d1, s1, 2);
    ck_assert_msg(!strcmp(d1, "Sa"), "1st strncpy test failed");

    char s2[50] = "AAAAA";
    char d2[50] = "NO";
    s21_strncpy(d2, s2, 0);
    ck_assert_msg(!strcmp(d2, "NO"), "2nd strncpy test failed");

    char s3[50] = "H";
    char d3[50] = "fELLO";
    s21_strncpy(d3, s3, 1);
    ck_assert_msg(!strcmp(d3, "HELLO"), "3rd strncpy test failed");

    char s4[50] = "amo";
    char d4[50] = "qwegus";
    s21_strncpy(d4, s4, 3);
    ck_assert_msg(!strcmp(d4, "amogus"), "4rth strncpy test failed");

    char s5[50] = "shrek";
    char d5[50] = "s";
    s21_strncpy(d5, s5, 5);
    ck_assert_msg(!strcmp(d5, "shrek"), "5th strncpy test failed");
}
END_TEST

START_TEST(strcspn_test) {
    char *str1 = "0123456789";
    char *str2 = "9876";
    ck_assert_msg(s21_strcspn(str1, str2) == strcspn(str1, str2),
                  "1st strcspn test failed");

    char *str3 = "0123456789";
    char *str4 = "";
    ck_assert_msg(s21_strcspn(str3, str4) == strcspn(str3, str4),
                  "2nd strcspn test failed");

    char *str5 = "";
    char *str6 = "123";
    ck_assert_msg(s21_strcspn(str5, str6) == strcspn(str5, str6),
                  "3rd strcspn test failed");

    char *str7 = "1337";
    char *str8 = "228";
    ck_assert_msg(s21_strcspn(str7, str8) == strcspn(str7, str8),
                  "4rth strcspn test failed");

    char *str9 = "19642";
    char *str10 = "64";
    ck_assert_msg(s21_strcspn(str9, str10) == strcspn(str9, str10),
                  "5th strcspn test failed");
}
END_TEST

START_TEST(strlen_test) {
    char *s1 = "0123456789";
    ck_assert_msg(s21_strlen(s1) == strlen(s1), "1st strlen test failed");

    char *s2 = "";
    ck_assert_msg(s21_strlen(s2) == strlen(s2), "2nd strlen test failed");

    char *s3 = "amogus";
    ck_assert_msg(s21_strlen(s3) == strlen(s3), "3rd strlen test failed");

    char *s4 = "shrek";
    ck_assert_msg(s21_strlen(s4) == strlen(s4), "4rth strlen test failed");

    char *s5 = "is love";
    ck_assert_msg(s21_strlen(s5) == strlen(s5), "5th strlen test failed");
}
END_TEST

START_TEST(strpbrk_test) {
    char *str1 = "hello";
    char *str2 = "hel";
    char *res1, *res2;
    res1 = s21_strpbrk(str1, str2);
    res2 = strpbrk(str1, str2);
    ck_assert_str_eq(res1, res2);

    char *str4 = "ab";
    res1 = s21_strpbrk(str1, str4);
    res2 = strpbrk(str1, str4);
    ck_assert_ptr_eq(res1, res2);

    char *str5 = "o";
    res1 = s21_strpbrk(str1, str5);
    res2 = strpbrk(str1, str5);
    ck_assert_str_eq(res1, res2);

    char *str6 = "abcdefghjkl";
    char *str7 = "abcd";
    res1 = s21_strpbrk(str6, str7);
    res2 = strpbrk(str6, str7);
    ck_assert_str_eq(res1, res2);

    char *str8 = "amogus is shrek?";
    char *str9 = "is";
    res1 = s21_strpbrk(str8, str9);
    res2 = s21_strpbrk(str8, str9);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(strrchr_test) {
    char *s1 = "School-21";
    char *s2 = "";
    char *s3 = "amogus";

    ck_assert_msg(s21_strrchr(s1, 'm') == strrchr(s1, 'm'),
                  "1st strrchr test failed");
    ck_assert_msg(s21_strrchr(s1, 'o') == strrchr(s1, 'o'),
                  "2nd strrchr test failed");
    ck_assert_msg(s21_strrchr(s2, 'o') == strrchr(s2, 'o'),
                  "3rd strrchr test failed");
    ck_assert_msg(s21_strrchr(s3, ' ') == strrchr(s3, ' '),
                  "4rth strrchr test failed");
    ck_assert_msg(s21_strrchr(s3, 's') == strrchr(s3, 's'),
                  "5th strrchr test failed");
}
END_TEST

START_TEST(strspn_test) {
    char *s1 = "School-21";
    char *s2 = "ho";
    char *s3 = "";

    ck_assert_msg(s21_strspn(s1, s2) == strspn(s1, s2),
                  "1st strspn test failed");
    ck_assert_msg(s21_strspn(s3, s2) == strspn(s3, s2),
                  "2nd strspn test failed");
    ck_assert_msg(s21_strspn(s2, s3) == strspn(s2, s3),
                  "3rd strspn test failed");
    ck_assert_msg(s21_strspn(s1, s3) == strspn(s1, s3),
                  "4rth strspn test failed");
    ck_assert_msg(s21_strspn(s3, s1) == strspn(s3, s1),
                  "5th strspn test failed");
}
END_TEST

START_TEST(strstr_test) {
    char *s1 = "School-21";
    char *s2 = "ho";
    char *s3 = "";

    ck_assert_msg(s21_strstr(s1, s2) == strstr(s1, s2),
                  "1st strstr test failed");
    ck_assert_msg(s21_strstr(s1, s3) == strstr(s1, s3),
                  "2nd strstr test failed");
    ck_assert_msg(s21_strstr(s3, s2) == strstr(s3, s2),
                  "3rd strstr test failed");
    ck_assert_msg(s21_strstr(s2, s3) == strstr(s2, s3),
                  "4rth strstr test failed");
    ck_assert_msg(s21_strstr(s3, s1) == strstr(s3, s1),
                  "5th strstr test failed");
}
END_TEST

START_TEST(to_upper_test) {
    char destination[] = "Here w0 are123\0";
    char *test01 = s21_to_upper(destination);
    ck_assert_str_eq(test01, "HERE W0 ARE123");
    free(test01);

    char destination2[] = "Here w0 are\n\0";
    char *test02 = s21_to_upper(destination2);
    ck_assert_str_eq(test02, "HERE W0 ARE\n");
    free(test02);

    char destination3[] = "a\n\0";
    char *test03 = s21_to_upper(destination3);
    ck_assert_str_eq(test03, "A\n");
    free(test03);

    char destination4[] = " \n\0";
    char *test04 = s21_to_upper(destination4);
    ck_assert_str_eq(test04, " \n");
    free(test04);

    char destination5[] = " \0";
    char *test05 = s21_to_upper(destination5);
    ck_assert_str_eq(test05, " ");
    free(test05);

    char destination6[] = "\n\0";
    char *test06 = s21_to_upper(destination6);
    ck_assert_str_eq(test06, "\n");
    free(test06);

    char destination7[] = "\0";
    char *test07 = s21_to_upper(destination7);
    ck_assert_str_eq(test07, "");
    free(test07);
}
END_TEST

START_TEST(to_lower_test) {
    char destination[] = "HERE W0 ARE123\0";
    char *test01 = s21_to_lower(destination);
    ck_assert_str_eq(test01, "here w0 are123");
    free(test01);

    char destination2[] = "HERE W0 ARE\n\0";
    char *test02 = s21_to_lower(destination2);
    ck_assert_str_eq(test02, "here w0 are\n");
    free(test02);

    char destination3[] = "A\n\0";
    char *test03 = s21_to_lower(destination3);
    ck_assert_str_eq(test03, "a\n");
    free(test03);

    char destination4[] = " \n\0";
    char *test04 = s21_to_lower(destination4);
    ck_assert_str_eq(test04, " \n");
    free(test04);

    char destination5[] = " \0";
    char *test05 = s21_to_lower(destination5);
    ck_assert_str_eq(test05, " ");
    free(test05);

    char destination6[] = "\n\0";
    char *test06 = s21_to_lower(destination6);
    ck_assert_str_eq(test06, "\n");
    free(test06);

    char destination7[] = "\0";
    char *test07 = s21_to_lower(destination7);
    ck_assert_str_eq(test07, "");
    free(test07);
}
END_TEST

START_TEST(insert_test) {
    char *s1 = "School-21 test";
    char *s2 = "insert ";
    char *s3 = "amogus";
    char *s4 = "is";
    char *s5 = "shrek";
    char *res1 = s21_insert(s1, " ", 3);
    char *res2 = s21_insert(s5, s3, 5);
    char *res3 = s21_insert(s3, s5, 0);
    char *res4 = s21_insert(s5, s4, 5);
    char *res5 = s21_insert(s2, s1, 4);

    ck_assert_str_eq(res1, "Sch ool-21 test");
    ck_assert_str_eq(res2, "shrekamogus");
    ck_assert_str_eq(res3, "shrekamogus");
    ck_assert_str_eq(res4, "shrekis");
    ck_assert_str_eq(res5, "inseSchool-21 testrt ");

    free(res1);
    free(res2);
    free(res3);
    free(res4);
    free(res5);
}
END_TEST

START_TEST(trim_test) {
    char dest[] = "-=Hello=-\0";
    char *test01 = s21_trim(dest, "-");
    ck_assert_str_eq(test01, "=Hello=\0");
    free(test01);

    char dest2[] = "-Hello\n\0";
    char *test02 = s21_trim(dest2, "-");
    ck_assert_str_eq(test02, "Hello\n\0");
    free(test02);

    char dest3[] = "a\0";
    char *test03 = s21_trim(dest3, "a");
    ck_assert_str_eq(test03, "");
    free(test03);

    char dest4[] = " \n\0";
    char *test04 = s21_trim(dest4, "\n");
    ck_assert_str_eq(test04, " ");
    free(test04);

    char dest5[] = "\n\0";
    char *test05 = s21_trim(dest5, "\0");
    ck_assert_str_eq(test05, "\n");
    free(test05);

    char dest6[] = " \0";
    char *test06 = s21_trim(dest6, " ");
    ck_assert_str_eq(test06, "");
    free(test06);
}
END_TEST

START_TEST(strerror_test) {
    char *str1 = s21_strerror(20);
    char *str2 = strerror(20);
    ck_assert_str_eq(str1, str2);

    char *str3 = s21_strerror(12);
    char *str4 = strerror(12);
    ck_assert_str_eq(str3, str4);

    char *str5 = s21_strerror(1337);
    char *str6 = strerror(1337);
    ck_assert_str_eq(str5, str6);

    char *str7 = s21_strerror(1);
    char *str8 = strerror(1);
    ck_assert_str_eq(str7, str8);

    char *str9 = s21_strerror(25);
    char *str10 = strerror(25);
    ck_assert_str_eq(str9, str10);
}
END_TEST

START_TEST(strtok_test) {
    char test1[50] = "aboba,hello,world,trim";
    char test2[50] = "aboba,hello,world,trim";
    char delim1[10] = "123,";
    char *orig1 = {0}, *copy1 = {0};
    orig1 = strtok(test1, delim1);
    copy1 = s21_strtok(test2, delim1);
    char orig_res1[1000] = {0};
    char copy_res1[1000] = {0};
    while (orig1 != NULL) {
        strcat(orig_res1, orig1);
        orig1 = strtok(NULL, delim1);
    }
    while (copy1 != NULL) {
        strcat(copy_res1, copy1);
        copy1 = s21_strtok(NULL, delim1);
    }
    ck_assert_str_eq(orig_res1, copy_res1);

    char str[] = "School-21";
    char *tok1 = s21_strtok(str, "-");
    char *tok2 = strtok(str, "-");
    char *tok3 = s21_strtok(str, "");
    char *tok4 = strtok(str, "");
    char *tok5 = s21_strtok(str, "oo");
    char *tok6 = strtok(str, "oo");
    char *tok7 = s21_strtok(str, "Sc");
    char *tok8 = strtok(str, "Sc");
    char *tok9 = s21_strtok(str, "21");
    char *tok10 = strtok(str, "21");

    ck_assert_msg(!strcmp(tok1, tok2), "1st strtok test failed");
    ck_assert_msg(!strcmp(tok3, tok4), "2nd strtok test failed");
    ck_assert_msg(!strcmp(tok5, tok6), "3rd strtok test failed");
    ck_assert_msg(!strcmp(tok7, tok8), "4rth strtok test failed");
    ck_assert_msg(!strcmp(tok9, tok10), "5th strtok test failed");
}
END_TEST

START_TEST(s21_sprintf_test) {
    char c[255] = {}, d[255] = {}, x1 = 't';
    int n = 2100, n1 = 0, n2 = -21;
    short sh = 123, sh1 = -123;
    float f = 21.21, f1 = -21.21;
    long int lg = 12345678912345, lg1 = -12345678912345;
    s21_sprintf(c, "%% %p", &n);
    sprintf(d, "%% %p", &n);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg,
                lg1, lg1);
    sprintf(d, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg, lg1,
            lg1);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%10d %+3d %+010d %+-10d %+-10d % -10d %-10d %-10d", n,
                212121, 2121, n2, n, 21, 55, -55);
    sprintf(d, "%10d %+3d %+010d %+-10d %+-10d % -10d %-10d %-10d", n, 212121,
            2121, n2, n, 21, 55, -55);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%-10d %010d %010d %*d %2d", 21, n2, n, 10, n, n2);
    sprintf(d, "%-10d %010d %010d %*d %2d", 21, n2, n, 10, n, n2);
    ck_assert_str_eq(c, d);
    s21_sprintf(
        c, "%.*d %3.10d %.d %-+.5d %-+10.5d %.10d %.10d %2.2d %.d % d %.0d", 10,
        n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
    sprintf(d, "%.*d %3.10d %.d %-+.5d %-+10.5d %.10d %.10d %2.2d %.d % d %.0d",
            10, n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%d %d %d %d %d %ld %ld", INT_MIN, INT_MAX, SHRT_MAX,
                SHRT_MIN, USHRT_MAX, LONG_MAX, LONG_MIN);
    sprintf(d, "%d %d %d %d %d %ld %ld", INT_MIN, INT_MAX, SHRT_MAX, SHRT_MIN,
            USHRT_MAX, LONG_MAX, LONG_MIN);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%c %10c %-10c", '!', 'a', 'b');
    sprintf(d, "%c %10c %-10c", '!', 'a', 'b');
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
    sprintf(d, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello",
                "hello", "hello", "hello", "hello", "hello");
    sprintf(d, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello", "hello",
            "hello", "hello", "hello", "hello");
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello",
                L"hello", L"hello", L"hello", L"hello", L"hello", L"hello");
    sprintf(d, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello", L"hello",
            L"hello", L"hello", L"hello", L"hello", L"hello");
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%u %lu", UINT_MAX, ULONG_MAX);
    sprintf(d, "%u %lu", UINT_MAX, ULONG_MAX);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "hello %n", &n);
    sprintf(d, "hello %n", &n1);
    ck_assert_msg(c, d, "error");
    s21_sprintf(c, "%-10o %lo %lo %o %o %o %10o %#10o %0#10o", 21, lg, lg1, n,
                0, n2, 0, 21, 42);
    sprintf(d, "%-10o %lo %lo %o %o %o %10o %#10o %0#10o", 21, lg, lg1, n, 0,
            n2, 0, 21, 42);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%#o %#o %#10o %0#10o %.10o %.0o %#5.10o", n, n2, 0, 0, n, 0,
                123);
    sprintf(d, "%#o %#o %#10o %0#10o %.10o %.0o %#5.10o", n, n2, 0, 0, n, 0,
            123);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%x %x %x %10x %-10x %.10x %.0x %#5.10x", n, n1, n2, 0, 21,
                n, 0, 123);
    sprintf(d, "%x %x %x %10x %-10x %.10x %.0x %#5.10x", n, n1, n2, 0, 21, n, 0,
            123);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx",
                n, n2, 21, 0, 42, 21, 0, -65, lg, lg1);
    sprintf(d, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx", n,
            n2, 21, 0, 42, 21, 0, -65, lg, lg1);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%X %X %X %10X %-10X %lX", n, n1, n2, 0, 21, lg1);
    sprintf(d, "%X %X %X %10X %-10X %lX", n, n1, n2, 0, 21, lg1);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%#X %#X %-#10X %#10X %#10X %0#10X %0#10X", n, n2, 21, 42, 0,
                4221, n1);
    sprintf(d, "%#X %#X %-#10X %#10X %#10X %0#10X %0#10X", n, n2, 21, 42, 0,
            4221, n1);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "%+.1f %.2f %.3f %.4f %10.5f %10.5f %-10.3f %-10.2f", f, f1,
                21.21, -21.21, 42.42, -42.42, f, f1);
    sprintf(d, "%+.1f %.2f %.3f %.4f %10.5f %10.5f %-10.3f %-10.2f", f, f1,
            21.21, -21.21, 42.42, -42.42, f, f1);
    ck_assert_str_eq(c, d);
    s21_sprintf(c, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1, 21.,
                21.21, 0.0, 21.21, 21., 0.0, 21.21);
    sprintf(d, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1, 21.,
            21.21, 0.0, 21.21, 21., 0.0, 21.21);
    ck_assert_str_eq(c, d);
    ck_assert_int_eq(
        s21_sprintf(c, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1,
                    21., 21.21, 0.0, 21.21, 21., 0.0, 21.21),
        sprintf(d, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1, 21.,
                21.21, 0.0, 21.21, 21., 0.0, 21.21));
    ck_assert_int_eq(
        s21_sprintf(c,
                    "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx",
                    n, n2, 21, 0, 42, 21, 0, -65, lg, lg1),
        sprintf(d, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx",
                n, n2, 21, 0, 42, 21, 0, -65, lg, lg1));
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf = 0;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, memchr_test);
    tcase_add_test(tc1_1, memcmp_test);
    tcase_add_test(tc1_1, memcpy_test);
    tcase_add_test(tc1_1, memmove_test);
    tcase_add_test(tc1_1, memset_test);
    tcase_add_test(tc1_1, strcat_test);
    tcase_add_test(tc1_1, strncat_test);
    tcase_add_test(tc1_1, strchr_test);
    tcase_add_test(tc1_1, strcmp_test);
    tcase_add_test(tc1_1, strncmp_test);
    tcase_add_test(tc1_1, strcpy_test);
    tcase_add_test(tc1_1, strncpy_test);
    tcase_add_test(tc1_1, strcspn_test);
    tcase_add_test(tc1_1, strlen_test);
    tcase_add_test(tc1_1, strpbrk_test);
    tcase_add_test(tc1_1, strrchr_test);
    tcase_add_test(tc1_1, strspn_test);
    tcase_add_test(tc1_1, strstr_test);
    tcase_add_test(tc1_1, to_upper_test);
    tcase_add_test(tc1_1, to_lower_test);
    tcase_add_test(tc1_1, insert_test);
    tcase_add_test(tc1_1, trim_test);
    tcase_add_test(tc1_1, strerror_test);
    tcase_add_test(tc1_1, strtok_test);
    tcase_add_test(tc1_1, s21_sprintf_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
