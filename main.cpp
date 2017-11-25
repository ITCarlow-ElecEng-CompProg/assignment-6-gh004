/** Gearoid Hanrahan
    Lab 6
    Decimal / Binary Conversion */


#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h>
#include <math.h>

using namespace std;

void bin_2_dec(void);
void dec_2_bin(void);
char displaymenu(void);


/** Main function */
int main()
{
    char choice;
    /** start of Loop*/
    do
    {
        choice = displaymenu();


        /** User options to select which conversion is needed, invalid input or quit */
        switch (choice)
        {
            case 'b' :      bin_2_dec();
                            break;

            case 'd' :      dec_2_bin();
                            break;

            case 'q' :      system("cls");
                            cout << "Goodbye" << endl;
                            break;

            default  :      cout << "Invalid selection" << endl;
                            break;

        }

    }

    while (choice != 'q');

    return 0;
}

    char displaymenu(void)
{
    char choice;
    /** turns previous screen off */
    system("cls");
    /** user enters which command they want to use */
    cout << "Conversion Calculator \n\n";
    cout << "Press b for bin-dec conversion \n";
    cout << "Press d for dec-bin conversion \n";
    cout << "Press q to quit \n\n";

    choice = getchar();
    return choice;
}

/** bin to dec sub-function */
void bin_2_dec()
{
    /** declaring int and long int variables */
    long int bin, dec = 0, remainder;
    int i = 0;

    /** turns previous screen off */
    system("cls");

    /** display headin on console and read in value */
    cout << "Enter Binary number to be converted : \t" ;
    cin >> bin;
    /** while bin is greater than 0 */
    while (bin != 0)
    {
        /** remainder = binary number / 10 */
        remainder = bin % 10;
        /** binary = binary */
        bin /= 10;
        /** decimal = remainder * 2^i (i = 0 on first loop, 1 on second etc */
        dec = dec + remainder  * pow(i, 2);
        i++;
    }
    /** Display binary = decimal value */
    cout << "\n\t\t    Decimal value :   " << dec ;

    cout << "\n\nPress any key to return to the main menu...";

    fflush(stdin);
    getchar();

    return ;
}


void dec_2_bin()
{
    /** declaring int and long int variables */
    long int decimal, binary = 0, rem, arrayval[8]={0};
    int i = 0;

    /** turns previous screen off */
    system("cls");

    /** display headin on console and read in value */
    cout << "Enter Decimal number to be converted : \t" ;
    cin >> decimal;
    /** while decimal is greater than 0 */
    while (decimal != 0)
    {
        /** rem = the remainder of decimal after its been divided by 2 */
        rem = decimal % 2;
        /** decimal = decimal /2 */
        decimal /= 2;
        /** binary = binary + rem */
        //binary += rem;
        /** increment i each loop */
        arrayval[i]=rem;
        i++;
    }

    /** condition for for loop to dipsplay bin num backwards */
    for(i=7; i>=0; i--)
    {
        cout << arrayval[i];
    }

    cout << "\n\nPress any key to return to the main menu...";

    fflush(stdin);
    getchar();

    return ;
}
