#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "Dog.h"

#define SIZE 3

int main(void)
{
	Dog kennel[SIZE] =
	{
		{"coco", 25},
		{"rocky", 20},
		{"dawn", 23}
	};

	SortDogs(kennel, SIZE, "name");

	printf("the dogs sorted by name:\n");

	PrintDogs(kennel, SIZE);

	SortDogs(kennel, SIZE, "weight");

	printf("the dogs sorted by weight:\n");

	PrintDogs(kennel, SIZE);


	return 0;
}

void SortDogs(Dog kennel[], size_t size, char* sort_parameter)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		for (size_t j = 0; j < size - i - 1; ++j)
		{
			if (sort_parameter == "name")
			{
				if (strcmp((kennel[j]).name,(kennel[j + 1]).name) > 0)
				{
					SwapDogs(&(kennel[j]), &(kennel[j + 1]));
				}
			}
			else if (sort_parameter = "weight")
			{
				if ((kennel[j]).weight > (kennel[j + 1]).weight)
				{
					SwapDogs(&(kennel[j]), &(kennel[j + 1]));
				}
			}
		}
	}
}

void SwapDogs(Dog* A, Dog* B)
{
	Dog temp = *A;
	*A = *B;
	*B = temp;
}

void PrintDogs(Dog kennel[], size_t size)
{
	printf("name:\t\tweight:\n");
	for (size_t i = 0; i < size; ++i)
	{
		printf("%s\t%f\n", (kennel[i]).name, (kennel[i]).weight);
	}
}
