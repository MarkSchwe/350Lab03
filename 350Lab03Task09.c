/*
LAB03 TASK09
Mark Schweitzer
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h> /* defines options flags */
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */
/*
This is a program to reverse the effect of Task 8. It takes two files on the command line: one that serves as the read file that contains tons of ASCII numbers, and another file that is created by
the program which gets the text from the first file but translated back into characters. Special characters N and S are added into the input file to make sure the final result is correctly
formatted.

*/

//same function as the one from task 8. Used to simulate 10^i
double expr(int i){
double b = 1;
    for(int k = 0; k < i; k++){
        b = b * 10;
    }
    return b;
}

//function to translate a character i into an integer
int returnchar(char i){
    if(i == '0'){
        return 0;
    }
    if(i == '1'){
        return 1;
    }
    if(i == '2'){
        return 2;
    }
    if(i == '3'){
        return 3;
    }
    if(i == '4'){
        return 4;
    }
    if(i == '5'){
        return 5;
    }
    if(i == '6'){
        return 6;
    }
    if(i == '7'){
        return 7;
    }
    if(i == '8'){
        return 8;
    }
    if(i == '9'){
        return 9;
    }
}

int main( int argc, char *argv[] ) 
{
    umask(0);
    //buffers for storing individual characters and one for storing each set of ASCII numbers
    char b[1];
    char temp[3];
    int index = 0;
    int nread = 0;
int v = open(argv[1], O_RDONLY);
int k = open(argv[2], O_CREAT | O_RDWR | O_EXCL, 0666);
if(v != -1 && k != -1){
while ((nread = read(v,b,1)>0)){
    if(nread != -1){
        // separates N & S characters from the ASCII numbers. Main bit stores ASCII numbers in sets of 3 so each set can be translated into numbers which can be turned
        //into letters.
    if (*b != 'N' && *b != 'S'){
        temp[index++] = *b;
        if(index == 3){
            int total = 0;
            int in = 0;
            //for storing each number-character in total from right to left based on digit.
            for(int i = 2; i > -1; i--){
                total = total+(returnchar(temp[i]) * expr(in));
                in++;
                
            }
            //turns int total back into a character before writing it to the file.
            char word = total + '\0';
            write(k,&word,1);
            index = 0;
        }
    } else {
        //inputs a newline if it detects an N in the file text
        if (*b == 'N'){
            char *f = ("\n");
            write(k,f,1);
        }
        //inputs a space if it detects an S in the file text
        if(*b == 'S'){
        char *f = (" ");
            write(k,f,1);
        }
    }
    } else {
        //error if something goes wrong with the reading.
        printf("Reading error");
    }
}
} else {
    //error if something goes wrong with the file opening
    printf("File open/creation error or file already exists.");
}
close(k);
close(v);
exit (0);
}
