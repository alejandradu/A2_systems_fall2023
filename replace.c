/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Alejandra Duran Urriago                                    */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo)
{
   size_t FromLen, count = 0;          
   const char *head, *end_string, *tail;   

   assert(pcLine != NULL);
   assert(pcFrom != NULL);
   assert(pcTo != NULL);

   FromLen = Str_getLength(pcFrom);

   head = pcLine;      /* start of text yet to be matched */     
   end_string = head + (int) Str_getLength(pcLine);

   tail = Str_search(head, pcFrom);  /* match begins at tail */

   if(tail == NULL) {                /* pcFrom is NULL or no matches*/
      printf(pcLine);
      return 0;
   }

   while (tail != NULL) {            /* while there is still a match */
      count++;
      while (head!=tail) {           /* print chars before match */  
         putchar(*head);
         head++;
      }
      
      printf(pcTo);                  /* print pcTo at match place*/

      head = head + FromLen;              /* update head after match */
      tail = Str_search(head, pcFrom);    /* match begins at tail */
   }

   while(head!=end_string) {        /* print last unmatched stretch */
      putchar(*head);
      head++;
   }

   return count;

}

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3};

   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   char *pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL) {
      if(*pcFrom == '\0') {          /* if pcFrom is empty */
         printf(acLine);   
      } else {
         uReplaceCount += replaceAndWrite(acLine, pcFrom, pcTo); 
      }
   }

   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
