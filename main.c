#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int num = 0;

	while (num <= 0) {
		printf("Enter a positive integer: ");
		scanf("%d", &num);
		if (num <= 0) {
			printf("That is not a positive integer. Try again!\n");
		}
	}

	pid_t cpid;
	if (fork() == 0) {
		char output[100];
		sprintf(output, "%d", num);
		strcat(output, ", ");
		while (num != 1) {
			char nextNum[100];
			if (num % 2 == 0) {
				num = num/2;
			}
			else {
				num = num*3+1;
			}
			sprintf(nextNum, "%d", num);
			strcat(output, nextNum);
			if (num != 1) {
				strcat(output, ", ");
			}
		}
		strcat(output, "\n");
		printf("%s", output);
	}
	else {
		cpid = wait(NULL);
	}
}
