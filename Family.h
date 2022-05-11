#pragma once
#include"People.h"
#include<vector>
class Family{
private:
	string nameF;
	string status;
	string _insert;
	vector<People> p;
public:
	Family() {
		nameF = p[0].getName();
	}
	Family(string status, string _insert, vector<People> p):nameF(p[0].getName()) {
		this->status = status;
		this->_insert = _insert;
		this->p = p;
		nameF = p[0].getName();
	}
	string getNameF() {
		return nameF;
	}
	string getStatus() {
		return status;
	}
	string getAdd() {
		return _insert;
	}
	vector<People> getP() {
		return p;
	}
	void display(){
		cout << "householder's name: " << nameF << endl;
		cout << "Number Member: " << p.size() << endl;
		cout << "Address: " << _insert << endl;
		cout << "Status: " << status << endl;
		cout << "List Information Member" << endl;
		for (int i = 0; i < p.size(); i++){
			p[i].display();
		}
	}
	static vector<Family> getPoorHousehold(vector<Family>fa) {
		vector<Family>::iterator k;
		vector<Family>fasort;
		for (k = fa.begin(); k != fa.end(); k++) {
			if ((*k).status == "poor") {
				fasort.push_back(*k);
			}
		}
		return fasort;
	}
	static vector<Family> getFamilySurename(vector<Family>fa,string surename) {
		vector<Family>::iterator k;
		vector<Family>fasort;
		for (k = fa.begin(); k != fa.end(); k++) {
			if ((*k).nameF == surename) {
				fasort.push_back(*k);
			}
		}
		return fasort;
	}

};
