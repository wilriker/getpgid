#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	char *p;
	pid_t pid, pgid;
	if (argc < 2) {
		pid = 0;
	} else {
		pid	= strtol(argv[1], &p, 10);
		if (pid < 0 || *p != '\0' || errno == ERANGE) {
			return 1;
		}
	}
	pgid = getpgid(pid);
	if (errno == ESRCH || errno == EINVAL || errno == EPERM || errno == EACCES) {
		perror(NULL);
		return 2;
	}
	printf("%d\n", pgid);
	return 0;
}
