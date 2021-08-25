#pragma once
#include <stdbool.h>


/// @brief a struct for a number, containing a value field 
/// and a bool representing whether it is real or not
typedef struct Number_t
{
    /// @brief a union for a value,
    /// either a double if it is real
    /// or two floats if it is complex
    union Value
    {
        struct Complex
        {
            float real;
            float imaginary;
        } Complex;

        double real;
    } Value;

    bool isReal;

} Number;

/// @brief the operations to be used by the program
typedef enum Operation
{
    EXIT,
    ADD, 
    SUB,
    MULT, 
    DIV,
    EQUAL
} Operation;

/// @brief the two different number types
typedef enum NUMBERTYPE
{
    COMPLEX,
    REAL    
} NumberType;

/// @brief runs a loop that reads two values and an operation
/// and displays the result of the operation 
void CalculatorLoop();

/// @brief performs the inputted operation on the two numbers
/// @param num1 the first number in the equation
/// @param num2 the second number in the equation
/// @param op the operation to be performed
/// @return the result of the operation
Number Calculation(Number num1, Number num2, Operation op);

/// @brief adds the two numbers together and returns the sum
/// @param num1 the first number to be added
/// @param num2 the second number to be added
/// @return the sum of the two numbers
Number Add(Number num1, Number num2);

/// @brief adds two complex numbers and returns the result
/// @param num1 the first complex number to be added
/// @param num2 the second complex number to be added
/// @return the sum of the two complex numbers
Number ComplexAdd(Number num1, Number num2);

/// @brief subtracts the second number from the first and returns the difference
/// @param num1 the number to subtract the second number from
/// @param num2 the number to subtract from the first number
/// @return the difference between the first number and second number
Number Sub(Number num1, Number num2);

/// @brief subtracts two complex numbers and returns the difference
/// @param num1 the number to subtract the second number from
/// @param num2 the number to subtract from the first number
/// @return the difference between the first number and second number
Number ComplexSub(Number num1, Number num2);

/// @brief multiplies the two numbers and returns the product
/// @param num1 the first number to multiply
/// @param num2 the second number to multiply
/// @return the product of the two numbers
Number Mult(Number num1, Number num2);

/// @brief multiplies two complex numbers and returns the product
/// @param num1 the first number to multiply
/// @param num2 the second number to multiply
/// @return the product of the two numbers
Number ComplexMult(Number num1, Number num2);

/// @brief divides the first number by the second number and returns the quotient
/// @param num1 the dividend
/// @param num2 the divisor
/// @return the quotient of the two numbers
Number Div(Number num1, Number num2);

/// @brief divides two complex numbers and returns the quotient
/// @param num1 the dividend
/// @param num2 the divisor
/// @return the quotient of the two numbers
Number ComplexDiv(Number num1, Number num2);

/// @brief reads in a real or complex number and returns it 
/// @param no parameters
/// @return the number that is entered by the user
Number ReadNumber(void);

/// @brief reads in a number to the num parameter based on the type
/// @param type the type of the number that is going to be read
/// @param num the number that will hold the value that is read
void ReadValue(NumberType type, Number *num);

/// @brief prints the operation message
/// @param no parameters
void PrintOperationMessage(void);

/// @brief prints the number message
/// @param no parameters
void PrintNumberMessage(void);

/// @brief reads in an operation from the user and returns it
/// @param no parameters
/// @return the operation that is entered by the user
Operation ReadOperation(void);

/// @brief prints the number
/// @param num the number to be printed
void PrintNumber(Number num);

/// @brief prints the operation 
/// @param op the operation to be printed
void PrintOp(Operation op);

/// @brief returns whether the numbers imaginary value is 0
/// @param num the number to check
bool IsComplex(Number num);