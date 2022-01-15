//Build cstring type function by your own
/*
#include <iostream>
#include <string.h>
#include<string>
using namespace std;
#define MAX 300
int myStrlen(char s[], int k); //Ham tra ve chieu dai chuoi s ke tu vi tri k
void myMemmove(char s[], int vt, int k); //Xoa k ky tu trong chuoi s, bat dau tu vi tri vt. 
int myStrstr(char s[], char s1[]); //Tim chuoi s1 trong chuoi s, neu tim thay tra ve vi tri s1[0] trong chuoi s, khong tin thay tra ve -1
void Chuanhoa(char s[]);
int myStrcmp1(char s1[], char s2[]);
int myStrcmp(char s1[], const char s2[]);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void myStrcpy(char s[], int vt, char s1[], int k);
void DemTieng(char s1[]);
void StringReverse(char st[]); 
void StringReverse2(char st[]);
/*int main()
{
	char s[MAX];
	cin.getline(s, MAX);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
		DemTieng(s);
	return 0;
	
int main()
{
	char s[MAX];
	cin.getline(s, MAX);	//Nhap chuoi s	
	Chuanhoa(s);
	cout << s << endl;
	return 0;
}
int main()
{
	char s1[MAX], s2[MAX];
	cin.getline(s1, MAX);
	cin.getline(s2, MAX);
	int kt = myStrcmp1(s1, s2);
	cout << kt << endl;
	return 0;
}
int main()
{
	char s[MAX];
	cin.getline(s, MAX);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
	{
		StringReverse(s);
		cout << s << endl;
	}
	return 0;
}
int mainte11() {
	string s;
	getline(cin, s);
	int BaseScore = 40, Bonus_Excess = 3, Bonus_Upper = 4, Bonus_Number = 5, Bonus_Symbols = 5;
	int Num_Upper = 0, Num_Numbers = 0, Num_Symbols = 0;
	int Bonus_Combo, Bonus_FlatLower, Bonus_FlatNumber, Num_Excess;
	if (s.length() < 8) {
		cout << "KhongHopLe";
		return 0;
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.' || s[i] == '\\' || s[i] == '/' || s[i] == ',' || s[i] == ' ') {
				cout << "KhongHopLe";
				return 0;
			}
			else {
				if (s[i] >= '0' && s[i] <= '9') {
					Num_Numbers++;
				}
				else if (s[i] >= 'A' && s[i] <= 'Z') {
					Num_Upper++;
				}
				else if (s[i] >= 'a' && s[i] <= 'z') {}
				else {
					Num_Symbols++;
				}
			}
		}
	}
	if (Num_Numbers * Num_Symbols * Num_Upper > 0) {
		Bonus_Combo = 25;
	}
	else if (Num_Numbers * Num_Symbols > 0 || Num_Symbols * Num_Upper > 0 || Num_Numbers * Num_Upper > 0) {
		Bonus_Combo = 15;
	}
	else {
		Bonus_Combo = 0;
	}
	if (Num_Numbers + Num_Symbols + Num_Upper == 0) {
		Bonus_FlatLower = -15;
	}
	else { Bonus_FlatLower = 0; }
	if (Num_Numbers == s.length()) {
		Bonus_FlatNumber = -35;
	} else { Bonus_FlatNumber = 0; }
	Num_Excess = s.length() - 8;
	int score = BaseScore + (Num_Excess * Bonus_Excess) + (Num_Upper * Bonus_Upper) + 
		(Num_Numbers * Bonus_Number) + (Num_Symbols * Bonus_Symbols) + Bonus_Combo + Bonus_FlatLower + Bonus_FlatNumber;
	if (score < 50) {
		cout << "Yeu";
	}
	else if (score >= 50 && score < 75) {
		cout << "Vua";
	}
	else if (score >= 75 && score < 100) {
		cout << "Manh";
	}
	else { cout << "RatManh"; }
	return 0;
}
void myMemmove(char s[], int vt, int k) {
	int count = 0;
	if (s[vt - 1 + k] == '\0') {
		s[vt - 1] = '\0';
	}
	else {
		for (int i = vt - 1; s[i + k] != '\0'; i++) {
			s[i] = s[i + k];
			count = i + k;
		}
		s[count + 1 - k] = '\0';
	}
}
void StringReverse(char s[]) {
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '\0') {
			break;
		}
		else if ((s[i - 1] == ' ' || (i == 0)) && (s[i] != ' ' && s[i] != '\0')) {
			int count2 = 0;
			int temp = i;
			char check[MAX];
			while (s[i] != ' ' && s[i] != '\0') {
				check[count2] = s[i];
				i++;
				count2++;
			}
			check[count2] = '\0';
			int i = temp;
			for (int j = count2 - 1; j > -1; j--) {
				s[i] = check[j];
				i++;
			}
			i--;
		}
	}
}
void StringReverse2(char s[]) {
	char s3[MAX];
	myStrcpy(s, 1, s3, MAX);
	int bruh = myStrlen(s3, 1);
	for (int i = bruh - 1,g=0; i > -1; i--) {
		s[g] = s3[i];
		g++;
	}
	s[bruh]='\0';
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '\0') {
			break;
		}
		else if ((s[i - 1] == ' ' || (i == 0)) && (s[i] != ' ' && s[i] != '\0')) {
			int count2 = 0;
			int temp = i;
			char check[MAX];
			while (s[i] != ' ' && s[i] != '\0') {
				check[count2] = s[i];
				i++;
				count2++;
			}
			check[count2] = '\0';
			int i = temp;
			for (int j = count2 - 1; j > -1; j--) {
				s[i] = check[j];
				i++;
			}
			i--;
		}
	}
}

int myStrcmp(char s1[], const char s2[]) {
	if (myStrlen(s1, 1) == 0) { return 0; }
	else return 1;
}
void DemTieng(char s1[]) 
{
	char s2[MAX];
	myStrcpy(s1, 1, s2, MAX);
	for (int i = 0; s2[i] != '\0'; i++) 
	{
		i = 0;
		while (s2[0] == ' ') 
		{
			myMemmove(s2, 1, 1);
		}
		if (myStrlen(s2, 1) == 0) { break; }
		int result = 0;
		int count = 0; //lay ra vi tri luc ket thuc
		int count2 = 0; // lay ra do lon cua tu va ket thuc chuoi can so sanh
		char check[MAX]="";
		for (int j = i; s2[j] != ' ' && s2[j] != '\0'; j++) 
		{
			count = j;
			check[count2] = s2[j];
			count2++;
		}
		check[count2] = '\0';
		for (int j = 0, flag1 = 0; s2[j] != '\0'; j++)
		{
			flag1 = 0;
			int temp = j;
			if ((j == 0 || s2[j - 1] == ' ') && check[0] == s2[j])
			{
				while (flag1 < count2)
				{
					if (check[flag1] == s2[j])
					{
						flag1++;
						j++;
					}
					else break;
				}
				if (flag1 == count2 && (s2[j] == ' ' || s2[j] == '\0'))
				{
					result++;
					myMemmove(s2, j - count2 + 1, count2);
					j = temp - 1;
				}
			}
		}
		cout << check << ": " << result << endl;
	}
}
void myStrcpy(char s[], int vt, char s1[], int k) {
	int count = 0;
	int flag = 0;
	for (int i = vt - 1; s[i] != '\0' && flag < k; i++) {
		s1[i] = s[i];
		count++;
		flag++;
	}
	s1[count] = '\0';
}
int myStrlen(char s[], int k) {
	int count = 0;
	for (int i = k - 1; s[i] != '\0'; i++) {
		count++;
	}
	return count;
}

void Chuanhoa(char s[]) {
	while (s[0] == ' ') {
		myMemmove(s, 1, 1);
	}
	s[0]=toupper(s[0]);
	int count = 0;
	for (int i = 1; s[i] != '\0'; i++) {
		if (s[i] == ' ' && s[i + 1] == ' ') {
			myMemmove(s, i + 1, 1);
			i--;
		}
		else if (s[i] == ' ' && s[i + 1] == '\0') {
			myMemmove(s, i + 1, 1);
			i--;
		}
	}
	for (int i = 1; s[i] != '\0'; i++) {
		s[i]=tolower(s[i]);
	}
	for (int i = 1; s[i] != '\0'; i++) {
		if (s[i] == ' ') {
			s[i+1]=toupper(s[i+1]);
		}
	}
}
int myStrcmp1(char s1[], char s2[]) {
	for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
		if (s1[i] > s2[i]) { return 1; }
		if (s1[i] < s2[i]) { return -1; }
	}
	if (myStrlen(s1, 1) > myStrlen(s2, 1)) {
		return 1;
	}
	if (myStrlen(s1, 1) < myStrlen(s2, 1)) {
		return -1;
	}
	return 0;
}*/