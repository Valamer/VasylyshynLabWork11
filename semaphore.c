#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>

#define SEMAPHORE_NAME "Vasylyshyn"

int main(int argc, char ** argv) {

	sem_t *sem;

	if ( argc != 2 ) {
		if((sem = sem_open(SEMAPHORE_NAME, 0770, 0)) == SEM_FAILED ) {
			fprintf(stderr, "ERROR in opening semaphore");
			return 1;
		}
		printf("sem_open. Semaphore is taken.\nWaiting for it to be dropped.\n");
		if (sem_wait(sem) < 0)
			fprintf(stderr, "sem_wait ERROR");
		if (sem_close(sem) < 0)
			fprintf(stderr, "sem_close ERROR");
		return 0;
	}
	else {
		printf("Vasylyshyn is dropping semaphore\n");
		if ( (sem = sem_open(SEMAPHORE_NAME, 0)) == SEM_FAILED ) {
			fprintf(stderr, "sem_open error");
			return 1;
		}
		sem_post(sem);
		printf("sem_post. Semaphore is dropped by Vasylyshyn.\n");
	}
}
