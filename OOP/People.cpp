#pragma once
#include<iostream>
using namespace std;
class People {
private:
	string name;
	int age;
	string job;
	string id;
public:
	People(){}
	People(string name, int age, string job, string id) {
		this->name = name;
		this->age = age;
		this->job = job;
		this->id = id;
	}
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	string getJob() {
		return job;
	}
	string getId() {
		return id;
	}
	void display() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Job: " << job << endl;
		cout << "Id: " << id << endl;
	}
};