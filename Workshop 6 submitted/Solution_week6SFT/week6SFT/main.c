#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringhelp.h"
#include <string.h>
#include <ctype.h>
#include "log4c.h"
#include <assert.h>

int main(void)
{
	struct Log4cStruct log = l4cOpen("log1.txt", 0);
	l4cPrintf(&log, L4C_INFO, "Main function of application is started...");
	
	// remove \n from whole string.

	char testStr[] = { "This is a string with embedded newline character and 12345 numbers inside it as well 67890" };
	assert(testStr[0] != '\0');// Assert that the test string is not empty
	
	l4cWarning(&log, "The string has to be in perfect condition.");

	struct StringIndex index = indexString(testStr);

	assert(index.numLines > 0 || index.numWords > 0 || index.numNumbers > 0); // Assert that the indexing process succeeded
	int i;

	printf("LINES\n");
	for (i = 0; i < index.numLines; i++)
	{
		l4cPrintf(&log, L4C_INFO, "No of LINES is: %d", index.numLines);
		printUntil(index.str, index.lineStarts[i], '\n');
		printf("\n");
	}
	printf("\nWORDS\n");
	l4cPrintf(&log, L4C_INFO, "No of WORDS are: %d", index.numWords);
	for (i = 0; i < index.numWords; i++)
	{
		
		printUntilSpace(index.str, index.wordStarts[i]);
		printf("\n");
	}
	printf("\nNUMBERS\n");
	l4cPrintf(&log, L4C_INFO, "No of NUMBERS are: %d", index.numNumbers);
	for (i = 0; i < index.numNumbers; i++)
	{
		printUntilSpace(index.str, index.numberStarts[i]);
		printf("\n");
	}
	l4cPrintf(&log, L4C_INFO, "End of the application...");
	l4cClose(&log);
	return 0;
	
}
