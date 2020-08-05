//CSCE312: Lab-3 Problem-1 Timing Framework

/* ***   README   **** */
/*This file is a framework: i.e. there is no actual code whose execution time will be
measured. You need to populate the appropriate functions with the code that you wrote 
for the previous problems in order to get useful data. 

Turning in this file without your code will result in zero points being awarded for this problem.

run this file as: gcc FileName.c -o ExecutableName -lrt 

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int process;
    sscanf(argv[1] , "%d" , &process);
    char* oc = argv[2];
    switch(process)
    {
        case 0:
            printf("Everything is disabled\n");
            printf("Nothing works, change to try again. \n");
            break;
        case 1:
            printf("Reading from ROM at address %s\n" , oc);
            printf("1: Read from in port with address %s\n" , oc);
            printf("2: Pull the value from the ROM w/ given address %s into bidirectional data bus\n" , oc);
            printf("3: Swap controls to writing to the output stream\n");
            printf("4: I/O writes the data out into the output pin.");
            break;
        case 10:
            printf("Reading from RAM at address %s\n" , oc);
            printf("1: Read from in port with address %s\n" , oc);
            printf("2: Pull the value from the RAM w/ given address %s into bidirectional data bus\n" , oc);
            printf("3: Swap controls to writing to the output stream\n");
            printf("4: I/O writes the data out into the output pin.");
            break;
        case 11:
            printf("Writing into RAM at address %s\n" , oc);
            printf("1: Swap control to read from user input/ROM\n");
            printf("2: Store user input / ROM value into the bidirectional data bus\n");
            printf("3: Swap to write into the RAM, given an address %s\n" , oc);
            printf("4: The RAM updates the data at the given address %s with the value stored in the bidirectional data bus\n");
            break;
        case 100:
            printf("Reading from digital input line\n");
            printf("1: Read in the signal from the enable which can be determined via the pin on the line\n");
            printf("2: If this is 1, then the data can be read and stored / outputted\n");
            printf("3: If this is 0, then do nothing.\n");
            break;
        case 101:
            printf("Writing to a digital output line\n");
            printf("1: Read in the signal from the 3 bit pin on the output control line\n");
            printf("2: Based on the data from the pin, the corresponding action will be performed\n");
            printf("000 - Disable all\n");
            printf("001 - Read ROM\n");
            printf("010 - Read RAM\n");
            printf("011 - Write RAM\n");
            printf("100 - Write I/0\n");
            printf("101 - Read I/0\n");
            break;
    }
}