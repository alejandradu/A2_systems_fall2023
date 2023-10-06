/*--------------------------------------------------------------------*/
/* stra.c                                                             */
/* Author: Alejandra Duran Urriago                                    */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include <stddef.h>
#include <assert.h>  
#include "str.h"

size_t Str_getLength(const char src[])
{
   size_t uLength = 0;
   assert(src != NULL); 
   while (src[uLength] != '\0') 
      uLength++;
   return uLength;
}

char * Str_copy(char out[], const char src[])
{
   size_t i = 0;
   assert(src != NULL); 
   assert(out != NULL);

   while(src[i] != '\0') {    /* copy all chars up until first null*/
      out[i] = src[i];
      i++;
   }
   out[i]= '\0';          /* add final null, leave the rest unchanged*/
   return out;

}

char * Str_concat(char out[], const char src[])
{
   size_t i = 0, j = 0;
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
   out[i] = '\0';              /* add final null */   
   return out;

}

int Str_compare(const char s1[], const char s2[])
{
   size_t i = 0;
   char c1, c2;
   assert(s1 != NULL);
   assert(s2 != NULL);

   while((c1 = s1[i]) == (c2 = s2[i])) {  
      /* if all chars are equal */
      if(i == Str_getLength(s1) || i == Str_getLength(s2)) {  
         return 0;
      } 
      i++;
   }
      if(c1 == '\0') {            /* s1 is shorter*/
         return -1;
      } else if(c2 == '\0') {     /* s1 is longer*/
         return 1;
      } else {                /* the not-NULL chars are different */
         if(c1 > c2) {
            return 1;
         } else {
            return -1;
         }
      }
}

 /*  Helper function                                                                                                                                                                                                                                                                               
 *   Determine if all chars of the needle match to the haystack 
 *   starting at a given index
 *                                                                                                                                                                     
 *   haystack: null-terminated char array, at least as big as needle     
 *   needle: null-terminated char array   
 *   start: given index to start matching at haystack[start]                                                                                                                    
 *                                                                                                                                                                                        
 *   returns: (int) 0 if all needle chars match, 1 otherwise */
static int Str_scan_match(const char haystack[], const char needle[], 
                          size_t start) {
   size_t k = 0;
   assert(haystack != NULL);
   assert(needle != NULL);
   assert(start != NULL);

   while(needle[k] != '\0') {
      if(haystack[start + k] != needle[k]) { 
         break;
      }
      k++;
   }
   if(needle[k] == '\0') {        /* all chars matched */
      return 1;
   } else {
      return 0;
   }
}

char * Str_search(const char haystack[], const char needle[])
{  
   size_t i = 0;
   int match;
   assert(haystack != NULL);
   assert(needle != NULL);
   
   if(needle[0] == '\0') {                   /* if needle is empty*/
      return (char*) haystack;               /* cast */
   }
   else {
      while(haystack[i] != '\0') {
         if(haystack[i] == needle[0]) {    
            /* scan for needle match starting at i */
            match = Str_scan_match(haystack, needle, i);  
            if(match == 1) {
               return (char*) &haystack[i];  /* cast */
            }
         }
         i++;   
      }                
      return NULL;      /* if no successful match*/
   } 
}
