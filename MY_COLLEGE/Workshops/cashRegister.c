// cashRegister.c
// DIVYANSHU DUGAR 
// STUDENT ID : 177110210


#include <stdio.h> // including the standard input output header file
int main()
{
    float cost_item1, cost_item2, cost_item3; // declaring 3 float type variables.
    printf("Enter the cost of item 1: $"); // taking input the cost of the 1st item from the user
    scanf("%f", &cost_item1); 
    printf("Enter the cost of item 2: $"); // taking input the cost of the 2nd item from the user
    scanf("%f", &cost_item2);
    printf("Enter the cost of item 3: $"); // taking input the cost of the 3rd item from the user
    scanf("%f", &cost_item3);
    float total_cost = cost_item1 + cost_item2 + cost_item3; // calculating the total price of all the three items.
    printf("The total cost is $%f\n", total_cost);
    int num_dollars = ((int)(total_cost * 100)) / 100; // calculating the total dollars spent
    printf("You used %d dollars,", num_dollars);
    int cents = ((int)(total_cost*100)%100);
    int quarters = cents/25; // calculating the total quarters to be returned
    printf("%d quarters,",quarters);
    int dimes = (cents-(25*quarters))/10; // calculating the total dimes to be returned
    printf("%d dimes,",dimes);
    int nickels = ((cents-(25*quarters))-dimes*10)/5; // calculating the total nickels to be returned
    printf("%d nickels,",nickels);
    int pennies = (((cents-(25*quarters))-dimes*10)-5*nickels); // calculating the total pennies to be returned
    printf("%d pennies",pennies);
    return 0;
}
