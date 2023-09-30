#ifndef str
#define str

#include <stddef.h>

/* Comment */
size_t Str_getLength(const char src[]);

/* Comment */
char * Str_copy(char out[], const char src[]);

/* Comment */
char * Str_concat(char out[], const char src[]);

/* Comment */
int Str_compare(const char s1[], const char s2[]);

/* Comment */
int Str_scan_match(const char haystack[], const char needle[], size_t start, size_t len_needle);

/* Comment */
char * Str_search(const char haystack[], const char needle[]);

#endif