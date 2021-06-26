/*
    This code gets a roman number, wrtten in all caps, and convert it to an arabic number
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // variables
    char romanNumber[51];
    int i, arabicNumber;
    int numberInCaps; // 0 = not in caps | 1 = all caps

    // initialize i and arabicNumber
    i = 0;
    arabicNumber = 0;

    // initialize numberInCaps
    numberInCaps = 0;

    while (numberInCaps == 0)
    {
        enterNumber:
        
        // get romanNumber
        printf("\nEnter a roman number in all caps: ");
        fgets(romanNumber, 51, stdin);
        romanNumber[strcspn(romanNumber, "\n")] = 0;
        fflush(stdin);

        // Check if the number is in all caps
        for (i = 0; i < 51; i++)
        {
            if (romanNumber[i] == 'i' || romanNumber[i] == 'v' || romanNumber[i] == 'x' || romanNumber[i] == 'l' || romanNumber[i] == 'c' || romanNumber[i] == 'd' || romanNumber[i] == 'm')
                {
                    printf ("\nYou didn't type your roman number in all caps. Please, try again.\n");
                    goto enterNumber;
                }
            
            else
                numberInCaps = 1; // This will break this loop
        }
    }

    // Reseting i
    i = 0;

    // Repeat checking each character up to the end of the romanNumber —> romanNumber will have 51 positions

    while(romanNumber[i] != 0)
    {
        // position of I

        if (romanNumber[i] == 'I' && romanNumber[i+1] == 'V')
        {
            arabicNumber = arabicNumber + 4;
            i = i + 2;
        }

        if (romanNumber[i] == 'I' && romanNumber[i+1] == 'X')
        {
            arabicNumber = arabicNumber + 9;
            i = i + 2;
        }

        if (romanNumber[i] == 'I' && romanNumber[i+1] != 'X' &&  romanNumber[i+1] != 'V')
        {
            arabicNumber = arabicNumber + 1;
            i = i + 1;
        }

        // checking for V

        if (romanNumber[i] == 'V')
        {
            arabicNumber = arabicNumber + 5;
            i = i + 1;
        }


        // position of X

        if (romanNumber[i] == 'X' && romanNumber[i+1] == 'L')
        {
            arabicNumber = arabicNumber + 40;
            i = i + 2;
        }

        if (romanNumber[i] == 'X' && romanNumber[i+1] == 'C')
        {
            arabicNumber = arabicNumber + 90;
            i = i + 2;
        }

        if (romanNumber[i] == 'X' && romanNumber[i+1] != 'C' && romanNumber[i+1] != 'L')
        {
            arabicNumber = arabicNumber + 10;
            i = i + 1;
        }

        // checking for L

        if (romanNumber[i] == 'L')
        {
            arabicNumber = arabicNumber + 50;
            i = i + 1;
        }

        // Postion of C

        if (romanNumber[i] == 'C' && romanNumber[i+1] == 'D')
        {
            arabicNumber = arabicNumber + 400;
            i = i + 2;
        }

        if (romanNumber[i] == 'C' && romanNumber[i+1] == 'M')
        {
            arabicNumber = arabicNumber + 900;
            i = i + 2;
        }

        if (romanNumber[i] == 'C' && romanNumber[i+1] != 'M' && romanNumber[i+1] != 'D')
        {
            arabicNumber = arabicNumber + 100;
            i = i + 1;
        }

        // checking for D

        if (romanNumber[i] == 'D')
        {
            arabicNumber = arabicNumber + 500;
            i = i + 1;
        }

        // checking for M

        if (romanNumber[i] == 'M')
        {
            arabicNumber = arabicNumber + 1000;
            i = i + 1;
        }
    }

    // printing the result
    printf("\n%s in arabic numbers is %d\n\n", romanNumber, arabicNumber);

    return 0;
}
