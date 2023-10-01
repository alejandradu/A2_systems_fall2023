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
