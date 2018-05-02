//
//  LinearSearch.cpp
//
//
//  Created by CALEB SARIKEY & ALEX O'HARE
//

#include <iostream>
#include <time.h>
using namespace std;

//struct to hold data
struct empType{
    int ID;
    double Score;
};

// populates array A[] with n random elements
void populateArray(empType A[], int n){
    for (int i = 0; i < n; i++){
        A[i].ID = rand() % (n*2+1);
        A[i].Score = rand() % 101;
    }
};

//prints n elements of array A[]
void printArray(empType A[], int n){
    cout << "ID\tScore\n";
    for (int i = 0; i < n; i++){
        cout << A[i].ID << "\t" << A[i].Score << endl;
    }
};

// searches array A[].ID for element x
// if x is found, outputs the index at which it is located
// if x is not found, outputs a console message indicating not found
// returns a counter of the number of comparisons made
int linearSearch(empType A[], int size, int x, int &counter);

/*------------------------------------------------------------------------------*/
int main(){

    srand(time(0));    //seed random number generator

    //to hold test sizes
    int M[5] = { 100, 1000, 10000, 100000, 1000000 };

    //to store average number of ops and average execution time
    int avgOps, avgTime;

    cout << "Linear Search Analysis: Average Comparisons and Execution Time\n";
    cout << "Calculated over 1,000 iterations for each n = {100, 1000, 10000, 100000, 1000000}\n\n";
    cout << "Input Size\tAverage Comparisons\tAverage Time" << endl;

    //repeat for 4 test sizes
    for(int k=0; k<5; k++){
        avgOps = 0;
        avgTime = 0;

        //repeat 100 times and take average
        for(int i=0; i<1000; i++){
            //allocate array of size M[i]
            empType *A;
            A = new empType[M[k]];

            // randomaly populate array
            populateArray(A, M[k]);

            //generate random id to search for
            int x = rand() % (M[k]*2+1);

            //store starting clock time
            clock_t ms = clock();

            //counts comparisons made
            int counter = 0;

            //search for x
            int ops = linearSearch(A, M[k] - 1, x, counter);

            //calculate time passed since clock start
            ms = clock() - ms;

            /* statement below prints ops and time for each iteration */
            //cout << "n = " << M[k] << " \t " << ops << " \t\t " << ms << "ms \n";
            avgOps += ops;
            avgTime += ms;
        }
        //calculate averages and display
        avgOps = avgOps / 1000;
        avgTime = avgTime / 1000;
        cout << "n = " << M[k] << " \t " << avgOps << "\t\t\t" << avgTime << "ms \n\n";
    }

    cout << endl << endl;
    //system("pause");
    return 0;
}
/*------------------------------------------------------------------------------*/
int linearSearch(empType A[], int size, int x, int &counter){
    for(int i=0; i<=size; i++){
        if(A[i].ID == x){
            counter++;
            return counter;
        }
        else
            counter++;
    }
    return counter;
};
