/**
 * @file str.c
 * @brief Pointer based versions of simple string functions
 * @author Benjamin Wilson
 * @date Fall 2021
 * @bug none
 * @todo none
 */

#include "str.h"
#include <stdio.h>

/** Finds length of a string like strlen()
 * @param s string to be measured
 * @return The length of the string, which is also the amount of bytes
 * that it has. This does not include the terminator character at the end.
 */
int str_len(char *s)
{
	/* Keeps track of character count */
	int count;
	int i = 0;

	while(i > -1)
	{
		if(*(s + i) != '\0')
		{
			count = i + 1;
			i++;

		/* Exit loop once terminator is reacahed */
		} else {
			i = -1;
		}
	}

	return count;
}

/* array version */
/* concantenate t to the end of s; s must be big enough */
void str_cat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0') 	/* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
}

/* array version */
void squeeze(char s[], int c)
{
	int i, j;
	
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];

	s[j] = '\0';
}


void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = str_len(s) - 1; i < j; i++, j-- ) {
		/* change this so it calls cswap */
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	
}

/** Copies n chars of src into dest
 * @param dest Pointer based string that will take copied values
 * @param src Pointer based string that will give values to be copied
 * @param n Number of chars to be copied, as long as it doesn't go beyond string lengths
 */
void pstr_ncpy(char *dest, char *src, int n)
{
	int i;

	for(i = 0; i < n && (*(src + i) != '\0'); i++)
	{
		*(dest + i) = *(src + i);
	}
}

/** Concantenates a string to the end of another string as long
 * as s is big enough.
 * @param s The string that will be added on to
 * @param t The string that is added to s
 */
void pstr_cat(char *s, char *t)
{
	int i, j = 0;

	/* Finds the end index of s */
	while(*(s + i) != '\0')
		i++;
	
	/* Latches start of t onto the end of s, where the terminator of s was */
	while((*(s + i++) = *(t + j++)) != '\0');
}

/** Compares values of string characters between 2 strings for a certain length
 * and returns a given nuumber based on whether one of them
 * is smaller or larger than the other; based on ASCII int values of chars
 * @param s One of the strings whose characters get compared
 * @param t One of the strings whose characters get compared
 * @param n The number of characters in a string to be compared
 * @return 0 if all the chars in the length n are the same, 1 if the first
 * char difference in string s is larger, and -1 if the first char difference
 * in string t is smaller.
 */
int pstr_ncmp(char *s, char *t, int n)
{
	int cmp;
	int i;
	
	for(i = 0; i < n && (*(s + i) != '\0') && (*(t + i) != '\0'); i++)
	{
		if(*(s + i) == *(t + i))
		{
			/* No difference found, keep going */
			cmp = 0;
		} else if(*(s + i) > *(t + i))
		{
			/* Difference found */
			cmp = 1;
			i = n;
		} else
		{
			/* Difference found */
			cmp = -1;
			i = n;
		}
	}

	return cmp;
}

/* finds char c in the string */
/** Finds the pointer address of char c in the string
 * @param s The string to be searched and frisked ;)
 * @param c The char that is searched for
 * @return The pointer to the address of char c in the string. If
 * nothing is found, the pointer points to NULL.
 */
char *pindex(char *s, int c)
{
	char *p = NULL;
	int i = 0;

	while((*(s + i) != '\0') && (i != -1))
	{
		if(*(s + i) == c)
		{
			/* Sets the pointer to the character address and exits loop */
			p = &(*(s + i));
			i = -2;
		}

		i++;
	}
	
	
	return p;
}

/* Deletes given character c from string */
/** Deletes a given character c from a given string based on ASCII values
 * and puts the string back together.
 * @param s The string to be modified.
 * @param c The character to be deleted.
 */
void psqueeze(char *s, int c)
{
	int i, j;
	char *tmp = s;

	for(i = j = 0; *(s + i) != '\0'; i++)
	{
		/* All chars not equal to c, are placed in tmp string */
		if((*(s + i)) != c)
			*(tmp + j++) = *(s + i);
	}

	*(tmp + j) = '\0';

	/* Pastes tmp string without c into original string */
	for(i = 0; i <= j; i++)
		*(s + i) = *(tmp + i);
}

/** Swaps the characters of strings c and d
 * @param c The first string
 * @param d The second string
 */
void cswap(char *c, char *d)
{
	int i;
	char tmp;

	for(i = 0; (*(c + i) != '\0'); i++)
	{
		tmp = *(c + i);
		*(c + i) = *(d + i);
		*(d + i) = tmp;
	}
}

/** Reverses the characaters of string s in a pointer based fashion
 * @param s The string to be reversed
 */
void preverse(char *s)
{
	int i;
	int j = str_len(s) - 1;
	char tmp;

	for(i = 0; i < j; i++, j--)
	{
		/* I tried to implement cswap in a lot of different ways, but
		I'm not sure how to do it completely (only half the string getting
		reversed) without changing cswap params, so I just went with a way
		that I know works */
		tmp = *(s + i);
		*(s + i) = *(s + j);
		*(s + j) = tmp;
	}
}
