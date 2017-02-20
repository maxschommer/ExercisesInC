/*An implemination of "tee" that takes the same command line arguments.
Author: Max Schommer*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char ch;
	int append = 0;
	int count = 0;
	char line[100];
	while((ch = getopt(argc, argv, "a")) != EOF){
		switch (ch) {
			case 'a':
				append = 1;
				break;
			default:
				fprintf(stderr, "Unknown Option: %s\n", optarg);
		}
	}

	argc -= optind;
	argv += optind;

	FILE *f[argc];

	for(count = 0; count< argc; count++){
		if (append){
			f[count] = fopen(argv[count], "a");

		} else {
			f[count] = fopen(argv[count], "w");
		}
	}

	
	while (scanf("%99[^\n]\n", line) != EOF){
		for (count = 0; count < argc; count++){
			fprintf(f[count], "%s\n", line);
		}
	}

	for(count = 0; count< argc; count++){
		fclose(f[count]);
	}
	

}