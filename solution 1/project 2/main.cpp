// 3장-StudentStack.cpp : StudentStack 테스트 프로그램
#include "StudentStack.h"
void main()
{
	StudentStack stack; // 학생 스택 객체 생성
	stack.push(Student(2015130007, "홍길동", "컴퓨터공학과"));
	stack.push(Student(2015130100, "이순신", "기계공학과"));
	stack.push(Student(2015130135, "황희",  "법학과"));
	stack.display();
	stack.pop();
	stack.display();
}
