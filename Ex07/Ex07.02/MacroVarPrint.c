#include "MacroVarPrint.h"

#define ARRAY_SIZE 10

int main(void)
{
	int grades[ARRAY_SIZE];
	for (size_t index = 0; index < ARRAY_SIZE; ++index)
	{
		grades[index] = index + 1;
	}

	int sum = 0;
	int average = 0;

	for (size_t index = 0; index < ARRAY_SIZE; ++index)
	{
		sum += grades[index];
		average = sum / (index + 1);
		TRACE_VAR(index, "%u");
		TRACE_VAR(sum, "%d");
		TRACE_VAR(average, "%d");
		printf("\n");
	}

	return 0;
}