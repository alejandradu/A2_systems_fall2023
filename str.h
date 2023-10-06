/* header file for the Str module
*  the functions pass array-type arguments, 
*  but these are analogous to the functions that pass pointers */

#ifndef str
#define str

#include <stddef.h>

 /*  Get length of a string up to the first NULL                                                                                                                                                                                                                                                                               
 *                                                                                                                                                                                        
 *   src: null-terminated char array                                                                                                                                 
 *                                                                                                                                                                                        
 *   returns: number of chars before NULL (long unsigned int) */
size_t Str_getLength(const char src[]);

 /*  Copy one string literal to another                                                                                                                                                                                                                                                                                
 *                                                                                                                                                                        
 *   src: null-terminated char array     
 *   out: char array at least as big as src, where src is copied                                                                                                                           
 *                                                                                                                                                                                        
 *   returns: array (pointer to the first element) with src copy */
char * Str_copy(char out[], const char src[]);

 /*  Concatenate one string literal to another                                                                                                                                                                                                                                                                                
 *   Overwrites the (first) NULL termination of the initial
 *   char sequence in out. Adds src immediately after.
 *                                                                                                                                                                     
 *   src: null-terminated char array     
 *   out: null-terminated char array with enough empty elements to fit 
 *   src                                                                                                                          
 *                                                                                                                                                                                        
 *   returns: array (pointer to the first element) with concatenation */
char * Str_concat(char out[], const char src[]);

 /*  Compare two string literals                                                                                                                                                                                                                                                                               
 *   Uses the continuity of ASCII representation
 *   to compare chars with logical operators.
 *                                                                                                                                                                     
 *   s1: null-terminated char array     
 *   s2: null-terminated char array                                                                                                                          
 *                                                                                                                                                                                        
 *   returns: (int) 0 if s1 == s2, 1 if s1 > s2, -1 if s2 > s1 */
int Str_compare(const char s1[], const char s2[]);

 /*  Search for the first match of a given string literal (the needle)
 *   in another string literal (the haystack)
 *                                                                                                                                                                     
 *   haystack: null-terminated char array, at least as big as needle     
 *   needle: null-terminated char array                                                                                                              
 *                                                                                                                                                                                        
 *   returns: NULL if needle is empty or if no matches, or
 *            pointer to the first element in haystack of match found */
char * Str_search(const char haystack[], const char needle[]);

#endif