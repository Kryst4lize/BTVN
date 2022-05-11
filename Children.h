#pragma once
#include"Person.h"
#include<iostream>
using namespace std;
class Children:public Person{
public:
	Children(){}
	Children(string name,int age,string _insert,vector<Book> vb):Person(name,age,_insert,vb){}
	~Children(){}
	long moneyPay() {
		return 5000 * getVB().size();
	}
	void display() {
		cout << "Children!" << endl;
		Person::display();
	}
};