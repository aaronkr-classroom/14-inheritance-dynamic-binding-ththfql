// main_grad.cpp
#include <algorithm>

#include <ios>

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "Grad.h"

using namespace std;

int main() {
	vector<Core> students; // 백터의 타입 변경
	Grad record; // read 함수로 읽을 타입 변경
	string::size_type maxlen = 0;

	// 데이터를 읽고 저장하기
	while (record.read(cin)) { // Core 객체가 아닌 Grad 객체를 읽음
		maxlen = max(maxlen, record.getName().size());
		students.push_back(record);
	}

	// 학생 기록을 알파벳 순으로 정렬
	sort(students.begin(), students.end(), compare);

	// 이름과 점수 출력
	for (vector<Grad>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].getName()
			<< string(maxlen + 1 - students[i].getName().size(), ' ');

		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
