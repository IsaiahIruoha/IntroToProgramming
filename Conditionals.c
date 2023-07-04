//I attest to the originality of my work
#include <stdio.h> //required library for input / output functions
#include <math.h> //required library for math functions

//the function objective is use conditional statements to examine an electric circuit that contains various components
int main () {
    float time, sourceVoltage; //variables storing float values for time and the voltage on the source
    float bulbVoltage = 0.00; //variable storing the bulb voltage, base value of zero if no other value assigned it means a switch is active
    printf("Enter time in seconds: "); //prompt for the time input
    scanf("%f", &time); //user inputs time in seconds which is stored in a float variable "time"
    sourceVoltage = 8 * cos(M_PI * time); //calculate voltage at source with given equation

    if (sourceVoltage > 0.01) { //checks if source voltage is positive, negative or zero
        printf("Source voltage is positive\n");
    } else if (sourceVoltage < -0.01) {
        printf("Source voltage is negative\n");
    } else {
        printf("Source voltage is zero\n");
    }
    if (sourceVoltage < -0.7) printf("Switch 1 is closed\n"); //determines if switch 1 activates
    if (sourceVoltage > 6.4) printf("Switch 2 is closed\n"); //determines if switch 2 activates

    //if neither of the switches are active, a value is assigned to bulbVoltage using V = IR with current being calculated using the sourceVoltage/total resistance
    if (sourceVoltage > -0.7 &&  sourceVoltage < 6.4) bulbVoltage = (sourceVoltage/10) * 8;
    printf("The Voltage of the bulb is %.2f V\n", bulbVoltage); //prints the bulb voltage to 2 decimal places
    (bulbVoltage >= 1 && bulbVoltage <= 5.2) ? printf("The bulb is on\n") : printf("The bulb is not on\n"); //if bulb is within given range it is on, otherwise it is off
}