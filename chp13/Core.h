#ifndef GUARD_CORE_H
#define GUARD_CORE_H

#include<string>
#include <iostream>
#include <vector>


using namespace std;

class Core {
public:
	// Core 클래스의 기본 생성자와 기본 값
	Core() : midterm(0), final(0) {};

	// istream으로 Core 객체 생성
	Core(istream& is) { read(is);  };

	string getName() const;
	virtual double grade() const; // 가상 함수
	virtual istream& read(istream&); // 가상 함수

	virtual ~Core() {} // 가상 소멸자
protected:
	istream& read_common(istream&); // 이름, 시험, 과제
	double midterm, final;
	vector<double> homework;
	
	virtual Core clone() const { return  new Core(*this);}
private:
	string name;
	// friend class Student_info;
};

bool compare(const Core&, const Core&);
bool compare_grades(const Core&, const Core&);

#endif

