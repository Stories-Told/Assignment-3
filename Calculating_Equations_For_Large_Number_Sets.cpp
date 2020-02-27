#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// Input file
ifstream inFile;
// Output file
ofstream outFile;

// Global variable for row, column, Counter, and trial number
const int r = 100; // Change if need more rows for more numbers
const int c = 100; // Change if need more columns for more numbers
int COUNTER = 0; // Used in order to output the correct output for each trial from 1-100
int trialNumber = 1; // Used for counting each trial's number (1-100)

// Forward declarations
void Print_Trial_Number();
void Number_Sorting(double arr[r][c], double temp);
void Calculate_Mean(double arr[r][c]);
void Find_Median(double arr[r][c]);
void Calculate_Standard_Deviation(double arr[r][c]);
void Find_Minimum(double arr[r][c]);
void Find_Maximum(double arr[r][c]);
void Throw_Error();
void Print_Trial_Results();

int main()
{
    // Open the input file
    inFile.open("stats.txt");
    // Create new output file
    outFile.open("results.txt");

    // Check to see if file opened successfully
    Throw_Error();

    // Outputs the results of all 100 trials(rows)
    Print_Trial_Results();

    // Close the input and output files
    inFile.close();
    outFile.close();

    return 0;
}

// Sorting function in ascending order
void Number_Sorting(double arr[r][c], double temp)
{
    for (int i = 0; i < r; i++) // For loop for row
    {
        for (int j = 0; j < c; j++) // For loop for column
        {
            for (int k = 0; k < c - j - 1; k++) // For loop for sorting function
            {
                if(arr[i][k] > arr[i][k + 1]) // If statement checking if the proceeding number is smaller than the number before it
                {
                    temp = arr[i][k]; // If the number is larger store in temp holding
                    arr[i][k] = arr[i][k + 1]; // The larger number now equals the smaller number
                    arr[i][k + 1] = temp; // The smaller number gets stored in temp for next loop
                }
            }
        }
    }
}

// Function to print trial number
void Print_Trial_Number()
{
    // Prints trial and the number to console and to results.txt
    cout << "trial: " << setw(11) << left << trialNumber;
    outFile << "trial: " << setw(11) << left << trialNumber;
}

// Calculates the mean of the sum of 100 numbers in the array
// per row of the multi dimension array
void Calculate_Mean(double arr[r][c])
{
    // Variables to calculate the mean
    double mean[c]; // Stores each row's(1-100) mean in a array
    double meanSum; // Used to calculate the sum of the mean

    // Nested for loop to calculate each row's mean
    for (int i = 0; i < r; i++) // For loop for the row number in the array
    {
        for (int j = 0; j < c; j++) // For loop for the column number array
        {
            meanSum += arr[i][j]; // Loops for the entire column (variable c) and adds them together
        }
        mean[i] = meanSum / c; // saves the mean int an array starting at 0 until 100
        meanSum = 0; // resets sum of mean back to 0 in order to calculate a new mean
    }

    // Prints the formatted mean to console and results.txt
    cout << left << fixed << setprecision(1) << "mean: " << setw(12) << mean[COUNTER];
    outFile << left << fixed << setprecision(1) << "mean: " << setw(12) << mean[COUNTER];
}


// Function to find the median value
void Find_Median(double arr[r][c])
{
    // Variables in order to find the median
    int halfOfRow = 49; // Takes half of the 100 number row in the array
    double medianSum; // Variable used to add the median value up
    double median[c]; // Array used to store all rows median value
    double temp; // used for Number_Sorting() function

    Number_Sorting(arr,temp); // Sorts number in ascending order to find the median

    for (int i = 0; i < r; i++) // For loop for row(r)
    {
        for (int j = 0; j < c; j++) // For loop for column(c)
        {
            medianSum = (arr[i][halfOfRow] + arr[i][halfOfRow + 1]) / 2; // Takes half of the array column plus half+1 and divides
        }
        median[i] = medianSum; // Store median in the array for each row
        medianSum = 0; // Reset sum back to 0 for next row's median
    }

    // Prints the formatted median to console and results.txt
    cout << left << fixed << setprecision(1) << "median: " << setw(14) << median[COUNTER];
    outFile << left << fixed << setprecision(1) << "median: " << setw(14) << median[COUNTER];
}

// Function to find the minimum value of each row
void Find_Minimum(double arr[r][c])
{
    // Variables in order to find the min of each row
    double minimumNum; // Stores the current rows min
    double minimum[c]; // Array used for holding each row's min
    double temp; // Needed for Number_Sorting() function

    Number_Sorting(arr, temp);

    for (int i = 0; i < r; i++) // For loop for row(r)
    {
        for (int j = 0; j < c; j++) // For loop for column(c)
        {
            minimumNum = arr[i][0]; // Takes the current rows first number
        }
        minimum[i] = minimumNum; // Stores min number into an array for each row
        minimumNum = 0; // Resets min to 0 for next row's min
    }

    // Prints formatted min to console and results.txt
    cout << left << fixed << setprecision(1) << "min: " << setw(11) << minimum[COUNTER];
    outFile << left << fixed << setprecision(1) << "min: " << setw(11) << minimum[COUNTER];
}

// Function to find the maximum value of each row
void Find_Maximum(double arr[r][c])
{
    // Variables used to find the max
    double maximumNum; // Stores current row's max number
    double maximum[c]; // Array used to store each row's max number
    double temp; // Needed for Number_Sorting() function

    Number_Sorting(arr, temp); // Sorts each row's numbers in ascending order

    for (int i = 0; i < r; i++) // For loop for row(r)
    {
        for (int j = 0; j < c; j++) // For loop for column(c)
        {
            maximumNum = arr[i][c - 1]; // Takes the last number in the row's array
        }
        maximum[i] = maximumNum; // Stores each row's current max into an array
        maximumNum = 0; // Resets max for next row's max number
    }

    // Prints formatted max value to console and results.txt
    cout << left << fixed << setprecision(1) << "max: " << setw(11) << maximum[COUNTER];
    outFile << left << fixed << setprecision(1) << "max: " << setw(11) << maximum[COUNTER];
}

// Function used to calculate the Standard Deviation of each row
void Calculate_Standard_Deviation(double arr[r][c])
{
    // Variables used for calculating the SD
    double sumMean; // Saves the sum of mean for each row
    double mean[c]; // Stores the mean in an array for each row
    double sumSD; // Saves the sum of each number subtracted from the row's mean
    double SD[c]; // Stores the SD in an array for each row

    // For loop to find the mean
    for (int i = 0; i < r; i++) // For loop for row(r)
    {
        for (int j = 0; j < c; j++) // For loop for column(c)
        {
            sumMean += arr[i][j]; // Finds the sum of all the numbers in each row
        }
        mean[i] = sumMean / c; // Saves the mean into an array for each row
        sumMean = 0; // Resets mean to 0 for the next row's mean
    }

    // For loop to find the SD
    for (int i = 0; i < r; i++) // For loop for row(r)
    {
        for (int j = 0; j < c; j++) // For loop for column(c)
        {
            sumSD += pow(arr[i][j] - mean[i], 2.0); // Find the sum of each rows numbers subtracted from mean and squared
        }
        SD[i] = sqrt(sumSD / 100); // Stores each row's SD into an array
        sumSD = 0; // Resets the sum of SD to 0 for next row's SD
    }

    // Prints formatted Standard Deviation to console and results.txt
    cout << left << fixed << setprecision(1) << "std dev: " << setw(15) << SD[COUNTER];
    outFile << left << fixed << setprecision(1) << "std dev: " << setw(15) << SD[COUNTER];
}

void Throw_Error()
{
    // Check to see if the file could be opened
    // if not throw an error
    if (!inFile)
    {
        cerr << "Unable to open file stats.txt..." << endl;
        exit(1); // Exit the program cleanly
    }
}

// Takes all the calculations for all the functions and
// places them in one spot in order to print to console
// and results.txt
void Print_Trial_Results()
{
    // Array variable to store all the numbers in the
    // input file
    double arr[100][100];

    // If statement to check and see if you
    // are reading from the input file
    if(inFile.is_open())
    {
        // for loop to store the numbers into
        // an multi dimensional array(100x100)
        for (int i = 0; i < r; i++) // For loop for row(r)
        {
            for (int j = 0; j < c; j++) // For loop for column(c)
            {
                inFile >> arr[i][j]; // Takes numbers from input file and stores in multi dimensional array(100x100)
            }
        }
    }

    // Variable for sorting function
    double temp;
    Number_Sorting(arr,temp); // Sorts numbers in ascending order

    // For loop to output each rows results one at a time
    for (int i = 0; i < r; i++)
    {
        Print_Trial_Number();
        Calculate_Mean(arr);
        Find_Median(arr);
        Find_Minimum(arr);
        Find_Maximum(arr);
        Calculate_Standard_Deviation(arr);

        cout << endl; // Starts new line for next row
        outFile << endl; // Starts new line for next row

        COUNTER++; // Adds 1 to the global counter in order to proceed to the next row
        trialNumber++; // Adds 1 to the global trial number in order to reflect the correct row in the output
    }
}
