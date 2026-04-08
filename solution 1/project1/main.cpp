#include "ArrayStack.h"
void main() {
	ArrayStack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.display(); //그 전 push한 1,2,3 출력
	stack.pop();
	stack.pop();
	stack.pop();
	stack.push(4);
	stack.display();
}