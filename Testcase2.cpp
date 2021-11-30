// C++ program to find out execution time of
// of functions
#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;
  
// For demonstration purpose, we will fill up
// a vector with random integers and then sort
// them using sort function. We fill record
// and print the time required by sort function
int mainte2()
{
  
    vector<int> values(10000);
  
    // Generate Random values
    auto f = []() -> int { return rand() % 10000; };
  
    // Fill up the vector
    generate(values.begin(), values.end(), f);
  
    // Get starting timepoint
    auto start = chrono::high_resolution_clock::now();
  
    // Call the function, here sort()
    sort(values.begin(), values.end());
  
    // Get ending timepoint
    auto stop = chrono::high_resolution_clock::now();
  
    // Get duration. Substart timepoints to 
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration1 = chrono::duration_cast<chrono::microseconds>(stop - start);
    duration<long ,micro> duration2 = duration_cast<chrono::microseconds>(stop - start);
    chrono::microseconds duration2z = chrono::duration_cast<chrono::microseconds>(stop - start);
    duration<double>epoch_time = start-stop;
    auto epoch_time2 = start - stop;
  
    cout << "Time taken by function: "
         << duration2.count() << " microseconds" << endl;
  
    return 0;
}