//
// Created by Леонид Шайхутдинов on 24.04.2023.
//

/*
Напишите функцию, которая:
i. выделяет на куче буфер (например, размером 100 байт);
ii. записывает в него какую-либо фразу (например, hello world);
iii. выводит содержимое буфера;
iv. освобождает выделенную память;
v. снова выводит содержимое буфера;
vi. выделяет еще один буфер;
vii. записывает в них какую-либо фразу (например, hello world);
viii. выводит содержимое буфера;
ix. перемещает указатель на середину буфера;
x. освобождает память по этому указателю.
xi. выводит содержимое буфера;
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>

#define DEFAULT_BUFF_SIZE 100

// size_t buff_size - size of buffer in bytes
void buffer_experiment(size_t buff_size)
{
	// 1. Выделяет на куче буффер.
	char* buffer = (char*)malloc(sizeof(char) * buff_size);
	// 2. Записывает фразу hello buffer.
	strcpy(buffer, "Hello buffer");
	// 3. Выводит buffer.
	printf("%s\n", buffer);
	// 4. Освобождает выделенную память.
	free(buffer);
	// 5. Снова выводит содержимое буффера
	printf("%s\n", buffer);
	// 6. Выделяет еще один буффер
	char* buffer2 = (char*)malloc(sizeof(char) * buff_size);
	if (buffer2 == NULL)
	{
		printf("malloc failed\n");
	}
	// 7. Записывает в него фразу
	strcpy(buffer2, "Hello buffer2");
	// 8. Выводит содержимое буффера
	printf("%s\n", buffer2);
	// 9. Перемещает указатель на середину буффера
	buffer2 = (buffer2 + buff_size/2);
	//sleep(1);
	// 10. Освобождает память по этому указателю
	free(buffer2);
	// 11. Выводит содержимое буффера.
	printf("%s", buffer2);
}


int main()
{
	buffer_experiment(DEFAULT_BUFF_SIZE);
	return 0;
}