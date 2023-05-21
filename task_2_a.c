#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
	int i = 0;
	while (argv[++i] != NULL) {
		printf("%s ", argv[i]);
	}
	pid_t pid = getpid();
	printf("pid: %d\n", pid);

	sleep(1);
	execl("/media/psf/Home/CLionProjects/os_lab_4/task_2_a", " ", "Hello", "world!", NULL);
}
