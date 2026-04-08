#include <cstdio>	  // C 헤더파일 <stdio.h>을 포함하는 것과 동일
#include <cstdlib>  // C 헤더파일 <stdlib.h>을 포함하는 것과 동일
#include "studentStack.h"
#include "Utility.h"

StudentStack::StudentStack() { top = -1; }
bool StudentStack::isEmpty() { return top == -1; }
bool StudentStack::isFull() { return top == MAX_STACK_SIZE - 1; }

void StudentStack::push(Student e) {		// 맨 위에 항목 삽입
	if (isFull()) error("스택 포화 에러");
	data[++top] = e;
}
Student StudentStack::pop() {				// 맨 위의 요소를 삭제하고 반환
	if (isEmpty()) error("스택 공백 에러");
	return data[top--];
}
Student StudentStack::peek() {			// 삭제하지 않고 맨 위 요소 반환
	if (isEmpty()) error("스택 공백 에러");
	return data[top];
}
void StudentStack::display() {			// 스택 내용을 화면에 출력
	printf("[전체 학생의 수 = %2d]\n", top + 1);
	for (int i = 0; i <= top; i++)
		data[i].display();
	printf("\n");
}