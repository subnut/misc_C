#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int
main(void)
{
	/* Don't let zombies be created */
	signal(SIGCHLD, SIG_IGN);

	puts("Hi!");
	for (;;)
	{
		puts("Forking!");
		switch (fork()) {
			case -1:
				return perror("Couldn't fork"),
				       EXIT_FAILURE;
			case 0:
				return puts("I'm a child!"),
				       EXIT_SUCCESS;
			default: {
					 puts("I'm the parent");
					 sleep(1);
				 }
		}
	}
}
