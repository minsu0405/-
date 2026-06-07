#pragma once

// BinaryNode.h
// 이진 트리에서 사용할 노드(Node) 클래스
// Record 클래스를 상속받아 단어(word)와 의미(meaning)를 저장함

#include "Record.h"

class BinaryNode : public Record
{
protected:
	// 왼쪽 자식 노드를 가리키는 포인터
	BinaryNode* left;

	// 오른쪽 자식 노드를 가리키는 포인터
	BinaryNode* right;

public:

	// 생성자
	// 기본값은 빈 문자열("")
	// 부모 클래스 Record 생성자도 같이 호출됨
	BinaryNode(const char* w = "", const char* m = "", const char* e = "")
		: Record(w, m, e), left(NULL), right(NULL) {
	}

	// 왼쪽 자식 노드 설정
	void setLeft(BinaryNode* l) {
		left = l;
	}

	// 오른쪽 자식 노드 설정
	void setRight(BinaryNode* r) {
		right = r;
	}

	// 왼쪽 자식 노드 반환
	BinaryNode* getLeft() {
		return left;
	}

	// 오른쪽 자식 노드 반환
	BinaryNode* getRight() {
		return right;
	}

	// 현재 노드가 리프 노드인지 확인
	// 리프 노드 = 자식이 하나도 없는 노드
	bool isLeaf() {
		return left == NULL && right == NULL;
	}
};