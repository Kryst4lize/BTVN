#include<iostream>
#include<random>
#include<vector>
#include<fstream>
#include<chrono>
#include<sstream>
#include<cstdlib>
#include"sort.h"
#include<algorithm>
#define element 1000000
using namespace std;
using namespace std::chrono;
//Create a set of random number (50000 number to be precisely)
void randomCreate() {
	random_device rd;
	mt19937 ak(rd());
	uniform_real_distribution<double> mt(-40000, 40000);
	ofstream a("inputdata.txt");
	if (a.is_open()) {
		cout << "FIle da mo: " << endl;
	}

	for (int j = 0; j < 2; j++) {
		double k = -40000;
		for (int i = 0; i < element; i++) { // input 1 million time
			uniform_real_distribution<double> mk(k+0.5, k+1);
			k = mk(ak);
			a << k << " ";
		}
		a << endl;
	}
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < element ; i++) { // input 1 million time
			a << mt(ak) << " ";
		}
		a << endl;
	}
	return;
}
//Timepoint comparasion function implementation
void timepoint() {
	//initial array
    ifstream g("Inputdata.txt");
	for (int j = 1; j <= 10; j++) {
		double* arr = new double[element];
		double* arrheap = new double[element];
		double* arrquick = new double[element];
		double* arrmerge = new double[element];
		double* arrstd = new double[element];
		string s;
		stringstream ss;
		getline(g, s);
		ss << s;
		for (int i = 0; i < element; i++) {
			ss >> arr[i];
			arrheap[i] = arr[i];
			arrmerge[i] = arr[i];
			arrquick[i] = arr[i];
			arrstd[i] = arr[i];
		}
		//calculate heapSort's time
		auto start1 = high_resolution_clock::now();
		heapSort(arrheap, element);
		auto end1 = high_resolution_clock::now();
		auto timepoint1 = duration_cast<milliseconds>(end1 - start1);
		cout << "Time to sort using heap sort in "<<j<<" trial: "<< timepoint1.count() << endl;
		//calculate quickSort's time
		auto start2 = high_resolution_clock::now();
		quickSort(arrquick, 0, element -1);
		auto end2 = high_resolution_clock::now();
		auto timepoint2 = duration_cast<milliseconds>(end2 - start2);
		cout << "Time to sort using quick sort in "<<j<<" trial: " << timepoint2.count() << endl;
		//calculate mergeSort's time
		auto start3 = high_resolution_clock::now();
		mergeSort(arrmerge, 0, element -1);
		auto end3 = high_resolution_clock::now();
		auto timepoint3 = duration_cast<milliseconds>(end3 - start3);
		cout << "Time to sort using merge sort in " << j << " trial: "<< timepoint3.count() << endl;
		//calculate quickSort's time
		auto start4 = high_resolution_clock::now();
		stdSort(arrstd);
		auto end4 = high_resolution_clock::now();
		auto timepoint4 = duration_cast<milliseconds>(end4 - start4);
		cout << "Time to sort using std::sort in " << j << " trial: " << timepoint4.count() << endl;
		//release memory
		delete[] arr;
		delete[] arrheap;
		delete[] arrquick;
		delete[] arrmerge;
		delete[] arrstd;
	}
}
