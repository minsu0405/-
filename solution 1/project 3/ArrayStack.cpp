#include <cstdio>	  // C 헤더파일 <stdio.h>을 포함하는 것과 동일
#include <cstdlib>  // C 헤더파일 <stdlib.h>을 포함하는 것과 동일
#include "ArrayStack.h"
#include "Utility.h"

ArrayStack::ArrayStack() : top(-1) { for (int i = 0; i < MAX_STACK_SIZE; i++) data[i] = 0; }	// 스택 성성자
ArrayStack::~ArrayStack() {}																	// 스택 소멸자
bool ArrayStack::isEmpty() { return top == -1; }
bool ArrayStack::isFull() { return top == MAX_STACK_SIZE - 1; }

void ArrayStack::push(int e) {			// 맨 위에 항목 삽입
	if (isFull()) error("스택 포화 에러");
	data[++top] = e;
}

int ArrayStack::pop() {					// 맨 위에 요소를 삭제하고 반환
	if (isEmpty())error("스택 공백 에러");
	return data[top--];
}

int ArrayStack::peek() {				// 삭제하지 않고 요소 반환
	if (isEmpty())error("스택 공백 에러");
	return data[top];
}

void ArrayStack::display() {			// 스택 내용을 화면에 출력
	printf("[스택 항목의 수 = %2d] ==> ", top + 1);
	for (int i = 0; i <= top; i++)
		printf("<%2d>", data[i]);
	printf("\n");
}