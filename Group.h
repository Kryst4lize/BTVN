#include"Family.h"
#include"People.h"
class Group  {
private:
	string nameGr;
	vector<Family> f;
public:
	Group() {}
	Group(string nameGr, vector<Family>f) :f(f), nameGr(nameGr) {}
	string getNameGr() {
		return nameGr;
	}
	vector<Family> getF() {
		return f;
	}
	int getNumberFamily() {
		return f.size();
	}
	static double avgAgeGroup(Group v) {
		double total = 0;
		 double number = 0;
		//get the total age of every family
		for (int i = 0; i < v.getF().size(); i++) {
			for (int j = 0; j < v.getF()[i].getP().size(); j++) {
				total = total + v.getF()[i].getP()[j].getAge();
			}
		}
		//get total number of member in every family
		for (int i = 0; i < v.getF().size(); i++) {
			number = number + v.getF()[i].getP().size();
		}
		return total / number;
	}	
	static vector<People> getPeopleHaveNotJob(Group g) {
		vector<People>Unemployee;
		for (int i = 0; i < g.getF().size(); i++) {
			for (int j = 0; j < g.getF()[i].getP().size(); j++) {
				if (g.getF()[i].getP()[j].getJob() == "") {
					Unemployee.push_back(g.getF()[i].getP()[j]);
				}
			}
		}
		return Unemployee;
	}
};