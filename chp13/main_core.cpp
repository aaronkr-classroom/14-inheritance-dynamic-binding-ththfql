// main_core.cpp
#include <algorithm>

#include <ios>

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "Core.h"

using namespace std;

int main() {
	vector<Core> students; // Core 객체에 해당하는 기록을 읽고 처리
	Core record;
	string::size_type maxlen = 0;

	// 데이터를 읽고 저장하기
	while (record.read(cin)) {
		maxlen = max(maxlen, record.getName().size());
		students.push_back(record);
	}

	// 학생 기록을 알파벳 순으로 정렬
	sort(students.begin(), students.end(), compare);

	// 이름과 점수 출력
	for (vector<Core>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].getName()
			<< string(maxlen + 1 - students[i].getName().size(), ' ');

		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch(domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
