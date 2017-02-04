/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#define NUM_TRACKS 5


char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
	if (strstr(tracks[i], search_for)) {
	    printf("Track %i: '%s'\n", i, tracks[i]);
	}
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
/*This function prints all of the tracks along with the track numbers
that are associated with a given track that match the regex pattern
in the function input.*/

    int i;
    regex_t re;//The we use a shorthand for regex_t and define it as re
    regmatch_t matches[NUM_TRACKS];

    if (!regcomp(&re, pattern, REG_EXTENDED)){//This checks if the regular expression compiled. 
                                              //It would return not 0 if there was
                                              //an error.
        
        for (i=0; i<NUM_TRACKS; i++){//We iterate through tracks
            

             if (!regexec(&re, tracks[i], NUM_TRACKS, matches, 0)) {//The regex in matches is executed. A match 
                                                                   //results in "true"
                 printf("Track %i: '%s'\n", i, tracks[i]);
            }
        }
    }
    else {//Error for REGEX compilation
    puts("The regex you entered did not compile");
    exit(1);
    }
    regfree(&re);
}


// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
	*ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
