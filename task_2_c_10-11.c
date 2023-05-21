//
// Created by Леонид Шайхутдинов on 01.05.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <signal.h>

void handle_sigsegv(int sig) {
	printf("Segmentation fault (signal %d)\n", sig);
	exit(EXIT_FAILURE);
}

int main()
{
	signal(SIGSEGV, handle_sigsegv);

	pid_t pid = getpid();
	printf("pid: %d\n", pid);
	int enter = 0;
	
	// Ожидание для того, чтобы успеть зайти на /proc/pid/maps
	printf("Введите любую цифру кроме нуля для начала работы\n");
	while (scanf("%d", &enter), enter == 0)
		sleep(1);


	void *ptr = mmap(NULL, 4096 * 10, PROT_READ | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1 , 0);

	*(int*)ptr = 1;

	while (scanf("%d", &enter), enter == 0)
		sleep(1);


	//munmap(ptr, 4096 * 10);

	
	return 0;
}