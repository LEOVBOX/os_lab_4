//
// Created by Леонид Шайхутдинов on 21.04.2023.
//
#include <unistd.h>
#include <stdio.h>
#include <malloc.h>

#define STACK_BLOCK 1024
#define HEAP_BLOCK 1024

// 3. Функция выделяющая на стеке массив и рекурсивно вызывает себя
void mem_alloc_stack(size_t block_size)
{
	int array[block_size];
	sleep(1);
	printf("alloced\n");
	mem_alloc_stack(block_size);
}


int main()
{
	pid_t pid = getpid();
	// 1. Выводит pid процесса
	printf("pid: %d\n", pid);

	mem_alloc_stack(STACK_BLOCK);
	// 2. Ждет 10 секунд
	sleep(10);
	return 0;
}