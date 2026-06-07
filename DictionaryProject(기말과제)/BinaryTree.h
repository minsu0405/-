#pragma once

// BinaryTree.h
// 기본 이진 트리(Binary Tree) 클래스

#include "BinaryNode.h"

class BinaryTree
{
protected:

	// 트리의 시작 노드(루트 노드)
	BinaryNode* root;

public:

	// 생성자
	// 처음에는 트리가 비어 있으므로 root를 NULL로 설정
	BinaryTree() : root(NULL) {}

	// 트리가 비어있는지 확인
	bool isEmpty() {
		return root == NULL;
	}

	// 중위 순회(Inorder Traversal)
	// 순서: 왼쪽 -> 현재 노드 -> 오른쪽
	void inorder(BinaryNode* node) {

		// 노드가 NULL이 아닐 경우만 실행
		if (node != NULL) {

			// 왼쪽 자식 노드 방문
			if (node->getLeft() != NULL)
				inorder(node->getLeft());

			// 현재 노드 출력
			node->display();

			// 오른쪽 자식 노드 방문
			if (node->getRight() != NULL)
				inorder(node->getRight());
		}
	}

	// 노드 총 개수 세기 (재귀)
	int countNodes(BinaryNode* node) {
		if (node == NULL) // 노드가 없으면 0 반환
			return 0;
		return 1 + countNodes(node->getLeft()) + countNodes(node->getRight()); 
		// 현재 노드(1) + 왼쪽 서브트리 노드 수 + 오른쪽 서브트리 노드 수
	}
};