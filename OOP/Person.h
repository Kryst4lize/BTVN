#include"Book.h"
#include<vector>
#include<algorithm>
#pragma once
class Person {
private:
	string name;
	int age;
	string _insert;
	vector<Book> vb;
public:
	Person(){}
	virtual ~Person() {}
	Person(string name,int age,string _insert,vector<Book>vb):name(name),age(age),_insert(_insert),vb(vb){}
	string getName() {
		return name;
	}
	string getAdd() {
		return _insert;
	}
	int getAge() {
		return age;
	}
	vector<Book> getVB() {
		return vb;
	}
	virtual long moneyPay() = 0;
	virtual void display() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Add: " << _insert << endl;
		cout << "List Book Borrowed:" << endl;
		for (int i = 0; i < vb.size(); i++){
			vb[i].display();
		}
		cout << "Money Pay: " << moneyPay() << endl;
	}
	static void sortPersonAge(vector<Person*>& vt) {
		for (int i = 0; i < vt.size(); i++) {
			for (int j = 0; j < vt.size()-1; j++) {
				if (vt[j]->getAge() < vt[j+1]->getAge()) {
					swap(vt[j], vt[j + 1]);
				}
			}
		}
	}
	static vector<int> getListAge(vector<Person*>vt){
		vector<int> str;
		for (int i = 0; i < vt.size(); i++)
		{
			if (!(find(str.begin(), str.end(), vt[i]->getAge()) != str.end()))
			{
				str.push_back(vt[i]->getAge());
			}
		}
		return str;
	}
	static vector<Book>getMaxBookBorrowed(vector<Person*>vp, vector<Book>vb) {
		//count how many times that book was borrowed
		vector<int>count(vb.size(), 0);
		for (int i = 0; i < vp.size(); i++) {
			for (int j = 0; j < vb.size(); j++) {
				for (int k = 0; k < vp[i]->getVB().size(); k++) {
					if (vp[i]->getVB()[k].getNameBook() == vb[j].getNameBook()) {
						count[j] = count[j] + 1;
					}
				}
			}
		}
		//take the max times the book was borrowed and sort
		vector<int>::iterator k = max_element(count.begin(), count.end());
		int max = *k;
		vector<Book>final;
		for (int i = 0; i < vb.size(); i++) {
			if (count[i] == max) {
				final.push_back(vb[i]);
			}
		}
		return final;
	}
};

