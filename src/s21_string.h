#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#define s21_size_t unsigned long long
#define s21_NULL ((void *)0)

#define BUFFERSIZE 1024
#define EPSILON_VALUE 0.000001f
#define SPACE_SYM " \n\r\t\v\f"

s21_size_t s21_strlen(const char *str);
s21_size_t s21_strspn(const char *str1, const char *str2);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);
char *s21_strerror(int s21_errnum);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf(const char *str, const char *format, ...);

typedef struct sprintf_format {
  char flag_r;
  char flag_s;
  char flag_p;
  char flag_m;
  char flag_z;
  int width;
  int accuracy;
  char length;
  char length2;
  int float_part;
  int is_negative;
  char spec;
  char unsign;
} s_format;

int s21_parse_flags(const char *format, s21_size_t *i, s_format *s_flags);
int s21_parse_width(va_list *ap, const char *format, s21_size_t *i,
                    s_format *s_flags);
int s21_parse_accuracy(va_list *ap, const char *format, s21_size_t *i,
                       s_format *s_flags);
int s21_parse_length(const char *format, s21_size_t *i, s_format *s_flags);
char *s21_switch_spec(va_list *ap, s21_size_t j, s_format *s_flags);
char *s21_process_spec_n(va_list *ap, s21_size_t j);
char *s21_process_spec_id(va_list *ap, s_format *s_flags);
char *s21_process_spec_xuo(va_list *ap, s_format *s_flags);
char *s21_process_spec_p(va_list *ap, s_format *s_flags);
char *s21_process_spec_f(va_list *ap, s_format *s_flags);
char *s21_process_spec_e(va_list *ap, s_format *s_flags);
char *s21_process_spec_g(va_list *ap, s_format *s_flags);
char *s21_process_spec_c(va_list *ap, s_format *s_flags);
char *s21_process_spec_s(va_list *ap, s_format *s_flags);
void s21_reverse(char str[], int len);
void s21_process_flags(char *str, s_format *s_flags);
char *s21_itoa(long long num, int base, s_format *s_flags);
char *s21_ftoa(long double f, int acc, s_format *s_flags);
int s21_delendzero(char *str);
char *s21_ftoexp(long double f, s_format *s_flags);
char *s21_naninf(long double f, s_format *s_flags);
char *s21_ftog(long double f, s_format *s_flags);
char *s21_wcstombs(wchar_t *wc_str, s_format *s_flags);

typedef struct sflags {
  int ast;
  int weight;
  char length;
  char spec;
} sscanf_flags;

int s21_get_base(const char *str, s21_size_t *i);
int s21_char2int(char c);
int s21_get_sign(sscanf_flags *f, const char *str, s21_size_t *i, int *error);
int s21_checkinf(const char *str, s21_size_t *i);
int s21_checknan(const char *str, s21_size_t *i);
long long int s21_get_number(sscanf_flags *flags, const char *str,
                             s21_size_t *i, int *error, int base);
unsigned long long int s21_get_unumber(sscanf_flags *flags, const char *str,
                                       s21_size_t *i, int *error, int base);
long double s21_get_fnumber(sscanf_flags *flags, const char *str, s21_size_t *i,
                            int *error);
int s21_get_char(sscanf_flags *flags, va_list *vargs, const char *str,
                 s21_size_t *i, int *count);
int s21_get_str(sscanf_flags *flags, va_list *vargs, const char *str,
                s21_size_t *i, int *count, int *error);
int s21_save_number(sscanf_flags *flags, va_list *vargs, long long int t,
                    int *count);
int s21_save_unumber(sscanf_flags *flags, va_list *vargs, long long int t,
                     int *count);
int s21_save_fnumber(sscanf_flags *flags, va_list *vargs, long double t,
                     int *count);
int s21_parse_format(sscanf_flags *flags, const char *format, s21_size_t *j,
                     int *error);
int s21_switch_cpec(sscanf_flags *flags, va_list *vargs, const char *str,
                    s21_size_t *i, int *count, int *error);
int s21_delete_spaces(const char *str, s21_size_t *i);

#endif  // SRC_S21_STRING_H_
