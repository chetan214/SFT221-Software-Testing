#define _CRT_SECURE_NO_WARNINGS
#include "stringhelp.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "log4c.h"
#include <assert.h>

int nextWhite(const char* str)
{
	
	int i, result = -1;
	for (i = 0; result < 0 && str[i] != '\0'; i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			result = i;
		}
	}
	return ((result * -1) != result) ? i : result;
}
int isNumber(const char* str, const int len)
{
	int result;
	for (result = 1; result <= len && result; result++)
	{
		if (!isdigit(str[result - 1])) result = -1;
	}
	return result;
}
struct StringIndex indexString(const char* str)
{
	
	struct Log4cStruct log = l4cOpen("log.txt", 0);
	l4cPrintf(&log, L4C_INFO, "Indexing the string is now started...");
	l4cWarning(&log, "The string has to be in perfect condition.");
	struct StringIndex result = { {0}, {0}, {0}, 0, 0, 0 };
	l4cPrintf(&log, L4C_INFO, "All integer counters are set to zero in StringIndex result");
	char buf[MAX_WORD_SIZE + 1] = { 0 };
	int i, sp;
	strcpy(result.str, str);
	l4cPrintf(&log, L4C_INFO, "Copied string to result.str: %s", result.str);

	
	if (str[0] != '\0')
	{
		l4cPrintf(&log, L4C_INFO, "str[0] condition is checked and passed");
		result.lineStarts[0] = 0;
		result.numLines = 1;
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		while (str[i] != '\0' && isspace(str[i]))
		{
			
			if (str[i] == '\0')
			{
				result.lineStarts[result.numLines++] = i + 1;
			}
			i++;
		}
		for (sp = 0; str[sp + i] != '\0' && !isspace(str[sp + i]); sp++);
		if (isNumber(str + i, sp))
		{
			result.numberStarts[result.numNumbers++] = i;
			l4cPrintf(&log, L4C_INFO, "Number found at position: %d", i);
		}
		else
		{
			result.wordStarts[result.numWords++] = i;
			l4cPrintf(&log, L4C_INFO, " Word found at position: %d", i);
		}
		i += sp - 1;
	}

	
	l4cPrintf(&log, L4C_INFO, "Result:- Number of lines: %d, words: %d, numbers: %d", result.numLines, result.numWords, result.numNumbers);
	l4cPrintf(&log, L4C_INFO, "Indexing Completed...");
	l4cClose(&log);

	return result;
}
int getNumberLines(const struct StringIndex* idx)
{
	return idx->numLines;
}
int getNumberWords(const struct StringIndex* idx)
{
	return idx->numWords;
}
int getNumberNumbers(const struct StringIndex* idx)
{
	
		return idx->numNumbers;
	
}
void getWord(char word[], const struct StringIndex* idx, int wordNum)
{
	
	int i, sp, start;
	word[0] = '\0';
	if (wordNum < idx->numWords && wordNum >= 0)
	{
		start = idx->wordStarts[wordNum];
		sp = nextWhite(idx->str + start);
		for (i = 0; i <= sp; i++)
		{
			word[i] = idx->str[start + i]; 
			
		}
		word[sp] = '\0';
		
	}

}
void getNumber(char word[], const struct StringIndex* idx, int numberNum)
{
	int i, sp, start;
	word[0] = '\0';
	if (numberNum < idx->numNumbers && numberNum >= 0)
	{
		start = idx->numberStarts[numberNum];
		sp = nextWhite(idx->str + start);
		for (i = 0; i < sp; i++)
		{
			word[i] = idx->str[sp + i];
		}
		word[sp] = '\0';
		}
}
char* getLine(struct StringIndex* idx, int lineNum)
{
	char* result = NULL;
	if (lineNum < idx->numLines && lineNum >= 0)
	{
		result = idx->str + idx->lineStarts[lineNum];
	}
	return result;
}
void printUntil(const char* s, const int start, const char terminator)
{
	int i;
	for (i = start; s[i] != '\0' && s[i] != terminator; i++)
		printf("%c", s[i]);
}
void printUntilSpace(const char* s, const int start)
{
	int i;
	for (i = start; s[i] != '\0' && !isspace(s[i]); i++)

		printf("%c", s[i]);
	
}
