#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Declare functions
double mean( double prices_array[]);
double standard_dev(double prices_array[]);

int main(void)
{
	// Initialize data types
	double avg = 0;
	double sd = 0;
	

	// Specify file to read from 
	FILE *home_prices = fopen("C:/Users/email_000/Desktop/prices.dat", "r");

	// Specify file to write to
	FILE *outfile = fopen("C:/Users/email_000/Desktop/prices_summary.dat", "w");

	if (home_prices == NULL)     // If the file doesn't open, print an error message
	{
		printf("Error opening file\n");
		return 1;
	}
	 
	// Set array of home prices
	 double prices_array[120];
	 int i;

	 // Store all home prices into array
	for (i = 0; i < 120; i++)
	{
		fscanf(home_prices, "%lf", &prices_array[i]);
	}

	// Print array
	for (i = 0; i < 120; i++)
	{
		printf("Home price is %lf\n", prices_array[i]);
	}

	avg= mean(prices_array);			// Set formula for average
	sd = standard_dev(prices_array);	// Set formula for standard deviation

	// Print results to file
	fprintf(outfile, "Average is %Lf\n Standard Deviation is %Lf\n", avg, sd);

}

 double mean(double prices_array[])		// Function for calculating mean
{
	double mean_var;					// Initialize mean
	double sum = 0.0;					// Initialize sum
	int i;
	for (i = 0; i < 120; i++)			// Sum all prices in array
	{
		sum= sum + prices_array[i];
	}
	mean_var = sum / 120;				// Formula for calculating mean

	printf("Average is %Lf\n", mean_var);	// Print result
	
	return mean_var;
}

 double standard_dev(double prices_array[])    // Function for standard deviation
 {
	 // Initialize data types
	 double mean_var;
	 double finalstandarddev;
	 double sum = 0.0;
	 double standarddeviation = 0.0;
	 int i;

	 for (i = 0; i < 120; i++)					// Sum all prices in array
	 {
		 sum = sum + prices_array[i];
	 }
	 mean_var = sum / 120;						// Formula for calculating mean
	 for (i = 0; i < 120; i++)					// Calculate standard deviation
	 {
		 standarddeviation += pow(prices_array[i] - mean_var, 2);

	 }
	 finalstandarddev = sqrt(standarddeviation / 120);  // Finish standard deviation calculation
	 printf("Standard deviation is %Lf\n", finalstandarddev);		// Print result
	 return finalstandarddev;
		 
 }