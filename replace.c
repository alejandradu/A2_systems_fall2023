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
   size_t ToLen, FromLen, LineLen, count = 0;             /* could count many repetitions */
   const char *start_match;   /* pointers to a pointer */
   char *temp;

   assert(pcLine != NULL);
   assert(pcFrom != NULL);
   assert(pcTo != NULL);

   LineLen = Str_getLength(pcLine);
   ToLen = Str_getLength(pcTo);
   FromLen = Str_getLength(pcFrom);

   if(*pcFrom == '\0' || Str_search(pcLine, pcFrom) == pcLine) {    /* pcFrom is NULL or no matches*/
      printf(pcLine);
      return 0;
   }

   /* if not implicit */             
   start_match = pcLine;       /* assign at the beginnind of string */
   while((temp = Str_search(start_match, pcFrom) != start_match)) { 
      count++;
      start_match = temp + FromLen;      /* shift pointer to start a new search BUG + or minus 1??*/
   }

   char result[LineLen + count*ToLen + 1];     /* output array */
   start_match = pcLine;                       /* reset pointers */
   temp = start_match;

   while((temp = Str_search(start_match, pcFrom)) != start_match && temp != NULL) { /* check this syntax */
      /* overwrite NULL at the start position of the match */
      *temp = '\0';
      /* concat preceding piece of pcLine before match to output */
      Str_concat(result, start_match);
      /* concat the word to replace*/
      Str_concat(result, pcTo);
      /* shift pointer to start a new search BUG + or minus 1??*/
      start_match = temp + FromLen;     
   }
   
   printf(result);
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

   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL)
      /* Insert your code here. */

   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
