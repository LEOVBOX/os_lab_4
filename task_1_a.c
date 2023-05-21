//
// Created by Леонид Шайхутдинов on 24.04.2023.
//

#include <stdio.h>
#include <unistd.h>

int global_var;
int init_glob_var = 100;
const int glob_cnst = 18;

void crt_var()
{
	int var = 5;
	printf("var address: %p\n", &var);
}

void crt_static_var()
{
	static int stat = 6;
	printf("static var addres: %p\n", &stat);
}

void crt_const()
{
	const int cnst = 10;
	printf("const address: %p\n", &cnst);
}


int main()
{
	crt_static_var();
	crt_var();
	crt_const();
	printf("global non init var address: %p\n", &global_var);
	printf("glogal init var address: %p\n", &init_glob_var);
	printf("glogal init const address: %p\n", &glob_cnst);
	pid_t pid = getpid();
	printf("pid: %d\n", pid);
	int stop_dig = 1;
	while (stop_dig != 0)
	{
		scanf("%d", &stop_dig);
	}
	return 0;
}