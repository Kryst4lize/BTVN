#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int mainf() {
	// Create and open a text file
	ofstream MyFile;
	MyFile.open("filename.txt");
	if (MyFile.is_open()) {
		// Write to the file
		MyFile << "Files can be tricky, but it is fun enough!";
		MyFile << ". Bruh my friend" << endl;
		MyFile << "Djt me cuoc doi._Bomman_";
		MyFile << 88;
	}
	else {
		cout << "Lam deo gi co file nao dmm"<<endl;
	}
	MyFile.close();
		// Close the file
		// Create a text string, which is used to output the text file
		string myText;

		// Read from the text file
		ifstream MyReadFile("filename.txt");

		// Use a while loop together with the getline() function to read the file line by line
		while (getline(MyReadFile, myText)) {
			// Output the text from the file
			cout << myText << endl;
		}

		// Close the file
		MyReadFile.close();
		fflush(stdin);
		return 0;
}
// A C++ program to show difference
// between exit() and _Exit()

