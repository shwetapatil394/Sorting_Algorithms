/* CalculatorApp.cpp : Client for calculator application */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\Bin\Include\CalcLibrary.h"

enum operationChoice {
    ADDITION = 1,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
};

int main()
{
    while (1)
    {
        int choice, a, b;
        long long int result;

        /*  Input from user */
        printf("Choose operation from following list.\n");
        printf("\n\t1.Add\n\t2.Subtract\n\t3.Multiply\n\t4.Divide\n\t0:Exit\n\nEnter your choice:");
        scanf("%d", &choice);
        if (0 == choice)
        {
            printf("Exiting...\n");
            exit(-1);
        }
        if (0 > choice || 4 < choice)
        {
            puts("\n----------- WRONG CHOICE -----------\n");
            continue;
        }
        printf("Enter two numbers.\n");
        printf("A :");
        scanf("%d", &a);
        printf("B :");
        scanf("%d", &b);

        /*  Processing  */
        switch (choice)
        {
            case ADDITION:
                result = Add(a, b);
                break;
            case SUBTRACTION:
                result = Subtract(a, b);
                break;
            case MULTIPLICATION:
                result = Multiply(a, b);
                break;
            case DIVISION:
                result = Divide(a, b);
                break;
        }

        /*  Output  */
        printf("\n\n---- Result = %lld ----\n\n", result);
    }
}


