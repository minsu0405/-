#pragma once

// Record.h
// 단어와 의미를 저장하는 레코드 클래스

#include <cstdio>
#include <cstring>

// 단어 최대 길이
#define MAX_WORD_SIZE 40

// 의미 최대 길이
#define MAX_MEANING_SIZE 200

// 예시 최대 길이
#define MAX_EXAMPLE_SIZE 200

class Record
{
protected: // 필드

	// 영어 단어 저장  키 필드
	char word[MAX_WORD_SIZE];

	// 단어 의미 저장
	char meaning[MAX_MEANING_SIZE];

	// 단어 예시 저장
	char example[MAX_EXAMPLE_SIZE];

public:

	// 생성자
	Record(const char* w = "", const char* m = "", const char* e = "") {
		set(w, m, e);
	}

	// 단어와 의미 저장 (예시도 포함)
	void set(const char* w, const char* m, const char* e) {

		strcpy_s(word, sizeof(word), w);
		strcpy_s(meaning, sizeof(meaning), m);
		strcpy_s(example, sizeof(example), e);
	}

	// Record 객체끼리 비교
	int compare(Record* n) {

		return compare(n->word);
	}

	// 문자열 단어 비교
	int compare(char* w) {

		return strcmp(w, word);
	}

	// 의미 비교
	int compareMeaning(char* m) {

		return strcmp(meaning, m);
	}

	// 예시 비교
	int compareExample(char* e) {
		return strcmp(example, e);
	}

	// 단어와 의미 출력
	void display() {

		printf(" %12s : %-40s : %-40s\n", word, meaning, example);
	}

	// 다른 레코드 데이터 복사
	void copy(Record* n) {

		set(n->word, n->meaning, n->example);
	}
};