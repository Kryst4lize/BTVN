#include "Week2.h"
Time::Time(int hour, int minute, int second) {
	this->hour = hour;
	this->minute = minute;
	this->second = second;
	Change();
}
void Time::Change() {
	minute += second / 60;
	second %= 60;
	hour += minute / 60;
	minute %= 60;
	hour %= 24;
}
void Time::setH(int h) {
	hour = h;
	Change();
}
void Time::setM(int m) {
	minute = m;
	Change();
}
void Time::setS(int s) {
	second = s;
	Change();
}
int Time::getH() {
	return hour;
}
int Time::getM() {
	return minute;
}
int Time::getS() {
	return second;
}
void Time::output() {
	cout << "Dong ho dang chi (24H Format) : " << hour << "::" << minute << "::" << second << endl;
	cout << "Dong ho dang chi (AM/PM Format) : " << hour % 12 << "::" << minute << "::" << second;
	if (hour > 12) {
		cout << " PM\n";
	}
	else {
		cout << " AM\n";
	}
}
void Date::Change() {
	while (1) {
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day>31) {
			day -= 31;
			month++;
			if (month > 12) {
				year += month / 12;
				month %= 12;
			}
			if (day < 31 && month != 2) {
				break;
			}
			if (day < 29 && month == 2 && year%4!=0) {
				break;
			}
			if (day < 30 && month == 2 && year%4==0) {
				break;
			}
		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && day>30) {
			day -= 30;
			month++;
			if (day < 32) {
				break;
			}
		}
		else if(month==2 && day>28 && year%4!=0){
			day -= 28;
			month++;
			if (day < 32) {
				break;
			}
		}
		else if (month == 2 && day > 29 && year % 4 == 0) {
			day -= 29;
			month++;
			if (day < 32) {
				break;
			}
		}
	}
	year += month / 12;
	month %= 12;
}
void Date::setD(int d) {
	day = d;
	Change();
}
void Date::setM(int m) {
	month = m;
	Change();
}
void Date::setY(int y) {
	year = y;
}
int Date::getD() {
	return day;
}
int Date::getM() {
	return month;
}
int Date::getY() {
	return year;
}
int Stack::size() {
	return index;
}
void Stack::push(int a) {
	if (index == 10) {
		cout << "Stack is full so it cannot be pushed in.";
		return;
	}
	stack[index] = a;
	index++;
}
int Stack::pop() {
	if (index == 0) {
		cout << "Stack is empty so it cannot be popped. \n";
		return -1;
	}
	index--;
	return stack[index + 1];
}
bool Stack::isEmpty() {
	if (index == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool Stack::isFull() {
	if (index == 10) {
		return true;
	}
	else {
		return false;
	}
}
int Stack::top() {
	if (index == 0) {
		cout << "Stack is empty\n";
		return -1;
	}
	return stack[index - 1];
}
void convert102(int m) {
	Stack s;
	while (m != 0) {
		s.push(m % 2);
		m /= 2;
	}
	while (!s.isEmpty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
}
void convert108(int m) {
	Stack s;
	while (m != 0) {
		s.push(m % 8);
		m /= 8;
	}
	while (!s.isEmpty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
}
void convert1016(int m) {
	Stack s;
	while (m != 0) {
		s.push(m % 16);
		m /= 16;
	}
	while (!s.isEmpty()) {
		switch (s.top()) {
		case 10:
			cout << "A";
			break;
		case 11:
			cout << "B";
			break;
		case 12:
			cout << "C";
			break;
		case 13:
			cout << "D";
			break;
		case 14:
			cout << "E";
			break;
		case 15:
			cout << "F";
			break;
		default:
			cout << s.top();
		}
		s.pop();
	}
	cout << endl;
}
void Partition(int m) { 
	// erathones
	vector<bool>prime(1000, 1);
	prime[1] = 0;
	for (int i = 2; i < 1000; i++) {
		if (prime[i]) {
			for (int j = 2; j * i < 1000; j++) {
				prime[i * j] = false;
			}
		}
	}
	Stack s;
	int i = 2;
	int n = m;
	while (n != 1) {
		if (prime[i] == true && n % i == 0) {
			n /= i;
			s.push(i);
		}
		else {
			i++;
		}
	}
	cout << m << " = ";
	while (!s.isEmpty()) {
		if (s.size() != 1) {
			cout << s.top() << "*";
			s.pop();
		}
		else {
			cout << s.top();
			s.pop();
		}
	}
	cout << endl;
}
int queue::size() {
	return index;
}
bool queue::empty() {
	if (index == 0) {
		return true;
	}
	else { return false; }
}
void queue::push(int a) {
	if (index == 10) {
		cout << "Queue is full so it cannot be pushed in.";
		return;
	}
	queue[index] = a;
	index++;
}
int queue::pop() {
	if (index == 0) {
		cout << "Queue is empty so it cannot be popped. \n";
		return -1;
	}
	int temp = queue[0];
	for (int i = 0; i < index; i++) {
		queue[i] = queue[i + 1];
	}
	index--;
	return temp;
}
int queue::front() {
	return queue[0];
}
int queue::back() {
	return queue[index - 1];
}
String::String(string arr = "") {
	this->a = new string;
	for (auto s : arr) {
		(*a) += s;
	}
}
string String::operator + (string b) {
	for (auto s : b) {
		(*a) += s;
	}
	return (*a);
}
string String::reverse() {
	string temps = "";
	cout << (*a).length() << endl;
	for (int i = (*a).length() - 1; i > -1; i--) {
		temps += (*a)[i];
	}
	(*a) = temps;
	return temps;
}
void String::input(string b) {
	(*a) = b;
}
string String::output() {
	cout << *a << endl;
	return *a;
}
void list::push_back(int a) {
	arr.resize(index + 1);
	arr[index] = a;
	index++;
}
void list::push_front(int a) {
	arr.resize(index + 1);
	for (int i = index; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = a;
	index++;
}
int list::pop_back() {
	if (index == 0) {
		cout << "List is empty so it can pop" << endl;
		return -1;
	}
	int a = arr[index - 1];
	arr.resize(index - 1);
	return a;
}
int list::pop_front() {
	if (index == 0) {
		cout << "List is empty so it can pop" << endl;
		return -1;
	}
	int temps = arr[0];
	for (int i = 0; i < index - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr.resize(index - 1);
}
int list::front() {
	if (index == 0) {
		cout << "No element is list" << endl;
		return -1;
	}
	return arr[0];
}
int list::back() {
	if (index == 0) {
		cout << "No element is list" << endl;
		return -1;
	}
	return arr[index - 1];
}
bool compareS(string a, string b) {
	for (int i = 0; i < a.length() && i < b.length(); i++) {
		if (a[i] == b[i]) {
			continue;
		}
		else {
			return toupper(a[i]) < toupper(b[i]);
		}
	}
	return a.length() < b.length();
}
void Checking2(string link) {
	ifstream check(link);
	string s;
	vector<vector<string>>arr(1);
	arr[0].resize(1);
	int indexS = 0, indexW = 0, indexP = 0;;
	while (getline(check, s)) {
		indexP++;
		//question 1 and 2
		for (int i = 0; i < s.length(); i++) {
			if ((s[i] == '!') || (s[i] == '?') || (s[i] == '.')) {
				indexS++;
				arr.resize(long long(indexS) + 1);
				indexW = 0;
			}
			else if (s[i] == ' ') {
				indexW++;
				arr[indexS].resize(long long(indexW) + 1);
			}
			else if ((s[i] == '(') || (s[i] == ')') || (s[i] == '\"') || s[i] == ',' || s[i] == '\'') {
				continue;
			}
			else {
				arr[indexS][indexW] += s[i];
			}
		}
		arr.resize(arr.size() - 1);
		for (int i = 0; i < arr.size(); i++) {
			arr[i].resize(arr[i].size() - 1);
		}
		cout << arr.size() << endl;
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i].size() << " ";
		}
		cout << endl;
		//question 3
		map<string, int>maxfre;
		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				maxfre[arr[i][j]]++;
			}
		}
		map<string, int>::iterator it;
		int count1 = 0;
		for (it = maxfre.begin(); it != maxfre.end(); it++) {
			if (it->second > count1) {
				count1 = it->second;
			}
		}
		for (it = maxfre.begin(); it != maxfre.end(); it++) {
			if (it->second == count1) {
				cout << it->first;
			}
		}
		cout << endl;
		//question 4
		for (int i = 0; i < arr.size(); i++) {
			sort(arr[i].begin(), arr[i].end(), compareS);
		}
		for (auto a : arr) {
			for (auto b : a) {
				cout << b << " ";
			}
			cout << endl;
		}
	}
}