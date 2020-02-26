#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// Global variable for row and column amount
const int r = 100;
const int c = 100;
int COUNTER = 0;
int trialNumber = 1;

// Forward declarations
void Print_Trial_Number();
void Number_Sorting(double arr[r][c], double temp);
void Calculate_Mean(double arr[r][c]);
void Find_Median(double arr[r][c]);
void Calculate_Standard_Deviation(double arr[r][c]);
void Find_Minimum(double arr[r][c]);
void Find_Maximum(double arr[r][c]);
void Print_Trial_Results();

int main()
{
    // Outputs the results of all 100 trials and calculations
    Print_Trial_Results();

    return 0;
}

// Sorting function in ascending order
void Number_Sorting(double arr[r][c], double temp)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            for (int k = 0; k < c - j - 1; k++)
            {
                if(arr[i][k] > arr[i][k + 1])
                {
                    temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
    }
}

// Function to print trial number
void Print_Trial_Number()
{
    cout << "trial: " << trialNumber << "           ";

    trialNumber++;
}

// Calculates the mean of the sum of 100 numbers in the array
// from the input file
void Calculate_Mean(double arr[r][c])
{
    double mean[c];
    double meanSum;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            meanSum += arr[i][j];
        }
        mean[i] = meanSum / c;
        meanSum = 0;
    }

    cout << left << fixed << setprecision(1) << "mean: " << mean[COUNTER] << "            ";
}


// Function to find the median value
void Find_Median(double arr[r][c])
{
    int halfOfRow = 49;
    double medianSum;
    double median[c];
    double temp;

    Number_Sorting(arr,temp);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            medianSum = (arr[i][halfOfRow] + arr[i][halfOfRow + 1]) / 2;
        }
        median[i] = medianSum;
        medianSum = 0;
    }

    cout << left << fixed << setprecision(1) << "median: " << median[COUNTER] << "              ";
}

// Function to find the minimum value
void Find_Minimum(double arr[r][c])
{
    double minimumNum;
    double minimum[c];
    double temp;

    Number_Sorting(arr, temp);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            minimumNum = arr[i][0];
        }
        minimum[i] = minimumNum;
        minimumNum = 0;
    }

    cout << left << fixed << setprecision(1) << "min: " << minimum[COUNTER] << "           ";
}

void Find_Maximum(double arr[r][c])
{
    double maximumNum;
    double maximum[c];
    double temp;

    Number_Sorting(arr, temp);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            maximumNum = arr[i][100 - 1];
        }
        maximum[i] = maximumNum;
        maximumNum = 0;
    }

    cout << left << fixed << setprecision(1) << "max: " << maximum[COUNTER] << "           ";
}

void Calculate_Standard_Deviation(double arr[r][c])
{
    double sumMean;
    double mean[c];
    double sumSD;
    double SD[c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sumMean += arr[i][j];
        }
        mean[i] = sumMean / c;
        sumMean = 0;
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sumSD += pow(arr[i][j] - mean[i], 2.0);
        }
        SD[i] = sqrt(sumSD / 100);
        sumSD = 0;
    }

    cout << left << fixed << setprecision(1) << "std dev: " << SD[COUNTER] << "               ";
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
    double arr[100][100];

    // If statement to check and see if you
    // are reading from the input file
    if(inFile.is_open())
    {
        // for loop to store the numbers into
        // an array
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                inFile >> arr[i][j];
            }
        }
    }

    // Variable for sorting function
    double temp;
    Number_Sorting(arr,temp);

    for (int i = 0; i < r; i++)
    {
        Print_Trial_Number();
        Calculate_Mean(arr);
        Find_Median(arr);
        Find_Minimum(arr);
        Find_Maximum(arr);
        Calculate_Standard_Deviation(arr);
        cout << endl;

        COUNTER++;
    }

    // Close the input and output files
    inFile.close();
    outFile.close();
}
