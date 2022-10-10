#include<stdio.h>

int main(void)
{
	int count = 0;	// Variable for counting lines
	int c;			// Variable for storing file characters
	char your_character;	// variable for inputted character

	FILE *the_original = fopen("C:/Users/email_000/Desktop/the_original.txt", "r");  // open and read original text file

	if (the_original == NULL)	// If the file doesn't open
	{
		printf("Error opening your file\n");	// print error message
		return 1;
	}

	while ((c = getc(the_original)) != EOF)	// While reading the file
	{
		if (c != '\n')	
		{
			putchar(c);	// display character
		}
		else
		{
			count++;		// increment of 1
			putchar('\n');  // display character of next line
		}
		if (count > 19)		// stop at the 20th line
		{
			break;
		}

	}

	// Prompt user to enter a character:
	printf("Enter a character: ");
	// Store response into variable:
	scanf("%c", &your_character);	

	if (your_character == 'q')  // If the inputted character is 'q'
	{
		// Kill the program:
		printf("This program has been terminated.\n");
	}
	else 
	{
		// Print the next 20 lines
		while ((c = getc(the_original)) != EOF)
		{

			if (c != '\n')
			{
				putchar(c);	// display character
			}
			else
			{
				count++;		// increment of 1
				putchar('\n');	// display character of next line 
			}
			if (count > 39)  // stop at the 40th line
			{
				break;
			}

		}
	}
	
	fclose(the_original);	// close original file

	return 0;
}