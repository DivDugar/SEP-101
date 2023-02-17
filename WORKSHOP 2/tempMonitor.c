/* SEP101 - Lab 2: The Temperature Monitor
   tempMonitor.c
   Divyanshu Dugar Student ID : 17110210
*/


#include <stdio.h> // including the standard input output file
#define days 4 // defining a variable days with a constant value 4

int main()
{
    float lowTemp[days], highTemp[days]; // declaring to arrays of size 4 which will store the low and the high temperatures of 4 days respectively.
    int validEntry = 0; // declaring and initializing a flag variable
    float sumHighTemp = 0, sumLowTemp = 0; 
    int lowestTemperature = 40, highestTemperature = -40;
    int indexLowestTemperature = 0, indexHighestTemperature = 0; // declaring to variables to store the index of the highest and the lowest temperature
    float avgLowTemperature, avgHighTemperature, avgTemperature;
    for (int i = 0; i < days; i++) // iteration to go through the array
    {
        do 
        {
            printf("Enter the high value for the day %d: ", i + 1);
            scanf("%d", &highTemp[i]); // taking the high value from the user of each day
            printf("Enter the low value for the day %d: ", i + 1);
            scanf("%d", &lowTemp[i]); // taking the low value from the user of each day
            if (lowTemp[i] < -40 || highTemp[i] > 40 || lowTemp[i] > highTemp[i] || highTemp[i] < lowTemp[i]){ // checking if the user input is within the specified bounds (valid input or not)
                validEntry = 0; // keeping the flag variable false as the input is not valid
                printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
            }
            else{
                validEntry = 1; // making the flag value true if the input is valid
            }
            printf("\n");
        } while (validEntry == 0);

        sumLowTemp += lowTemp[i]; // calculating the sum of all the low temperatures
        sumHighTemp += highTemp[i]; // calculating the sum of all the high temperatures

        if (lowTemp[i] < lowestTemperature){ // calcualting the lowest of all the temperatures
            lowestTemperature = lowTemp[i];
            indexLowestTemperature = i+1; // increasing the index by 1 as days start from 1 but array indexing starts from 0
        }

        if (highTemp[i] > highestTemperature){ // calculating the highest of all the temperatures
            highestTemperature = highTemp[i];
            indexHighestTemperature = i+1;
        }
    }

    avgLowTemperature = sumLowTemp/days; // calculating the average of the low temperature of all the 4 days
    avgHighTemperature = sumHighTemp/days; // calculating the average of the high temperature of all the 4 days
    avgTemperature = (sumHighTemp + sumLowTemp) / (days*2); // calculating the overall average of the temperature of the 4 days

    printf("The high temperatures were: ");
    for (int i = 0; i < days; i++)
    {
        printf("%d ",highTemp[i]); // printing all the input values of high temperatures of all the 4 days
    }
    printf("\n"); 
    
    printf("The low temperatures were: ");
    for (int i = 0; i < days; i++)  
    {
        printf("%d ",lowTemp[i]); // printing all the input values of low temperatures of all the 4 days
    }
    printf("\n");

    // printing all the values calculated above one by one.

    printf("The average LOW temperature was: %.2f\n",avgLowTemperature);
    printf("The average HIGH temperature was: %.2f\n",avgHighTemperature);
    printf("The average temperature was: %.2f\n",avgTemperature);
    printf("The highest temperature was %d, on day %d\n",highestTemperature,indexHighestTemperature);
    printf("The lowest temperature was %d, on day %d\n",lowestTemperature,indexLowestTemperature);

    return 0;
}