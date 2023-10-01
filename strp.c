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

char * Str_copy(char *out, const char *src[])
{
   size_t LenOut = Str_getLength(out);
   char *curr = src;   /* pointer to src DON'T modify src value QUESTION or &?*/
   assert(src != NULL); 
   assert(out != NULL);

   while(*src != '\0') {      /* copy all chars up until first null*/
      *out = *curr;   /* should initially be the same value of src? */
      curr++;
      out++;
   }
   while(curr - src != LenOut) {   /* add final null and fill any overhang BUG */
      *out = '\0';
      curr++;
      out++;                       /* in the end out has moved LenOut*/
   }
   return out - (int) LenOut;      /* should be pointer to memory adress */

}

char * Str_concat(char *out, const char *src)
{
   size_t LenOut = Str_getLength(out), i = 0, j = 0;
   char *curr = src;
   assert(src != NULL);
   assert(out != NULL);

   while(*out != '\0') {      /* Get index of first NULL in out */
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
