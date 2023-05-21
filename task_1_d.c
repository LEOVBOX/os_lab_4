//
// Created by Леонид Шайхутдинов on 24.04.2023.
//

#include <stdio.h>
#include <unistd.h>

int* crt_var()
{
	int a = 5;
	int* result = &a;
	return result;
}

int main()
{
	pid_t pid = getpid();
	printf("pid: %d\n", pid);
	int* a = crt_var();
	printf("var addr: %p\n", a);
	int stop_dig = 1;
	while (stop_dig != 0)
	{
		scanf("%d", &stop_dig);
	}
	return 0;
}