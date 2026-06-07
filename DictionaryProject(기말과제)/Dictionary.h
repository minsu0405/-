#pragma once

// Dictionary.h
// 영어 사전 클래스

#include "BinSrchTree.h"

class Dictionary : public BinSrchTree
{
public:

	// 전체 단어 출력
	void printAllWords() {

		printf("    >> 나의 단어장:\n");
		//단어장 안에 단어 총 개수 출력(추가한 내용)
		int count = countNodes(root); // BinaryTree 클래스의 countNodes 함수를 
		//사용하여 트리의 노드 수를 계산
		printf("    >> 단어 총 개수: %d\n", count);

		// 트리가 비어있지 않으면 중위 순회 출력
		if (!isEmpty())
			inorder(root);

		//추가한 내용 만약에 출력할 시 단어가 없다면
		else
			printf("    >> 단어장이 비어 있습니다.\n");
	}

	// 단어 검색
	void searchWord(char* word) {

		// 단어 탐색
		BinaryNode* node = search(word);

		// 찾았을 경우
		if (node != NULL) {

			printf("    >> ");

			node->display();
		}

		// 못 찾은 경우
		else
			printf("    >> 등록되지 않은 단어: %s\n", word);
	}

	// 의미 검색
	void searchMeaning(char* m) {

		// 트리가 비어있지 않으면 의미 검색
		BinaryNode* node = (isEmpty()) ? NULL : searchByMeaning(root, m);

		// 찾았을 경우
		if (node != NULL) {

			printf("    >> ");

			node->display();
		}

		// 못 찾은 경우
		else
			printf("    >> 등록되지 않은 의미: %s\n", m);
	}

	// 의미를 기준으로 재귀 탐색
	BinaryNode* searchByMeaning(BinaryNode* node, char* m) {

		// 노드가 없거나 의미가 같으면 반환
		if (node == NULL || node->compareMeaning(m) == 0)
			return node;

		// 왼쪽 서브트리 탐색
		BinaryNode* theNode = searchByMeaning(node->getLeft(), m);

		// 찾았으면 반환
		if (theNode != NULL)
			return theNode;

		// 오른쪽 서브트리 탐색
		return searchByMeaning(node->getRight(), m);
	}
};