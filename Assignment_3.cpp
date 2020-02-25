#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

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
    double sum;
    // Counter variables
    int n, m;
    string line;

    while(inFile)
    {
        for (int i = 0; i < 10000; i++)
        {
            inFile >> arr[i];
        }
    }

    for (int i = 0; i < 100; i++)
    {
        cout << arr[i] << " ";

        sum += arr[i] ;
    }

    cout << "\nMean: " << fixed << setprecision(1) << sum / 100;

    cout << "\n\n";

    sum = 0;

    for (int i = 100; i < 200; i++)
    {

        cout << arr[i] << " ";

        sum += arr[i];
    }

    cout << "\nMean: " << fixed << setprecision(1) << sum / 100;







    // Close the input and output files
    inFile.close();
    outFile.close();

    return 0;
}
