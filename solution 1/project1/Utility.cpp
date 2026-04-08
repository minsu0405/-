#include <cstdio>
#include <cstdlib>
#include "Utility.h"

void error(const char* message) { //에러 메세지를 출력하고 프로그램을 종료하는 함수
    printf("%s\n", message);
    exit(1);
}