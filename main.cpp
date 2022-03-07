/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "studyInPink2.h"
using namespace std;

int readFile(
    const string & filename, 
    string & ntb1, 
    string & ntb2,
    string & ntb3,
    string & points,
    string & moves,
    string & tag,
    string & message
) {
//This function is used to read the input file,
//DO NOT MODIFY THIS FUNTION
    ifstream myfile(filename);
    if (myfile.is_open()) {
        myfile >> ntb1
            >> ntb2
            >> ntb3
            >> points
            >> moves
            >> tag
            >> message;

        return 1;
    }
    else return 0;
}

int main(int argc, const char * argv[]) {
    string filename = "input1.txt";
    string ntb1, ntb2, ntb3, points, moves, tag, message;

    bool isRead = readFile(filename, ntb1, ntb2, ntb3, points, moves, tag, message);
    if (isRead){
        cout << ntb1 << endl;
        cout << ntb2 << endl;
        cout << ntb3 << endl;
        cout << points << endl;
        cout << moves << endl;
        cout << tag << endl;
        cout << message << endl;

        // Task 1
        string pwd1 = notebook1(ntb1);
        string pwd2 = notebook2(ntb2);
        string pwd3 = notebook3(ntb3);
        string listPwd = generateListPasswords(pwd1, pwd2, pwd3);

        cout << "pwd1: " << pwd1 << endl;
        cout << "pwd2: " << pwd2 << endl;
        cout << "pwd3: " << pwd3 << endl;
        cout << "List passwords: " << listPwd << endl;

        // Task 2
        int arr[100][100];
        string outTimes, outCatchUps;

        bool reached = chaseTaxi(arr, points, moves, outTimes, outCatchUps);
        cout << "Can reach: " << reached << endl;
        cout << "outTimes: " << outTimes << endl;
        cout << "outCatchUps: " << outCatchUps << endl;

        // Task 3
        string loginInfo = enterLaptop(tag, message);
        cout << loginInfo << endl;
    }
    else{
        cout << "Cannot read input file";
    }
    return 0;
}
