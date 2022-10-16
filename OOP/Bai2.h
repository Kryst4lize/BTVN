#pragma once
struct Point {
	int x=0;
	int y=0;
};
class polygon {
private:
public:
	virtual void input() = 0;
	virtual void output() = 0;
	virtual void move() = 0;
};
class rectangle:public polygon {
private:
	Point A, B, C;
public:
	void input();
	void output();
	void move();
};
class quadrilateral:public polygon {
private:
	Point A, B, C, D;
public:
	void input();
	void output();
	void move();
};
class square :public polygon{
private:
	Point A, B, C, D;
public:
	void input();
	void output();
	void move();
};
class parallelogram: public polygon{
private:
	Point A, B, C, D;
public:
	void input();
	void output();
	void move();
};
void bai2();

