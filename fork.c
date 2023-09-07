#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		printf("Soy el proceso hijo (PID: %d)\n", getpid());
	else
		printf("Soy el proceso padre (PID: %d)\n", getpid());
	return (0);
}
