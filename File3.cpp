#include<vector>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class Person 
{
public:
	int age;
	string name;
	int rating;
	char gender;
	//display the stats of one person
	Person(string name, char gender, int age, int rating) 
	{
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->rating = rating;
	}
};
class Leaderboard 
{
private:
	vector<Person>rank;
	string path;
public:
	void setpath(string path) 
	{
		this->path = path;
	}
	string getpath() 
	{
		return path;
	}
	Leaderboard(vector<Person>rank) :rank(rank) {}
	void insert(Person a) 
	{
		rank.push_back(a);
	}
	void writefile() 
	{
		ofstream file(path,ios::out|ios::trunc);
		if (file.is_open()==0) 
		{
			cout << "Path is illegal,please insert another path";
			cin >> path;
			writefile();
		}
		else 
		{
			for (int i = 0; i < rank.size(); i++) 
			{
				file.write((char*)&rank[i],sizeof(rank[i]));
			}
		}
	}
	void readfile(int rating) 
	{
		ifstream file(path);
		if (!file.is_open()) 
		{
			cout << "Path is illegal,please insert another path";
			cin >> path;
			readfile(rating);
		}
		else 
		{
			cout << "Open file successfully" << endl;
			while(!file.eof())
			{
				_getch();
				int count = 0;
				for (int i = 0; i < rank.size(); i++) 
				{
					file.read((char*)&rank[i], sizeof(rank[i]));
					if (rating==rank[i].rating)
					{
						count++;
						cout << setw(10) << rank[i].name;
						cout << "," << setw(2) << rank[i].gender;
						cout << "," << setw(3) << rank[i].age;
						cout << "," << setw(6) << rank[i].rating << endl;
					}
				}
				cout << "There is " << count << " result match your rating" << endl;
			}
			
		}
		file.close();
	}
};
int mainf3() {
	vector<Person>rank= { Person("Minh",'m',19,15000),Person("Thuy",'w',21,25000),Person("Michael",'m',25,15000),Person("Ha My",'w',18,12500)};
	Leaderboard a(rank);
	a.setpath("C:/Users/pc/Desktop/Minh/AuthorBook/File3.txt");
	a.insert(Person("Ninh", 'm', 15, 15000));
	a.writefile();
	a.readfile(15000);
	return 0;
}
