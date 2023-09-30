#ifndef str
#define str

#include <stddef.h>

size_t Str_getLength(const char src[]);

char * Str_copy(char out[], const char src[]);

char * Str_concat(char out[], const char src[]);

int Str_compare(const char s1[], const char s2[]);

int scan_match(const char haystack[], const char needle[], size_t start, size_t len_needle);

char * Str_search(const char haystack[], const char needle[]);

#endif