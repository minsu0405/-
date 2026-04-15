// 05장-CircularQueue.cpp
#include "CircularQueue.h"
#include "CircularDeque.h"
void main()
{
	CircularDeque que;
	for (int i = 1; i < 10; i++)
	que.addFront(i);
	que.display();
	que.deleteFront();
	que.deleteRear();
	que.deleteFront();
	que.display();
}