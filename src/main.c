#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "util.h"


int main(int argc, char * argv[]) {

	array = (int*)malloc(sizeof(int));

	if (NULL == array) {
		perror("Insufficient memory...\n");
		return EXIT_FAILURE;
	}

	prompt();
	usage();

    while(1) {

		char *line = malloc(256 * sizeof(char));

		// user input
    	printf("Quarantine > ");
    	fgets(line, 256, stdin);

    	// arg_v count
    	int arg_count = 0;

    	// array of arguments with maximum of 50 elements
    	char *arg_vector[50];

    	// parse string into array of strings
    	getArgVector(line, &arg_count, arg_vector);

		if(strcmp(line , "\n") ==  0) {
			continue;
		}

		// quit
		if(strcmp(line, "quit\n") == 0) {
			printf("Bye!\n");
			free(array);
			free(line);
			exit(1);
		}
		else
			// printf("No of args: %d\n", arg_count);
			// for (int i = 0; i < arg_count; ++i)
			// {
			// 	printf("%s\n", arg_vector[i]);
			// }
			if(strcmp(arg_vector[0], "set") == 0) {
				process_args(arg_count, arg_vector);
				printf("N: %d  X: %d \n", n, x);
			}

    		free(line);
    }

    return 0;
}
