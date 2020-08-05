/*
Lab-1, Problem-4, Sample soltion-2
Note: Only requirement 1,2,3,4 is covered 
modify this code to include requirement 5 also

Also add your own INPUT/OUTPUT code to test it.

PLEASE READ BEFORE COMPILING OR THERE WILL BE AN ERROR
MUST BE COMPILED USING gcc lab1_prob4_solution2_hint.c -lm IN ORDER TO USE THE MATH LIBRARY!


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

	//Requirement 1, 2, 3, 4, 5
	switch (input & 0xff) //Change to 0xff for all 5 requirements
	{
		case 5: case 7: case 13: case 21: case 23: case 29:
			output = 1;
			break;
			
		case 32: case 33: case 34: case 35: case 36:
			output = 2;
			break;
		
		case 37:
			output = 3;
			break;

		case 38:
			output = 2;
			break;

		case 39:
			output = 3;
			break;

		case 40: case 41: case 42: case 43: case 44:
			output = 2;
			break;

		case 45:
			output = 3;
			break;
		
		case 46: case 47: case 49: case 51:
			output = 2;
			break;
		
		case 53: case 55:
			output = 3;
			break;
		
		case 57: case 59:
			output = 2;
			break;
		
		case 61:
			output = 3;
			break;
		
		case 63:
			output = 2;
			break;
		
		case 69: case 71: case 77: case 85: case 87: case 93:
			output = 1;
			break;
		
		case 96: case 97: case 98: case 99: case 100:
			output = 2;
			break;
		
		case 101:
			output = 3;
			break;
		
		case 102:
			output = 2;
			break;
		
		case 103:
			output = 3;
			break;
		
		case 104: case 105: case 106: case 107: case 108:
			output = 2;
			break;
		
		case 109:
			output = 3;
			break;
		
		case 110: case 111: case 113: case 115:
			output = 2;
			break;
		
		case 117: case 119:
			output = 3;
			break;
		
		case 121: case 123:
			output = 2;
			break;
		
		case 125:
			output = 3;
			break;
		
		case 127:
			output = 2;
			break;
		
		case 133: case 135: case 141: case 149: case 151: case 157:
			output = 1;
			break;
		
		case 160: case 161: case 162: case 163: case 164:
			output = 2;
			break;
		
		case 165:
			output = 3;
			break;
		
		case 166:
			output = 2;
			break;
		
		case 167:
			output = 3;
			break;
		
		case 168: case 169: case 170: case 171: case 172:
			output = 2;
			break;
		
		case 173:
			output = 3;
			break;
		
		case 174: case 175: case 177: case 179:
			output = 2;
			break;
		
		case 181: case 183:
			output = 3;
			break;
		
		case 185: case 187:
			output = 2;
			break;
		
		case 189:
			output = 3;
			break;
		
		case 191:
			output = 2;
			break;
		
		case 192: case 193: case 194: case 195: case 196:
			output = 4;
			break;
		
		case 197:
			output = 5;
			break;
		
		case 198:
			output = 4;
			break;
		
		case 199:
			output = 5;
			break;
		
		case 200: case 201: case 202: case 203: case 204:
			output = 4;
			break;
		
		case 205:
			output = 5;
			break;
		
		case 206: case 207: case 208: case 209: case 210: case 211: case 212:
			output = 4;
			break;
		
		case 213:
			output = 5;
			break;
		
		case 214:
			output = 4;
			break;
		
		case 215:
			output = 5;
			break;
		
		case 216: case 217: case 218: case 219: case 220:
			output = 4;
			break;
		
		case 221:
			output = 5;
			break;
		
		case 222: case 223:
			output = 4;
			break;
		
		case 224: case 225: case 226: case 227: case 228:
			output = 6;
			break;
		
		case 229:
			output = 7;
			break;
		
		case 230:
			output = 6;
			break;
		
		case 231:
			output = 7;
			break;
		
		case 232: case 233: case 234: case 235: case 236:
			output = 6;
			break;
		
		case 237:
			output = 7;
			break;
		
		case 238: case 239:
			output = 6;
			break;
		
		case 240:
			output = 4;
			break;
		
		case 241:
			output = 6;
			break;
		
		case 242:
			output = 4;
			break;
		
		case 243:
			output = 6;
			break;
		
		case 244:
			output = 4;
			break;
		
		case 245:
			output = 7;
			break;
		
		case 246:
			output = 4;
			break;
		
		case 247:
			output = 7;
			break;
		
		case 248:
			output = 4;
			break;
		
		case 249:
			output = 6;
			break;

		case 250:
			output = 4;
			break;

		case 251:
			output = 6;
			break;
		
		case 252:
			output = 4;
			break;
		
		case 253:
			output = 7;
			break;
		
		case 254:
			output = 4;
			break;
		
		case 255:
			output = 6;
			break;

/*---------------------------
		case 32:
		case 34:
		case 36:
		case 38:
		case 40:
		case 42:
		case 44:
		case 46:
		case 49:
		case 51:
			output = 2;
		break;

		case 53:
		case 55:
			output = 3;
		break;

		case 57:
		case 59:
			output = 2;
		break;

		case 61:
			output = 3;
		break;

		case 63:
			output = 2;
---------------------------*/
	
	}


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
