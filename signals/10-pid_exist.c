#include <signal.h>
#include <sys/types.h>

/**
 * pid_exist - a function that tests if a process exists, given its PID
 * @pid: id
 *
 * Return: 1 or 0
 */
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) + 1);
}
