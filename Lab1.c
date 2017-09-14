/*
Sam O'Callaghan
14/09/2017

*/
#include <stdio.h>

//initialise variables

int width = 0;
int height = 0;
int depth = 0;
int volume = 0;

char str1[] = "The box is very tall.\n";
char str2[] = "The box is very deep.\n";
char str3[] = "The box is very wide.\n";
char str4[] = "The box is not tall or deep or wide.\n";

int main(void)
{

	//Width
	printf("Please provide a number for WIDTH to the nearest millimeter: \n");
	scanf("%d", &width);
	printf("Width: %d \n", width);


	//Height
	printf("Please provide a number for HEIGHT to the nearest millimeter: \n");
	scanf("%d", &height);
	printf("Height: %d \n", height);

	//Depth
	printf("Please provide a number for DEPTH to the nearest millimeter: \n");
	scanf("%d", &depth);
	printf("Depth: %d \n", depth);

	return 0;
}