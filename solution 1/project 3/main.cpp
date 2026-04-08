#define _CRT_SECURE_NO_WARNINGS // 03장-CheckMatching.cpp
#include "ArrayStack.h"			// 프로그램 3.1의 ArrayStack 클래스 코드 사용
#include "Utility.h"			// 프로그램 2.1의 error() 함수 코드 사용

//bool CheckMatching(const char* filename); //이거 선언 이유는 쳌 매칭 함수가 메인 아래에 있어 오류가 뜨기에 껍대기 함수선언
// 주 함수
void main() // CheckMatching를 사용하여 아래 파일의 괄호 매칭 검사
{
	CheckMatching("ArrayStack.h");
	CheckMatching("main.cpp");
}


