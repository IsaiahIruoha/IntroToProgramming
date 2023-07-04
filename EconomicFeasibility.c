//i attest to the originality of my work
#include <stdio.h> //required library for input / output functions

//the function objective is to use inputted variables to calculate the economic feasibility and payback period of projects
int main () {

    //define int variables
    int dataSets, lowestSGLimestone, highestPLimestone, highestFVLimestone;

    printf("Enter the number of limestones to compare: "); //prompt for amount of limestones being compared
    scanf("%d", &dataSets); //scans for user input

    double limestoneData[dataSets][4]; //2D array created for limestone data storage
    //double variables defined
    double porosityPercent, hydraulicConductivity, specificGravity, lowestSpecificGravity, highestPorosity, highestFlowVelocity;

    //loop to associate the 2D array columns with different limestone properties and scans user for input
    for(int i = 0; i < dataSets; i++){
        printf("Enter the porosity %%, hydraulic conductivity (m/s), and specific gravity for Limestone %d: \n", i+1);
        scanf("%lf %lf %lf", &porosityPercent, &hydraulicConductivity, &specificGravity);
        limestoneData[i][0] = porosityPercent;
        limestoneData[i][1] = hydraulicConductivity;
        limestoneData[i][2] = specificGravity;
    }

    //stores a temporary value for the lowest specific gravity and checks for lower values, storing the data set number if found
    lowestSpecificGravity = limestoneData[0][2];
    lowestSGLimestone = 1;
    for(int i = 0; i < dataSets; i++){
        if (lowestSpecificGravity > limestoneData[i][2]) {
        lowestSpecificGravity = limestoneData[i][2];
        lowestSGLimestone = i+1;
        }
    }
    //prints the lowest specific gravity and the limestone its associated with
    printf("The limestone with the lowest specific gravity is Limestone %d with a specific gravity of %lf.4\n", lowestSGLimestone, lowestSpecificGravity);

    printf("Flow velocities: \n");
    for(int i = 0; i < dataSets; i++) { //runs the formula for flow velocity and assigns it to a column in the 2D array
        limestoneData[i][3] = (-limestoneData[i][1]*100)*(1200*100)*(-0.725*100);
        if (limestoneData[i][3] < 0) { //ensures that negative flow velocities are not printed
            limestoneData[i][3] *= -1;
            printf("Limestone %d: %.2lf cm^3/s \n", i+1, limestoneData[i][3]);
        } else {
            printf("Limestone %d: %.2lf cm^3/s \n", i+1, limestoneData[i][3]);
        }
    }

    //stores a temporary value for the highest porosity and checks for higher, storing the data set number if found
    highestPorosity = limestoneData[0][0];
    highestPLimestone = 1;
    for(int i = 0; i < dataSets; i++){
        if (highestPorosity < limestoneData[i][0]) {
            highestPorosity = limestoneData[i][0];
            highestPLimestone = i+1;
        }
    }

    //stores a temporary value for the highest flow velocity and checks for higher, storing the data set number if found
    highestFlowVelocity = limestoneData[0][3];
    highestFVLimestone = 1;
    for(int i = 0; i < dataSets; i++){
        if (highestFlowVelocity < limestoneData[i][3]) {
            highestFlowVelocity = limestoneData[i][3];
            highestFVLimestone = i+1;
        }
    }

    //checks if the limestone with the highest porosity also has the highest flow velocity then prints yes or no statements
    if(highestFVLimestone == highestPLimestone) {
        printf("The rock with the highest porosity has the highest flow velocity.");
    } else {
        printf("The rock with the highest porosity does not have the highest flow velocity.");
    }
}