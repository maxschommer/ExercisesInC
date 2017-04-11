#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
/*
After working at this for ~four hours, and still getting 
seg faults while trying to cast an int to a gchar, I looked
at David's solution. This takes a file.txt after calling the
program. 

Example: ./word_counter text.txt
*/
void iterator(gpointer key, gpointer value, gpointer user_data) {
 	printf(user_data, (char*) key, (int*) value);
}

int main (int argc, char **argv)
{
    char* text_file = argv[1]; 
    GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
    gchar* file;
    g_file_get_contents(text_file, &file, NULL, NULL);
    gchar** words = g_strsplit(file, " ", -1);

    while(*words) {
    	gpointer value = g_hash_table_lookup(hash, *words);
    	if(value)
    	{
    		g_hash_table_replace(hash, *words, (gpointer) value +1);
    	}
    	else{
    		g_hash_table_insert(hash, *words, (gpointer) 1);
    	}
    	words++;
    }

    g_hash_table_foreach(hash, iterator, "Freq of %s is %d\n");
    return 0;
}