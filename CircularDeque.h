#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"
#include "CircularQueue.h"

#define MAX_DEQUE_SIZE	100

class CircularDeque :public CircularQueue
{
	int	front;
	int	rear;
	int	data[MAX_DEQUE_SIZE];
public:
	CircularDeque() :CircularQueue() { front = rear = 0; }
	~CircularDeque() {}
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_DEQUE_SIZE == front; }
	void enqueue(int val) {
		if (isFull())
			error("  error: 큐가 포화상태입니다\n");
		else {
			rear = (rear + 1) % MAX_DEQUE_SIZE;
			data[rear] = val;
		}
	}
	void addRear(int val) {
		if (isFull())
			error("  error: 큐가 포화상태입니다\n");
		else {
			rear = (rear + 1) % MAX_DEQUE_SIZE;
			data[rear] = val;
		}
	}
	void deleteRear(int val) {
		if (isFull())
			error("  error: 큐가 포화상태입니다\n");
		else {
			rear = (rear - 1) % MAX_DEQUE_SIZE;
			data[rear] = val;
		}
	}
	int dequeue() {
		if (isEmpty())
			error("  Error: 큐가 공백상태입니다\n");
		else {
			front = (front + 1) % MAX_DEQUE_SIZE;
			return data[front];
		}
	}
	int deleteFront() {
		if (isEmpty())
			error("  Error: 큐가 공백상태입니다\n");
		else {
			front = (front + 1) % MAX_DEQUE_SIZE;
			return data[front];
		}
	}
	int addFront() {
		if (isEmpty())
			error("  Error: 큐가 공백상태입니다\n");
		else {
			front = (front - 1) % MAX_DEQUE_SIZE;
			return data[front];
		}
	}
	int peek() {
		if (isEmpty())
			error("  Error: 큐가 공백상태입니다\n");
		else
			return data[(front + 1) % MAX_DEQUE_SIZE];
	}
	int getFront() {
		if (isEmpty())
			error("  Error: 큐가 공백상태입니다\n");
		else
			return data[(front + 1) % MAX_DEQUE_SIZE];
	}
	int getFront() {
		if (isEmpty())
			error("  Error: 큐가 공백상태입니다\n");
		else
			return data[(front + 1) % MAX_DEQUE_SIZE];
	}


	void display() { // 큐의 내용을 순서대로 출력하기 위해
		printf("큐 내용 : ");
		int maxi = (front < rear) ? rear : rear + MAX_DEQUE_SIZE;
		// 삼항연산자로 rear가 더 크면 maxi로 front가 더 크면 rear + MAX_DEQUE_SIZE로 설정함
		for (int i = front + 1; i <= maxi; i++)
			printf("[%2d] ", data[i % MAX_DEQUE_SIZE]);
		printf("\n");
	}
};