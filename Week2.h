#pragma once
// implement int main in the end of this file (in comment file)
#include<vector>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<map>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
//Bai 1
class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time(int hour = 0, int minute = 0, int second = 0);
	~Time(){}
	void Change();
	void setH(int h);
	void setM(int m);
	void setS(int s);
	int getH();
	int getM();
	int getS();
	void output();
};
class Date 
{
private:
	int day, month, year;
public:
	Date(int day = 1, int month = 1, int year = 2000) {}
	~Date() {}
	void Change();
	void setD(int);
	void setM(int);
	void setY(int);
	int getD();
	int getM();
	int getY();
};
//Bai 2
class Stack {
private:
	int index = 0;
	int stack[15];
public:
	int size();
	void push(int);
	int pop();
	bool isEmpty();
	bool isFull();
	int top();
};
//Bai 3
void Partition(int m); //// Partify the prime number element of a number
//Bai 4
void convert102(int m); // decimal to binary
void convert108(int m); // decimal to oct
void convert1016(int m); // decimal to hexadecimal
//Bai 5
class queue {
private:
	int index = 0;
	int queue[15];
public:
	int size();
	bool empty();
	void push(int a);
	int pop();
	int front();
	int back();
};
//Bai 6
class String {
private:
	string* a;
public:
	String(string);
	~String() {
		delete a;
	}
	string operator + (string b);
	string reverse();
	void input(string b);
	string output();
};
//Bai 7
class list {
private:
	vector<int>arr;
	int index = 0;
public:
	void push_back(int a);
	void push_front(int a);
	int pop_back();
	int pop_front();
	int front();
	int back();
};
//bai 8
void Checking2(string link);
bool compareS(string a, string b); //extra function for Checking2