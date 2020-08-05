/*
Sample Solution-1 for Lab-1, Problem-4
Add your own INPUT/OUTPUT code to test it.
*/

#include <stdio.h> //This is useful to do i/o to test the code 
#include <math.h> // Used for converting binary to decimal

unsigned int input;  

unsigned int output;  



int convert(int n) {
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}


//For input interface implementation
inline void read_inputs_from_ip_if(){

	/* write your own input code */
	printf("Input States:\n");
	printf("Sensor: ");
	scanf("%d", &input);
	input = convert(input);

}

//For output interface implementation
inline void write_output_to_op_if(){

	/* write your own output code */
	printf("Output States\n");
	printf("BELL: %d\n", (output & 0x01)/1);
	printf("DLA: %d\n", (output & 0x02)/2);
	printf("BA: %d\n", (output & 0x04)/4);
	printf("\n\n");

}


//The code segment which implements the decision logic
inline void control_action(){

	//Reset output
	output = 0;
	
	//Requirement 1, 2, 3
	switch (input & 0xf)
	{
		case 5:
		case 7:
		case 13:
			output =  0x1;
	}

	//Requirement 4
	switch (input & 0x31)
	{
		case 32:
		case 49:
			output = output | 0x2;
	}

	//Requirement 5
	if ((input & 0xc0) == 0xc0)
			output = output | 0x4;

}


//The main program
int main(int argc, char *argv[])
{
	
	/*The main control loop which keeps the system alive and responsive for ever, 
	until the system is powered off */
	for (; ; )
	{
		read_inputs_from_ip_if();
		control_action();
		write_output_to_op_if();

	}
	
	return 0;
}
