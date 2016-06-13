#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	char *p;
	pid_t pid, pgid;
	pid	= strtol(argv[1], &p, 10);
	if (pid <= 0 || *p != '\0' || errno == ERANGE) {
		return 1;
	}
	pgid = getpgid(pid);
	if (pgid <= 0) {
		return 2;
	}
	printf("%d\n", pgid);
	return 0;
}
