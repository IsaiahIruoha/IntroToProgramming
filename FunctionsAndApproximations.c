//I attest to the originality of my work
#include <stdio.h> //input & output functions
#include <math.h> //math function library
float riemannSumFunction (float initialBound, float finalBound, float intervalNumber); //function to calculate the left riemann sum given bounds and interval number
float taylorSeries (float givenValue, float intervalNumber); //function allows taylor series approximations for the provided function given a position and interval number
float taylorRiemannSum (float initialBound, float finalBound, float intervalNumber); //calculates the left hand riemann sum of the taylor series approximations
float riemannSum5, riemannSum25, riemannSum100, taylorRiemannSum5, taylorRiemannSum25, taylorRiemannSum100; //variables defined for the storage of riemann sums

int main () { //main function for user input and printing the calculated functions associated with e^x^2
    float inputInitialBound, inputFinalBound; //stores variables for the boundary
    printf("Enter the bounds to compute the Riemann Sum:"); //prompts boundary value input
    while(1) { //ensures that a valid boundary is provided
        scanf("%f %f", &inputInitialBound, &inputFinalBound); //scans for values
        if(inputInitialBound < inputFinalBound) { //checks if boundary is viable for the provided function
            break;
        } else {
            printf("Enter the bounds to compute the Riemann Sum:"); //re-prompts if invalid boundary input
        }
    }

    riemannSum5 = riemannSumFunction(inputInitialBound, inputFinalBound, 5); //riemann sum for 5 intervals
    printf("Riemann Sum with 5 intervals: %.2f\n", riemannSum5);
    riemannSum25 = riemannSumFunction(inputInitialBound, inputFinalBound, 25); //riemann sum for 25 intervals
    printf("Riemann Sum with 25 intervals: %.2f\n", riemannSum25);
    riemannSum100 = riemannSumFunction(inputInitialBound, inputFinalBound, 100); //riemann sum for 100 intervals
    printf("Riemann Sum with 100 intervals: %.2f\n", riemannSum100);
    printf("-----------------------------------------------\n");
    printf("Taylor Series Approximation at x = %.2f with 3 terms: %.2f\n", inputInitialBound, taylorSeries(inputInitialBound, 3)); //taylor series with 3 terms
    printf("Taylor Series Approximation at x = %.2f with 5 terms: %.2f\n", inputInitialBound, taylorSeries(inputInitialBound, 5)); //taylor series with 5 terms
    printf("Taylor Series Approximation at x = %.2f with 10 terms: %.2f\n", inputInitialBound, taylorSeries(inputInitialBound,10)); //taylor series with 10 terms
    printf("-----------------------------------------------\n");
    taylorRiemannSum5 = taylorRiemannSum(inputInitialBound,inputFinalBound, 5); //taylor series riemann sum for 5 intervals
    printf("Taylor Series Riemann Sum with 5 intervals: %.2f\n", taylorRiemannSum5);
    taylorRiemannSum25 = taylorRiemannSum(inputInitialBound,inputFinalBound, 25); //taylor series riemann sum for 25 intervals
    printf("Taylor Series Riemann Sum with 25 intervals: %.2f\n", taylorRiemannSum25);
    taylorRiemannSum100 = taylorRiemannSum(inputInitialBound,inputFinalBound, 100); //taylor series riemann sum for 100 intervals
    printf("Taylor Series Riemann Sum with 100 intervals: %.2f\n", taylorRiemannSum100);
    printf("-----------------------------------------------\n");
    printf("Error in Riemann Sums with 5 intervals: %.2f%%\n", (((taylorRiemannSum5-riemannSum5)/riemannSum5)*100)); //prints error between the 5 interval riemann sums
    printf("Error in Riemann Sums with 25 intervals: %.2f%%\n", (((taylorRiemannSum25-riemannSum25)/riemannSum25)*100)); //prints error between the 25 interval riemann sums
    printf("Error in Riemann Sums with 100 intervals: %.2f%%\n", (((taylorRiemannSum100-riemannSum100)/riemannSum100)*100)); //prints error between the 100 interval riemann sums
}

float riemannSumFunction (float initialBound, float finalBound, float intervalNumber){ //function calculates the left hand riemann sum of the function based on input bounds and interval number
    float rectangleWidth = (finalBound - initialBound)/intervalNumber; //determines step size
    float riemannSumResult = 0;
    for (int i = 0; i < intervalNumber; i++) {
        riemannSumResult += (exp(pow((initialBound + (rectangleWidth*i)), 2))); //function includes logic to work towards end of bound
    }
    riemannSumResult *= rectangleWidth; //multiplies the sum by the increase size
return riemannSumResult; //returns value 
}

float taylorSeries (float givenValue, float intervalNumber) { //function uses provided taylor series to calculate an approximate value
float taylorSeriesApprox = 0;
float modifiedIntervalNumber = 1;
    for (int i = 1; i <= intervalNumber; ++i) {
        taylorSeriesApprox += (pow((pow(givenValue, 2)), (i-1)))/modifiedIntervalNumber; //taylor series calculation for e^x^2
        modifiedIntervalNumber = modifiedIntervalNumber*i; //used for determine factorial
    }
    return taylorSeriesApprox; //returns value
}

float taylorRiemannSum (float initialBound, float finalBound, float intervalNumber){ //function takes the left hand riemann sum of the taylor series
    float rectangleWidth = (finalBound - initialBound)/intervalNumber;
    float taylorRiemannResult = 0;
    for (int i = 0; i < intervalNumber; i++) { //loops until reached desired interval, uses nested taylor series function to provide the approximate values
        taylorRiemannResult += taylorSeries(initialBound, 10);
        initialBound += rectangleWidth; //allows initial bound to work towards the final bound
    }
    taylorRiemannResult *= rectangleWidth; //multiplies the sum by the increase size
    return taylorRiemannResult; //returns value
}