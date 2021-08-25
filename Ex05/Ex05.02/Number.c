#include <stdio.h>
#include <malloc.h>
#include "Number.h"

int main(void)
{
    CalculatorLoop();

    return 0;
}

void CalculatorLoop()
{
    Number first_number = ReadNumber();

    Operation op = ReadOperation();

    while (op != EXIT)
    {
        Number second_number = ReadNumber();

        PrintNumber(first_number);

        PrintOp(op);

        PrintNumber(second_number);

        PrintOp(EQUAL);

        first_number = Calculation(first_number, second_number, op);

        PrintNumber(first_number);

        op = ReadOperation();
    } 
}

Number Calculation(Number num1, Number num2, Operation op)
{
    Number result;
    switch (op)
    {
        case ADD:
        {
            if (num1.isReal && num2.isReal)
            {
                return Add(num1, num2);
            }
            else if (!num1.isReal && !num2.isReal)
            {
                result = ComplexAdd(num1, num2);
            }
            else if (num1.isReal)
            {
                num1.Value.Complex.real = (float)num1.Value.real;
                num1.Value.Complex.imaginary = 0;
                result = ComplexAdd(num1, num2);
            }
            else
            {
                num2.Value.Complex.real = (float)num2.Value.real;
                num2.Value.Complex.imaginary = 0;
                result = ComplexAdd(num1, num2);
            }
            break;
        }
        case SUB:
        {
            if (num1.isReal && num2.isReal)
            {
                return Sub(num1, num2);
            }
            else if (!num1.isReal && !num2.isReal)
            {
                result = ComplexSub(num1, num2);
            }
            else if (num1.isReal)
            {
                num1.Value.Complex.real = (float)num1.Value.real;
                num1.Value.Complex.imaginary = 0;
                result = ComplexSub(num1, num2);
            }
            else
            {
                num2.Value.Complex.real = (float)num2.Value.real;
                num2.Value.Complex.imaginary = 0;
                result = ComplexSub(num1, num2);
            }
            break;
        }
        case MULT:
        {
            if (num1.isReal && num2.isReal)
            {
                return Mult(num1, num2);
            }
            else if (!num1.isReal && !num2.isReal)
            {
                result = ComplexMult(num1, num2);
            }
            else if (num1.isReal)
            {
                num1.Value.Complex.real = (float)num1.Value.real;
                num1.Value.Complex.imaginary = 0;
                result = ComplexMult(num1, num2);
            }
            else
            {
                num2.Value.Complex.real = (float)num2.Value.real;
                num2.Value.Complex.imaginary = 0;
                result = ComplexMult(num1, num2);
            }
            break;
        }
        case DIV:
        {
            if (num1.isReal && num2.isReal)
            {
                return Div(num1, num2);
            }
            else if (!num1.isReal && !num2.isReal)
            {
                result = ComplexDiv(num1, num2);
            }
            else if (num1.isReal)
            {
                num1.Value.Complex.real = (float)num1.Value.real;
                num1.Value.Complex.imaginary = 0;
                result = ComplexDiv(num1, num2);
            }
            else
            {
                num2.Value.Complex.real = (float)num2.Value.real;
                num2.Value.Complex.imaginary = 0;
                result = ComplexDiv(num1, num2);
            }
            break;
        }
    }
    if (!IsComplex(result))
    {
        result.Value.real = (double)result.Value.Complex.real;
    }
    return result;
}

Number Add(Number num1, Number num2)
{
    Number sum;
    sum.Value.real = num1.Value.real + num2.Value.real;
    sum.isReal = true;
    return sum;
}

Number ComplexAdd(Number num1, Number num2)
{
    Number sum;
    sum.Value.Complex.real = num1.Value.Complex.real + num2.Value.Complex.real;
    sum.Value.Complex.imaginary = num1.Value.Complex.imaginary + num2.Value.Complex.imaginary;
    sum.isReal = false;
    return sum;
}

Number Sub(Number num1, Number num2) {
    
    Number diff;
    diff.Value.real = num1.Value.real - num2.Value.real;
    diff.isReal = true;
    return diff;
}

Number ComplexSub(Number num1, Number num2)
{
    Number diff;
    diff.Value.Complex.real = num1.Value.Complex.real - num2.Value.Complex.real;
    diff.Value.Complex.imaginary = num1.Value.Complex.imaginary - num2.Value.Complex.imaginary;
    diff.isReal = false;
    return diff;
}

Number Mult(Number num1, Number num2)
{
    Number prod;
    prod.Value.real = num1.Value.real * num2.Value.real;
    prod.isReal = true;
    return prod;
}

Number ComplexMult(Number num1, Number num2)
{
    Number prod;
    prod.Value.Complex.real = (num1.Value.Complex.real * num2.Value.Complex.real)
        - (num1.Value.Complex.imaginary * num2.Value.Complex.imaginary);
    prod.Value.Complex.imaginary = (num1.Value.Complex.real * num2.Value.Complex.imaginary)
        + (num2.Value.Complex.real * num1.Value.Complex.imaginary);
    prod.isReal = false;
    return prod;
}

Number Div(Number num1, Number num2)
{
    Number quot;
    quot.Value.real = num1.Value.real / num2.Value.real;
    quot.isReal = true;
    return quot;
}

Number ComplexDiv(Number num1, Number num2)
{
    Number quot;
    
    quot.Value.Complex.real = (num1.Value.Complex.real * num2.Value.Complex.real)
        + (num1.Value.Complex.imaginary * num2.Value.Complex.imaginary);
    quot.Value.Complex.real /= (num2.Value.Complex.real * num2.Value.Complex.real)
        + (num2.Value.Complex.imaginary * num2.Value.Complex.imaginary);

    quot.Value.Complex.imaginary = (num1.Value.Complex.imaginary * num2.Value.Complex.real)
        - (num1.Value.Complex.real * num2.Value.Complex.imaginary);
    quot.Value.Complex.imaginary /= (num2.Value.Complex.real * num2.Value.Complex.real)
        + (num2.Value.Complex.imaginary * num2.Value.Complex.imaginary);

    quot.isReal = false;
    return quot;
}

Number ReadNumber(void)
{
    printf("enter a number type:\nfor real enter 1\nfor complex enter 0\n");

    NumberType type;
    int temp = 0;
    scanf_s("%d", &temp);
    type = temp;

    PrintNumberMessage();

    Number *entry = (Number *)malloc(sizeof(Number));
    ReadValue(type, entry);

    return *entry;
}

void PrintNumberMessage(void)
{
    printf("enter the value of the number:\n");
    printf("for complex numbers first enter the real value\n");
    printf("and then the imaginary value\n");

}

void ReadValue(NumberType type, Number *num)
{
    switch (type)
    {
        case REAL:
        {
            double value = 0.0;
            scanf_s("%lf", &value);
            num->Value.real = value;
            num->isReal = true;
            break;
        }
        case COMPLEX:
        {
            float real_value = 0.0, imaginary_value = 0.0;
            scanf_s("%f %f", &real_value, &imaginary_value);
            num->Value.Complex.real = real_value;
            num->Value.Complex.imaginary = imaginary_value;
            num->isReal = false;
            break;
        }
    }
}

Operation ReadOperation(void)
{
    PrintOperationMessage();

    Operation operation;
    int temp;

    scanf_s("%d", &temp);
    operation = temp;

    return operation;

}

void PrintOperationMessage(void)
{
    printf("enter the operation to perform\n");
    printf("1 for addition\n");
    printf("2 for subtraction\n");
    printf("3 for multiplication\n");
    printf("4 for division\n");
    printf("0 to exit\n");
}

void PrintNumber(Number num)
{
    if (num.isReal)
    {
        printf("%lf\n", num.Value.real);
    }
    else
    {
        printf("(%f + %f", num.Value.Complex.real, num.Value.Complex.imaginary);
        printf("i)\n");
    }
}

void PrintOp(Operation op)
{
    switch (op)
    {
        case ADD:
        {
            printf(" + ");
            break;
        }
        case SUB:
        {
            printf(" - ");
            break;
        }
        case MULT:
        {
            printf(" * ");
            break;
        }
        case DIV:
        {
            printf(" / ");
            break;
        }
        case EQUAL:
        {
            printf(" = ");
            break;
        }
    }
}

bool IsComplex(Number num)
{
    return num.Value.Complex.imaginary != 0;
}