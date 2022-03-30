/* CalculatorApp.cpp : Client for calculator application */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "..\..\Bin\Include\CalcLibrary.h"
#include "Windows.h"

enum operationChoice {
    ADDITION = 1,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
};

typedef long long(*LPFNDLLFUNC1)(int, int);

int main()
{
    while (1)
    {
        int choice, a, b;
        long long int result = 0;

        HINSTANCE hDll = NULL;
        LPFNDLLFUNC1 lpfnDllFunc;

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
            hDll = LoadLibrary("LibCalculator.dll");
            if (NULL != hDll)
            {
                lpfnDllFunc = (LPFNDLLFUNC1)GetProcAddress(hDll, "Add");
                if (NULL != lpfnDllFunc)
                {
                    result = lpfnDllFunc(a, b);
                }
                FreeLibrary(hDll);
            }
            break;
        case SUBTRACTION:
            hDll = LoadLibrary("LibCalculator.dll");
            if (NULL != hDll)
            {
                lpfnDllFunc = (LPFNDLLFUNC1)GetProcAddress(hDll, "Subtract");
                if (NULL != lpfnDllFunc)
                {
                    result = lpfnDllFunc(a, b);
                }
                FreeLibrary(hDll);
            }
            break;
        case MULTIPLICATION:
            hDll = LoadLibrary("LibCalculator.dll");
            if (NULL != hDll)
            {
                lpfnDllFunc = (LPFNDLLFUNC1)GetProcAddress(hDll, "Multiply");
                if (NULL != lpfnDllFunc)
                {
                    result = lpfnDllFunc(a, b);
                }
                FreeLibrary(hDll);
            }
            break;
        case DIVISION:
            hDll = LoadLibrary("LibCalculator.dll");
            if (NULL != hDll)
            {
                lpfnDllFunc = (LPFNDLLFUNC1)GetProcAddress(hDll, "Divide");
                if (NULL != lpfnDllFunc)
                {
                    result = lpfnDllFunc(a, b);
                }
                FreeLibrary(hDll);
            }
            break;
        }

        /*  Output  */
        printf("\n\n---- Result = %lld ----\n\n", result);
    }
}