/*
LAB03 TASK07
Mark Schweitzer

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//function to simulate 10^x (carrot in this instance)
double expon(int carrot){
    double b = 1;
    for(int i = 0; i <= carrot; i++){
        b = b * 10;
    }
    return b;
}

//function to take a number as a character string and return it as an integer. Also can detect negative numbers and accounts for that
//by seeing if the first character is - or not, and executes similar but different tasks depending on if that character is present.
//if so, then it returns the number as a negative, and if not, then it returns it as a positive.
int realNum(char *num){
    int size = 0;
    int total = 0;
    //for size of number (in terms of digits)
    while(num[size] != '\0'){
        size++;
    }
    int floomp = 0;
    int f = size-1;
    //realNum path for positive numbers.
    if(num[0] != '-'){
    for(int i = 0; i < size; i++){
        floomp = (int)num[f] - '0';
        total = total + (floomp * expon(i));
        f = f - 1;
    }
    total = total / 10;
    return total;
    }
    //realNum path for negative numbers.
    if(num[0] == '-'){
    for(int i = 1; i < size; i++){
        floomp = (int)num[f] - '0';
        total = total + (floomp * expon(i));
        f = f - 1;
    }
    total = total / 100;
    return -total;
    }
}

//takes a pointer array and sends each individual of the pointer array into the function that returns it as itself either as a 
//positive or negative integer and adds that to a total before printing that total out.
int main( int argc, char *argv[] ) 
{
    if(argc > 1){
int total = 0;
//sends each argument into realNum and adds it to total.
for(int i = 1; i < argc; i++){
    total = total + realNum(argv[i]);
}
printf(" Sum: %d\n",total);
    } else {
        //prints error if there are no arguments and returns -1
        printf("ERROR: No arguments present.");
        exit(-1);
    }

exit (0);
}

