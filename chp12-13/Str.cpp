#include <iostream>
#include <iterator>
#include <cstring>

#include "Str.h"

using namespace std;

//section 12.3.2 / page 216
istream& operator>>(istream& is, Str& s) { //입력 연산자
	// 기존 값 제거
	s.data.clear();

	// 띄어쓰기 까지 문자 읽기
	char c;
	while (is.get(c) && isspace(c))
		; // 아무것도 안해도 됨

	// 계속 문자가 있으면 다음 띄어쓰기까지 읽기
	if (is) {
		do s.data.push_back(c);
		while (is.get(c) && !isspace(c))
			; //아무것도 안해도 됨

		// 띄어쓰기 있으면 다시 스트림으로 보내기
		if (is)
			is.unget();

	}
	return is;
}

// section 12.3.1 / page 216
ostream& operator<<(ostream& os, const Str& s) { //출력 연산자
	for (Str::size_type i = 0; i != s.size(); ++i) {
		os << s[i];
	}
	return os;
}
// Section 12.3.3. / page 219
Str operator+(const Str& s, const Str& t) { //문자열 결합
	Str r = s;
	r += t;
	return r;
}
