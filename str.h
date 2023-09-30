/* header file for the Str module*/

#ifndef str
#define str

#include <stddef.h>

/* Comment src, function*/
size_t Str_getLength(const char src[]);

/* Comment out, src, function*/
char * Str_copy(char out[], const char src[]);

/* Comment out, src, function*/
char * Str_concat(char out[], const char src[]);

/* Comment s1, s2, function*/
int Str_compare(const char s1[], const char s2[]);

/* Comment haystack, needle, start, len_needle, function*/
int Str_scan_match(const char haystack[], const char needle[], size_t start, size_t len_needle);

/* Comment haystack, needle, function*/
char * Str_search(const char haystack[], const char needle[]);

#endif