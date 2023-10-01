#include <stdio.h>
#include <stddef.h>
#include <assert.h>  
#include "str.h"

size_t Str_getLength(const char *src)
{
   const char *end;   /* what is const in here? in the end i do ++*/
   assert(src != NULL);
   end = src;
   while (*end != '\0')
      end++; 
   return (size_t)(end - src);
}

char * Str_copy(char *out, const char *src)
{
   const char *curr;        /* do this bc i don't wanna change src? */
   assert(src != NULL); 
   assert(out != NULL);
   curr = src;

   while(*curr != '\0') {    /* copy all chars up until first null*/
      *out = *curr;   
      curr++;
      out++;
   }
   *out = '\0';              /* add final null */
 
   return out - (curr - src);      /* curr - src is len out has moved */

}

char * Str_concat(char *out, const char *src)
{
   size_t LenOut = Str_getLength(out), i = 0, j = 0;
   const char *curr = src;
   assert(src != NULL);
   assert(out != NULL);

   while(*out != '\0') {      /* Get index of first NULL in out */
      i++;
   }
   while(curr[j] != '\0') {      /* copy src up until first NULL */
      out[i] = curr[j];          
      j++;
      i++;
   }
   while(i <= LenOut) {          /* add final null and fill any overhang BUG */   
      out[i] = '\0';
      i++;
   }
   return out;

}




/* ------------ */




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

int Str_scan_match(const char haystack[], const char needle[], size_t start) {
   size_t k = 0;
   assert(haystack != NULL);
   assert(needle != NULL);

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
            match = Str_scan_match(haystack, needle, i);    /* scan for needle match starting at i */
            if(match == 1) {
               return (char*) &haystack[i];  /* cast */
            }
         }
         i++;   
      }                                      /* if no successful match*/
      return NULL;
   } 
}