#pragma once
#include <cstring>
struct Customer
{
	int id;
	char gender;
	char name[20];
	char priority;
public:
	Customer() : id(0), gender('m'), name{ '\0' }, priority('n') {} //기본 생성자 함수
	Customer(int id, char gen = 'm', const char* name = "", char pri = 'n')// 호출할 때 파라미터 타입을 받아서 
		: id(id), gender(gen), priority(pri) { // 객체 초기화 리스트 사용 
		strcpy_s(this->name, sizeof(this->name), name);	////문자열인 name은 배열이여서 strcpy_s로 복사 / C-style string copy, buffer overflow prevented
		//이름이 똑같을 때 구분하기 위해 this->를 사용함
	}
	~Customer() {}
	const char* getName() const { return name; }
	char getGender() const { return gender; }
	char getPriority() const { return priority; }
	int getId() const { return id; }
};


//name[]이라는 배열울 초기화 할때 name[] = {0,0,0} | = {'\0'} 같다