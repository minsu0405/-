#define _CRT_SECURE_NO_WARNINGS // 03장-CheckMatching.cpp
#include "ArrayStack.h"			// 프로그램 3.1의 ArrayStack 클래스 코드 사용
#include "Utility.h"			// 프로그램 2.1의 error() 함수 코드 사용


//내가 해야하는 것
//이번 괄호 매칭 함수는 주석이나 문자열 안에 있는 것을 매칭에 사용하기 때문에
// 괄호 매칭을 할때에 주석이나 문자열 안에 있는 괄호는 매칭에서 제외하는 방법을 찾아보자
// 
// 주어진 파일을 읽어 괄호 매칭을 검사하고 결과를 출력하는 함수
bool CheckMatching(const char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
		error("Error: 파일 존재하지 않습니다.\n");

	int nLine = 1;			// 읽은 라인의 개수
	int nChar = 0;			// 읽은 문자 개수
	ArrayStack stack;		// 스택 객체
	char	ch;

	while ((ch = getc(fp)) != EOF) { // 파일에서 한 문자씩 읽어들임
		if (ch == '\n') nLine++;
		nChar++;
		if (ch == '[' || ch == '(' || ch == '{') // 여는 괄호는 스택에 push
			stack.push(ch);
		else if (ch == ']' || ch == ')' || ch == '}') {
			int prev = stack.pop(); // 닫는 괄호는 스택에서 pop하여 짝이 맞는지 검사
			if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{')) break; // 짝이 맞지 않으면 검사 중단
		}
	}
	fclose(fp);// 파일 닫기

	printf("[%s] 파일 검사결과:\n", filename);
	if (!stack.isEmpty())
		printf("  Error: 문제발견! (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	else
		printf("  OK: 괄호닫기정상 (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}