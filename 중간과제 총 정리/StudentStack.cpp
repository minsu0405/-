#include "LinkedStack.h"

void main()
{
	LinkedStack stack; //스택구조로 
	stack.push(new Node(2015130007, "홍길동", "컴퓨터공학과"));
	stack.push(new Node(2015130100, "이순신", "기계공학과"));
	stack.push(new Node(2015130135, "황희" , "법학과"));
	stack.display();

	Node* node = stack.pop();
	printf("[Pop항목]\n");
	node->display(); // 노드의 자신의 값 출력 황희
	printf("\n");
	delete node; //동적 할당으로 만든 메모리 삭제
	stack.display();
}