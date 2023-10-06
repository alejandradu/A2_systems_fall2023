/*--------------------------------------------------------------------*/
/* strp.c                                                             */
/* Author: Alejandra Duran Urriago                                    */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include <stddef.h>
#include <assert.h>  
#include "str.h"

size_t Str_getLength(const char *src)
{
   const char *end;  
   assert(src != NULL);
   end = src;
   while (*end != '\0')
      end++; 
   return (size_t)(end - src);
}

char * Str_copy(char *out, const char *src)
{
   const char *curr;    
   assert(src != NULL); 
   assert(out != NULL);
   curr = src;

   while(*curr != '\0') {    /* copy all chars up until first null*/
      *out = *curr;   
      curr++;
      out++;
   }
   *out = '\0';                    /* add final null */
 
   return out - (curr - src);   /* curr - src is what out has moved */

}

char * Str_concat(char *out, const char *src)
{
   size_t LenOut = Str_getLength(out);
   const char *curr;
   assert(src != NULL);
   assert(out != NULL);
   curr = src;

   while(*out != '\0') {      /* Get index of first NULL in out */
      out++;
   }
   while(*curr != '\0') {      /* copy src up until first NULL */
      *out = *curr;          
      out++;
      curr++;
   }
   *out = '\0';                /* add final null */

   return out - (int) LenOut - (curr - src); /* back to start of out */

}

int Str_compare(const char *s1, const char *s2)
{
   int int_l1 = (int) Str_getLength(s1);
   int int_l2 = (int) Str_getLength(s2);
   const char *c1;
   const char *c2;
   assert(s1 != NULL);
   assert(s2 != NULL);
   c1 = s1;
   c2 = s2;

   while(*c1 == *c2) {  
      /* if all chars are equal */
      if((c1 - s1) == int_l1 || (c2 - s2) == int_l2) { 
         return 0;
      } 
      c1++;
      c2++;
   }
      if(*c1 == '\0') {            /* s1 is shorter*/
         return -1;
      } else if(*c2 == '\0') {     /* s1 is longer*/
         return 1;
      } else {                  /* the not-NULL chars are different  */
         if(*c1 > *c2) {
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
 *   curr_haystack: null-terminated char array, at least as big as 
 *                  needle     
 *   needle: null-terminated char array                                                                                                                    
 *                                                                                                                                                                                        
 *   returns: (int) 0 if all needle chars match, 1 otherwise */
static int Str_scan_match(const char *curr_haystack, 
                          const char *needle) 
{   
   const char *curr_needle;
   const char *curr_temp_haystack;
   assert(curr_haystack != NULL);
   assert(needle != NULL);
   curr_needle = needle;
   curr_temp_haystack = curr_haystack;

   while(*curr_needle != '\0') {
      if(*curr_temp_haystack != *curr_needle) { 
         break;
      }
      curr_temp_haystack++;
      curr_needle++;
   }
   if(*curr_needle == '\0') {        /* all chars matched */
      return 1;
   } else {
      return 0;
   }
}

char * Str_search(const char *haystack, const char *needle)
{  
   size_t dummy;
   int match;
   const char *curr;
   assert(haystack != NULL);
   assert(needle != NULL);
   curr = haystack;

   if(*needle == '\0') {                 /* if needle is empty*/
      return (char*) curr;               /* cast */
   }
   else {
      while(*curr != '\0') {
         if(*curr == *needle) {    
            /* scan for needle match starting at i */
            match = Str_scan_match(curr, needle);   
            if(match == 1) {
               return (char*) curr;      /* cast */
            }
         }
         curr++;   
      }                                
      return NULL;     /* if no successful match*/
   } 
}