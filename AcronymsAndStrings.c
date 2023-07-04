//i attest to the originality of my work
#include <stdio.h> //required library for input / output functions
#include <string.h> //required library for string functions

int main () { //main function, allows a string input and converts it into an acronym, then allows acronym inputs for full string
    int numDatabase; //stores the number of acronyms requested
    char index[50]; //string stores the user input and compares it to existing acronyms
    printf("Enter number of acronyms to add to the database: "); //prompt and scan statement for number of acronyms to be input
    scanf("%d", &numDatabase);
    getchar(); //reads the \n left behind by the scanf statement so that the future fgets function does not pickup the new line
    char postCondense[numDatabase][50]; //string array for the storage of the acronym
    char preCondense[numDatabase][50]; //string array for the storage of the full name

    for (int i = 0; i < numDatabase; i++) { //Memory Clear to solve issues with characters existing within the created strings
        for (int j = 0; j < 50; j++) {
            postCondense[i][j] = '\0';
            preCondense[i][j] = '\0';
        }
    }
    for (int i = 0; i < numDatabase; i++) { //iterates through the number of variables input
        printf("Enter the string to convert into an acronym: "); //prompt and input for the full name
        fgets(preCondense[i], 50, stdin);
        if (preCondense[i][(int)strlen(preCondense[i]) -1 ] == '\n') { //adds the null character to the string
            preCondense[i][(int)strlen(preCondense[i]) -1 ] = '\0';
        }
        int tempCounter = 1;
        for (int j = 0; j < (int)strlen(preCondense[i]) - 1; j++) {
            if (preCondense[i][j] >= 65 && preCondense[i][j] <= 90) { //checks if letters are capitalized
                if (preCondense[i][j - 1] == 32 || j == 0) { //confirms capital letters are at the start of words or the first letter in the name
                    for (int k = tempCounter - 1; k < tempCounter; k++) {
                        postCondense[i][k] = preCondense[i][j]; //used to store the letters that have passed through within a string array
                    }
                    tempCounter++; //allows iteration through each character
                }
            }
        }
        printf("Acronym of \"%s\" is \"%s\".\n", preCondense[i], postCondense[i]); //prints the acronym along with previously input name
    }
    while (1) {
        printf("Enter the acronym of the string you would like to see, or enter 0 to exit: "); //prompt and scan for the acronym check
        fgets(index, 50, stdin);
        if (index[strlen(index) - 1] == '\n') { //adds the null character to the string
            index[strlen(index) - 1] = '\0';
        }
        for (int i = 0; i < numDatabase; i++) { //iterates through number of possible acronyms
            if (strcmp(index, postCondense[i]) == 0) { //compares acronyms, if same then continue
                printf("The corresponding string to \"%s\" is \"%s\".\n", postCondense[i], preCondense[i]); //prints the acronym associated with the string  and the full string
            } else if (i == numDatabase-1 && (strcmp(index, "0") != 0)) { //if the loop has checked each of the acronyms and the input was no 0, print no match statement
                printf("No match found.\n");
            }
        }
        if (strcmp(index, "0") == 0) { //if value input is 0 then ends the code
            printf("\n");
            break;
        }
    }
}