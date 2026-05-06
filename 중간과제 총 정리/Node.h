#pragma once
// Node.h : 연결된 스택을 위한 노드 클래스 구현 파일
#include "Student.h"			// 프로그램 3.3의 "Student.h" 팡리 포함
class Node : public Student {		// Student 상속하여 구현
	Node* link;		// 다음 노드를 가리키는 포인터 변수
public:
	Node(int id = 0, const char* name = "", const char* dept = "")
		: Student(id, name, dept) {
		link = NULL;
	}
	~Node(void) {}
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
};
