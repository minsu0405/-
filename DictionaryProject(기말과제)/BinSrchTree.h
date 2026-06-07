#pragma once

// BinSrchTree.h
// 이진 탐색 트리(Binary Search Tree) 클래스

#include "BinaryTree.h"

class BinSrchTree : public BinaryTree
{
public:

	// =========================
	// 탐색(Search)
	// =========================

	// 루트 노드부터 단어 검색 시작
	BinaryNode* search(char* key) {
		return searchRecur(root, key);
	}

	// 재귀를 이용한 탐색 함수
	BinaryNode* searchRecur(BinaryNode* n, char* key) {

		// 노드가 없으면 검색 실패
		if (n == NULL)
			return NULL;

		// 찾는 단어와 현재 노드 단어가 같으면 반환
		if (n->compare(key) == 0)
			return n;

		// key가 더 작으면 왼쪽 탐색
		else if (n->compare(key) < 0)
			return searchRecur(n->getLeft(), key);

		// key가 더 크면 오른쪽 탐색
		else
			return searchRecur(n->getRight(), key);
	}

	// =========================
	// 삽입(Insert)
	// =========================

	void insert(BinaryNode* n) {

		// 삽입할 노드가 없으면 종료
		if (n == NULL)
			return;

		// 트리가 비어있으면 root에 저장
		if (isEmpty())
			root = n;

		// 아니면 재귀 삽입
		else
			insertRecur(root, n);
	}

	// 재귀 삽입 함수
	void insertRecur(BinaryNode* r, BinaryNode* n) {

		// 중복 데이터면 삽입 안 함
		if (n->compare(r) == 0)
			return;

		// 삽입할 값이 더 크면 왼쪽으로 이동
		else if (n->compare(r) > 0) {

			// 왼쪽 자식이 비어있으면 삽입
			if (r->getLeft() == NULL)
				r->setLeft(n);

			// 아니면 재귀 탐색
			else
				insertRecur(r->getLeft(), n);
		}

		// 삽입할 값이 더 작으면 오른쪽 이동
		else {

			// 오른쪽 자식이 비어있으면 삽입
			if (r->getRight() == NULL)
				r->setRight(n);

			// 아니면 재귀 탐색
			else
				insertRecur(r->getRight(), n);
		}
	}

	// =========================
	// 삭제(Remove)
	// =========================

	void remove(char* data) {

		// 트리가 비어있으면 종료
		if (isEmpty())
			return;

		BinaryNode* parent = NULL;
		BinaryNode* node = root;

		// 삭제할 노드 탐색
		while (node != NULL && node->compare(data) != 0) {

			parent = node;

			// 현재 값보다 작으면 왼쪽
			// 크면 오른쪽 이동
			node = (node->compare(data) < 0)
				? node->getLeft()
				: node->getRight();
		}

		// 찾지 못한 경우
		if (node == NULL) {
			printf(" Error: key is not in the tree!\n");
			return;
		}

		// 실제 삭제 함수 호출
		else
			remove(parent, node);
	}

	// 실제 노드 삭제 함수
	void remove(BinaryNode* parent, BinaryNode* node) {

		// =========================
		// CASE 1 : 리프 노드 삭제
		// =========================
		if (node->isLeaf()) {

			// 삭제 노드가 루트라면
			if (parent == NULL)
				root = NULL;

			else {

				// 부모의 왼쪽 자식이면 제거
				if (parent->getLeft() == node)
					parent->setLeft(NULL);

				// 부모의 오른쪽 자식이면 제거
				else
					parent->setRight(NULL);
			}
		}

		// =========================
		// CASE 2 : 자식이 하나인 경우
		// =========================
		else if (node->getLeft() == NULL || node->getRight() == NULL) {

			// 존재하는 자식 노드 저장
			BinaryNode* child = (node->getLeft() != NULL)
				? node->getLeft()
				: node->getRight();

			// 삭제 노드가 루트라면
			if (node == root)
				root = child;

			else {

				// 부모와 자식 연결
				if (parent->getLeft() == node)
					parent->setLeft(child);
				else
					parent->setRight(child);
			}
		}

		// =========================
		// CASE 3 : 자식이 둘인 경우
		// =========================
		else {

			// 후계자(successor) 탐색
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();

			// 오른쪽 서브트리에서 가장 작은 값 찾기
			while (succ->getLeft() != NULL) {
				succp = succ;
				succ = succ->getLeft();
			}

			// 후계자 제거 연결 작업
			if (succp->getLeft() == succ)
				succp->setLeft(succ->getRight());
			else
				succp->setRight(succ->getRight());

			// 후계자 데이터를 현재 노드에 복사
			node->copy(succ);

			// 실제 삭제 대상 변경
			node = succ;
		}

		// 메모리 해제
		delete node;
	}
};