/**
 * @file dynamic_strings.c
 * @brief Uses standard string.h functions to copy a string and concatanate
 * @author Benjamin Wilson
 * @date Fall 2021
 * @bug None that I see
 * @todo none
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC_FAILED 1000

int main()
{
    /* Strings */
    char *s = "c run, c run unix, run unix run";
    char *t = ", go c, go!";
    char *u;

    /* Add one for the NULL char of the new string */
    size_t len = strlen(s) + strlen(t) + 1;

    /* Allocates memory on heap for u to be assigned to. Same size as
    needed for new combo concatanated strings */
    u = malloc(len * sizeof(char));

    /* Exits program if space can not be allocated */
    if(u == NULL)
    {
        printf("malloc has failed. goodbye...\n");
        exit(MALLOC_FAILED);
    }

    /* Copies s into the first indexes of u string */
    strncpy(u, s, strlen(s) + 1);
    printf("u = \"%s\"\n", u);

    /* Added the t onto remaining space of u */
    strncat(u, t, len);
    printf("u = \"%s\"\n", u);

    /* Frees heap */
    free(u);

    return 0;
}