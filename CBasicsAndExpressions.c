#include <stdio.h> //library storing base functions
#include <math.h> //library storing math functions
int main() { //main function
    float boxSpringMass, throneMass; //creating the variables storing decimal values for the scenario
    int minimumStudents, completionTime; //stores the minimum students needed for lifting along with the completion time
    printf("Enter the mass of the box spring in kg: "); //text prompt requesting the mass of the box spring
    scanf("%f", &boxSpringMass); //scan function allows user input for the box spring mass
    printf("\nEnter the mass of the throne in kg: "); //text prompt requesting the mass of the throne
    scanf("%f", &throneMass); //scan function allows user input for the throne mass
    minimumStudents = ceil(((boxSpringMass + throneMass) * 9.81)/300); //minimum students are calculated and value is stored in an int variable, ceil stops the value from having a decimal by rounding up
    printf("\n\nThe ThunderMugz will need a minimum of %d students to carry it.\n", minimumStudents); //text printing the previously calculated value for minimum students
    completionTime = ((boxSpringMass + throneMass) * (4-(exp(0.1*minimumStudents)))); //assigning a value to the int using the provided equation with mass and minimum students
    printf("It will take %d minutes and %d seconds to complete the ThunderMugz challenge.\n", completionTime/60, completionTime%60);
    //the printf function above relays the whole number of minutes and uses the remaining decimals to calculate the seconds
}