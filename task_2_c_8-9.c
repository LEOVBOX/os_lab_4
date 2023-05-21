//
// Created by Леонид Шайхутдинов on 01.05.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

int main()
{
	int count = 0;
	printf("Введите количество итераций\n");
	scanf("%d", &count);
	int buff_size = 0;
	printf("Введите размер выделяемых блоков памяти в байтах\n");
	scanf("%d", &buff_size);
	
	pid_t pid = getpid();
	printf("pid: %d\n", pid);
	int enter = 0;
	
	// Ожидание для того, чтобы успеть зайти на /proc/pid/maps
	printf("Введите любую цифру кроме нуля для начала работы\n");
	while (scanf("%d", &enter), enter == 0)
		sleep(1);

	void** alloced_blocks = NULL;

	for (int i = 1; i <= count; i++)
	{
		void* buffer = malloc(buff_size);
		if (buffer == NULL)
		{
			printf("Ошибка выделения памяти на итерации %d\n", count);
			exit(1);
		}
		if (alloced_blocks == NULL)
		{
			alloced_blocks = (void**)malloc(sizeof(void*));
			if (alloced_blocks == NULL)
			{
				printf("Ошибка выделения памяти alloced_blocks\n");
				exit(1);
			}
		}
		else
		{
			printf("realloc\n");
			alloced_blocks = realloc(alloced_blocks, sizeof(void*) * i + sizeof(void*));
		}
		alloced_blocks[i - 1] = buffer;
		printf("Выделено %d байт на итерации %d\n", buff_size, i);
		printf("Всего выделено %d байт \n", i * buff_size);
		sleep(1);
	}

	void* ptr = mmap(NULL, 4096 * 10, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1 , 0);

	while (scanf("%d", &enter), enter == 0)
		sleep(1);

	for (int i = 0; i < count; i++)
	{
		free(alloced_blocks[i]);
	}
	free(alloced_blocks);

	munmap(ptr, 4096 * 10);

	
	return 0;
}