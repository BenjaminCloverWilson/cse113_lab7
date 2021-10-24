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

int str_len(char *s)
{
	int count;
	int i = 0;

	while(i > -1)
	{
		if(*(s + i) != '\0')
		{
			count = i + 1;
			i++;

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

/* copy n chars of src into dest */
void pstr_ncpy(char *dest, char *src, int n)
{
	int i;

	for(i = 0; i < n && (*(src + i) != '\0'); i++)
	{
		*(dest + i) = *(src + i);
	}
}

/* concantenate t to the end of s; s must be big enough! */
void pstr_cat(char *s, char *t)
{
	int i, j = 0;

	while(*(s + i) != '\0')
		i++;

	while((*(s + i++) = *(t + j++)) != '\0');

}

/* compare string lengths */
int pstr_ncmp(char *s, char *t, int n)
{
	int cmp;
	int i;
	
	for(i = 0; i < n && (*(s + i) != '\0') && (*(t + i) != '\0'); i++)
	{
		if(*(s + i) == *(t + i))
		{
			cmp = 0;
		} else if(*(s + i) > *(t + i))
		{
			cmp = 1;
			i = n;
		} else
		{
			cmp = -1;
			i = n;
		}
	}

	return cmp;
}

/* finds char c in the string */
char *pindex(char *s, int c)
{
	char *p = NULL;
	int i = 0;

	while((*(s + i) != '\0') && (i != -1))
	{
		if(*(s + i) == c)
		{
			p = &(*(s + i));
			i = -2;
		}

		i++;
	}
	
	
	return p;
}

/* Deletes given character c from string */
void psqueeze(char *s, int c)
{
	int i, j;
	char *tmp = s;

	for(i = j = 0; *(s + i) != '\0'; i++)
	{
		if((*(s + i)) != c)
			*(tmp + j++) = *(s + i);
	}

	*(tmp + j) = '\0';

	for(i = 0; i <= j; i++)
		*(s + i) = *(tmp + i);
}

/* Swaps c and d */
void cswap(char *c, char *d)
{
	int i;
	char *tmp = c;

	for(i = 0; (*(c + i) != '\0'); i++)
	{
		*(tmp + i) = *(c + i);
		*(c + i) = *(d + i);
		*(d + i) = *(tmp + i);
	}
}


void preverse(char *s)
{
	int i = 0;
	int j = str_len(s) - 1;
	char *d = s;
	char *tmp = s;

	while(*(s + i) != '\0')
	{
		*(s + i) = *(d + j);
		i++;
		j--;
	}

	for(i = 0, j = str_len(tmp) - 1; *(s + i) != '\0'; i++)
	{
		*(s + j) = *(tmp + i);
		j--;
	}
}