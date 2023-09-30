#include <stdio.h>
#include <stddef.h>
#include <assert.h>  
#include "str.h"

 /*  Get length of a string up to the first NULL                                                                                                                                                                                                                                                                               
 *                                                                                                                                                                                        
 *   src: pointer to a string literal                                                                                                                             
 *                                                                                                                                                                                        
 *   returns: number of chars before NULL (long unsigned int) */

size_t Str_getLength(const char *src)
{
   const char *end;
   assert(src != NULL);
   end = src;
   while (*end != '\0')
      end++; 
   return (size_t)(end - src);
}

 /*  Copy one string literal to another                                                                                                                                                                                                                                                                                
 *                                                                                                                                                                        
 *   src: pointer to a string literal
 *   out: pointer to a string literal (the copy, at least as long as src)                                                                                                                           
 *                                                                                                                                                                                        
 *   returns: pointer to the copy of src */

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
