// Grad.h
#ifndef GUARD_GARD_H
#define GUARD_GARD_H

#include "Core.h"

class Grad : public Core {
public:
	// 두 생성자 모두 암묵적으로 Core::Core()를 사용하여
	// 객체가 기본 클래스에서 상속한 부분을 초기화
	Grad() : thesis(0) {};
	Grad(istream& is) { read(is); }
	double grade() const;
	istream& read(istream&);
protected:
	Grad* clone() const {return  new Grad(*this);}
private:
	double thesis;
};

#endif