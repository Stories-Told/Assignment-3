#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// Global constant variable for max amount of
// numbers that can be in the array
const int MAX = 10000;

// Forward declarations
void Number_Sorting(double arr[], double temp);
double Calculate_Mean(double mean, double sum, double arr[]);
double Find_Median(int halfOfElement, double temp, double arr[], double median);
double Calculate_Standard_Deviation(double arr[], double mean, double sum, double standardDeviation);
double Find_Minimum(double arr[], double temp, double minimum);
double Find_Maximum(double arr[], double temp, double maximum);
void Print_Trial_Results();

int main()
{
    // Outputs the results of all 100 trials
    Print_Trial_Results();

    return 0;
}

// Sorting function in ascending order
void Number_Sorting(double arr[], double temp)
{
    // Sorting in ascending order
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100 - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Calculates the mean of the sum of 100 numbers in the array
// from the input file
double Calculate_Mean(double mean, double sum, double arr[])
{
    for (int i = 0; i < 100; i++)
    {
        sum += arr[i];
    }

    mean = sum / 100;

    return mean;
}


// Function to find the median value
double Find_Median(int halfOfElement, double temp, double arr[], double median)
{
    // Sorts 100 numbers in the array from descending order
    Number_Sorting(arr,temp);

    median = (arr[halfOfElement] + arr[halfOfElement + 1]) / 2;

    return median;
}

// Function to find the minimum value
double Find_Minimum(double arr[], double temp, double minimum)
{
    // Sort the 100 numbers in order to find the minimum value
    Number_Sorting(arr,temp);

    // Take the first value, which is the smallest number
    minimum = arr[0];

    return minimum;
}

double Find_Maximum(double arr[], double temp, double maximum)
{
    Number_Sorting(arr,temp);

    maximum = arr[100 - 1];

    return maximum;
}

double Calculate_Standard_Deviation(double arr[], double mean, double sum, double standardDeviation)
{
    // Calculate the mean of the numbers
    for (int i = 0; i < 100; i++)
    {
        sum += arr[i];
    }
    mean = sum / 100;

    // Reset sum to equal 0 in order to calculate
    // standard deviation correctly
    sum = 0;

    // Calculate Standard Deviation
    for (int i = 0; i < 100; ++i)
    {
        sum += pow(arr[i] - mean, 2.0);
    }
    sum = sum / 100;
    standardDeviation = sqrt(sum);

    return standardDeviation;
}

void Print_Trial_Results()
{
    // Input file
    ifstream inFile;
    // Output file
    ofstream outFile;

    // Open the input file
    inFile.open("stats.txt");
    // Create new output file
    outFile.open("results.txt");

    // Check to see if the file could be opened
    // if not throw an error
    if (!inFile)
    {
        cerr << "Unable to open file stats.txt..." << endl;
        exit(1); // Exit the program cleanly
    }

    // Array variable to store all the numbers in the
    // input file
    double arr[MAX];

    // If statement to check and see if you
    // are reading from the input file
    if(inFile.is_open())
    {
        // Variable for counting in the while loop
        int i = 0;

        // While loop to keep looping and store the numbers into
        // an array
        for (int i = 0; i < MAX; i++)
        {
            inFile >> arr[i];
        }
    }

    // Variables for calculating mean
    double mean;
    double sum;
    // Variables for sorting function and finding median
    double median;
    int temp;
    int halfOfElement = 49;
    // Variable for holding the minimum value
    double minimum;
    // Variable for holding the maximum value
    double maximum;
    // Variable for calculating standard deviation
    double standardDeviation;

    // Formatted output of all required categories
    cout << left // Start trial format
         << setw(11)
         << "trial 1"
         << left // Start mean format
         << "mean: "
         << setw(12)
         << fixed
         << setprecision(1)
         << Calculate_Mean(mean, sum, arr)
         << left // Start median format
         << "median: "
         << setw(14)
         << Find_Median(halfOfElement,temp,arr, median)
         << left // Start minimum format
         << "min: "
         << setw(11)
         << Find_Minimum(arr, temp, minimum)
         << left // Start maximum format
         << "max: "
         << setw(11)
         << Find_Maximum(arr, temp, maximum)
         << left // Start standard deviation format
         << "std dev: "
         << setw(15)
         << Calculate_Standard_Deviation(arr,mean,sum,standardDeviation)
         << endl;


    // Output to new file, titled "results.txt"
    outFile << left // Start trial format
            << setw(11)
            << "trial 1"
            << left // Start mean format
            << "mean: "
            << setw(12)
            << fixed
            << setprecision(1)
            << Calculate_Mean(mean, sum, arr)
            << left // Start median format
            << "median: "
            << setw(14)
            << Find_Median(halfOfElement,temp,arr, median)
            << left // Start minimum format
            << "min: "
            << setw(11)
            << Find_Minimum(arr, temp, minimum)
            << left // Start maximum format
            << "max: "
            << setw(11)
            << Find_Maximum(arr, temp, maximum)
            << left // Start standard deviation format
            << "std dev: "
            << setw(15)
            << Calculate_Standard_Deviation(arr,mean,sum,standardDeviation)
            << endl;

    // Close the input and output files
    inFile.close();
    outFile.close();
}
