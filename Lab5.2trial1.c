#include <stdio.h>
#include <math.h>

float standard_deviation(float data[], int n);

int main()
{
	int n, i, sum, max, min, mean;
	float data[100];
	printf("Enter number of values: ");
	sscanf("%d", &n);
	printf("Enter the values: ");
	for (i = 0; i<n; ++i)
		scanf("%f", &data[i]);
	printf("\n");
	printf("Standard Deviation = %f\n", standard_deviation(data, n));
	sum = sum_array(data, 100);
	printf("Sum is %d\n", sum);

	return 0;
}

float standard_deviation(float data[], int n)
{
	float mean = 0.0, sum_deviation = 0.0;
	int i;
	for (i = 0; i<n; ++i)
	{
		mean += data[i];
	}
	mean = mean / n;
	for (i = 0; i<n; ++i)
		sum_deviation += (data[i] - mean)*(data[i] - mean);
	return sqrt(sum_deviation / n);
}
