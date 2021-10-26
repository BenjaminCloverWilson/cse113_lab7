/**
 * @file dyn_array.c
 * @brief Takes up to 11 integers, dynamically allocates space, and does statistics stuff
 * @author Benjamin Wilson
 * @date Fall 2021
 * @bug None that I see
 * @todo none
 */

#include <stdio.h>
#include <stdlib.h>

/* Sizes of strings and error messages */
#define SIZE 11
#define LEN 64
#define MALLOC_FAILED 1000

/* Function prototypes */
void print_array(int *s);
int min(int *s);
int max(int *s);
double avg(int *s);
int median(int *s);

int main()
{
    /* String (and pointer) and iteration declarations */
    int *s;
    char buf[LEN];
    char *tmp;
    int i, j, k;

    /* Allocates space for dynamic pointers in program */
    s = malloc(SIZE * sizeof(int));
    tmp = malloc(3 * sizeof(char));

    /* In case heap can not allocates space for some reason terminate program */
    if(s == NULL)
    {
        printf("malloc failed. goodbye...\n");
        exit(MALLOC_FAILED);
    }

    /* User input of numbers */
    printf("Enter up to 11 integers seperated by spaces and with no more than 2 digits: ");
    fgets(buf, LEN, stdin);

    /* Puts char user input into int data types and stores in right pointer *s */
    for(i = j = k = 0; i < SIZE && buf[j] != '\n'; i++)
    {
        /* Stores first digit of user input into first index of small tmp pointer */
        *(tmp + k++) = buf[j++];

        /* If there a second digit present this stores it into second index of tmp */
        if(buf[j] != ' ')
            *(tmp + k++) = buf[j++];
        else
            *(tmp + k++) = '\0';

        /* Convert user input chars into ints and store in *s */
        *(s + i) = atoi(tmp);

        /* Increase index of user input array past space separater and reset tmp index*/
        j++;
        k = 0;
    }

    /* Call statistical functions for user input stored in *s */
    print_array(s);
    printf("Min: %d\n", min(s));
    printf("Max: %d\n", max(s));
    printf("Average: %lf\n", avg(s));
    printf("Median: %d\n", median(s));

    /* Free dynamically allocated pointers from heap memory */
    free(tmp);
    free(s);

    return 0;
}

/** Prints out array of numbers with pointer format
 * @param s pointer array of integers to be printed */
void print_array(int *s)
{
    int i;

    printf("s[] = { ");

    for(i = 0; *(s + i) != '\0'; i++)
        printf("%d ", *(s + i));
    
    printf("}\n");
}

/** Finds minimum value in an array of numbers with pointer format
 * @param s pointer array of integers to find min of
 * @return The minimum data value in the given array of numbers
 */
int min(int *s)
{
    int i;
    int min = *(s + 0);

    /* Iterate through all index values of pointer array */
    for(i = 0; *(s + i) != '\0'; i++)
    {
        /* Stores new minimum found */
        if(*(s + i) < min)
            min = *(s + i);    
    }

    return min;
}

/** Finds maximum value in an array of numbers with pointer format
 * @param s pointer array of integers to find max of
 * @return The maximum data value in the given array of numbers
 */
int max(int *s)
{
    int i;
    int max = *(s + 0);

    /* Iterate through all index values of pointer array */
    for(i = 0; *(s + i) != '\0'; i++)
    {
        /* Stores new maximum found */
        if(*(s + i) > max)
            max = *(s + i);    
    }

    return max;
}

/** Finds the average of all the data in the pointer array of ints
 * @param s The pointer array where data is taken from
 * @result The average of all the int data in the inputted pointer array
 */
double avg(int *s)
{
    double avg;
    int i;
    double sum = 0;
    double size = 0;

    /* Finds the sum and count of all the data values in the pointer array */
    for(i = 0; *(s + i) != '\0'; i++)
    {
        sum += *(s + i);
        size++;
    }
    
    avg = sum / size;

    return avg;
}

/** Finds the median of the present data values in the pointer array
 * @param s The pointer array where data is taken from
 * @result The median of all the int data in the inputted pointer array
 */
int median(int *s)
{
    int count = 0;
    int i, j, min_index, tmp;
    int med, dif, hold;

    /* Sorts inputted pointer array */
    for(i = 0; *(s + i) != '\0'; i++)
    {
        min_index = i;

        for(j = i + 1; *(s + j) != '\0'; j++)
        {
            if(*(s + j) < *(s + min_index))
            {
                min_index = j;
                tmp = *(s + i);
                *(s + i) = *(s + min_index);
                *(s + min_index) = tmp;
            }
        }
    }

    /* Counts the number of values in the array */
    for(i = 0; *(s + i) != '\0'; i++)
        count++;
    
    /* Odd number of data points in array */
    if(count % 2 != 0)
    {
        med = (*(s + ((count - 1) / 2)) + *(s + (count + 1) / 2)) / 2;

        /* Median is value in array that is closest to whatever is found above */
        dif = 10000000;
        for(i = 0; *(s + i) != '\0'; i++)
        {
            if(dif > (*(s + i) - med) * (*(s + i) - med))
            {
                dif = (*(s + i) - med) * (*(s + i) - med);
                hold = *(s + i);
            }
        }
        med = hold;
    }
    
    /* Even number of data points in array */
    else
        med = *(s + (count / 2));

    return med;
}
