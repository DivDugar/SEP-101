/* SEP101 – Lab 1 : The Cash Register
 * cashRegister.c 
 * Divyanshu Dugar ID : 177110210 */

#include <stdio.h>
int main()
{
    float cost_item1, cost_item2, cost_item3; // declaration of variables to store the cost of the items

    // Taking the inputs of the 3 items from the user
    printf("Enter the cost of item 1: $");
    scanf("%f", &cost_item1);

    printf("Enter the cost of item 2: $");
    scanf("%f", &cost_item2);

    printf("Enter the cost of item 3: $");
    scanf("%f", &cost_item3);

    float total_cost = cost_item1 + cost_item2 + cost_item3; // Total cost of all the items
    printf("The total cost is $%.2f \n", total_cost);

    int remainder = total_cost * 100 + 0.0001; // removing the decimal and fixing the slight error on the compilers end

    int num_Dollars, num_Quarters, num_Dimes, num_Nickels, num_Pennies; // declaring the variables to store the value of dollars, dimes, nickels and pennies

    num_Dollars = remainder / 100; // calculating the dollar value
    remainder = remainder % 100;   // storing the cents left

    num_Quarters = remainder / 25; // calculating the number of quarters
    remainder = remainder % 25;    // calculating the cents left to find dimes

    num_Dimes = remainder / 10; // calculating the number of dimes
    remainder = remainder % 10; // calculating the cents left to find nickels

    num_Nickels = remainder / 5; // calculating the number of nickels
    remainder = remainder % 5;   // calculating the cents left to find pennies

    num_Pennies = remainder; // remaining digits give the total number of pennies

    printf("You used %d dollars, %d quarters, %d dimes, %d nickels, %d pennies.", num_Dollars, num_Quarters, num_Dimes, num_Nickels, num_Pennies); // printing the desired output.

    return 0;
}