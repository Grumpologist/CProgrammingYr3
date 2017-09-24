/*
Sam O'Callaghan
22 / 09 / 17
ES31 LAB1 X00131917
A programme to calculate the volume of a 3 dimensional shape assigned by the instructor, using user console input.
Version 1.1
*/
#define _USE_MATH_DEFINES

//I decided to use an existing library for Pi, despite increasing the size of the program
//Plus I had an excuse to look at the API and get familiar with standard libraries.  
#include <stdio.h>
#include <math.h>

//function prototypes
	//non return types
void basicSort(float * lengthAlpha, float * lengthBeta);
void userInput(float * inputValue, char * userPrompt[]);
	//integer return types
float volumeCalculation(float totalWidth, float totalSpace, float totalDepth);
int valueValidation(float * inputValue);
int autoTest();


//initialise integer variables
float lengthOne = 0.0;
float lengthTwo = 0.0;
float depthOne = 0.0;
float volume = 0.0;

//create strings to prompt user feedback
char widthPromptOne[] = "Please provide the total base width of your shape:\n";
char widthPromptTwo[] = "Please provide the length of the space along the base of your shape:\n";
char depthPromptOne[] = "Please provide the depth of your shape:\n";
char entryConfirmationOne[] = "You have entered: \n";
char invalidEntry[] = "Invalid Entry, please try again\n\n\n\n";

//pointers 
//to maximise code reuse and readability, passing by value into functions seemed a good clean solution 
//in this problem
//for geometric use
float * baseLength = &lengthOne;
float * spaceLength = &lengthTwo;
float * depth = &depthOne;
//for user feedback/ console output
char * basePrompt = &widthPromptOne;
char * spacePrompt = &widthPromptTwo;
char * depthPrompt = &depthPromptOne;

//test data 
/*
an array with 4 rows and 3 columns
the program can be made to iterate through this upon starting
to show test values anfd confirm the validity of the calculation function.
*/
int i, j;
float testData[6][3] =
{
	{ 2,1,1 },//row indexed 0
	{ 4,1,1 },//row indexed 1
	{ 6,2,4 },//row indexed 2
	{ 6,2,6 },//row indexed 3
	{ 5,1,2 },//row indexed 4
	{ 5,3,2 }//row indexed 5

};

//ver 1.1 TODO:
//condition check vs user entry
//(check for -ve values and zero specified by class instructor)

int main(void)
{

	//uncomment line below to Call the testing procedure upon running program
	autoTest();

	//----Total Width------//

	//call validation
	userInput(baseLength, basePrompt);
	//printf("baselength : %f \n", lengthOne);

	//----Space Width------//
	userInput(spaceLength, spacePrompt);
	//printf("spacelength : %f \n", lengthTwo);

	//----Total Depth------//
	userInput(depth, depthPrompt);
	//printf("depth : %f \n", depthOne);

	//----Calculations-----//

	//sort
	basicSort(&lengthOne, &lengthTwo);

	//calculation
	volumeCalculation(lengthOne, lengthTwo, depthOne);

	printf("Total volume : %f \n", volume);

	return 0;
}

//function to calculate the volume of the object
float volumeCalculation(float totalWidth, float totalSpace, float totalDepth)
{
	//calculate area of two circles 
	float circleOne = ((totalWidth / 2) * (totalWidth / 2) * M_PI);
	//printf("circle 1 : %f \n", circleOne);
	float circleTwo = ((totalSpace / 2) * (totalSpace / 2) * M_PI);
	//printf("circle 2 : %f \n", circleTwo);
	//calculate volume of shape
	volume = ((circleOne - circleTwo) * depthOne);
	return volume;
}//end of function

int autoTest() {
	/*
	Automatic test procedure, Test Data stored in 2D array
	nested for loop to iterate through the data in a logical fashion
	*/

	//inner loop
	for (int i = 0; i < 6; i++)
	{

		//inner loop
		for (int j = 0; j < 3; j++)
		{
			//local variable
			int loader = j;
			//test console output
			printf(" %f\t", testData[i][j]);

			//this switch reads the test data arrays for testing the calculation function. 
			switch (loader)
			{
			case (0):
				lengthOne = testData[i][j];
				break;
			case (1):
				lengthTwo = testData[i][j];
				break;
			case (2):
				depthOne = testData[i][j];
				break;
			default:
				break;
			}

		}//inner for loop

		 //call volumeCalculation with testData for verification
		volumeCalculation(lengthOne, lengthTwo, depthOne);
		printf("Test volume %d : %f \n", (i + 1), volume);
	}//outer for loop

	 //print out user confrimation 
	printf("\n\t\tAuto testing complete\n\n\n\n");


}//end of function

 //function that sorts the two lengths to mitigate against user shenanigans
 //I don't actually like this implementation but it was quick to do and that was the priority in this case
void basicSort(float * lengthAlpha, float * lengthBeta) {
	//temp storage for the lengths to be sorted
	float swappingBucket = 0;

	if (*lengthAlpha > *lengthBeta) {
		return;
	}

	swappingBucket = *lengthAlpha;
	*lengthAlpha = *lengthBeta;
	*lengthBeta = swappingBucket;

}//end sorting function


void userInput(float * inputValue, char * userPrompt[]) {
	//to facilitae exiting the for loop
	int check = 0;

	//to iterate through 3 possible erronous inputs 
	for (int i = 0; i < 3; i++) {
		//prompt user for input
		printf("%s", userPrompt);
		//read user input
		scanf("%f", inputValue);
		//validate user entry
		check = valueValidation(inputValue);

		//force exit of for loop upon valid entry
		if (check == 1) {
			i = 3;
		}//end if

	}//end for

}//end User Input

 //function to check for -ve values and zero
int valueValidation(float * inputValue) {
	
	//to return result
	int bool = 0;
	
	//for condition check
	float test = *inputValue;
	
	//check user input
	if (test <= 0)
	{
		//print out user input confirmation 
		printf("invalid input \n ");


	}else{

		//return true
		bool = 1;

	}//end if

	return bool;

}//end valueValidation
