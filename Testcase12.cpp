#include<iostream>
#include<string>
using namespace std;
void replaceString(string s,string s1,string s2){
	string s3="";
	for (int i = s1.length() - 1; i > -1; i--) {
		s3 += s1[i];
	}
	for (int i = s.length() - 1; i > -1; i--) {
		if (s3[0] == s[i]) {
			int temp = i;
			int count = 0; //dem xem trung duoc bao nhieu ky tu, neu nhu trung du ky tu cua s3 thi moi xac dinh la tu can 
			for (int j = 0 ; j < s3.length(); j++) {
				if (s3[j] == s[temp]) {
					count++; // dem
					temp--;
				}
				else { break; }
			}
			if (count == s3.length()) {
				s.replace(temp+1,s3.length(),s2);
				cout << s;
				return;
			}
		}
	}
	cout << s;
	return;
}
int main() {
	string alc = "Evil";
	replaceString("dai hoc bach khoa sai gon", "ai", "ong");
	return 0;
}
