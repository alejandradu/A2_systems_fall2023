#include <stdio.h>
#include <stddef.h>
#include <assert.h>  
#include "str.h"

/*  QUESTION: how is the length of char arrays, or arrays in general, limited? 

QUESTION: can't use sizeof, have to call other, but that requires const,
do i do a temp? 

QUESTION: ASCII continuity */


 /*  Get length of a string up to the first NULL                                                                                                                                                                                                                                                                               
 *                                                                                                                                                                                        
 *   src: null-terminated char array                                                                                                                                 
 *                                                                                                                                                                                        
 *   returns: number of chars before NULL (long unsigned int) */

size_t Str_getLength(const char src[])
{
   size_t uLength = 0;
   assert(src != NULL); 
   while (src[uLength] != '\0') 
      uLength++;
   return uLength;
}

 /*  Copy one string literal to another                                                                                                                                                                                                                                                                                
 *                                                                                                                                                                        
 *   src: null-terminated char array     
 *   out: char array at least as big as src, where src is copied                                                                                                                           
 *                                                                                                                                                                                        
 *   returns: array (pointer to the first element) with src copy */

char * Str_copy(char out[], const char src[])
{
   size_t LenOut = Str_getLength(out), i = 0;
   assert(src != NULL); 
   assert(out != NULL);

   while(src[i] != '\0') {      /* copy all chars up until first null*/
      out[i] = src[i];
      i++;
   }
   while(i <= LenOut) {          /* add final null and fill any overhang BUG */   
      out[i] = '\0';
      i++;
   }
   return out;

}

 /*  Concatenate one string literal to another                                                                                                                                                                                                                                                                                
 *   Overwrites the (first) NULL termination of the initial
 *   char sequence in out. Adds src immediately after.
 *                                                                                                                                                                     
 *   src: null-terminated char array     
 *   out: null-terminated char array with enough empty elements to fit src                                                                                                                          
 *                                                                                                                                                                                        
 *   returns: array (pointer to the first element) with concatenation */

char * Str_concat(char out[], const char src[])
{
   size_t LenOut = Str_getLength(out), i = 0, j = 0;
   assert(src != NULL);
   assert(out != NULL);

   while(out[i] != '\0') {      /* Get index of first NULL in out */
      i++;
   }
   while(src[j] != '\0') {      /* copy src up until first NULL */
      out[i] = src[j];          
      j++;
      i++;
   }
   while(i <= LenOut) {          /* add final null and fill any overhang BUG */   
      out[i] = '\0';
      i++;
   }
   return out;

}

 /*  Compare two string literals                                                                                                                                                                                                                                                                               
 *   Uses the continuity of ASCII representation
 *   to compare chars with logical operators.
 *                                                                                                                                                                     
 *   s1: null-terminated char array     
 *   s2: null-terminated char array                                                                                                                          
 *                                                                                                                                                                                        
 *   returns: (int) 0 if s1 == s2, 1 if s1 > s2, -1 if s2 > s1 */

int Str_compare(const char s1[], const char s2[])
{
   size_t i = 0;
   char c1, c2;
   assert(s1 != NULL);
   assert(s2 != NULL);

   while((c1 = s1[i]) == (c2 = s2[i])) {  
      if(i == Str_getLength(s1) || i == Str_getLength(s2)) {    /* all chars are equal */
         return 0;
      } 
      i++;
   }
      if(c1 == '\0') {            /* s1 is shorter*/
         return -1;
      } else if(c2 == '\0') {     /* s1 is longer*/
         return 1;
      } else {                    /* the not-NULL chars are different  */
         if(c1 > c2) {
            return 1;
         } else {
            return -1;
         }
      }
}

 /*  Helper function                                                                                                                                                                                                                                                                               
 *   Determine if all chars of the needle match to the haystack starting at a given index
 *                                                                                                                                                                     
 *   haystack: null-terminated char array, at least as big as needle     
 *   needle: null-terminated char array   
 *   start: given index to start matching at haystack[start]      
 *   len_needle: size of the needle, excluding the final NULL                                                                                                               
 *                                                                                                                                                                                        
 *   returns: (int) 0 if all needle chars match, 1 otherwise */

int scan_match(const char haystack[], const char needle[], size_t start, size_t len_needle) {
   size_t k = 0;
   while(k <= len_needle) {
      if(haystack[start + k] != needle[k]) { 
         break;
      }
      k++;
   }
   if(k == len_needle) {        /* all chars matched*/
      return 1;
   } else {
      return 0;
   }
}

 /*  Search for the first match of a given string literal (the needle)
*    in another string literal (the haystack)
 *                                                                                                                                                                     
 *   haystack: null-terminated char array, at least as big as needle     
 *   needle: null-terminated char array                                                                                                              
 *                                                                                                                                                                                        
 *   returns: NULL if needle is empty, haystack if no matches, or
 *            pointer to the first element in haystack of match found */

char * Str_search(const char haystack[], const char needle[])
{
   size_t HLen = Str_getLength(haystack), NLen = Str_getLength(needle), i = 0;
   int match;
   assert(haystack != NULL);
   assert(needle != NULL);

   if(NLen == 0) {                        /* if needle is empty*/
      return haystack;
   }
   else {
      for(; i <= HLen; i++) {
         if(haystack[i] == needle[i]) {   /* first match */
            match = scan_match(haystack, needle, i, NLen);    /* scan for needle match starting at i */
            if(match == 1) {
               return &haystack[i]; 
            }
         }
      }                                   /* if no successful match*/
      return NULL;
   }
}
