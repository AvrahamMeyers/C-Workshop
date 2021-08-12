/// @file Ex01.08
/// Author: Avraham Meyers
/// Course: C Workshop
/// Assignment: Homework 1, Question 8

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int max, min, second_largest, second_smallest;

    printf("enter a list of numbers terminated by a 0\n");

    int first_entry;
    scanf_s("%d", &first_entry);
    min = second_largest = second_smallest = max = first_entry;

    int second_entry;
    scanf_s("%d", &second_entry);

    if (second_entry != 0)
    {
        min = second_largest = (first_entry <= second_entry) ? first_entry : second_entry;
        max = second_smallest = (first_entry >= second_entry) ? first_entry : second_entry;

        int entry;
        scanf_s("%d", &entry);

        while (entry != 0)
        {
            if (entry < min)
            {
                second_smallest = min;
                min = entry;
            }

            if (entry < second_smallest && entry > min)
            {
                second_smallest = entry;
            }

            if (entry > max)
            {
                second_largest = max;
                max = entry;
            }

            if (entry > second_largest && entry < max)
            {
                second_largest = entry;
            }

            scanf_s("%d", &entry);
        }
    }

    printf("the second largest value is: %d\n", second_largest);
    printf("the second smallest value is: %d\n", second_smallest);

    return 0;
}

