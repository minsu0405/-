#include "CircularCustomerQueue.h"
#include "Customer.h"
#include <cstdio>
using namespace std;

int main(void) {
	CircularCustomerQueue male, female; //
	int id = 1;
	char name[20]; //문자열
	char gender;
	printf("미팅 주선 프로그램\n");
	while (true) {
		printf("학생의 이름을 입력하세요: ");
		scanf_s("%s", name, (unsigned)_countof(name));
		printf("성별을 입력하세요 (m:남학생,f:여학생): ");
		scanf_s(" %c", &gender, 1);
		Customer student(id, gender, name); // 학생의 객체 생성 번호 성별 이름
		if (gender == 'm' || gender == 'M') {
			male.enqueue(student); // 남학생 큐에 학생을 추가
			printf("남학생 %s이(가) 대기열에 추가되었습니다.\n", name);
		}
		else if (gender == 'f' || gender == 'F') {
			female.enqueue(student); // 여학생 큐에 학생을 추가
			printf("여학생 %s이(가) 대기열에 추가되었습니다.\n", name);
		}
		else {
			printf("성별을 잘못 입력 하였습니다. M(m) 또는 F(f)를 입력하세요.\n");
			continue;
		}
		id++; // 정상적인 입력이 있을 때만 id 증가
		// 남학생 큐와 여학생 큐에 모두 학생이 있을 때 미팅 주선	
		if (!male.isEmpty() && !female.isEmpty()) {
			Customer man = male.dequeue();
			Customer woman = female.dequeue();
			printf("커플이 탄생하였습니다: 남학생 %s, 여학생 %s\n", man.getName(), woman.getName());
		}
		else {
			printf("아직 커플이 탄생하지 않았습니다. 대기열에서 기다려주세요.\n");
			printf("현재 대기열 상태: 남학생 %d명, 여학생 %d명\n", male.size(), female.size());
			// 사이즈 출력하여 대기열 상태 보여주기size()
		}
		printf("계속진행하려면 아무 키나 누르세요...\n");
		getchar(); // 사용자 입력 대기
	}
	return 0;
}