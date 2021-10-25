#include <stdio.h>
#include <stdlib.h>

#define SIZE 11
#define LEN 64
#define MALLOC_FAILED 1000

void print_array(int *s);
int min(int *s);
int max(int *s);
int avg(int *s);
int median(int *s);

int main()
{
    int *s;
    char buf[LEN];
    char *tmp;
    int i, j, k;

    s = malloc(SIZE * sizeof(int));
    tmp = malloc(3 * sizeof(char));

    if(s == NULL)
    {
        printf("malloc failed. goodbye...\n");
        exit(MALLOC_FAILED);
    }

    printf("Enter tp to 11 integers seperated by commas: ");
    fgets(buf, LEN, stdin);

    for(i = j = k = 0; i < SIZE && buf[j] != '\n'; i++)
    {
        *(tmp + k++) = buf[j++];

        if(buf[j] != ' ')
            *(tmp + k++) = buf[j++];
        else
            *(tmp + k++) = '\0';

        *(s + i) = atoi(tmp);

        printf("%s\n", tmp);

        j++;
        k = 0;
    }

    for(i = 0; *(s + i) != '\0'; i++)
        printf("%d\t", *(s + i));

    print_array(s);
    printf("Min: %d", min(s));
    printf("Max: %d", max(s));
    printf("Average: %d", avg(s));

    free(tmp);
    free(s);

    return 0;
}


void print_array(int *s)
{
    int i;
    for(i = 0; *(s + i) != '\0'; i++)
        printf("s[] = {%d, ", *(s + i));
}

int min(int *s)
{
    int i;
    int min = *(s + 0);

    for(i = 0; *(s + i) != '\0'; i++)
    {
        if(*(s + i) < min)
            min = *(s + i);    
    }

    return min;
}

int max(int *s)
{
    int i;
    int max = *(s + 0);

    for(i = 0; *(s + i) != '\0'; i++)
    {
        if(*(s + i) > max)
            max = *(s + i);    
    }

    return max;
}

int avg(int *s)
{
    int i;
    int sum = 0;
    int avg;

    for(i = 0; *(s + i) != '\0'; i++)
        sum += *(s + i);
    
    avg = sum / (i + 1);
}

int median(int *s)
{
    
}