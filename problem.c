#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare functions
char input(char full_name[]);
void output(char full_name[]);

// Declare strings and lengths
char first_name[100];
char last_name[100];
char full_name[200];

int main(void)

{
	printf("Enter your first name:");   // Ask user to enter their first name
	gets(first_name);					// Store the result into its respective string
	printf("Enter your last name:");	// Ask user to enter their last name
	gets(last_name);					// Store the result into its respective string
	input(full_name);					// Declare input
	output(full_name);					// Declare output
	return 0;
}

char input(char full_name[])			// Input function for storing full name
{
	strcpy(full_name, first_name);		// Copy the first name string
	strcat(full_name, last_name);		// Concatenate with the last name string
	printf("You entered %s\n", full_name);
}

char output(char full_name[])			// Output function for outputting inverted name
{
	printf("Inverted name is %s, %s\n", last_name, first_name);		// Print the inverted name with comma
}

