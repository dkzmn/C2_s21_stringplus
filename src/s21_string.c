#include "s21_string.h"

extern char *STRERRORARRAY_LINUX[];
extern char *STRERRORARRAY_MACOS[];
char undef[] = "Unknown error 000000000000000000000000";

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *p = (unsigned char *)str;
  unsigned char ch = c;
  while (n > 0) {
    if (*p == ch) return (void *)p;
    p++;
    n--;
  }
  return s21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++)
    if (*(char *)((char *)str1 + i) != *(char *)((char *)str2 + i))
      return *((char *)(str1) + i) - *(char *)((char *)str2 + i);
  return 0;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++)
    *(char *)((char *)dest + i) = *(char *)((char *)src + i);
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *psrc = (char *)src;
  char *pdest = (char *)dest;
  if ((psrc < pdest) && (pdest < psrc + n)) {
    for (pdest += n, psrc += n; n--;) {
      *--pdest = *--psrc;
    }
  } else {
    while (n--) {
      *pdest++ = *psrc++;
    }
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *p = str;
  while (n-- > 0) *p++ = (unsigned char)c;
  return str;
}

char *s21_strcat(char *dest, const char *src) {
  int i = 0;
  char *first = dest;
  while (dest[i] != '\0') {
    i++;
  }
  int j = 0;
  while (src[j] != '\0') {
    dest[i] = src[j];
    i++;
    j++;
  }
  dest[i] = '\0';
  return first;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int i = 0;
  char *first = dest;
  while (dest[i] != '\0') {
    i++;
  }
  s21_size_t j = 0;
  while ((src[j] != '\0') && (j < n)) {
    dest[i] = src[j];
    i++;
    j++;
  }
  dest[i] = '\0';
  return first;
}

char *s21_strchr(const char *str, int c) {
  while (*str != c && *str != '\0') {
    str++;
  }
  if (*str == c) {
    return (char *)str;
  } else {
    return s21_NULL;
  }
}

int s21_strcmp(const char *str1, const char *str2) {
  for (; *str1 == *str2 && *str1; ++str1, ++str2) {
  }
  if (!*str1 && !*str2) return 0;
  return *str1 - *str2;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  for (; *str1 == *str2 && *str1 && (n > 0); ++str1, ++str2) n--;
  if ((!*str1 && !*str2) || (n == 0)) return 0;
  return *str1 - *str2;
}

char *s21_strcpy(char *dest, const char *src) {
  char *first = dest;
  while ((*dest++ = *src++)) {
  }
  return first;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) dest[i] = src[i];
  for (; i < n; i++) dest[i] = '\0';
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  while (*str1 && !s21_strchr(str2, *str1++)) i++;
  return i;
}

char *s21_strerror(int s21_errnum) {
#ifndef MACOS
  if ((s21_errnum >= 0) && (s21_errnum <= 133)) {
    return STRERRORARRAY_LINUX[s21_errnum];
  } else {
    s21_sprintf(undef, "Unknown error %d", s21_errnum);
    return undef;
  }
#endif
#ifdef MACOS
  if ((s21_errnum >= 0) && (s21_errnum <= 106)) {
    return STRERRORARRAY_MACOS[s21_errnum];
  } else {
    s21_sprintf(undef, "Unknown error: %d", s21_errnum);
    return undef;
  }
#endif
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t count = 0;
  while (str[count] != '\0') count++;
  return count;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  while (!s21_strchr(str2, *str1) && *str1 != '\0') {
    str1++;
  }
  if (s21_strchr(str2, *str1) && *str1 != '\0') {
    return (char *)str1;
  } else {
    return s21_NULL;
  }
}

char *s21_strrchr(const char *str, int c) {
  char *r = s21_NULL;
  while (*str != '\0') {
    if (*str == c) r = (char *)str;
    str++;
  }
  if (*str == c) r = (char *)str;
  return r;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  while (*str1 && s21_strchr(str2, *str1++)) {
    i++;
  }
  return i;
}

int compare(const char *str1, const char *str2) {
  while (*str1 && *str2) {
    if (*str1 != *str2) {
      return 0;
    }
    str1++;
    str2++;
  }
  return (*str2 == '\0');
}

char *s21_strstr(const char *str1, const char *str2) {
  if (*str2 == '\0') return (char *)str1;
  while (*str1 != '\0') {
    if ((*str1 == *str2) && compare(str1, str2)) {
      return (char *)str1;
    }
    str1++;
  }
  return s21_NULL;
}

char *s21_strtok(char *str, const char *delim) {
  char *p, *ret;
  const char *q;
  static char *saveptr = s21_NULL;
  if (!str && !saveptr) return s21_NULL;
  if (!saveptr) {
    saveptr = str;
  }
  ret = saveptr;
  for (p = saveptr; *p != '\0'; p++) {
    for (q = delim; *q != '\0'; q++) {
      if (*p == *q) break;
    }
    if (*q == '\0') {
      break;
    }
  }
  if (*p == '\0') {
    saveptr = s21_NULL;
    return s21_NULL;
  }
  ret = p;
  for (; *p != '\0'; p++) {
    for (q = delim; *q != '\0'; q++) {
      if (*p == *q) break;
    }
    if (*q != '\0') {
      *p++ = '\0';
      break;
    }
  }
  saveptr = p;
  return ret;
}

void *s21_to_upper(const char *str) {
  if (str == s21_NULL) return s21_NULL;
  s21_size_t length = s21_strlen(str);
  char *newstr = malloc(sizeof(char) * (length + 1));
  if (newstr) {
    newstr[length] = '\0';
    s21_size_t i = 0;
    while (str[i] != '\0') {
      if ((str[i] >= 97) && (str[i] <= 122))
        newstr[i] = str[i] - 32;
      else
        newstr[i] = str[i];
      i++;
    }
  }
  return newstr;
}

void *s21_to_lower(const char *str) {
  if (str == s21_NULL) return s21_NULL;
  s21_size_t length = s21_strlen(str);
  char *newstr = malloc(sizeof(char) * (length + 1));
  if (newstr) {
    newstr[length] = '\0';
    s21_size_t i = 0;
    while (str[i] != '\0') {
      if ((str[i] >= 65) && (str[i] <= 90))
        newstr[i] = str[i] + 32;
      else
        newstr[i] = str[i];
      i++;
    }
  }
  return newstr;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t len1, len2, i;
  if (src != s21_NULL)
    len1 = s21_strlen(src);
  else
    len1 = 0;
  if (str != s21_NULL)
    len2 = s21_strlen(str);
  else
    len2 = 0;
  if (start_index > len1) return s21_NULL;
  char *newstr = malloc(sizeof(char) * (len1 + len2 + 1));
  if (newstr) {
    for (i = 0; i < start_index; i++) newstr[i] = src[i];
    for (i = start_index; i < start_index + len2; i++)
      newstr[i] = str[i - start_index];
    for (i = start_index + len2; i < len1 + len2; i++)
      newstr[i] = src[i - len2];
    newstr[len1 + len2] = '\0';
  }
  return newstr;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL) return s21_NULL;
  char def_trim_chars[1024];
  if (trim_chars != s21_NULL && s21_strlen(trim_chars) != 0)
    s21_strcpy(def_trim_chars, trim_chars);
  else
    s21_strcpy(def_trim_chars, "\t\n\v\r\f ");
  int len = s21_strlen(src);
  int newlength = len;
  char *srcfirst = (char *)src;
  char *srclast = (char *)src + len;
  if (len > 0) srclast--;
  while (s21_strchr(def_trim_chars, *srcfirst) && *srcfirst) {
    srcfirst++;
    newlength--;
  }
  while (s21_strchr(def_trim_chars, *srclast) && newlength > 0) {
    srclast--;
    newlength--;
  }
  char *newstr = malloc(sizeof(char) * (newlength + 1));
  if (newstr) {
    int i = 0;
    while (i < newlength) {
      newstr[i] = *srcfirst;
      srcfirst++;
      i++;
    }
    newstr[newlength] = '\0';
  }
  return newstr;
}

int s21_sprintf(char *str, const char *format, ...) {
  s21_size_t i = 0, j = 0;
  char *str_val = s21_NULL;
  va_list ap;
  va_start(ap, format);
  while (format[i] != '\0') {
    if (format[i] != '%') {
      str[j++] = format[i++];
      continue;
    }
    s_format s_flags = {0, 0, 0, 0, 0, 0, -1, '\0', '\0', 0, 0, '\0', 0};
    i++;
    if (format[i] == '\0') exit(EXIT_FAILURE);
    if (format[i] == '%') {
      str[j++] = format[i++];
      continue;
    }
    while (format[i] && format[i] == ' ' && format[i + 1] == ' ') i++;
    s21_parse_flags(format, &i, &s_flags);
    s21_parse_width(&ap, format, &i, &s_flags);
    s21_parse_accuracy(&ap, format, &i, &s_flags);
    s21_parse_length(format, &i, &s_flags);
    s_flags.spec = format[i];
    str_val = s21_switch_spec(&ap, j, &s_flags);
    s21_process_flags(str_val, &s_flags);
    s21_strcpy(&str[j], str_val);
    j += s21_strlen(str_val);
    if (str_val) free(str_val);
    str_val = s21_NULL;
    i++;
  }
  va_end(ap);
  str[j] = '\0';
  return j;
}

int s21_parse_flags(const char *format, s21_size_t *i, s_format *s_flags) {
  while (s21_strchr("# +-0", format[*i]) != s21_NULL && format[*i]) {
    if (format[*i] == '#' && s_flags->flag_r == 0)
      s_flags->flag_r = 1;
    else if (format[*i] == ' ' && s_flags->flag_s == 0)
      s_flags->flag_s = 1;
    else if (format[*i] == '+' && s_flags->flag_p == 0)
      s_flags->flag_p = 1;
    else if (format[*i] == '-' && s_flags->flag_m == 0)
      s_flags->flag_m = 1;
    else if (format[*i] == '0' && s_flags->flag_z == 0)
      s_flags->flag_z = 1;
    else
      break;
    (*i)++;
  }
  return 0;
}

int s21_parse_width(va_list *ap, const char *format, s21_size_t *i,
                    s_format *s_flags) {
  if (s21_strchr("-0123456789", format[*i]) != s21_NULL) {
    if (format[*i] == '-') (*i)++;
    while (s21_strchr("-0123456789", format[*i]) != s21_NULL) {
      s_flags->width = s_flags->width * 10 + ((int)format[*i] - '0');
      (*i)++;
    }
  } else if (format[*i] == '*') {
    s_flags->width = va_arg(*ap, int);
    if (s_flags->width < 0) {
      s_flags->width = -s_flags->width;
      s_flags->flag_m = 1;
    }
    (*i)++;
  }
  return 0;
}

int s21_parse_accuracy(va_list *ap, const char *format, s21_size_t *i,
                       s_format *s_flags) {
  if (format[*i] == '.') {
    (*i)++;
    if (s21_strchr("0123456789", format[*i]) != s21_NULL) {
      s_flags->accuracy = 0;
      while (s21_strchr("0123456789", format[*i]) != s21_NULL) {
        s_flags->accuracy = s_flags->accuracy * 10 + ((int)format[*i] - '0');
        (*i)++;
      }
    } else if (format[*i] == '*') {
      s_flags->accuracy = va_arg(*ap, int);
      if (s_flags->accuracy < 0) s_flags->accuracy = 6;
      (*i)++;
    } else {
      s_flags->accuracy = 0;
    }
  }
  return 0;
}

int s21_parse_length(const char *format, s21_size_t *i, s_format *s_flags) {
  if (s21_strchr("hlL", format[*i]) != s21_NULL) {
    s_flags->length = format[*i];
    (*i)++;
    if (s21_strchr("hlL", format[*i]) != s21_NULL) {
      s_flags->length2 = format[*i];
      (*i)++;
    }
  }
  return 0;
}

char *s21_switch_spec(va_list *ap, s21_size_t j, s_format *s_flags) {
  char *res = s21_NULL;
  switch (s_flags->spec) {
    case 'n': {
      res = s21_process_spec_n(ap, j);
      break;
    }
    case 'i':
    case 'd': {
      res = s21_process_spec_id(ap, s_flags);
      break;
    }
    case 'X':
    case 'x':
    case 'u':
    case 'o': {
      res = s21_process_spec_xuo(ap, s_flags);
      break;
    }
    case 'p': {
      res = s21_process_spec_p(ap, s_flags);
      break;
    }
    case 'f': {
      res = s21_process_spec_f(ap, s_flags);
      break;
    }
    case 'E':
    case 'e': {
      res = s21_process_spec_e(ap, s_flags);
      break;
    }
    case 'G':
    case 'g': {
      res = s21_process_spec_g(ap, s_flags);
      break;
    }
    case 'c': {
      res = s21_process_spec_c(ap, s_flags);
      break;
    }
    case 's': {
      res = s21_process_spec_s(ap, s_flags);
      break;
    }
    default:
      exit(EXIT_FAILURE);
  }
  return res;
}

char *s21_process_spec_n(va_list *ap, s21_size_t j) {
  int *n = va_arg(*ap, int *);
  *n = j;
  char *res = calloc(1, sizeof(char));
  if (!res) exit(EXIT_FAILURE);
  return res;
}

char *s21_process_spec_id(va_list *ap, s_format *s_flags) {
  int base = 10;
  char *res = s21_NULL;
  if (s_flags->length == 'h' && s_flags->length2 != 'h')
    res = s21_itoa((short)va_arg(*ap, int), base, s_flags);
  else if (s_flags->length == 'h' && s_flags->length2 == 'h')
    res = s21_itoa((signed char)va_arg(*ap, int), base, s_flags);
  else if (s_flags->length == 'l' && s_flags->length2 != 'l')
    res = s21_itoa(va_arg(*ap, long int), base, s_flags);
  else if (s_flags->length == 'l' && s_flags->length2 == 'l')
    res = s21_itoa(va_arg(*ap, long long int), base, s_flags);
  else
    res = s21_itoa(va_arg(*ap, int), base, s_flags);
  return res;
}

char *s21_process_spec_xuo(va_list *ap, s_format *s_flags) {
  s_flags->unsign = 1;
  char *res = s21_NULL;
  int base = 10;
  if (s_flags->spec == 'x' || s_flags->spec == 'X') base = 16;
  if (s_flags->spec == 'o') base = 8;
  if (s_flags->length == 'h' && s_flags->length2 != 'h')
    res = s21_itoa((unsigned short)va_arg(*ap, int), base, s_flags);
  else if (s_flags->length == 'h' && s_flags->length2 == 'h')
    res = s21_itoa((unsigned char)va_arg(*ap, int), base, s_flags);
  else if (s_flags->length == 'l' && s_flags->length2 != 'l')
    res = s21_itoa(va_arg(*ap, unsigned long), base, s_flags);
  else if (s_flags->length == 'l' && s_flags->length2 == 'l')
    res = s21_itoa(va_arg(*ap, unsigned long long), base, s_flags);
  else
    res = s21_itoa(va_arg(*ap, unsigned int), base, s_flags);
  return res;
}

char *s21_process_spec_p(va_list *ap, s_format *s_flags) {
  char *res = s21_NULL;
  s_flags->flag_r = 1;
  res = s21_itoa(va_arg(*ap, unsigned long long int), 16, s_flags);
  return res;
}

char *s21_process_spec_f(va_list *ap, s_format *s_flags) {
  char *res = s21_NULL;
  if (s_flags->accuracy < 0) s_flags->accuracy = 6;
  if (s_flags->length == 'L')
    res = s21_ftoa(va_arg(*ap, long double), s_flags->accuracy, s_flags);
  else
    res = s21_ftoa(va_arg(*ap, double), s_flags->accuracy, s_flags);
  return res;
}

char *s21_process_spec_e(va_list *ap, s_format *s_flags) {
  char *res = s21_NULL;
  if (s_flags->accuracy == -1) s_flags->accuracy = 6;
  if (s_flags->length == 'L')
    res = s21_ftoexp(va_arg(*ap, long double), s_flags);
  else
    res = s21_ftoexp(va_arg(*ap, double), s_flags);
  return res;
}

char *s21_process_spec_g(va_list *ap, s_format *s_flags) {
  char *res = s21_NULL;
  if (s_flags->accuracy == -1) s_flags->accuracy = 6;
  if (s_flags->length == 'L')
    res = s21_ftog(va_arg(*ap, long double), s_flags);
  else
    res = s21_ftog(va_arg(*ap, double), s_flags);
  return res;
}

char *s21_process_spec_c(va_list *ap, s_format *s_flags) {
  char *res = s21_NULL;
  int c = va_arg(*ap, wchar_t);
  int bytes = ((c >> 16 > 0) ? 4 : (c >> 12 > 0) ? 3 : (c >> 8 > 0) ? 2 : 1);
  res = calloc(abs(s_flags->width) + bytes + 1, sizeof(char));
  if (!res) exit(EXIT_FAILURE);
  wcstombs(res, &c, bytes);
  return res;
}

char *s21_process_spec_s(va_list *ap, s_format *s_flags) {
  char *res = s21_NULL;
  if (s_flags->length == 'l' && s_flags->length2 != 'l') {
    wchar_t *tmp = va_arg(*ap, wchar_t *);
    res = s21_wcstombs(tmp, s_flags);
  } else {
    char *tmp = va_arg(*ap, char *);
    int len_dif = 0;
    int acc = (int)s21_strlen(tmp);
    if (s_flags->accuracy > 0 &&
        ((int)s21_strlen(tmp) - s_flags->accuracy > 0)) {
      len_dif = (int)s21_strlen(tmp) - s_flags->accuracy;
      acc = s_flags->accuracy;
    }
    res = calloc((int)s21_strlen(tmp) - len_dif + s_flags->width + 1,
                 sizeof(char));
    if (!res) exit(EXIT_FAILURE);
    int k = 0;
    while (tmp[k] != '\0' && k < acc) {
      res[k] = tmp[k];
      k++;
    }
    res[k] = '\0';
  }
  return res;
}

void s21_reverse(char str[], int len) {
  int start, end;
  char temp;
  for (start = 0, end = len - 1; start < end; start++, end--) {
    temp = *(str + start);
    *(str + start) = *(str + end);
    *(str + end) = temp;
  }
}

int s21_atoi(char *str) {
  int res = 0;
  for (int i = 0; str[i] != '\0'; ++i) res = res * 10 + str[i] - '0';
  return res;
}

void s21_process_flags(char *str, s_format *s_flags) {
  int len = s21_strlen(str);
  int i = len;
  int width = s_flags->width;
  char c = ' ';
  s21_reverse(str, len);
  if (s_flags->flag_z == 0) {
    if (s_flags->flag_s == 1 || s_flags->flag_p == 1 || s_flags->flag_m == 1) {
      if (s_flags->flag_p == 1 && s_flags->spec != 'u' &&
          s_flags->spec != 'c' && s_flags->spec != 's' &&
          s_flags->spec != 'x' && s_flags->spec != 'X' &&
          s_flags->spec != 'o' && s_flags->is_negative == 0) {
        str[i++] = '+';
      }
    }
    if (s_flags->is_negative == 1) str[i++] = '-';
  }
  if (s_flags->flag_z == 1) c = '0';
  if (s_flags->flag_r == 1) {
    if (s_flags->spec == 'p' && s21_atoi(str) == 0) {
      i = 0;
#ifndef MACOS
      str[i++] = ')';
      str[i++] = 'l';
      str[i++] = 'i';
      str[i++] = 'n';
      str[i++] = '(';
#endif
#ifdef MACOS
      str[i++] = '0';
      str[i++] = 'x';
      str[i++] = '0';
#endif
    } else if ((s_flags->spec == 'x' || s_flags->spec == 'p') &&
               s21_atoi(str) != 0) {
      str[i++] = 'x';
      str[i++] = '0';
      width -= 2;
    } else if (s_flags->spec == 'X' && s21_atoi(str) != 0) {
      str[i++] = 'X';
      str[i++] = '0';
      width -= 2;
    } else if (s_flags->spec == 'o') {
      if (str[i - 1] != '0') {
        str[i++] = '0';
        width -= 1;
      }
    }
    str[i] = '\0';
  }
  if (s_flags->unsign == 1) s_flags->is_negative = 0;
  if ((s_flags->is_negative == 1 || s_flags->flag_p == 1) &&
      s_flags->spec != 's' && s_flags->spec != 'c' && s_flags->spec != 'u') {
    width = width - len - 1;
  } else {
    width -= len;
  }
  if (s_flags->flag_m == 0 && width > 0) {
    while (width > 0) {
      if (width == 1 && s_flags->flag_s == 1 && s_flags->flag_z == 1)
        str[i++] = ' ';
      else
        str[i++] = c;
      width--;
    }
  } else if (width <= 0 && s_flags->flag_s == 1 && s_flags->is_negative == 0 &&
             s_flags->flag_p == 0 && s_flags->spec != 'c' &&
             s_flags->spec != 's' && s_flags->spec != 'u') {
    str[i++] = ' ';
  }
  if (s_flags->flag_z == 1) {
    if (s_flags->flag_s == 1 || s_flags->flag_p == 1 || s_flags->flag_m == 1) {
      if (s_flags->flag_p == 1 && s_flags->spec != 'u' &&
          s_flags->spec != 'c' && s_flags->spec != 's' &&
          s_flags->is_negative == 0)
        str[i++] = '+';
    }
    if (s_flags->is_negative == 1) str[i++] = '-';
  }
  str[i] = '\0';
  s21_reverse(str, i);
  if (s_flags->flag_m == 1) {
    while (width > 0) {
      str[i++] = c;
      width--;
    }
  }
  str[i] = '\0';
}

char *s21_itoa(long long num, int base, s_format *s_flags) {
  int i = 0;
  s21_size_t temp_num = num;
  char upper_letter = (s_flags->spec == 'X') ? 'A' : 'a';
  char *temp_str = calloc(BUFFERSIZE, sizeof(char));
  if (!temp_str) exit(EXIT_FAILURE);
  if (temp_num == 0) {
    if (s_flags->accuracy == 0 && s_flags->spec != 'f') {
      temp_str[i] = '\0';
      return temp_str;
    } else if (s_flags->accuracy == -1) {
      temp_str[i] = '0';
      temp_str[i + 1] = '\0';
      return temp_str;
    } else if (s_flags->spec == 'g' || s_flags->spec == 'G') {
      temp_str[i] = '0';
      temp_str[i + 1] = '\0';
      return temp_str;
    }
  }
  if (num < 0 && base == 10 && s_flags->float_part == 0) {
    s_flags->is_negative = 1;
    if (s_flags->unsign == 0) temp_num = -num;
  }
  while (temp_num) {
    int rem = temp_num % base;
    temp_str[i++] = (rem > 9) ? (rem - 10) + upper_letter : rem + '0';
    temp_num /= base;
  }

  //  точность для 16 и 8-ричных систем счислений заполняется нулями
  if (s21_strchr("xXouid", s_flags->spec) != s21_NULL) {
    int acc = s_flags->accuracy;
    if (acc > 0) acc -= (int)s21_strlen(temp_str);
    while (acc > 0) {
      temp_str[i++] = '0';
      acc--;
    }
    if (s21_strchr("xXo", s_flags->spec) != s21_NULL) s_flags->flag_z = 0;
  }
  if (num == 0 && s_flags->spec == 'f') temp_str[i++] = '0';
  temp_str[i] = '\0';
  s21_reverse(temp_str, i);
  return temp_str;
}

char *s21_ftoa(long double f, int acc, s_format *s_flags) {
  int accuracy = acc;
  char *str = s21_NULL, *part = s21_NULL;
  long long int int_part;
  if (acc > 0) f = roundl(f * pow(10, acc)) / pow(10, acc);
  if (isinf(f) || isnan(f)) {
    str = s21_naninf(f, s_flags);
  } else {
    if (signbit(f)) {
      s_flags->is_negative = 1;
      f = -f;
    }
    if (acc > 0)
      int_part = (long long int)(f + EPSILON_VALUE);
    else
      int_part = (long long int)(roundl(f) + EPSILON_VALUE);
    long double float_part = f - (long double)int_part;
    if (float_part < 0) {
      float_part = -float_part;
    }
    str = s21_itoa(int_part, 10, s_flags);
    s21_size_t len = s21_strlen(str);
    if (acc == 0 && s_flags->flag_r == 1) str[len] = '.';
    if (acc > 0) {
      str[len] = '.';
      long long int temp_itoa = 0;
      while (accuracy > 0) {
        float_part *= 10;
        accuracy--;
      }
      temp_itoa = (long long int)(float_part + 0.5f);
      part = s21_itoa(temp_itoa, 10, s_flags);
      int part_len = (int)s21_strlen(part);
      int i = part_len;
      s21_reverse(part, part_len);
      accuracy = acc - part_len;
      while (accuracy > 0) {
        part[i++] = '0';
        accuracy--;
      }
      part[i] = '\0';
      s21_reverse(part, i);
      s_flags->float_part = 0;
      s21_strcpy(&str[++len], part);
      free(part);
    }
  }
  return str;
}

int s21_delendzero(char *str) {
  int size_str = s21_strlen(str);
  if (size_str > 0) {
    while (str[size_str - 1] == '0' || str[size_str - 1] == '.') {
      char c = str[size_str - 1];
      str[size_str - 1] = '\0';
      size_str--;
      if ((size_str == 0) || c == '.' || (size_str == 1 && str[0] == '0'))
        break;
    }
  }
  return 0;
}

char *s21_naninf(long double f, s_format *s_flags) {
  char *str = calloc(BUFFERSIZE, sizeof(char));
  if (!str) exit(EXIT_FAILURE);
  int i = 0;
  if (isinf(f)) {
    if (signbit(f)) str[i++] = '-';
    if (s_flags->spec == 'G' || s_flags->spec == 'E') {
      str[i++] = 'I';
      str[i++] = 'N';
      str[i++] = 'F';
    } else {
      str[i++] = 'i';
      str[i++] = 'n';
      str[i++] = 'f';
    }
  } else if (isnan(f)) {
#ifndef MACOS
    if (signbit(f)) str[i++] = '-';
#endif
    if (s_flags->spec == 'G' || s_flags->spec == 'E') {
      str[i++] = 'N';
      str[i++] = 'A';
      str[i++] = 'N';
    } else {
      str[i++] = 'n';
      str[i++] = 'a';
      str[i++] = 'n';
    }
  }
  str[i++] = '\0';
  return str;
}

char *s21_ftoexp(long double f, s_format *s_flags) {
  char *str = s21_NULL;
  long double temp = (long double)f;
  s21_size_t i = 0;
  long long int int_part = 0;
  int e = 0;
  if (isinf(f) || isnan(f)) {
    str = s21_naninf(f, s_flags);
  } else {
    if (signbit(temp)) {
      temp = -temp;
      s_flags->is_negative = 1;
    }
    while (temp > 0) {
      int_part = (long long int)(temp + EPSILON_VALUE);
      if ((int_part > 0 && int_part < 10)) {
        break;
      } else if (int_part >= 10) {
        temp /= 10;
        e += 1;
      } else if (int_part == 0) {
        temp *= 10;
        e -= 1;
      }
    }
    s_format s_temp = {
        s_flags->flag_r, 0, 0, 0, 0, 0, -1, '\0', '\0', 0, 0, '\0', 0};
    int ifg = 0;
    str = s21_ftoa(temp, s_flags->accuracy, &s_temp);
    if (s_flags->spec == 'g') {
      if (s_flags->flag_r == 0) s21_delendzero(str);
      s_flags->spec = 'e';
      ifg = 1;
    }
    if (s_flags->spec == 'G') {
      if (s_flags->flag_r == 0) s21_delendzero(str);
      s_flags->spec = 'E';
      ifg = 1;
    }
    if (e != 0 || ifg == 0) {
      i = s21_strlen(str);
      str[i++] = s_flags->spec;
      if (e < 0)
        str[i++] = '-';
      else
        str[i++] = '+';
      char *tm = s21_itoa(e, 10, &s_temp);
      if (s21_strlen(tm) < 2) str[i++] = '0';
      s21_strcpy(&str[i], tm);
      free(tm);
    }
  }
  return str;
}

char *s21_ftog(long double f, s_format *s_flags) {
  char *str = s21_NULL;
  long double temp = (long double)f;
  if (isinf(f) || isnan(f)) {
    str = s21_naninf(f, s_flags);
  } else {
    if (signbit(temp)) {
      temp = -temp;
      s_flags->is_negative = 1;
    }
    double tmp = temp;
    if (tmp < 0) tmp = -tmp;
    int count_c = 0;
    if (tmp == 0) count_c = 1;
    while (tmp >= 1) {
      tmp = tmp / 10;
      count_c++;
    }
    int pos_right = count_c;
    while (temp < pow(10, pos_right) && temp != 0) pos_right--;
    if (count_c > s_flags->accuracy || pos_right < -4) {
      if (s_flags->accuracy > 0) s_flags->accuracy--;
      str = s21_ftoexp(f, s_flags);
    } else {
      if (pos_right < 0 && s_flags->accuracy < abs(pos_right))
        s_flags->accuracy = abs(pos_right);
      str = s21_ftoa(f, s_flags->accuracy - count_c, s_flags);
      if (s_flags->flag_r == 0) s21_delendzero(str);
    }
  }
  return str;
}

char *s21_wcstombs(wchar_t *wc_str, s_format *s_flags) {
  int bytes = 0;
  wchar_t *tmp = wc_str;
  while (1) {
    if (*tmp <= 0) break;
    unsigned int c = *tmp++;
    bytes += ((c >> 24 > 0)   ? 5
              : (c >> 16 > 0) ? 4
              : (c >> 12 > 0) ? 3
              : (c >> 8 > 0)  ? 2
                              : 1);
  }
  int len_dif = 0;
  if (s_flags->accuracy > 0 && (bytes - s_flags->accuracy > 0)) {
    len_dif = bytes - s_flags->accuracy;
  }
  char *cstr = calloc(bytes - len_dif + 1 + s_flags->width, sizeof(char));
  if (!cstr) exit(EXIT_FAILURE);
  wcstombs(cstr, wc_str, bytes - len_dif);
  return cstr;
}

int s21_sscanf(const char *str, const char *format, ...) {
  s21_size_t i = 0, j = 0;
  int count_success = 0, error = 0;
  va_list ap;
  va_start(ap, format);
  if (s21_strspn(str, SPACE_SYM) == s21_strlen(str)) {
    count_success = -1;
    if (s21_strspn(format, SPACE_SYM) == s21_strlen(format)) count_success = 0;
    error = 1;
  }
  while (format[j] != '\0' && !error) {
    if (s21_strchr(SPACE_SYM, format[j]) != s21_NULL) {
      s21_delete_spaces(format, &j);
      s21_delete_spaces(str, &i);
    }
    if (format[j] == '\0') break;
    if (format[j] != '%') {
      if (str[i] != format[j]) error++;
      i++;
      j++;
      continue;
    }
    j++;
    if (format[j] == '%') {
      s21_delete_spaces(str, &i);
      if (str[i] != '%') error++;
      j++;
      i++;
      continue;
    }
    sscanf_flags sscanf_format = {0};
    s21_parse_format(&sscanf_format, format, &j, &error);
    if (sscanf_format.spec != 'c') s21_delete_spaces(str, &i);
    s21_switch_cpec(&sscanf_format, &ap, str, &i, &count_success, &error);
  }
  va_end(ap);
  return count_success;
}

int s21_get_base(const char *str, s21_size_t *i) {
  int base = 10;
  if (str[*i] == '0' && (str[*i + 1] == 'x' || str[*i + 1] == 'X')) {
    base = 16;
  } else if (str[*i] == '0') {
    base = 8;
  }
  return base;
}

int s21_char2int(char c) {
  if (c == 'a' || c == 'A')
    return 10;
  else if (c == 'b' || c == 'B')
    return 11;
  else if (c == 'c' || c == 'C')
    return 12;
  else if (c == 'd' || c == 'D')
    return 13;
  else if (c == 'e' || c == 'E')
    return 14;
  else if (c == 'f' || c == 'F')
    return 15;
  else
    return c - '0';
}

int s21_get_sign(sscanf_flags *f, const char *str, s21_size_t *i, int *error) {
  int sign = 1;
  if (str[*i] == '-') {
    sign = -1;
    (*i)++;
    if (f->weight > 0) {
      (f->weight)--;
      if (f->weight == 0) (*error)++;
    }
  } else if (str[*i] == '+') {
    (*i)++;
    if (f->weight > 0) {
      (f->weight)--;
      if (f->weight == 0) (*error)++;
    }
  }
  return sign;
}

int s21_checkinf(const char *str, s21_size_t *i) {
  int isinf = 0;
  if ((str[*i] == 'I' || str[*i] == 'i') &&
      (str[*i + 1] == 'N' || str[*i + 1] == 'n') &&
      (str[*i + 2] == 'F' || str[*i + 2] == 'f')) {
    isinf = 1;
  }
  return isinf;
}

int s21_checknan(const char *str, s21_size_t *i) {
  int isnan = 0;
  if ((str[*i] == 'N' || str[*i] == 'n') &&
      (str[*i + 1] == 'A' || str[*i + 1] == 'a') &&
      (str[*i + 2] == 'N' || str[*i + 2] == 'n')) {
    isnan = 1;
  }
  return isnan;
}

long long int s21_get_number(sscanf_flags *flags, const char *str,
                             s21_size_t *i, int *error, int base) {
  char sym[] = "0123456789ABCDEFabcdef";
  int overload = 0;
  long long int result = 0, old = 0;
  int sign = s21_get_sign(flags, str, i, error);
  if (base == 0) base = s21_get_base(str, i);
  if (base == 10) sym[10] = '\0';
  if (base == 8) sym[8] = '\0';
  int f0x = 0;
  if (base == 16 && str[*i] == '0' &&
      (str[*i + 1] == 'x' || str[*i + 1] == 'X')) {
    *i = *i + 2;
    f0x = 1;
  }
  if (s21_strchr(sym, str[*i]) != s21_NULL && str[*i]) {
    while (s21_strchr(sym, str[*i]) != s21_NULL && str[*i] &&
           flags->weight != 0) {
      old = result;
      result = result * base + s21_char2int(str[*i]);
      if (result < old) overload = 1;
      (*i)++;
      (flags->weight)--;
    }
  } else if (f0x == 0) {
    (*error)++;
  }
  if (overload == 1) {
    if (sign == 1) {
      result = LLONG_MAX;
    } else {
      result = LLONG_MIN;
    }
  } else {
    result = sign * result;
  }
  return result;
}

unsigned long long int s21_get_unumber(sscanf_flags *flags, const char *str,
                                       s21_size_t *i, int *error, int base) {
  char sym[] = "0123456789ABCDEFabcdef";
  int overload = 0;
  unsigned long long int result = 0, old = 0;
  int sign = s21_get_sign(flags, str, i, error);
  if (base == 0) base = s21_get_base(str, i);
  if (base == 10) sym[10] = '\0';
  if (base == 8) sym[8] = '\0';
  int f0x = 0;
  if (base == 16 && str[*i] == '0' &&
      (str[*i + 1] == 'x' || str[*i + 1] == 'X')) {
    *i = *i + 2;
    f0x = 1;
  }
  if (s21_strchr(sym, str[*i]) != s21_NULL && str[*i]) {
    while (s21_strchr(sym, str[*i]) != s21_NULL && str[*i] &&
           flags->weight != 0) {
      old = result;
      result = result * base + s21_char2int(str[*i]);
      if (result < old) overload = 1;
      (*i)++;
      (flags->weight)--;
    }
  } else {
    if (f0x == 0) (*error)++;
  }
  if (overload == 1)
    result = ULLONG_MAX;
  else
    result = sign * result;
  return result;
}

long double s21_get_fnumber(sscanf_flags *flags, const char *str, s21_size_t *i,
                            int *error) {
  char sym[] = "0123456789";
  long long int tmp = 0;
  long double result = 0;
  int temp_i = *i;
  int sign = s21_get_sign(flags, str, i, error);
  if (s21_checkinf(str, i)) {
    result = 1.0 / 0.0;
    *i = *i + 3;
  } else if (s21_checknan(str, i)) {
    result = 0.0 / 0.0;
    *i = *i + 3;
  } else {
    if (s21_strchr(sym, str[*i]) != s21_NULL && str[*i]) {
      while (s21_strchr(sym, str[*i]) != s21_NULL && str[*i] &&
             flags->weight != 0) {
        result = result * 10 + s21_char2int(str[*i]);
        (*i)++;
        (flags->weight)--;
      }
    }
    if (str[*i] == '.' && !(*error) && flags->weight != 0) {
      (*i)++;
      long double dr = 0.1;
      if (s21_strchr(sym, str[*i]) != s21_NULL && str[*i]) {
        (flags->weight)--;
        while (s21_strchr(sym, str[*i]) != s21_NULL && str[*i] &&
               flags->weight != 0) {
          result = result + s21_char2int(str[*i]) * dr;
          dr = dr / 10;
          (*i)++;
          (flags->weight)--;
        }
      } else {
        if (*i - temp_i == 1) (*error)++;
      }
    }
    if ((str[*i] == 'e' || str[*i] == 'E') && !(*error)) {
      (*i)++;
      (flags->weight)--;
      tmp = s21_get_number(flags, str, i, error, 10);
      if (tmp > 0) {
        while (tmp > 0) {
          result = result * 10;
          tmp--;
        }
      }
      if (tmp < 0) {
        while (tmp < 0) {
          result = result / 10;
          tmp++;
        }
      }
    }
    if (sign == -1 && result > 0) result = sign * result;
    if (*i - temp_i == 0) (*error)++;
  }
  return result;
}

int s21_get_char(sscanf_flags *flags, va_list *vargs, const char *str,
                 s21_size_t *i, int *count) {
  if (flags->ast == 0) {
    char *c = va_arg(*vargs, char *);
    *c = str[*i];
    (*count)++;
  }
  (*i)++;
  return 0;
}

int s21_get_str(sscanf_flags *flags, va_list *vargs, const char *str,
                s21_size_t *i, int *count, int *error) {
  int resit = 0;
  if (flags->weight == 0) flags->weight = -1;
  char *res;
  if (flags->ast == 0)
    res = va_arg(*vargs, char *);
  else
    res = s21_NULL;
  while (s21_strchr(SPACE_SYM, str[*i]) == s21_NULL && str[*i] &&
         flags->weight != 0) {
    if (flags->ast == 0) res[resit] = str[*i];
    (*i)++;
    (flags->weight)--;
    resit++;
  }
  if (flags->ast == 0) {
    if (resit > 0) {
      res[resit] = '\0';
      (*count)++;
    } else {
      (*error)++;
    }
  }
  return 0;
}

int s21_save_number(sscanf_flags *flags, va_list *vargs, long long int t,
                    int *count) {
  if (flags->ast == 0) {
    if (flags->length == 'h') {
      short int *si = va_arg(*vargs, short int *);
      *si = t;
    } else if (flags->length == 'l') {
      long int *si = va_arg(*vargs, long int *);
      *si = t;
    } else if (flags->length == 'L') {
      long long int *si = va_arg(*vargs, long long int *);
      *si = t;
    } else {
      int *si = va_arg(*vargs, int *);
      *si = t;
    }
    (*count)++;
  }
  return 0;
}

int s21_save_unumber(sscanf_flags *flags, va_list *vargs, long long int t,
                     int *count) {
  if (flags->ast == 0) {
    if (flags->length == 'h') {
      unsigned short int *si = va_arg(*vargs, unsigned short int *);
      *si = t;
    } else if (flags->length == 'l') {
      unsigned long int *si = va_arg(*vargs, unsigned long int *);
      *si = t;
    } else if (flags->length == 'L') {
      unsigned long long int *si = va_arg(*vargs, unsigned long long int *);
      *si = t;
    } else {
      unsigned int *si = va_arg(*vargs, unsigned int *);
      *si = t;
    }
    (*count)++;
  }
  return 0;
}

int s21_save_fnumber(sscanf_flags *flags, va_list *vargs, long double t,
                     int *count) {
  if (flags->ast == 0) {
    if (flags->length == 'L') {
      long double *si = va_arg(*vargs, long double *);
      *si = t;
    } else if (flags->length == 'l') {
      double *si = va_arg(*vargs, double *);
      *si = t;
    } else {
      float *si = va_arg(*vargs, float *);
      *si = t;
    }
    (*count)++;
  }
  return 0;
}

int s21_parse_format(sscanf_flags *flags, const char *format, s21_size_t *j,
                     int *error) {
  if (format[*j] == '*') {
    flags->ast = 1;
    (*j)++;
  }
  if (format[*j] >= '0' && format[*j] <= '9') {
    while (format[*j] >= '0' && format[*j] <= '9') {
      flags->weight = flags->weight * 10 + (format[*j] - '0');
      (*j)++;
    }
  }
  if (flags->weight == 0) flags->weight = -1;
  if (s21_strchr("hlL", format[*j]) != s21_NULL) {
    if (format[*j] == 'l' && format[*j + 1] == 'l') {
      flags->length = 'L';
      *j = *j + 2;
    } else {
      flags->length = format[*j];
      (*j)++;
    }
  }
  if (s21_strchr("cdieEfgGosuxXpn", format[*j]) != s21_NULL) {
    flags->spec = format[*j];
    (*j)++;
  } else {
    (*error)++;
  }
  return 0;
}

int s21_switch_cpec(sscanf_flags *flags, va_list *vargs, const char *str,
                    s21_size_t *i, int *count, int *error) {
  switch (flags->spec) {
    case 'c':
      s21_get_char(flags, vargs, str, i, count);
      break;
    case 's': {
      s21_get_str(flags, vargs, str, i, count, error);
      break;
    }
    case 'u': {
      unsigned long long int tmp = s21_get_unumber(flags, str, i, error, 10);
      if (!*error) s21_save_unumber(flags, vargs, tmp, count);
      break;
    }
    case 'd': {
      long long int tmp = s21_get_number(flags, str, i, error, 10);
      if (!*error) s21_save_number(flags, vargs, tmp, count);
      break;
    }
    case 'i': {
      long long int tmp = s21_get_number(flags, str, i, error, 0);
      if (!*error) s21_save_number(flags, vargs, tmp, count);
      break;
    }
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G': {
      long double tmp = s21_get_fnumber(flags, str, i, error);
      if (!*error) s21_save_fnumber(flags, vargs, tmp, count);
      break;
    }
    case 'o': {
      long long int tmp = s21_get_unumber(flags, str, i, error, 8);
      if (!*error) s21_save_unumber(flags, vargs, tmp, count);
      break;
    }
    case 'x':
    case 'X': {
      long long int tmp = s21_get_unumber(flags, str, i, error, 16);
      if (!*error) s21_save_unumber(flags, vargs, tmp, count);
      break;
    }
    case 'p': {
      flags->length = 'L';
      unsigned long long int tmp = s21_get_unumber(flags, str, i, error, 16);
      if (!*error) s21_save_unumber(flags, vargs, tmp, count);
      break;
    }
    case 'n': {
      int *n = va_arg(*vargs, int *);
      *n = *i;
      break;
    }
  }
  return 0;
}

int s21_delete_spaces(const char *str, s21_size_t *i) {
  while (s21_strchr(SPACE_SYM, str[*i]) != s21_NULL && str[*i] != '\0') (*i)++;
  return 0;
}

char *STRERRORARRAY_LINUX[134] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};

char *STRERRORARRAY_MACOS[107] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"};
