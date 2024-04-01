#include <check.h>
#include <errno.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_strlen_empty) {
  char *str = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_str1) {
  char *str = "123456789";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_str2) {
  char *str = "Hello world!";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_str3) {
  char *str = "Привет, мир!00000 00000";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strcmp_2empty) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_s21_strcmp_1empty) {
  char *str1 = "";
  char *str2 = "Hello world!";
  ck_assert_int_le(s21_strcmp(str1, str2), strcmp(str1, str2));
  ck_assert_int_ge(s21_strcmp(str2, str1), strcmp(str2, str1));
}
END_TEST

START_TEST(test_s21_strcmp_equal) {
  char *str1 = "Привет, мир!00000 00000";
  char *str2 = "Привет, мир!00000 00000";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_s21_strcmp_str1) {
  char *str1 = "Hello world!0123";
  char *str2 = "Hello world!";
  ck_assert_int_ge(s21_strcmp(str1, str2), strcmp(str1, str2));
  ck_assert_int_le(s21_strcmp(str2, str1), strcmp(str2, str1));
}
END_TEST

START_TEST(test_s21_strcmp_str2) {
  char *str1 = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOP{}|\":LKJHGFDSAZXCVBNM<>?";
  char *str2 = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOP{}|\":LKJHGFDSAZXCVBNM<>Z";
  ck_assert_int_le(s21_strcmp(str1, str2), strcmp(str1, str2));
  ck_assert_int_ge(s21_strcmp(str2, str1), strcmp(str2, str1));
}
END_TEST

START_TEST(test_s21_strcmp_str3) {
  char *str1 = "0987654321";
  char *str2 = "1234567890";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
  ck_assert_int_eq(s21_strcmp(str2, str1), strcmp(str2, str1));
}
END_TEST

START_TEST(test_s21_strcmp_str4) {
  char str1[6] = "ohaio";
  char str2[2] = "i";
  ck_assert_int_ge(s21_strcmp(str1, str2), strcmp(str1, str2));
  ck_assert_int_le(s21_strcmp(str2, str1), strcmp(str2, str1));
}
END_TEST

START_TEST(test_s21_strncmp_2empty) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 1), strncmp(str1, str2, 1));
}
END_TEST

START_TEST(test_s21_strncmp_1empty) {
  char *str1 = "";
  char *str2 = "Hello world!";
  ck_assert_int_le(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
  ck_assert_int_ge(s21_strncmp(str2, str1, 5), strncmp(str2, str1, 5));
}
END_TEST

START_TEST(test_s21_strncmp_equal) {
  char *str1 = "Hello world!";
  char *str2 = "Hello world!";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
  ck_assert_int_eq(s21_strncmp(str1, str2, 50), strncmp(str1, str2, 50));
}
END_TEST

START_TEST(test_s21_strncmp_test1) {
  char *str1 = "Hello world!0123";
  char *str2 = "Hello world!";
  ck_assert_int_le(s21_strncmp(str1, str2, 12), strncmp(str1, str2, 12));
  ck_assert_int_le(s21_strncmp(str2, str1, 13), strncmp(str2, str1, 13));
}
END_TEST

START_TEST(test_s21_strncmp_test2) {
  char *str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyZ";
  ck_assert_int_ge(s21_strncmp(str1, str2, 53), strncmp(str1, str2, 53));
  ck_assert_int_le(s21_strncmp(str2, str1, 52), strncmp(str2, str1, 52));
}
END_TEST

START_TEST(test_s21_strncmp_test3) {
  char *str1 = "0987654321";
  char *str2 = "1234567890";
  ck_assert_int_eq(s21_strncmp(str1, str2, 10), strncmp(str1, str2, 10));
  ck_assert_int_eq(s21_strncmp(str2, str1, 10), strncmp(str2, str1, 10));
}
END_TEST

START_TEST(test_s21_strcpy_empty) {
  char str1[100] = "";
  char str2[100] = "";
  char *source = "Привет, мир!00000 00000";
  ck_assert_pstr_eq(s21_strcpy(str1, source), strcpy(str2, source));
}
END_TEST

START_TEST(test_s21_strcpy_empty2) {
  char str1[100] = "Привет, мир!00000 00000";
  char str2[100] = "Привет, мир!00000 00000";
  char *source = "";
  ck_assert_pstr_eq(s21_strcpy(str1, source), strcpy(str2, source));
}
END_TEST

START_TEST(test_s21_strcpy_test1) {
  char str1[100] = "1234567890";
  char str2[100] = "1234567890";
  char *source = "Привет, мир!00000 00000";
  ck_assert_pstr_eq(s21_strcpy(str1, source), strcpy(str2, source));
}
END_TEST

START_TEST(test_s21_strcpy_test2) {
  char str1[100] = "123456789012345678901234567890";
  char str2[100] = "123456789012345678901234567890";
  char *source = "Aaaaa!";
  ck_assert_pstr_eq(s21_strcpy(str1, source), strcpy(str2, source));
}
END_TEST

START_TEST(test_s21_strncpy_empty) {
  char str1[100] = "";
  char str2[100] = "";
  char *source = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  ck_assert_pstr_eq(s21_strncpy(str1, source, 5), strncpy(str2, source, 5));
  ck_assert_pstr_eq(s21_strncpy(str1, source, 100), strncpy(str2, source, 100));
}
END_TEST

START_TEST(test_s21_strncpy_empty2) {
  char str1[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char str2[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *source = "";
  ck_assert_pstr_eq(s21_strncpy(str1, source, 10), strncpy(str2, source, 10));
}
END_TEST

START_TEST(test_s21_strncpy_test1) {
  char str1[100] = "1234567890";
  char str2[100] = "1234567890";
  char *source = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  ck_assert_pstr_eq(s21_strncpy(str1, source, 30), strncpy(str2, source, 30));
}
END_TEST

START_TEST(test_s21_strncpy_test2) {
  char str1[100] = "123456789012345678901234567890";
  char str2[100] = "123456789012345678901234567890";
  char *source = "Aaaaa!";
  ck_assert_pstr_eq(s21_strncpy(str1, source, 10), strncpy(str2, source, 10));
}
END_TEST

START_TEST(test_s21_strcspn_test1) {
  char str1[100] = "str test spn";
  char str2[100] = "test";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_test2) {
  char str1[100] = "str test spn";
  char str2[100] = "tsr";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_test3) {
  char str1[100] = "str test spn";
  char str2[100] = "abc";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_test4) {
  char str1[100] = "str test spn";
  char str2[100] = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_test5) {
  char str1[100] = "";
  char str2[100] = "str";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcat_empty1) {
  char str1[100] = "";
  char str2[100] = "";
  char *source = "";
  ck_assert_pstr_eq(s21_strcat(str1, source), strcat(str2, source));
}
END_TEST

START_TEST(test_s21_strcat_empty2) {
  char str1[100] = "";
  char str2[100] = "";
  char *source = "Hello world!";
  ck_assert_pstr_eq(s21_strcat(str1, source), strcat(str2, source));
}
END_TEST

START_TEST(test_s21_strcat_empty3) {
  char str1[100] = "Hello world!";
  char str2[100] = "Hello world!";
  char *source = "";
  ck_assert_pstr_eq(s21_strcat(str1, source), strcat(str2, source));
}
END_TEST

START_TEST(test_s21_strcat_test1) {
  char str1[100] = "Hello world!";
  char str2[100] = "Hello world!";
  char *source = "123456789012345678901234567890";
  ck_assert_pstr_eq(s21_strcat(str1, source), strcat(str2, source));
}
END_TEST

START_TEST(test_s21_strcat_test2) {
  char str1[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char str2[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *source = "1";
  ck_assert_pstr_eq(s21_strcat(str1, source), strcat(str2, source));
}
END_TEST

START_TEST(test_s21_strcat_test3) {
  char str1[100] = "1";
  char str2[100] = "1";
  char *source = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  ck_assert_pstr_eq(s21_strcat(str1, source), strcat(str2, source));
}
END_TEST

START_TEST(test_s21_strncat_empty1) {
  char str1[100] = "";
  char str2[100] = "";
  char *source = "";
  ck_assert_pstr_eq(s21_strncat(str1, source, 10), strncat(str2, source, 10));
}
END_TEST

START_TEST(test_s21_strncat_empty2) {
  char str1[100] = "";
  char str2[100] = "";
  char *source = "Hello world!";
  ck_assert_pstr_eq(s21_strncat(str1, source, 10), strncat(str2, source, 10));
}
END_TEST

START_TEST(test_s21_strncat_empty3) {
  char str1[100] = "Hello world!";
  char str2[100] = "Hello world!";
  char *source = "";
  ck_assert_pstr_eq(s21_strncat(str1, source, 5), strncat(str2, source, 5));
}
END_TEST

START_TEST(test_s21_strncat_test1) {
  char str1[100] = "Hello world!";
  char str2[100] = "Hello world!";
  char *source = "123456789012345678901234567890";
  ck_assert_pstr_eq(s21_strncat(str1, source, 15), strncat(str2, source, 15));
}
END_TEST

START_TEST(test_s21_strncat_test2) {
  char str1[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char str2[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *source = "1";
  ck_assert_pstr_eq(s21_strncat(str1, source, 50), strncat(str2, source, 50));
}
END_TEST

START_TEST(test_s21_strncat_test3) {
  char str1[100] = "1";
  char str2[100] = "1";
  char *source = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  ck_assert_pstr_eq(s21_strncat(str1, source, 40), strncat(str2, source, 40));
}
END_TEST

START_TEST(test_s21_strchr_empty) {
  char *str = "";
  char c = '0';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_test1) {
  char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char c = 'Z';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_test2) {
  char *str = "123456789012345678901234567890123456789012345678901234567890";
  char c = '0';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_test3) {
  char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char c = '\0';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strstr_empty1) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_s21_strstr_empty2) {
  char *str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *str2 = "";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_s21_strstr_empty3) {
  char *str1 = "";
  char *str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_s21_strstr_test1) {
  char *str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *str2 = "QWERTY";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_s21_strstr_test2) {
  char *str1 = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOP{}|\":LKJHGFDSAZXCVBNM<>?";
  char *str2 = "YTREWQ";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_s21_strstr_test3) {
  char *str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *str2 = "M";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_s21_strstr_test4) {
  char *str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *str2 = "z";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_s21_strtok_empty1) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_pstr_eq(s21_strtok(str1, str2), strtok(str1, str2));
}
END_TEST

START_TEST(test_s21_strtok_empty2) {
  char *str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *str2 = "";
  ck_assert_pstr_eq(s21_strtok(str1, str2), strtok(str1, str2));
}
END_TEST

START_TEST(test_s21_strtok_empty3) {
  char *str1 = "";
  char *str2 = "., -";
  ck_assert_pstr_eq(s21_strtok(str1, str2), strtok(str1, str2));
}
END_TEST

START_TEST(test_s21_strtok_test1) {
  char str1[] = "This function returns a pointer to the first token.";
  char str2[] = "This function returns a pointer to the first token.";
  char delim[] = "., ";
  char *p2 = strtok(str2, delim);
  char *p1 = s21_strtok(str1, delim);
  while (p1 != s21_NULL) {
    ck_assert_pstr_eq(p1, p2);
    p1 = s21_strtok(s21_NULL, delim);
    p2 = strtok(s21_NULL, delim);
  }
  ck_assert_pstr_eq(s21_strtok(s21_NULL, delim), strtok(s21_NULL, delim));
}
END_TEST

START_TEST(test_s21_strtok_test2) {
  char str1[] = "., The string.h header defines one variable type, one macro, ";
  char str2[] = "., The string.h header defines one variable type, one macro, ";
  char delim[] = "., ";
  char *p2 = strtok(str2, delim);
  char *p1 = s21_strtok(str1, delim);
  while (p1 != s21_NULL) {
    ck_assert_pstr_eq(p1, p2);
    p1 = s21_strtok(s21_NULL, delim);
    p2 = strtok(s21_NULL, delim);
  }
  ck_assert_pstr_eq(s21_strtok(s21_NULL, delim), strtok(s21_NULL, delim));
}
END_TEST

START_TEST(test_s21_strtok_test3) {
  char str1[] = "0123456789876543210123456789876543210123456789876543210";
  char str2[] = "0123456789876543210123456789876543210123456789876543210";
  char delim[] = "0123456789";
  ck_assert_pstr_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(test_s21_memchr_test1) {
  char str[] = "";
  s21_size_t n = 0;
  char f = 'A';
  ck_assert_ptr_eq(s21_memchr(str, f, n), memchr(str, f, n));
}
END_TEST

START_TEST(test_s21_memchr_test2) {
  char str[] = "123456789";
  s21_size_t n = 9;
  char f = '0';
  ck_assert_ptr_eq(s21_memchr(str, f, n), memchr(str, f, n));
}
END_TEST

START_TEST(test_s21_memchr_test3) {
  char str[] = "123456789";
  s21_size_t n = 9;
  char f = '1';
  ck_assert_ptr_eq(s21_memchr(str, f, n), memchr(str, f, n));
}
END_TEST

START_TEST(test_s21_memchr_test4) {
  char str[] = "123456789";
  s21_size_t n = 9;
  char f = '9';
  ck_assert_ptr_eq(s21_memchr(str, f, n), memchr(str, f, n));
}
END_TEST

START_TEST(test_s21_memchr_test5) {
  int array[] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
  s21_size_t n = 5 * sizeof(int);
  int f = 19;
  ck_assert_ptr_eq(s21_memchr(array, f, n), memchr(array, f, n));
}
END_TEST

START_TEST(test_s21_memchr_test6) {
  int array[] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
  s21_size_t n = 5 * sizeof(int);
  int f = 11;
  ck_assert_ptr_eq(s21_memchr(array, f, n), memchr(array, f, n));
}
END_TEST

START_TEST(test_s21_memchr_test7) {
  float array[] = {11.1, 12.1, 13.1, 14, 15.99, 16.001, 17, 18, 19};
  s21_size_t n = 9 * sizeof(float);
  int f = 14;
  ck_assert_ptr_eq(s21_memchr(array, f, n), memchr(array, f, n));
}
END_TEST

START_TEST(test_s21_memcmp_test1) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_test2) {
  char str1[] = "123456789";
  char str2[] = "123456789";
  s21_size_t n = 9;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_test3) {
  char str1[] = "123456789";
  char str2[] = "123456780";
  s21_size_t n = 9;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_test4) {
  char str1[] = "023456789";
  char str2[] = "123456789";
  s21_size_t n = 9;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_test5) {
  int array1[] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
  int array2[] = {11, 12, 13, 14, 15, 16, 17, 17, 19};
  s21_size_t n = 9 * sizeof(int);
  ck_assert_int_eq(s21_memcmp(array1, array2, n), memcmp(array1, array2, n));
}
END_TEST

START_TEST(test_s21_memcmp_test6) {
  int array1[] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
  int array2[] = {11, 12, 13, 14, 15, 16, 17, 17, 19};
  s21_size_t n = 7 * sizeof(int);
  ck_assert_int_eq(s21_memcmp(array1, array2, n), memcmp(array1, array2, n));
}
END_TEST

START_TEST(test_s21_memcmp_test7) {
  float array1[] = {11.1, 12.1, 13.1, 14, 15.99, 16.001, 17, 18, 19};
  float array2[] = {11.1, 12.1, 13.1, 14, 15.99, 16.001, 17.00001, 18, 19};
  s21_size_t n = 9 * sizeof(float);
  ck_assert_int_eq(s21_memcmp(array1, array2, n), memcmp(array1, array2, n));
}
END_TEST

START_TEST(test_s21_memcmp_test8) {
  float array1[] = {11.1, 12.1, 13.1, 14, 15.99, 16.001, 17, 18, 19};
  float array2[] = {11.1, 12.1, 13.1, 14, 15.99, 16.001, 17.00001, 18, 19};
  s21_size_t n = 6 * sizeof(float);
  ck_assert_int_eq(s21_memcmp(array1, array2, n), memcmp(array1, array2, n));
}
END_TEST

START_TEST(test_s21_memcpy_empty) {
  char str1[100] = "";
  char str2[100] = "";
  char *source = "Привет, мир!00000 00";
  ck_assert_mem_eq(s21_memcpy(str1, source, 21), memcpy(str2, source, 21), 21);
}
END_TEST

START_TEST(test_s21_memcpy_empty2) {
  char str1[100] = "Привет, мир!00000 00";
  char str2[100] = "Привет, мир!00000 00";
  char *source = "";
  ck_assert_mem_eq(s21_memcpy(str1, source, 1), memcpy(str2, source, 1), 1);
}
END_TEST

START_TEST(test_s21_memcpy_test1) {
  char str1[100] = "1234567890";
  char str2[100] = "1234567890";
  char *source = "Привет, мир!00000 00";
  ck_assert_mem_eq(s21_memcpy(str1, source, 21), memcpy(str2, source, 21), 21);
}
END_TEST

START_TEST(test_s21_memcpy_test2) {
  char str1[100] = "123456789012345678901234567890";
  char str2[100] = "123456789012345678901234567890";
  char *source = "Aaaaa!";
  ck_assert_mem_eq(s21_memcpy(str1, source, 7), memcpy(str2, source, 7), 7);
}
END_TEST

START_TEST(test_s21_memmove_empty) {
  char str1[100] = "";
  char str2[100] = "";
  char *source = "Привет, мир!00000 00";
  ck_assert_mem_eq(s21_memmove(str1, source, 21), memmove(str2, source, 21),
                   21);
}
END_TEST

START_TEST(test_s21_memmove_test1) {
  char str1[100] = "1234567890";
  char str2[100] = "1234567890";
  char *source = "Привет, мир!00000 00";
  ck_assert_mem_eq(s21_memmove(str1, source, 21), memmove(str2, source, 21),
                   21);
}
END_TEST

START_TEST(test_s21_memmove_test2) {
  char str1[100] = "123456789012345678901234567890";
  char str2[100] = "123456789012345678901234567890";
  char *source = "Aaaaa!";
  ck_assert_mem_eq(s21_memmove(str1, source, 7), memmove(str2, source, 7), 7);
}
END_TEST

START_TEST(test_s21_memmove_test3) {
  char str1[100] = "Привет, мир!00000 00";
  char str2[100] = "Привет, мир!00000 00";
  char *source1 = str1 + 5;
  char *source2 = str2 + 5;
  ck_assert_mem_eq(s21_memmove(str1, source1, 6), memmove(str2, source2, 6),
                   21);
}
END_TEST

START_TEST(test_s21_memmove_test4) {
  char str1[100] = "Привет, мир!00000 00";
  char str2[100] = "Привет, мир!00000 00";
  char *source1 = str1 + 10;
  char *source2 = str2 + 10;
  ck_assert_mem_eq(s21_memmove(str1, source1, 6), memmove(str2, source2, 6),
                   21);
}
END_TEST

START_TEST(test_s21_memmove_test5) {
  char str1[100] = "Привет, мир!00000 00";
  char str2[100] = "Привет, мир!00000 00";
  char *source1 = str1 + 2;
  char *source2 = str2 + 2;
  ck_assert_mem_eq(s21_memmove(source1, str1, 6), memmove(source2, str2, 6), 6);
}
END_TEST

START_TEST(test_s21_memmove_test6) {
  char str1[100] = "Привет, мир!00000 00";
  char str2[100] = "Привет, мир!00000 00";
  char *source1 = str1 + 10;
  char *source2 = str2 + 10;
  ck_assert_mem_eq(s21_memmove(source1, str1, 6), memmove(source2, str2, 6), 6);
}
END_TEST

START_TEST(test_s21_memset_test1) {
  char str1[100] = "012345678901234567890123456789";
  ck_assert_mem_eq(s21_memset(str1, 'A', 10), memset(str1, 'A', 10), 31);
}
END_TEST

START_TEST(test_s21_memset_test2) {
  char str1[100] = "012345678901234567890123456789";
  ck_assert_mem_eq(s21_memset(str1, 'A', 50), memset(str1, 'A', 50), 50);
}
END_TEST

START_TEST(test_s21_memset_test3) {
  char str1[100] = "";
  ck_assert_mem_eq(s21_memset(str1, '\0', 10), memset(str1, '\0', 10), 10);
}
END_TEST

START_TEST(test_s21_memset_test4) {
  char str1[100] = "012345678901234567890123456789";
  //  with memset(str1, 'A', 0)
  //  error: ‘memset’ used with constant zero length parameter; this could be
  //  due to transposed parameters [-Werror=memset-transposed-args] fix:
  //  memset(str1, 'A', 0 - 0)
  ck_assert_mem_eq(s21_memset(str1, 'A', 0), memset(str1, 'A', 0 - 0), 31);
}
END_TEST

START_TEST(test_s21_strpbrk_empty1) {
  char *str1 = "1234567890";
  char *str2 = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_pstr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_empty2) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_test1) {
  char *str1 = "1234567890";
  char *str2 = "963";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_pstr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_test2) {
  char *str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *str2 = "HELLO";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_pstr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_test3) {
  char *str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *str2 = "1234567890";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_pstr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_test4) {
  char *str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *str2 = "123Z123";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_pstr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(test_s21_strrchr_empty) {
  char *str = "";
  char c = '0';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test_s21_strrchr_test1) {
  char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char c = 'Z';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test_s21_strrchr_test2) {
  char *str = "123456789012345678901234567890123456789012345678901234567890";
  char c = '1';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test_s21_strrchr_test3) {
  char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char c = '\0';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test_s21_strspn_test1) {
  char str1[100] = "str test spn";
  char str2[100] = "test";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strspn_test2) {
  char str1[100] = "str test spn";
  char str2[100] = "tsr";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strspn_test3) {
  char str1[100] = "str test spn";
  char str2[100] = "abc";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strspn_test4) {
  char str1[100] = "str test spn";
  char str2[100] = "";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strspn_test5) {
  char str1[100] = "";
  char str2[100] = "str";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strerror_test1) {
  FILE *fp;
  fp = fopen("no_file.txt", "rb");
  if (fp == NULL) ck_assert_str_eq(s21_strerror(errno), strerror(errno));
  if (fp) fclose(fp);
}
END_TEST

START_TEST(test_s21_strerror_test2) {
#ifdef MACOS
  for (int i = 0; i < 107; i++) ck_assert_str_eq(s21_strerror(i), strerror(i));
#else
  for (int i = 0; i < 133; i++) ck_assert_str_eq(s21_strerror(i), strerror(i));
#endif
  //  лучше этот тест вообще убрать, т.к. валгринд 3.19 ругается на переменную с
  //  ошибкой char *err = strerror(-1); ck_assert_str_eq(s21_strerror(-1), err);
  //  if (err) free(err);
}
END_TEST

START_TEST(test_s21_to_upper_test1) {
  char *str1 = "abcdefghijklmnopqrstuvwxyz";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  free(str2);
}
END_TEST

START_TEST(test_s21_to_upper_test2) {
  char *str1 = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
  free(str2);
}
END_TEST

START_TEST(test_s21_to_upper_test3) {
  char *str1 = "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
  free(str2);
}
END_TEST

START_TEST(test_s21_to_upper_test4) {
  char *str1 = s21_NULL;
  char *str2 = s21_to_upper(str1);
  ck_assert_ptr_null(str2);
  free(str2);
}
END_TEST

START_TEST(test_s21_to_lower_test1) {
  char *str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abcdefghijklmnopqrstuvwxyz");
  free(str2);
}
END_TEST

START_TEST(test_s21_to_lower_test2) {
  char *str1 = "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "1234567890abcdefghijklmnopqrstuvwxyz1234567890");
  free(str2);
}
END_TEST

START_TEST(test_s21_to_lower_test3) {
  char *str1 = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "1234567890abcdefghijklmnopqrstuvwxyz1234567890");
  free(str2);
}
END_TEST

START_TEST(test_s21_to_lower_test4) {
  char *str1 = s21_NULL;
  char *str2 = s21_to_lower(str1);
  ck_assert_ptr_null(str2);
  free(str2);
}
END_TEST

START_TEST(test_s21_insert_test1) {
  char *str1 = "1";
  char *str2 = "2";
  char *str_res1 = s21_insert(str1, str2, 0);
  ck_assert_str_eq(str_res1, "21");
  free(str_res1);
  char *str_res2 = s21_insert(str1, str2, 1);
  ck_assert_str_eq(str_res2, "12");
  free(str_res2);
}
END_TEST

START_TEST(test_s21_insert_test2) {
  char *str1 = "";
  char *str2 = "abcdefghijklmnopqrstuvwxyz";
  char *str_res1 = s21_insert(str1, str2, 0);
  ck_assert_str_eq(str_res1, "abcdefghijklmnopqrstuvwxyz");
  free(str_res1);
  char *str_res2 = s21_insert(str2, str1, 0);
  ck_assert_str_eq(str_res2, "abcdefghijklmnopqrstuvwxyz");
  free(str_res2);
}
END_TEST

START_TEST(test_s21_insert_test3) {
  char *str1 = "12345678901234567890";
  char *str2 = "abcdefghijklmnopqrstuvwxyz";
  char *str_res1 = s21_insert(str1, str2, 10);
  ck_assert_str_eq(str_res1, "1234567890abcdefghijklmnopqrstuvwxyz1234567890");
  free(str_res1);
  char *str_res2 = s21_insert(str2, str1, 0);
  ck_assert_str_eq(str_res2, "12345678901234567890abcdefghijklmnopqrstuvwxyz");
  free(str_res2);
  char *str_res3 = s21_insert(str1, str2, 20);
  ck_assert_str_eq(str_res3, "12345678901234567890abcdefghijklmnopqrstuvwxyz");
  free(str_res3);
}
END_TEST

START_TEST(test_s21_insert_test4) {
  char *str1 = s21_NULL;
  char *str2 = "1234567890";
  char *str3 = "ABC";
  char *str_res1 = s21_insert(str1, str2, 0);
  ck_assert_str_eq(str_res1, "1234567890");
  free(str_res1);
  char *str_res2 = s21_insert(str2, str1, 0);
  ck_assert_str_eq(str_res2, "1234567890");
  free(str_res2);
  char *str_res3 = s21_insert(str2, str3, -1);
  ck_assert_ptr_null(str_res3);
  free(str_res3);
  char *str_res4 = s21_insert(str2, str3, 11);
  ck_assert_ptr_null(str_res4);
  free(str_res4);
}
END_TEST

START_TEST(test_s21_trim_test1) {
  char *str = "111222111";
  char *str_res1 = s21_trim(str, "1");
  ck_assert_str_eq(str_res1, "222");
  free(str_res1);
  char *str_res2 = s21_trim(str, "12");
  ck_assert_str_eq(str_res2, "");
  free(str_res2);
}
END_TEST

START_TEST(test_s21_trim_test2) {
  char *str = "qwertyuiop ,. qwertyuiop";
  char *str_res1 = s21_trim(str, " ,.");
  ck_assert_str_eq(str_res1, "qwertyuiop ,. qwertyuiop");
  free(str_res1);
  char *str_res2 = s21_trim(str, "qwertyuiop");
  ck_assert_str_eq(str_res2, " ,. ");
  free(str_res2);
}
END_TEST

START_TEST(test_s21_trim_test3) {
  char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *str_res1 = s21_trim(str, " ,.");
  ck_assert_str_eq(str_res1, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  free(str_res1);
  char *str_res2 = s21_trim(str, "ABC");
  ck_assert_str_eq(str_res2, "DEFGHIJKLMNOPQRSTUVWXYZ");
  free(str_res2);
  char *str_res3 = s21_trim(str, "A");
  ck_assert_str_eq(str_res3, "BCDEFGHIJKLMNOPQRSTUVWXYZ");
  free(str_res3);
  char *str_res4 = s21_trim(str, "Z");
  ck_assert_str_eq(str_res4, "ABCDEFGHIJKLMNOPQRSTUVWXY");
  free(str_res4);
  char *str_res5 = s21_trim(str, "XYZ");
  ck_assert_str_eq(str_res5, "ABCDEFGHIJKLMNOPQRSTUVW");
  free(str_res5);
  char *str_res6 = s21_trim(str, "ABCXYZ");
  ck_assert_str_eq(str_res6, "DEFGHIJKLMNOPQRSTUVW");
  free(str_res6);
}
END_TEST

START_TEST(test_s21_trim_test4) {
  char *str1 = "   \n\n\n\t\t\t111   \n\n\n\t\t\t";
  char *str2 = " 111 ";
  char *str3 = "\n111";
  char *str_res1 = s21_trim(str1, s21_NULL);
  char *str_res2 = s21_trim(str2, s21_NULL);
  char *str_res3 = s21_trim(str3, s21_NULL);
  ck_assert_str_eq(str_res1, "111");
  free(str_res1);
  ck_assert_str_eq(str_res2, "111");
  free(str_res2);
  ck_assert_str_eq(str_res3, "111");
  free(str_res3);
}
END_TEST

START_TEST(test_s21_sscanf_test_0) {
  char fstr[] = "";
  char str[] = "";
  int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_d_1) {
  char fstr[] = "%d";
  char str[] = "fdgsdgsdfgdgdfgdgfghvnvcnhg";
  int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_d_2) {
  char fstr[] = "%d %d";
  char str[] = "  12321  -111";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_d_3) {
  char fstr[] = "%d%d";
  char str[] = "  789789789789789789878678678 \t\n -8987897897888978978978978 ";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_d_4) {
  char fstr[] = "%d.%d %*d%d";
  char str[] = "  12321.999  -111   \n 77777";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_d_5) {
  char fstr[] = "%d%d%%%d%d";
  char str[] = "11111 22222 % 33333";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_d_6) {
  char fstr[] = "%d%d%d%d";
  char str[] = "12345 0xF 6 7";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_d_7) {
  char fstr[] = "%d";
  char str[] = "";
  int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_d_8) {
  char fstr[] = "%d";
  char str[] = "\n\n\n\n   \t\t\t\n\n\n";
  int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_d_9) {
  char fstr[] = "                 %d%d   %d%d";
  char str[] = "-1 -6 -7 -";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hd_1) {
  char fstr[] = "%hd";
  char str[] = "fdgsdgsdfgdgdfgdgfghvnvcnhg";
  short int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hd_2) {
  char fstr[] = "%hd %hd";
  char str[] = "  12321  -111";
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hd_3) {
  char fstr[] = "%hd%hd";
  char str[] = "  789789789789789789878678678 \t\n -8987897897888978978978978 ";
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hd_4) {
  char fstr[] = "%hd.%hd %hd%hd";
  char str[] = "  123219999.999999999  -999999111   \n 99977777";
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hd_5) {
  char fstr[] = "%hd%hd%hd%hd";
  char str[] = "11111 22222 33333";
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hd_6) {
  char fstr[] = "%hd%hd%hd%hd";
  char str[] = "12345 0xFF 6 7";
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hd_7) {
  char fstr[] = "%hd";
  char str[] = "";
  short int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hd_8) {
  char fstr[] = "%hd";
  char str[] = "\n\n\n\n   \t\t\t\n\n\n";
  short int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hd_9) {
  char fstr[] = "                 %hd%hd%hd%hd";
  char str[] = "-1 -6 -7 -";
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_ld_1) {
  char fstr[] = "%ld";
  char str[] = "fdgsdgsdfgdgdfgdgfghvnvcnhg";
  long int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_ld_2) {
  char fstr[] = "%ld %ld";
  char str[] = "  12321  -111";
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_ld_3) {
  char fstr[] = "%ld%ld";
  char str[] = "  789789789789789789878678678 \t\n -8987897897888978978978978 ";
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_ld_4) {
  char fstr[] = "%ld.%ld %ld%ld";
  char str[] = "  12321.999  -111   \n 77777";
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_ld_5) {
  char fstr[] = "%ld%ld%ld%ld";
  char str[] = "11111 22222 33333";
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_ld_6) {
  char fstr[] = "%ld%ld%ld%ld";
  char str[] = "12345 0xFF 6 7";
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_ld_7) {
  char fstr[] = "%ld";
  char str[] = "";
  long int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_ld_8) {
  char fstr[] = "%ld";
  char str[] = "\n\n\n\n   \t\t\t\n\n\n";
  long int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_ld_9) {
  char fstr[] = "                 %ld%ld%ld%ld";
  char str[] = "-1 -6 -7 -";
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lld_1) {
  char fstr[] = "%lld";
  char str[] = "fdgsdgsdfgdgdfgdgfghvnvcnhg";
  long long int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lld_2) {
  char fstr[] = "%lld %lld";
  char str[] = "  12321  -111";
  long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lld_3) {
  char fstr[] = "%lld%lld";
  char str[] = "  789789789789789789878678678 \t\n -8987897897888978978978978 ";
  long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lld_4) {
  char fstr[] = "%lld.%lld %lld%lld";
  char str[] = "  1232199999.99999999999  -1199999999991   \n 7777777777";
  long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lld_5) {
  char fstr[] = "%lld%lld%lld%lld";
  char str[] = "111111111111111 222222222222222 333333333333333";
  long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lld_6) {
  char fstr[] = "%lld%lld%lld%lld";
  char str[] = "12345123451234512345 0xFF 6 7";
  long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lld_7) {
  char fstr[] = "%lld";
  char str[] = "";
  long long int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lld_8) {
  char fstr[] = "%lld";
  char str[] = "\n\n\n\n   \t\t\t\n\n\n";
  long long int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lld_9) {
  char fstr[] = "                 %lld%lld%lld%lld";
  char str[] = "-1 -6 -7 -9";
  long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_u_1) {
  char fstr[] = "%u";
  char str[] = "fdgsdgsdfgdgdfgdgfghvnvcnhg";
  unsigned int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_u_2) {
  char fstr[] = "%u %u";
  char str[] = "  12321  -111";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_u_3) {
  char fstr[] = "%u%u";
  char str[] = "  789789789789789789878678678 \t\n -8987897897888978978978978 ";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_u_4) {
  char fstr[] = "%u.%u %u%u";
  char str[] = "  12321.999  -111   \n 77777";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_u_5) {
  char fstr[] = "%u%u%u%u";
  char str[] = "11111 22222 33333 -44444444444444";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_u_6) {
  char fstr[] = "%u%u%u%u";
  char str[] = "12345 0 -6 7";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_u_7) {
  char fstr[] = "%u";
  char str[] = "";
  unsigned int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_u_8) {
  char fstr[] = "%u";
  char str[] = "\n\n\n\n   \t\t\t\n\n\n";
  unsigned int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_u_9) {
  char fstr[] = "                 %u%u%u%u";
  char str[] = "-1 -6 -7 -9999999999999999999999999";
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hu_1) {
  char fstr[] = "%hu";
  char str[] = "fdgsdgsdfgdgdfgdgfghvnvcnhg";
  unsigned short int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hu_2) {
  char fstr[] = "%hu %hu";
  char str[] = "  12321  -111";
  unsigned short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hu_3) {
  char fstr[] = "%hu%hu";
  char str[] = "  789789789789789789878678678 \t\n -8987897897888978978978978 ";
  unsigned short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hu_4) {
  char fstr[] = "%hu.%hu %hu%%%hu";
  char str[] = "  12321.999  -111%   \n 77777";
  unsigned short int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned short int d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hu_5) {
  char fstr[] = "%hu%hu%hu%hu";
  char str[] = "11111 22222 33333 -44444444444444";
  unsigned short int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned short int d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hu_6) {
  char fstr[] = "%hu%hu%hu%hu";
  char str[] = "12345 0 -6 7";
  unsigned short int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned short int d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hu_7) {
  char fstr[] = "%hu";
  char str[] = "";
  unsigned short int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hu_8) {
  char fstr[] = "%hu";
  char str[] = "\n\n\n\n   \t\t\t\n\n\n";
  unsigned short int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_hu_9) {
  char fstr[] = "                 %hu%hu%hu%hu";
  char str[] = "-1 -6 -7 -9999999999999999999999999";
  unsigned short int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned short int d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lu_1) {
  char fstr[] = "%lu";
  char str[] = "fdgsdgsdfgdgdfgdgfghvnvcnhg";
  unsigned long int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lu_2) {
  char fstr[] = "%lu %lu";
  char str[] = "  12321  -111";
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lu_3) {
  char fstr[] = "%lu%lu";
  char str[] = "  789789789789789789878678678 \t\n -8987897897888978978978978 ";
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lu_4) {
  char fstr[] = "%lu.%lu %lu%lu";
  char str[] = "  12321.999  -111   \n 77777";
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned long int d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lu_5) {
  char fstr[] = "%lu%lu%lu%lu";
  char str[] = "11111 22222 33333";
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned long int d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lu_6) {
  char fstr[] = "%lu%lu%lu%lu";
  char str[] = "12345 0xFF 6 7";
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned long int d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lu_7) {
  char fstr[] = "%lu";
  char str[] = "";
  unsigned long int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lu_8) {
  char fstr[] = "%lu";
  char str[] = "\n\n\n\n   \t\t\t\n\n\n";
  unsigned long int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lu_9) {
  char fstr[] = "                 %lu%lu%lu%lu";
  char str[] = "-1 -6 -7 -";
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned long int d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_llu_1) {
  char fstr[] = "%llu";
  char str[] = "fdgsdgsdfgdgdfgdgfghvnvcnhg";
  unsigned long long int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_llu_2) {
  char fstr[] = "%llu %llu";
  char str[] = "  12321  -111";
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_llu_3) {
  char fstr[] = "%llu%llu";
  char str[] = "  789789789789789789878678678 \t\n -8987897897888978978978978 ";
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_llu_4) {
  char fstr[] = "%llu.%llu %llu%llu";
  char str[] = "  1232199999.99999999999  -1199999999991   \n 7777777777";
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned long long int d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_llu_5) {
  char fstr[] = "%llu%llu%llu%llu";
  char str[] = "999111111111111111 999222222222222222 999333333333333333";
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned long long int d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_llu_6) {
  char fstr[] = "%llu%llu%llu%llu";
  char str[] = "12345123451234512345 9xFF 6 7";
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned long long d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_llu_7) {
  char fstr[] = "%llu";
  char str[] = "";
  unsigned long long int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_llu_8) {
  char fstr[] = "%llu";
  char str[] = "\n\n\n\n   \t\t\t\n\n\n";
  unsigned long long int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_llu_9) {
  char fstr[] = "                 %llu%llu%llu%llu";
  char str[] = "-1 -6 -7 -9";
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned long long d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_i_1) {
  char fstr[] = "%i%i%i%i%i";
  char str[] = "0 0 0 0 00000000000000 0 0 ";
  int a1 = 1, a2 = 1, b1 = 1, b2 = 1, c1 = 1, c2 = 1, d1 = 1, d2 = 1;
  int e1 = 1, e2 = 1;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1, &e1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2, &e2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sscanf_test_i_2) {
  char fstr[] = "%i %i";
  char str[] = "11111 -11111 -011111 011111 0x11111 -0x11111";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int e1 = 0, e2 = 0, f1 = 0, f2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1, &e1, &f1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2, &e2, &f2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(e1, e2);
  ck_assert_int_eq(f1, f2);
}
END_TEST

START_TEST(test_s21_sscanf_test_i_3) {
  char fstr[] = "%i%i";
  char str[] = "  789789789789789789878678678 \t\n -8987897897888978978978978 ";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_i_4) {
  char fstr[] = "%i.%i %i%i";
  char str[] = "  012321.0x999999  -01199999   \n -0x77777";
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned long long int d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_i_5) {
  char fstr[] = "%i%i%i%i";
  char str[] = "0999111111111111111 0x999222222222222222 999333333333333333";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_i_6) {
  char fstr[] = "%i%i%i%i";
  char str[] = "     12345123451234512345 0xFF -6 -07ty";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_i_7) {
  char fstr[] = "%i";
  char str[] = "";
  int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_i_8) {
  char fstr[] = "%i";
  char str[] = "\n\n\n\n\t\t\t\n\n\n";
  int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_test_i_9) {
  char fstr[] = "                 %i  %i  %i  %i";
  char str[] = "-1 -6 -0X7 -9";
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  unsigned long long d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_f_1) {
  char fstr[] = "%f%f%f%f%f";
  char str[] = "0 0.0 0000.0000 0.0000000000001 100000000.0000000001";
  float a1 = 1, a2 = 1, b1 = 1, b2 = 1, c1 = 1, c2 = 1, d1 = 1, d2 = 1;
  float e1 = 1, e2 = 1;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1, &e1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2, &e2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sscanf_test_f_2) {
  char fstr[] = "%f%f%f%*f%f";
  char str[] = "1.111 nan inF 0 3333.3333";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_nan(b1);
  ck_assert_float_infinite(c1);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_f_3) {
  char fstr[] = "%f%f";
  char str[] = "999999999999999.9999999999999999 -9999999999999.99999999999999";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_f_4) {
  char fstr[] = "%f%f%f%f%f";
  char str[] = "1. .1 .  .  .  777.777 00000000.0000001 100000000000.000000001";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  float e1 = 0, e2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1, &e1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2, &e2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sscanf_test_f_5) {
  char fstr[] = "   \n\n %4f  \n\n\n \t %9f     %9f %*f         %f";
  char str[] = "0.123456789 -123456789.987654321 +999.999      \n    1.1";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_f_6) {
  char fstr[] = "   \n\n %f  \n\n\n \t %f     %f   =    %f";
  char str[] = "1243.567e-2 -1243.567e+20 +777e-5   =  \n    1e+1";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lf_1) {
  char fstr[] = "%lf%lf%lf%lf%lf";
  char str[] = "0 0.0 0000.0000 0.0000000000001 100000000.0000000001";
  double a1 = 1, a2 = 1, b1 = 1, b2 = 1, c1 = 1, c2 = 1, d1 = 1, d2 = 1;
  double e1 = 1, e2 = 1;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1, &e1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2, &e2);
  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
  ck_assert_double_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lf_2) {
  char fstr[] = "%lf%lf%lf%*lf%lf";
  char str[] = "1.111 nan inF 0 3333.3333";
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_nan(b1);
  ck_assert_double_infinite(c1);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lf_3) {
  char fstr[] = "%lf%lf";
  char str[] = "999999999999999.9999999999999999 -9999999999999.99999999999999";
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lf_4) {
  char fstr[] = "%lf%lf%lf%lf%lf";
  char str[] = "1. .1 .  .  .  777.777 00000000.0000001 100000000000.000000001";
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  double e1 = 0, e2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1, &e1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2, &e2);
  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
  ck_assert_double_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lf_5) {
  char fstr[] = "   \n\n %4lf  \n\n\n \t %9lf     %9lf %*lf         %lf";
  char str[] = "321.123456789 -123456789.987654321 +999.999      \n    0.1";
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_lf_6) {
  char fstr[] = "   \n\n %lf  \n\n\n \t %lf     %lf   =    %lf";
  char str[] = "1243.567e-2 -1243.567e+20 +777e-5   =  \n    1e+1";
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_llf_1) {
  char fstr[] = "%Lf%Lf%Lf%Lf%Lf";
  char str[] = "1 0.0 0000.0000 0.0000000000001 100000000.0000000001";
  long double a1 = 1, a2 = 1, b1 = 1, b2 = 1, c1 = 1, c2 = 1, d1 = 1, d2 = 1;
  long double e1 = 1, e2 = 1;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1, &e1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2, &e2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq_tol(d1, d2, EPSILON_VALUE);
  ck_assert_ldouble_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sscanf_test_llf_2) {
  char fstr[] = "%Lf%Lf%Lf%*Lf%Lf";
  char str[] = "1.111 nan inF 0 3333.3333";
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq_tol(a1, a2, EPSILON_VALUE);
  ck_assert_ldouble_nan(b1);
  ck_assert_ldouble_infinite(c1);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_llf_3) {
  char fstr[] = "%Lf%Lf";
  char str[] = "999999999999999.9999999999999999 -9999999999999.99999999999999";
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq_tol(a1, a2, 1e+11);
  ck_assert_ldouble_eq_tol(b1, b2, 1e+11);
}
END_TEST

START_TEST(test_s21_sscanf_test_llf_4) {
  char fstr[] = "%Lf%Lf%Lf%Lf%Lf";
  char str[] = "1. .1 .  .  .  777.777 00000000.0000001 100000000000.000000001";
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long double d1 = 0, d2 = 0, e1 = 0, e2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1, &e1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2, &e2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_ldouble_eq_tol(b1, b2, EPSILON_VALUE);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
  ck_assert_ldouble_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sscanf_test_llf_5) {
  char fstr[] = "   \n\n %4Lf  \n\n\n \t %9Lf     %9Lf %*Lf         %Lf";
  char str[] = "321.123456789 -123456789.987654321 +999.999      \n    0.1";
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq_tol(d1, d2, EPSILON_VALUE);
}
END_TEST

START_TEST(test_s21_sscanf_test_llf_6) {
  char fstr[] = "   \n\n %Lf  \n\n\n \t %Lf     %Lf   =    %Lf";
  char str[] = "1243.567e-2 -1243.567e+10 +777e-5   =  \n    1e+1";
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_ldouble_eq_tol(b1, b2, EPSILON_VALUE);
  ck_assert_ldouble_eq_tol(c1, c2, EPSILON_VALUE);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_eEgG_1) {
  char fstr[] = "   \n\n %e  \n\n\n \t %E     %g         %G";
  char str[] = "321.123456789 -123456789.987654321 +999.999      \n    0.001";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_eEgG_2) {
  char fstr[] = "   \n\n %e  \n\n\n \t %E     %g         %G";
  char str[] = "-321.12e+4 123456789.987654321 +999.999e-3      \n    1e-3";
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_o_1) {
  char fstr[] = "%o%o%o%o%o";
  char str[] = "76543210 12345670 0 1 1111191 ";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  int d1 = 0, d2 = 0, e1 = 0, e2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1, &e1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2, &e2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sscanf_test_o_2) {
  char fstr[] = "%o%o%o%o%o";
  char str[] = "+07 -70 -1 +1 -111111F";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int e1 = 0, e2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1, &e1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2, &e2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sscanf_test_o_3) {
  char fstr[] = "%o%o%o%o%o";
  char str[] = "     777     777777     777777777 77777777777 77777777777777 ";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int e1 = 0, e2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1, &e1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2, &e2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sscanf_test_o_4) {
  char fstr[] = "%15o%15o";
  char str[] = "-777777777777777777777777777777777777777777";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_s21_sscanf_test_o_5) {
  char fstr[] = "%o%o%o%o";
  char str[] = "     0      00000000000 00000000000001 00000000000000000001 ";
  int a1 = 1, a2 = 1, b1 = 1, b2 = 1, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_xX_1) {
  char fstr[] = "%x%x%X%X";
  char str[] = "0x10 0xFF 0xfF 0xFF";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_xX_2) {
  char fstr[] = "%x%x%X%X";
  char str[] = "0X10 0XFF 0XfF 0XFF";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_xX_3) {
  char fstr[] = "%x%x%x%x";
  char str[] = "0xFFFFFFFFFFFF -0xFFFFFFFFFFFF 0x1 0x55";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_xX_4) {
  char fstr[] = "%x%x%x%x";
  char str[] = "0x10 0xFF 0xfF 0x";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_xX_5) {
  char fstr[] = "%x   %x %x  \n\n\n %x%a\\";
  char str[] = "0x00 0x5555 0XAAAAAA 0xCDEFGFF";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_pn_1) {
  char fstr[] = "%p   %p%%\n\n\n %p%n";
  char str[] = "0xFEDCBA9876543210 0xFFFFFFFFFFFFFFFFFF % 0x01";
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_pn_2) {
  char fstr[] = "%n%p%p%n";
  char str[] = "0xFEDCBA9876543210 0xFFFFFFFFFFFFFFFFFF1";
  int a1 = 111, a2 = 111, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_c_1) {
  char fstr[] = "%c%c%c%c";
  char str[] = "ABCDEFGH";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_c_2) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "ABCDEFGH";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_c_3) {
  char fstr[] = "%c%c%c%c";
  char str[] = "/n/n/n/n/n/n/n/n/n/n123/n";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_s_1) {
  char a1[BUFFERSIZE] = "", b1[BUFFERSIZE] = "", c1[BUFFERSIZE] = "",
       d1[BUFFERSIZE] = "";
  char a2[BUFFERSIZE] = "", b2[BUFFERSIZE] = "", c2[BUFFERSIZE] = "",
       d2[BUFFERSIZE] = "";
  const char str[] = "gcc -Wall -Wextra -Werror -std=c11 -fsanitize=address";
  const char fstr[] = "%s%s%s%s";
  int res1 = s21_sscanf(str, fstr, a1, b1, c1, d1);
  int res2 = sscanf(str, fstr, a2, b2, c2, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(a1, a2);
  ck_assert_str_eq(b1, b2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_s_2) {
  char a1[BUFFERSIZE] = "", b1[BUFFERSIZE] = "", c1[BUFFERSIZE] = "",
       d1[BUFFERSIZE] = "";
  char a2[BUFFERSIZE] = "", b2[BUFFERSIZE] = "", c2[BUFFERSIZE] = "",
       d2[BUFFERSIZE] = "";
  const char str[] = "gcc -Wall -Wextra -Werror -std=c11 -fsanitize=address";
  const char fstr[] = "%2s%3s%4s%5s";
  int res1 = s21_sscanf(str, fstr, a1, b1, c1, d1);
  int res2 = sscanf(str, fstr, a2, b2, c2, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(a1, a2);
  ck_assert_str_eq(b1, b2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_s_3) {
  char a1[BUFFERSIZE] = "", b1[BUFFERSIZE] = "", c1[BUFFERSIZE] = "",
       d1[BUFFERSIZE] = "";
  char a2[BUFFERSIZE] = "", b2[BUFFERSIZE] = "", c2[BUFFERSIZE] = "",
       d2[BUFFERSIZE] = "";
  const char str[] = "gcc \n-Wall \n-Wextra \n-Werror \n-std=c11";
  const char fstr[] = "%5s%4s%3s%2s";
  int res1 = s21_sscanf(str, fstr, a1, b1, c1, d1);
  int res2 = sscanf(str, fstr, a2, b2, c2, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(a1, a2);
  ck_assert_str_eq(b1, b2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_s_4) {
  char a1[BUFFERSIZE] = "", b1[BUFFERSIZE] = "", c1[BUFFERSIZE] = "",
       d1[BUFFERSIZE] = "";
  char a2[BUFFERSIZE] = "", b2[BUFFERSIZE] = "", c2[BUFFERSIZE] = "",
       d2[BUFFERSIZE] = "";
  const char str[] = "gcc -Wall -Wextra -Werror -std=c11 -fsanitize=address";
  const char fstr[] = "%*s%*s%*s%s%s%s%s";
  int res1 = s21_sscanf(str, fstr, a1, b1, c1, d1);
  int res2 = sscanf(str, fstr, a2, b2, c2, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(a1, a2);
  ck_assert_str_eq(b1, b2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_s_5) {
  char a1[BUFFERSIZE] = "", b1[BUFFERSIZE] = "", c1[BUFFERSIZE] = "",
       d1[BUFFERSIZE] = "";
  char a2[BUFFERSIZE] = "", b2[BUFFERSIZE] = "", c2[BUFFERSIZE] = "",
       d2[BUFFERSIZE] = "";
  const char str[] = "gcc -Wall -Wextra -Werror -std=c11 -fsanitize=address";
  const char fstr[] = "%*s%*s%*s%1s%1s%5s%5s";
  int res1 = s21_sscanf(str, fstr, a1, b1, c1, d1);
  int res2 = sscanf(str, fstr, a2, b2, c2, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(a1, a2);
  ck_assert_str_eq(b1, b2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_test_combo_1) {
  char fstr[] = "%d%c%s%f%1d";
  char str[] = "-999 aaaaa 1e+1 +";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, e1 = 0, e2 = 0;
  char c1[BUFFERSIZE] = "", c2[BUFFERSIZE] = "";
  float d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, c1, &d1, &e1);
  int res2 = sscanf(str, fstr, &a2, &b2, c2, &d2, &e2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_str_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
  ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sscanf_test_combo_2) {
  char fstr[] = "%d%c%s%f";
  char str[] = "-999 aaaaa ";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, e1 = 0, e2 = 0;
  char c1[BUFFERSIZE] = "", c2[BUFFERSIZE] = "";
  float d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, c1, &d1, &e1);
  int res2 = sscanf(str, fstr, &a2, &b2, c2, &d2, &e2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_str_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
  ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sprintf_test_d_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%d%d%d%d%d%d";
  int a1 = -1316134911, a2 = -34343434, a3 = 0;
  int a4 = 123, a5 = 34343434, a6 = 1316134911;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_d_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Hello %d %d %d   %d %d \n %d world!";
  int a1 = -1316134911, a2 = -34343434, a3 = 0;
  int a4 = 123, a5 = 34343434, a6 = 1316134911;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_d_3) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Hello %25d %10d %5.5d   %#-.10d %#d \n %d world!";
  int a1 = -1316134911, a2 = -34343434, a3 = 0;
  int a4 = 123, a5 = 34343434, a6 = 1316134911;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_d_4) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Hello % 25d %010d %+5.5d   %#+-.10d %# d \n %d world!";
  int a1 = -1316134911, a2 = -34343434, a3 = 0;
  int a4 = 123, a5 = 34343434, a6 = 1316134911;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_hd_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Hello % 25hd %010hd %+5.5hd  %#+-.10hd %# hd \n%% %hd world!";
  short int a1 = -24577, a2 = -123, a3 = 0;
  short int a4 = 123, a5 = 132, a6 = 24577;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_hd_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Hello % 25hd %010hd %+5.5hd   %-.10hd %#hd \n % --5hd world!";
  short int a1 = -24577, a2 = -123, a3 = 0;
  short int a4 = 123, a5 = 132, a6 = 24577;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_hhd_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "% 25hhd %010hhd %+5.5hhd   %#+-.10hhd %# hhd \n%% %hhd %%";
  short int a1 = -24577, a2 = -123, a3 = 0;
  short int a4 = 123, a5 = 132, a6 = 24577;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_ld_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Hello % 25ld %#10ld %-5.5ld   %+.10ld %0ld % +-#0ld world!";
  long int a1 = -9999999999999999, a2 = -34343434, a3 = 0;
  long int a4 = 123, a5 = 34343434, a6 = 9999999999999999;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_ld_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Hello % 25ld %010ld %+5.5ld %#+-.10ld %# ld %+- #0ld world!";
  long int a1 = -9999999999999999, a2 = -34343434, a3 = 0;
  long int a4 = 123, a5 = 34343434, a6 = 9999999999999999;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_lld_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Hello %-lld %+9.*lld % *.*lld   %0.lld %#0lld %lld !";
  long long int a1 = -999999999999999999, a2 = -3434343434343434, a3 = 0;
  long long int a4 = 123, a5 = 3434343434343434, a6 = 999999999999999999;
  int res1 = s21_sprintf(str1, format, a1, 10, a2, 5, 6, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, 10, a2, 5, 6, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_lld_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Hello %-*lld %9.*lld %+*.*lld   %.lld %#+-0lld %lld !";
  long long int a1 = -999999999999999999, a2 = -3434343434343434, a3 = 0;
  long long int a4 = 123, a5 = 3434343434343434, a6 = 999999999999999999;
  int res1 = s21_sprintf(str1, format, -10, a1, 10, a2, 5, 6, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, -10, a1, 10, a2, 5, 6, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_oxi_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%o%x%X%i%#o%i%#X";
  int a1 = -1316134911, a2 = -34343434, a3 = 0;
  int a4 = 123, a5 = 34343434, a6 = 1316134911;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6, a3);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6, a3);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_oxi_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Hello %lx %lX %lo   %li %lo \n %li world!";
  long int a1 = -1316134911, a2 = -34343434, a3 = 0;
  long int a4 = 123, a5 = 34343434, a6 = 1316134911;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_oxi_3) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Hello %25o %10x %.0i   %#-.10i %#i \n %o world!";
  int a1 = -1316134911, a2 = -34343434, a3 = 0;
  int a4 = 123, a5 = 34343434, a6 = 1316134911;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_oxi_4) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = " % 25llo %010llx %+5.5llX   %#+-.10lli %# lli \n %llo world!";
  long long int a1 = -1316134911, a2 = -34343434, a3 = 0;
  long long int a4 = 123, a5 = 34343434, a6 = 1316134911;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_u_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%u %u %u %u %u %u";
  long int a1 = -999999999999999999, a2 = -111, a3 = 0;
  unsigned int a4 = 123, a5 = 2808348671, a6 = 1685115914;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_u_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Hello %-*u %9.*u %+*.*u   %.u %#+-0u %u !";
  long int a1 = -999999999999999999, a2 = -111, a3 = 0;
  unsigned int a4 = 123, a5 = 1685115914, a6 = 2808348671;
  int res1 = s21_sprintf(str1, format, -10, a1, 10, a2, 5, 6, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, -10, a1, 10, a2, 5, 6, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_hu_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "% 0.0hu% 1.1hu% 10.0hu % 0.10hu";
  unsigned int a1 = 321, a2 = 999999, a3 = 1;
  unsigned int a4 = 123, a5 = 1234, a6 = 1685115914;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_hu_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%+2.1hu%+4.2hu%+5.4hu%+10.2hu%+55.55hu%+1.1hu";
  unsigned int a1 = 321, a2 = 999999, a3 = 1;
  unsigned int a4 = 123, a5 = 1234, a6 = 1685115914;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_hhu_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "% 0.0hhu% 1.1hhu% 10.0hhu % 0.10hhu";
  unsigned int a1 = 321, a2 = 999999, a3 = 1;
  unsigned int a4 = 123, a5 = 1234, a6 = 1685115914;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_lu_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%*lu %0lu %5.*lu %#lu %*.lu %*.*lu";
  unsigned long int a1 = 321, a2 = 999999, a3 = 1;
  unsigned long int a4 = 123, a5 = 1234, a6 = 9991685115914;
  int res1 = s21_sprintf(str1, format, -3, a1, a2, 3, a3, a4, 7, a5, 8, 0, a6);
  int res2 = sprintf(str2, format, -3, a1, a2, 3, a3, a4, 7, a5, 8, 0, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_lu_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%-20.10hu%-40.20hu%-50.40hu%-100.20hu%-.hu%-10.10hu";
  unsigned long int a1 = 321, a2 = 999999, a3 = 1;
  unsigned long int a4 = 123, a5 = 1234, a6 = 9991685115914;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_llun_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%*llu %0llu %n %5.*llu %#llu %*.*llu";
  int n1 = -1, n2 = -1;
  unsigned long long int a1 = 321, a2 = 999999, a3 = 1;
  unsigned long long int a4 = 123, a5 = 999999999999999999;
  int res1 = s21_sprintf(str1, format, -3, a1, a2, &n1, 3, a3, a4, 8, 0, a5);
  int res2 = sprintf(str2, format, -3, a1, a2, &n2, 3, a3, a4, 8, 0, a5);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_llun_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%n%-20.10llu%-40.20llu%-50llu%%%-100.20llu%-.hu%-10.10llu%n";
  unsigned long long int a1 = 321, a2 = 999999, a3 = 1;
  unsigned long long int a4 = 123, a5 = 1234, a6 = 999999999999999999;
  int n1 = -1, n2 = -1, n3 = -1, n4 = -1;
  int res1 = s21_sprintf(str1, format, &n1, a1, a2, a3, a4, a5, a6, &n2);
  int res2 = sprintf(str2, format, &n3, a1, a2, a3, a4, a5, a6, &n4);
  ck_assert_int_eq(n1, n3);
  ck_assert_int_eq(n2, n4);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_p_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%p %5p %5.p %.p %.5p %5.5p %p !%%!";
  int m = 99;
  int *n = s21_NULL;
  int res1 = s21_sprintf(str1, format, &m, &m, &m, &m, &m, &m, n);
  int res2 = sprintf(str2, format, &m, &m, &m, &m, &m, &m, n);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_f_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "% .0f %+.f %-5.5f %# 20f %015.0f";
  float a1 = -99999999.99999999, a2 = -0.00000001, a3 = 0;
  float a4 = 0.00000001, a5 = 123.123, a6 = 99999999.99999999;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_f_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "% .0f %.f %.1f %1.f %1.1f %0.0f";
  float a1 = 11.11, a2 = 22.22, a3 = 33.33;
  float a4 = 44.44, a5 = 55.55, a6 = 66.66;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_lf_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%+-55.0lf %+-#.lf %--5.5lf %#0 20lf %#015.0lf";
  double a1 = -99999999.99999999, a2 = -0.00000001, a3 = 0;
  double a4 = 0.00000001, a5 = 123.123, a6 = 99999999.99999999;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_Lf_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%+-55.0Lf %+-#.Lf %--5.5Lf %#0 20Lf %#015.0Lf";
  long double a1 = -9999999999999.9999999999999, a2 = -0.0000000000001, a3 = 0;
  long double a4 = 0.0000000000001, a5 = 1, a6 = 9999999999999.9999999999999999;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_Lf_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%Lf %#Lf %5Lf %20Lf %15Lf %+Lf";
  long double a1 = -23.087654, a2 = 1234523459.123456789, a3 = 1.11111111111111;
  long double a4 = 0.9999999999999, a5 = 0, a6 = 1234567.0034598765432987654321;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_e_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%+-55.0e %+-#.e %--5.5e %#0 20e %#015.0e";
  double a1 = -9999999999999.9999999999999, a2 = -0.0000000000001, a3 = 0;
  double a4 = 0.0000000000001, a5 = 1, a6 = 9999999999999.9999999999999999;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_e_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%e %#e %5e %20e %15e %+e";
  double a1 = -23.087654, a2 = 1234523459.123456789, a3 = 1.11111111111111;
  double a4 = 0.9999999999999, a5 = 0, a6 = 1234567.0034598765432987654321;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_Le_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%+-55.0Le %+-#.Le %--5.5Le %#0 20Le %#015.0Le";
  long double a1 = -9999999999999.9999999999999, a2 = -0.0000000000001, a3 = 0;
  long double a4 = 0.0000000000001, a5 = 1, a6 = 9999999999999.9999999999999999;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_Le_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%Le %#Le %5Le %20Le %15Le %+Le";
  long double a1 = -23.087654, a2 = 1234523459.123456789, a3 = 1.11111111111111;
  long double a4 = 0.9999999999999, a5 = 0, a6 = 1234567.0034598765432987654321;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_E_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%+-55.0E %+-#.E %--5.5E %#0 20E %#015.0E";
  double a1 = -9999999999999.9999999999999, a2 = -0.0000000000001, a3 = 0;
  double a4 = 0.0000000000001, a5 = 1, a6 = 9999999999999.9999999999999999;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_E_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%E %#E %5E %20E %15E %+E";
  double a1 = -23.087654, a2 = 1234523459.123456789, a3 = 1.11111111111111;
  double a4 = 0.9999999999999, a5 = 0, a6 = 1234567.0034598765432987654321;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_LE_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%+-55.0LE %+-#.LE %--5.5LE %#0 20LE %#015.0LE";
  long double a1 = -9999999999999, a2 = -0.0000000000001, a3 = 0;
  long double a4 = 0.0000000000001, a5 = 1, a6 = 9999999999999.9999999999999999;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_LE_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%LE %#LE %5LE %20LE %15LE %+LE";
  long double a1 = -23.087654, a2 = 1234523459, a3 = 1.11111111111111;
  long double a4 = 0.9999999999999, a5 = 0, a6 = 1234567.0034598765432987654321;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_g_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%+-55.0g %+-#.g %--5.5g %#0 20g %#015.0g";
  double a1 = -9999999999999.9999999999999, a2 = -0.0000000000001, a3 = 0;
  double a4 = 0.0000000000001, a5 = 1, a6 = 9999999999999.9999999999999999;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_g_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%g %#g %5g %20g %15g %+g";
  double a1 = -23.087654, a2 = 1234523459.123456789, a3 = 1.11111111111111;
  double a4 = 0.9999999999999, a5 = 0, a6 = 1234567.0034598765432987654321;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_Lg_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%+-55.0Lg %+-#.Lg %--5.5Lg %#0 20Lg %#015.0Lg";
  long double a1 = -9999999999999.9999999999999, a2 = -0.0000000000001, a3 = 0;
  long double a4 = 0.0000000000001, a5 = 1, a6 = 9999999999999.9999999999999999;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_Lg_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%Lg %#Lg %5Lg %20Lg %15Lg %+Lg";
  long double a1 = -23.087654, a2 = 1234523459.123456789, a3 = 1.11111111111111;
  long double a4 = 0.9999999999999, a5 = 0, a6 = 1234567.0034598765432987654321;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_G_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%+-55.0g %+-#.G %--5.5G %#0 20G %#015.0G";
  double a1 = -9999999999999.9999999999999, a2 = -0.0000000000001, a3 = 0;
  double a4 = 0.0000000000001, a5 = 1, a6 = 9999999999999.9999999999999999;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_G_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%G %#G %5G %20G %15G %+G";
  double a1 = -23.087654, a2 = 1234523459.123456789, a3 = 1.11111111111111;
  double a4 = 0.9999999999999, a5 = 0, a6 = 1234567.0034598765432987654321;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_LG_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%+-55.0LG %+-#.LG %--5.5LG %#0 20LG %#015.0LG";
  long double a1 = -9999999999999, a2 = -0.0000000000001, a3 = 0;
  long double a4 = 0.0000000000001, a5 = 1, a6 = 9999999999999.9999999999999999;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_LG_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "%LG %#LG %5LG %20LG %15LG %+LG";
  long double a1 = -23.087654, a2 = 1234523459, a3 = 1.11111111111111;
  long double a4 = 0.9999999999999, a5 = 0, a6 = 1234567.0034598765432987654321;
  int res1 = s21_sprintf(str1, format, a1, a2, a3, a4, a5, a6);
  int res2 = sprintf(str2, format, a1, a2, a3, a4, a5, a6);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_fge_nan) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "123 %f %g %e %Lf %Lg %Le %G %E %LG %LE 321";
  double a1 = NAN;
  long double a2 = NAN;
  int res1 = s21_sprintf(str1, format, a1, a1, a1, a2, a2, a2, a1, a1, a2, a2);
  int res2 = sprintf(str2, format, a1, a1, a1, a2, a2, a2, a1, a1, a2, a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_fge_inf) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "123 %f %g %e %Lf %Lg %Le %G %E %LG %LE 321";
  double a1 = INFINITY;
  long double a2 = INFINITY;
  int res1 = s21_sprintf(str1, format, a1, a1, a1, a2, a2, a2, a1, a1, a2, a2);
  int res2 = sprintf(str2, format, a1, a1, a1, a2, a2, a2, a1, a1, a2, a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_s_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *s1 = "ABCDEFHJKLMNOP";
  char *s2 = "abcdefhjklmnop";
  const char *format = "Hello, %10s %10.15s %+s %-2.2s %s %s!";
  int res1 = s21_sprintf(str1, format, s1, s2, s1, s2, s1, s2);
  int res2 = sprintf(str2, format, s1, s2, s1, s2, s1, s2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_s_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Wide char test %ls %.4ls";
  wchar_t w[] = L"森我爱菠萝汉";
  int res1 = s21_sprintf(str1, format, w, w);
  int res2 = sprintf(str2, format, w, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_test_c_1) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char s1 = '0';
  char s2 = '\n';
  const char *format = "Hello, %10c %10.15c %+c %-c %c %c!";
  int res1 = s21_sprintf(str1, format, s1, s2, s1, s2, s1, s2);
  int res2 = sprintf(str2, format, s1, s2, s1, s2, s1, s2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_test_c_2) {
  char str1[BUFFERSIZE];
  char str2[BUFFERSIZE];
  char *format = "Wide char test %lc";
  wchar_t w = L'森';
  int res1 = s21_sprintf(str1, format, w);
  int res2 = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite = suite_create("S21_String");
  TCase *tcase_core_strlen = tcase_create("Strlen");
  tcase_add_test(tcase_core_strlen, test_s21_strlen_empty);
  tcase_add_test(tcase_core_strlen, test_s21_strlen_str1);
  tcase_add_test(tcase_core_strlen, test_s21_strlen_str2);
  tcase_add_test(tcase_core_strlen, test_s21_strlen_str3);
  suite_add_tcase(suite, tcase_core_strlen);

  TCase *tcase_core_strcmp = tcase_create("Strcmp");
  tcase_add_test(tcase_core_strcmp, test_s21_strcmp_2empty);
  tcase_add_test(tcase_core_strcmp, test_s21_strcmp_1empty);
  tcase_add_test(tcase_core_strcmp, test_s21_strcmp_equal);
  tcase_add_test(tcase_core_strcmp, test_s21_strcmp_str1);
  tcase_add_test(tcase_core_strcmp, test_s21_strcmp_str2);
  tcase_add_test(tcase_core_strcmp, test_s21_strcmp_str3);
  tcase_add_test(tcase_core_strcmp, test_s21_strcmp_str4);
  suite_add_tcase(suite, tcase_core_strcmp);

  TCase *tcase_core_strncmp = tcase_create("Strncmp");
  tcase_add_test(tcase_core_strncmp, test_s21_strncmp_2empty);
  tcase_add_test(tcase_core_strncmp, test_s21_strncmp_1empty);
  tcase_add_test(tcase_core_strncmp, test_s21_strncmp_equal);
  tcase_add_test(tcase_core_strncmp, test_s21_strncmp_test1);
  tcase_add_test(tcase_core_strncmp, test_s21_strncmp_test2);
  tcase_add_test(tcase_core_strncmp, test_s21_strncmp_test3);
  suite_add_tcase(suite, tcase_core_strncmp);

  TCase *tcase_core_strcpy = tcase_create("Strcpy");
  tcase_add_test(tcase_core_strcpy, test_s21_strcpy_empty);
  tcase_add_test(tcase_core_strcpy, test_s21_strcpy_empty2);
  tcase_add_test(tcase_core_strcpy, test_s21_strcpy_test1);
  tcase_add_test(tcase_core_strcpy, test_s21_strcpy_test2);
  suite_add_tcase(suite, tcase_core_strcpy);

  TCase *tcase_core_strncpy = tcase_create("Strncpy");
  tcase_add_test(tcase_core_strncpy, test_s21_strncpy_empty);
  tcase_add_test(tcase_core_strncpy, test_s21_strncpy_empty2);
  tcase_add_test(tcase_core_strncpy, test_s21_strncpy_test1);
  tcase_add_test(tcase_core_strncpy, test_s21_strncpy_test2);
  suite_add_tcase(suite, tcase_core_strncpy);

  TCase *tcase_core_strcspn = tcase_create("Strcspn");
  tcase_add_test(tcase_core_strcspn, test_s21_strcspn_test1);
  tcase_add_test(tcase_core_strcspn, test_s21_strcspn_test2);
  tcase_add_test(tcase_core_strcspn, test_s21_strcspn_test3);
  tcase_add_test(tcase_core_strcspn, test_s21_strcspn_test4);
  tcase_add_test(tcase_core_strcspn, test_s21_strcspn_test5);
  suite_add_tcase(suite, tcase_core_strcspn);

  TCase *tcase_core_strcat = tcase_create("Strcat");
  tcase_add_test(tcase_core_strcat, test_s21_strcat_empty1);
  tcase_add_test(tcase_core_strcat, test_s21_strcat_empty2);
  tcase_add_test(tcase_core_strcat, test_s21_strcat_empty3);
  tcase_add_test(tcase_core_strcat, test_s21_strcat_test1);
  tcase_add_test(tcase_core_strcat, test_s21_strcat_test2);
  tcase_add_test(tcase_core_strcat, test_s21_strcat_test3);
  suite_add_tcase(suite, tcase_core_strcat);

  TCase *tcase_core_strncat = tcase_create("Strncat");
  tcase_add_test(tcase_core_strncat, test_s21_strncat_empty1);
  tcase_add_test(tcase_core_strncat, test_s21_strncat_empty2);
  tcase_add_test(tcase_core_strncat, test_s21_strncat_empty3);
  tcase_add_test(tcase_core_strncat, test_s21_strncat_test1);
  tcase_add_test(tcase_core_strncat, test_s21_strncat_test2);
  tcase_add_test(tcase_core_strncat, test_s21_strncat_test3);
  suite_add_tcase(suite, tcase_core_strncat);

  TCase *tcase_core_strchr = tcase_create("Strchr");
  tcase_add_test(tcase_core_strchr, test_s21_strchr_empty);
  tcase_add_test(tcase_core_strchr, test_s21_strchr_test1);
  tcase_add_test(tcase_core_strchr, test_s21_strchr_test2);
  tcase_add_test(tcase_core_strchr, test_s21_strchr_test3);
  suite_add_tcase(suite, tcase_core_strchr);

  TCase *tcase_core_strstr = tcase_create("Strstr");
  tcase_add_test(tcase_core_strstr, test_s21_strstr_empty1);
  tcase_add_test(tcase_core_strstr, test_s21_strstr_empty2);
  tcase_add_test(tcase_core_strstr, test_s21_strstr_empty3);
  tcase_add_test(tcase_core_strstr, test_s21_strstr_test1);
  tcase_add_test(tcase_core_strstr, test_s21_strstr_test2);
  tcase_add_test(tcase_core_strstr, test_s21_strstr_test3);
  tcase_add_test(tcase_core_strstr, test_s21_strstr_test4);
  suite_add_tcase(suite, tcase_core_strstr);

  TCase *tcase_core_strtok = tcase_create("Strtok");
  tcase_add_test(tcase_core_strtok, test_s21_strtok_empty1);
  tcase_add_test(tcase_core_strtok, test_s21_strtok_empty2);
  tcase_add_test(tcase_core_strtok, test_s21_strtok_empty3);
  tcase_add_test(tcase_core_strtok, test_s21_strtok_test1);
  tcase_add_test(tcase_core_strtok, test_s21_strtok_test2);
  tcase_add_test(tcase_core_strtok, test_s21_strtok_test3);
  suite_add_tcase(suite, tcase_core_strtok);

  TCase *tcase_core_memchr = tcase_create("Memchr");
  tcase_add_test(tcase_core_memchr, test_s21_memchr_test1);
  tcase_add_test(tcase_core_memchr, test_s21_memchr_test2);
  tcase_add_test(tcase_core_memchr, test_s21_memchr_test3);
  tcase_add_test(tcase_core_memchr, test_s21_memchr_test4);
  tcase_add_test(tcase_core_memchr, test_s21_memchr_test5);
  tcase_add_test(tcase_core_memchr, test_s21_memchr_test6);
  tcase_add_test(tcase_core_memchr, test_s21_memchr_test7);
  suite_add_tcase(suite, tcase_core_memchr);

  TCase *tcase_core_memcmp = tcase_create("Memcmp");
  tcase_add_test(tcase_core_memcmp, test_s21_memcmp_test1);
  tcase_add_test(tcase_core_memcmp, test_s21_memcmp_test2);
  tcase_add_test(tcase_core_memcmp, test_s21_memcmp_test3);
  tcase_add_test(tcase_core_memcmp, test_s21_memcmp_test4);
  tcase_add_test(tcase_core_memcmp, test_s21_memcmp_test5);
  tcase_add_test(tcase_core_memcmp, test_s21_memcmp_test6);
  tcase_add_test(tcase_core_memcmp, test_s21_memcmp_test7);
  tcase_add_test(tcase_core_memcmp, test_s21_memcmp_test8);
  suite_add_tcase(suite, tcase_core_memcmp);

  TCase *tcase_core_memcpy = tcase_create("Memcpy");
  tcase_add_test(tcase_core_memcpy, test_s21_memcpy_empty);
  tcase_add_test(tcase_core_memcpy, test_s21_memcpy_empty2);
  tcase_add_test(tcase_core_memcpy, test_s21_memcpy_test1);
  tcase_add_test(tcase_core_memcpy, test_s21_memcpy_test2);
  suite_add_tcase(suite, tcase_core_memcpy);

  TCase *tcase_core_memmove = tcase_create("Memmove");
  tcase_add_test(tcase_core_memmove, test_s21_memmove_empty);
  tcase_add_test(tcase_core_memmove, test_s21_memmove_test1);
  tcase_add_test(tcase_core_memmove, test_s21_memmove_test2);
  tcase_add_test(tcase_core_memmove, test_s21_memmove_test3);
  tcase_add_test(tcase_core_memmove, test_s21_memmove_test4);
  tcase_add_test(tcase_core_memmove, test_s21_memmove_test5);
  tcase_add_test(tcase_core_memmove, test_s21_memmove_test6);
  suite_add_tcase(suite, tcase_core_memmove);

  TCase *tcase_core_memset = tcase_create("Memset");
  tcase_add_test(tcase_core_memset, test_s21_memset_test1);
  tcase_add_test(tcase_core_memset, test_s21_memset_test2);
  tcase_add_test(tcase_core_memset, test_s21_memset_test3);
  tcase_add_test(tcase_core_memset, test_s21_memset_test4);
  suite_add_tcase(suite, tcase_core_memset);

  TCase *tcase_core_strpbrk = tcase_create("Strpbrk");
  tcase_add_test(tcase_core_strpbrk, test_s21_strpbrk_empty1);
  tcase_add_test(tcase_core_strpbrk, test_s21_strpbrk_empty2);
  tcase_add_test(tcase_core_strpbrk, test_s21_strpbrk_test1);
  tcase_add_test(tcase_core_strpbrk, test_s21_strpbrk_test2);
  tcase_add_test(tcase_core_strpbrk, test_s21_strpbrk_test3);
  tcase_add_test(tcase_core_strpbrk, test_s21_strpbrk_test4);
  suite_add_tcase(suite, tcase_core_strpbrk);

  TCase *tcase_core_strrchr = tcase_create("Strrchr");
  tcase_add_test(tcase_core_strrchr, test_s21_strrchr_empty);
  tcase_add_test(tcase_core_strrchr, test_s21_strrchr_test1);
  tcase_add_test(tcase_core_strrchr, test_s21_strrchr_test2);
  tcase_add_test(tcase_core_strrchr, test_s21_strrchr_test3);
  suite_add_tcase(suite, tcase_core_strrchr);

  TCase *tcase_core_strspn = tcase_create("Strspn");
  tcase_add_test(tcase_core_strspn, test_s21_strspn_test1);
  tcase_add_test(tcase_core_strspn, test_s21_strspn_test2);
  tcase_add_test(tcase_core_strspn, test_s21_strspn_test3);
  tcase_add_test(tcase_core_strspn, test_s21_strspn_test4);
  tcase_add_test(tcase_core_strspn, test_s21_strspn_test5);
  suite_add_tcase(suite, tcase_core_strspn);

  TCase *tcase_core_strerror = tcase_create("Strerror");
  tcase_add_test(tcase_core_strerror, test_s21_strerror_test1);
  tcase_add_test(tcase_core_strerror, test_s21_strerror_test2);
  suite_add_tcase(suite, tcase_core_strerror);

  TCase *tcase_core_to_upper = tcase_create("To_upper");
  tcase_add_test(tcase_core_to_upper, test_s21_to_upper_test1);
  tcase_add_test(tcase_core_to_upper, test_s21_to_upper_test2);
  tcase_add_test(tcase_core_to_upper, test_s21_to_upper_test3);
  tcase_add_test(tcase_core_to_upper, test_s21_to_upper_test4);
  suite_add_tcase(suite, tcase_core_to_upper);

  TCase *tcase_core_to_lower = tcase_create("To_lower");
  tcase_add_test(tcase_core_to_lower, test_s21_to_lower_test1);
  tcase_add_test(tcase_core_to_lower, test_s21_to_lower_test2);
  tcase_add_test(tcase_core_to_lower, test_s21_to_lower_test3);
  tcase_add_test(tcase_core_to_lower, test_s21_to_lower_test4);
  suite_add_tcase(suite, tcase_core_to_lower);

  TCase *tcase_core_insert = tcase_create("Insert");
  tcase_add_test(tcase_core_insert, test_s21_insert_test1);
  tcase_add_test(tcase_core_insert, test_s21_insert_test2);
  tcase_add_test(tcase_core_insert, test_s21_insert_test3);
  tcase_add_test(tcase_core_insert, test_s21_insert_test4);
  suite_add_tcase(suite, tcase_core_insert);

  TCase *tcase_core_trim = tcase_create("Trim");
  tcase_add_test(tcase_core_trim, test_s21_trim_test1);
  tcase_add_test(tcase_core_trim, test_s21_trim_test2);
  tcase_add_test(tcase_core_trim, test_s21_trim_test3);
  tcase_add_test(tcase_core_trim, test_s21_trim_test4);
  suite_add_tcase(suite, tcase_core_trim);

  TCase *tcase_core_sscanf = tcase_create("Sscanf");
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_0);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_d_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_d_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_d_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_d_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_d_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_d_6);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_d_7);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_d_8);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_d_9);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hd_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hd_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hd_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hd_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hd_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hd_6);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hd_7);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hd_8);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hd_9);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_ld_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_ld_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_ld_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_ld_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_ld_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_ld_6);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_ld_7);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_ld_8);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_ld_9);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lld_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lld_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lld_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lld_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lld_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lld_6);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lld_7);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lld_8);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lld_9);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_u_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_u_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_u_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_u_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_u_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_u_6);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_u_7);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_u_8);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_u_9);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hu_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hu_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hu_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hu_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hu_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hu_6);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hu_7);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hu_8);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_hu_9);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lu_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lu_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lu_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lu_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lu_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lu_6);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lu_7);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lu_8);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lu_9);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llu_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llu_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llu_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llu_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llu_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llu_6);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llu_7);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llu_8);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llu_9);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_i_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_i_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_i_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_i_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_i_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_i_6);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_i_7);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_i_8);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_i_9);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_f_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_f_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_f_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_f_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_f_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_f_6);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lf_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lf_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lf_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lf_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lf_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_lf_6);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llf_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llf_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llf_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llf_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llf_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_llf_6);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_eEgG_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_eEgG_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_o_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_o_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_o_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_o_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_o_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_xX_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_xX_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_xX_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_xX_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_xX_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_pn_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_pn_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_c_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_c_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_c_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_s_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_s_2);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_s_3);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_s_4);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_s_5);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_combo_1);
  tcase_add_test(tcase_core_sscanf, test_s21_sscanf_test_combo_2);
  suite_add_tcase(suite, tcase_core_sscanf);

  TCase *tcase_core_sprintf = tcase_create("Sprintf");
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_d_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_d_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_d_3);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_d_4);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_hd_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_hd_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_hhd_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_ld_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_ld_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_lld_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_lld_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_oxi_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_oxi_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_oxi_3);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_oxi_4);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_u_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_u_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_hu_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_hu_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_hhu_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_lu_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_lu_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_llun_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_llun_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_p_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_f_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_f_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_lf_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_Lf_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_Lf_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_e_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_e_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_Le_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_Le_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_E_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_E_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_LE_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_LE_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_g_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_g_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_Lg_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_Lg_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_G_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_G_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_LG_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_LG_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_fge_nan);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_fge_inf);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_s_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_s_2);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_c_1);
  tcase_add_test(tcase_core_sprintf, test_s21_sprintf_test_c_2);
  suite_add_tcase(suite, tcase_core_sprintf);
  return suite;
}

int main(void) {
  setlocale(LC_ALL, "");
  setlocale(LC_NUMERIC, "C");
  int failed_count;
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
