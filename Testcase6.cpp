#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

void ChenChuoiTaiVitriK(char s[], char s1[], int k);
void Chuanhoa(char s[]);
int myStrlen(char s[], int k);
bool myStrcat(char s[], char s1[], char s2[]);
void myStrcpy(char s[], int vt, char s1[], int k);
int myStrstr(char s[], char s1[]);

int main()
{
	char s[MAX];
	fflush(stdin);
	cin.getline(s, MAX);
	char s1[MAX];
	myStrcpy(s, 0, s1, 0);
	Chuanhoa(s1);
	cout << s << endl << s1 << endl;
	return 0;
}
void ChenChuoiTaiVitriK(char s[], int vt, int k) {
	int count = 0;
	if (s[vt + k] == '\0') {
		s[vt] = '\0';
	}
	else {
		for (int i = vt; s[i + k] != '\0'; i++) {
			s[i] = s[i + k];
			count = i + k;
		}
		s[count + 1 - k] = '\0';
	}
}
void Chuanhoa(char s[]) {
	int count=0;
	char s3[MAX];
	myStrcpy(s, 0, s3, 0);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ' && s[i + 1] == '.') {
			ChenChuoiTaiVitriK(s, i, 1);
			myStrcpy(s, 0, s3, 0);
			i-=2;
		}
		else if (s[i] == '.' && s[i + 1] == ' ' &&s[i+2]==' ') {
			ChenChuoiTaiVitriK(s, i+1, 1);
			myStrcpy(s, 0, s3, 0);
			i --;
		}
		else if (s[i] == '.' && s[i + 1] == ' ' && s[i + 2] != '\0' && s[i+2]!='\0') {
			s[i + 2] = toupper(s[i + 2]);
		}
		else if (s[i] == '.' && s[i + 1] != ' ' && s[i + 1] != '\0') {
			for (int j = i +1; s3[j] != '\0';j++) {
				s[j+1]=s3[j];
			}
			s[i+1] = ' ';
			s[myStrlen(s3, 1) + 1] = '\0';
			myStrcpy(s, 0, s3, 0);
		}
	}
}
void myStrcpy(char s[], int vt, char s1[], int k) {
	int count = 0;
	int flag = 0;
	for (int i = vt; s[i] != '\0'; i++) {
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
