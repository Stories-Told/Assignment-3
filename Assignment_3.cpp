#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

// Forward declarations
double Calculate_Mean(double mean, double sum, double arr[]);
double Find_Median(int j, int halfOfElement, double temp, double arr[], double median);

int main()
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
    if (!inFile)
    {
        cerr << "Unable to open file stats.txt..." << endl;
        exit(1);
    }

    // Array variable to store all the numbers in the
    // input file
    double arr[10000];

    // Takes half of the first element and
    // then can add by 100 for each new elements half
    int halfOfElement = 49;

    // If statement to check and see if you
    // are reading from the input file
    if(inFile.is_open())
    {

        // Variable for counting in the while loop
        int i = 0;

        // While loop to keep looping and store the numbers into
        // an array
        for (int i = 0; i < 100; i++)
        {
            inFile >> arr[i];
        }
    }


    // Output the first 100 numbers
    for(int i = 0; i < 100; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "\n\n";


    // Variables for sorting function and finding median
    double median;
    int n,o,j;
    int temp;
    // Output the sorted first 100 numbers
    cout << "Median: " << Find_Median(j,halfOfElement,temp,arr, median) << endl;

    // Variables for calculating mean
    double mean;
    double sum;
    // Output the mean for the first 100 numbers in the array
    cout << "Mean: " << fixed << setprecision(1) << Calculate_Mean(mean, sum, arr) << endl;


    // Close the input and output files
    inFile.close();
    outFile.close();

    return 0;
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

// Sorts 100 numbers in the array from descending order
// and finds the median(middle) number of the number set
double Find_Median(int j, int halfOfElement, double temp, double arr[], double median)
{
    // Sorting in ascending order
    for (int i = 0; i < 100; i++)
    {
        for (j = 0; j < 100 - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    median = (arr[halfOfElement] + arr[halfOfElement + 1]) / 2;

    // Print sorted array
    for (int i = 0; i < 100; i++)
    {
        cout << arr[i] << "\t";
    }

    cout << endl;

    return median;
}
