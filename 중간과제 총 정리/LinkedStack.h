#pragma once
// LinkedStack.h : 연결된 스택 클래스 구현
#include "Node.h"
class LinkedStack {
	Node* top;
public:
	LinkedStack() { top = NULL; }// top을 null로 초기화
	~LinkedStack() { while (!isEmpty()) delete pop(); } //
	bool isEmpty() { return top == NULL; } //맨 위가 null를 가르킬 때
	void push(Node* n) { //새로운 노드를 추가하고
		if (isEmpty()) top = n; //아무것도 저장되어 있지 않다면 top은 n를 가르키게
		else {
			n->setLink(top); //기존의 스택의 top이 n의 link가 되도록 하고
			top = n; //n이 새로운 top이 되도록
		}
	}
	Node* pop() {
		if (isEmpty()) return NULL; //그냥 리턴 = 비어있다면
		Node* n = top; // top 원래 가르키던 곳을 n이 가르키도록 카피
		top = top->getLink(); // top이 다음 노드를 가르키도록
		return n; // n이 가르키는 노드를 리턴
	}
	Node* peek() { return top; }
	void display() {
		printf("[LinkedStack]\n");
		//top에서부터 null까지 출력
		for (Node* p = top; p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
};