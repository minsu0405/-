#pragma once
// Student.h : 학생 정보를 나타내는 클래스  현재 구현까지 완료된 모델
#include <cstdio> // printf() 함수 사용을 위한 헤더 파일
#include <cstdlib>// exit() 함수 사용을 위한 헤더 파일
#include <cstring>//strcpy_s() 함수 사용을 위한 헤더 파일
#define MAX_STRING	100
class Student {
	int		id;					// 학번
	char	name[MAX_STRING];	// 이름
	char	dept[MAX_STRING];	// 소속 학과
public:
	Student(int i = 0, const char* n = "", const char* d = "") { set(i, n, d); } //생성자 초기화	리스트
	void set(int i, const char* n, const char* d) {
		id = i;
		strcpy_s(name, n);		// 문자열 복사 함수
		strcpy_s(dept, d);		// 문자열 복사 함수
	}
	void display() {
		printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
	}
};