/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "studyInPink.h"
using namespace std;

int readFile(string filename, int& HP1, int& HP2, int& EXP1, int& EXP2, int& M1, int& M2, int& E1, int& E2, int& E3) {
    //This function is used to read the input file,
    //DO NOT MODIFY THIS FUNTION
    ifstream myfile(filename);
    if (myfile.is_open()) {
        myfile >> HP1 >> HP2;
        myfile >> EXP1 >> EXP2;
        myfile >> M1 >> M2;
        myfile >> E1 >> E2 >> E3;
        return 1;
    }
    else return 0;
}

int main(int argc, const char* argv[]) {
    string filename = "C:/Users/pc/Downloads/input.txt";
    int HP1 = -1, HP2 = -1;
    int EXP1 = -1, EXP2 = -1;
    int M1 = -1, M2 = -1;
    int E1 = -1, E2 = -1, E3 = -1;
    bool isRead = readFile(filename, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3);
    if (isRead) {
        //Task 1
        cout << firstMeet(EXP1, EXP2, E1) << endl;
        cout << EXP1 << " " << EXP2 << endl;
        //Task 2
        cout << investigateScene(EXP1, EXP2, HP2, M2, E2) << endl;
        cout << EXP1 << " " << EXP2 << " " << HP2 << " " << M2 << endl;
        //Task 3
        cout << traceLuggage(HP1, EXP1, M1, E3) << endl;
        cout << HP1 << " " << EXP1 << " " << M1 << endl;
    }
    else {
        cout << "Cannot read input file";
    }
    return 0;
}
