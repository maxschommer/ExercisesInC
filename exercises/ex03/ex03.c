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

/*Reflect: what worked, what slowed you down? What would you do differently next time?

Figuring out how to use command line arguments took a lot longer than expected. After
I figured out how to do that, the next most difficult part was trying to read the file.
I couldn't figure out how to read the file completely, so if any line is longer than 99
chars long, the program won't read it.

Compare your solution to the real thing. What do you see in professional code that is not in your solution?

The real solution doesn't have a character cap. It can read arbitrarily large files. There
is also a lot more error checking and command line options.
*/