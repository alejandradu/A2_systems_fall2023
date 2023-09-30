#include <stdio.h>
#include <stddef.h>
#include <assert.h>  
#include "str.h"

/* Description */
/* this argument does the assignment src[] = "input string" so LEN not necessary 
will call this after: only works if they are null-terminated only once */
size_t Str_getLength(const char src[])
{
   size_t uLength = 0;
   assert(src != NULL); 
   while (src[uLength] != '\0') 
      uLength++;
   return uLength;
}

/*  QUESTION: how is the length of char arrays, or arrays in general, limited? 
QUESTION: When i call the function: Str_copy(destination, copy) can 
I pass arguments that have only been declared and not
initialized? Ex char dest[]; 

REMEMBER that we put the const to not modify the first src

ASSUME that the out is big enough */

char * Str_copy(char out[], const char src[])
{
   assert(src != NULL); 
   assert(out != NULL);
   size_t LenOut = Str_getLength(out), i = 0;    /*sizes will include + 1 of last null*/

   while(src[i] != '\0') {      /* copy all chars from the source up until first null*/
      out[i] = src[i];
      i++;
   }
   while(i < LenOut) {          /* add final null and fill any overhang */   
      out[i] = '\0';
      i++;
   }
   return out;

}

/* ASSUME that out is big enough 
as the book says with arrays there is no other way
than traversing string until finding \n to know length 
concat up until the first \n of src

- it has to overwrite the last \n in the out string
- for now ASSUMING that we take the first null in out after
which we concat
*/

char * Str_concat(char out[], const char src[])
{
   assert(src != NULL);
   assert(out != NULL);
   size_t LenOut = Str_getLength(out), i = 0, j = 0;

   while(out[i] != '\0') {      /* Get index of first NULL in out */
      i++;
   }
   while(src[j] != '\0') {      /* copy src up until first NULL */
      out[i] = src[j];          /* overwrite last NULL of out */
      j++;
      i++;
   }
   while(i < LenOut) {          /* add final null and fill any overhang */   
      out[i] = '\0';
      i++;
   }
   return out;

}

/* Do we need to worry abt portability - bc the int conversions
 of chars might not be continuous elsewhere, it might just work for ASCII */
int Str_compare(const char s1[], const char s2[])
{
   size_t i = 0;
   char c1, c2;
   assert(s1 != NULL);
   assert(s2 != NULL);

   while((c1 = s1[i]) == (c2 = s2[i])) {
      i++;  
      if(i == Str_getLength(s1) || i == Str_getLength(s2)) { /* is this redundant */
         break;
         return 0;
      }  /* leaves i at the difference char*/
   }
      if(c1 == '\0') {  /* s1 finished first - s1 is shorter*/
         return -1;
      } else if(c2 == '\0') {  /* s1 is longer*/
         return 1;
      } else {    /* the chars are just different  */
         if(c1 > c2) {
            return 1;
         } else {
            return -1;
         }
      }
}


/* helper function 
find if all chars of the needle match starting at a given index in the haystack
return 1 if true 0 if not*/
int scan_match(const char haystack[], const char needle[], size_t start, size_t len_needle) {
   size_t k = 0;
   while(k < len_needle) {
      if(haystack[start + k] != needle[k]) { /* val of k is less than len*/
         break;
      }
      k++;
   }
   if(k == len_needle - 1) { /* all chars matched*/
      return 1;
   } else {
      return 0;
   }
}

/* assume that haystack is big enough, also that there is only one NULL in haystack? 
assume null-terminated haystack and needle */
char * Str_search(const char haystack[], const char needle[])
{
   assert(haystack != NULL);
   assert(needle != NULL);
   size_t HLen = Str_getLength(haystack);
   size_t NLen = Str_getLength(needle);
   size_t i = 0;
   int match;

   if(NLen == 1) {  /* if needle is empty*/
      return haystack;
   }
   else {
      for(; i < HLen; i++) {
         if(haystack[i] == needle[i]) { /* detect first match - find match*/
            match = scan_match(haystack, needle, i, NLen);
            if(match == 1) {
               return &haystack[i];  /* returns adress of first char of match, also breaks out of loop*/
            }
         }
      } /* if no successful match*/
      return NULL;
   }
}

/* If needle is an empty string, haystack is returned; if needle occurs nowhere in haystack, NULL is returned; otherwise a pointer to the first character of the
     first occurrence of needle is returned.*/
