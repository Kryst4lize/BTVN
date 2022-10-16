
using namespace std;
class book {
private:
	string name="";
	int year = 0;
	string author="";
public:
	virtual void input();
	virtual void output();
};
class SGK :public book {
private:
	string type = "Sach giao khoa";
public:
	void input();
	void output();
};
class TT :public book {
private:
	string type = "Tieu thuyet";
public:
	void input();
	void output();
};
class TC :public book {
private:
	string type = "Tap chi";
public:
	void input();
	void output();
};
class manage
{
private:
	vector<book*>arr;
public:
	void input();
	void output();
	void remove();
};
void bai1();