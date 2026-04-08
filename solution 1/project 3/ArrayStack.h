
#pragma once
// ArrayStack.h : 배열을 이용한 int 스택 클래스
#include <cstdio>	// C 헤더파일 <stdio.h>을 포함하는 것과 동일
#include <cstdlib>  // C 헤더파일 <stdlib.h>을 포함하는 것과 동일

const int MAX_STACK_SIZE = 20;		// 스택의 최대 크기 설정
class ArrayStack //클래스 선언
{
	// 아무것도 없는 private 영역이 생략되어 있다.
	//private:
	int top;						// 요소의 개수
	int data[MAX_STACK_SIZE];		// 요소의 배열
public:
	ArrayStack();	// 스택 생성자(초기화)
	~ArrayStack();	// 스택 소멸자
	bool isEmpty();
	bool isFull();
	void push(int e);
	int pop();
	int peek();
	void display();
}; //클래스는 세미콜론으로 끝나야한다