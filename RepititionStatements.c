//i attest to the originality of my work
#include <stdio.h> //required library for input / output functions
#include <math.h> //required library for math functions

//the function objective is to use inputted variables to calculate the economic feasibility and payback period of projects
int main () {
//floating point variables are created for user inputted values and the payBackPeriod (number of years until a project is profitable)
    float initialCost, projectAnnuity, interestRate, lifeSpan, payBackPeriod;
//various prompts and their scan functions to allow the user to input values
    printf("Enter the initial cost of the project: $");
    scanf("%f", &initialCost);
    printf("Enter the annuity of the project: $");
    scanf("%f", &projectAnnuity);
    printf("Enter the interest rate in %%: ");
    scanf("%f", &interestRate);
    printf("Enter the lifespan of the project in years: ");
    scanf("%f", &lifeSpan);

    float presentValue = -initialCost; //allows the presentValue to be instantly considering the initial startup cost

    if(lifeSpan > 0) { //stops the present value from changing if a negative or zero lifeSpan is input by user (remains flat at the initial cost)
        for(int n = 1; n <= lifeSpan; n++){ //for loop indexing until it reaches the lifeSpan
            presentValue = presentValue + (projectAnnuity / (pow((1.0 + interestRate / 100.0), n))); //uses the provided present value formula and adds to the previous year
        }
    }

    if(presentValue < 0) printf("Present worth of the project = -$%.2f\n", -presentValue); //prints the present worth, additional code added to clean-up output for negative values
    if(presentValue >= 0) printf("Present worth of the project = $%.2f\n", presentValue); //prints the present worth for all positive values or values equal to zero
    (presentValue > 0) ? printf("The project is economically feasible.\n") : printf("The project is not economically feasible.\n"); //conditional operator used to determine if project is economically feasible

    float totalAmount = -initialCost; //creates a value similar to presentValue that is necessary as storage for calculating payBackPeriod
    if(presentValue >= 0) { //if the previously printed presentValue was non-negative, this do-while loop will run
        do {
            totalAmount = totalAmount + (projectAnnuity / (pow((1.0 + interestRate / 100.0), payBackPeriod))); //calculates a value using the present value formula
            payBackPeriod++; //increases the payBackPeriod by one
        } while (totalAmount <= 0); //keeps the function running until the totalAmount becomes positive meaning the project is beginning to profit
    } else { //if the previously printed presentValue was negative, this do-while loop will run
        do {
            totalAmount = totalAmount + (projectAnnuity / (pow((1.0 + interestRate / 100.0), payBackPeriod)));
            payBackPeriod++; //increases the payBackPeriod by one
        } while (totalAmount <= 0); //keeps the function running until the totalAmount becomes positive meaning the project is beginning to profit
        payBackPeriod++; //increases the payBackPeriod by one, this additional statement fixes an issue that occurred with negative presentValue numbers
    }
    printf("The payback period for this project is %.f years.\n", payBackPeriod); //prints the payBackPeriod in years
}