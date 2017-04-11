all:ex_compile word_counter

ex_compile: ex_compile.c
	gcc ex_compile.c -Wall -o ex_compile `pkg-config --cflags --libs glib-2.0`
word_counter: word_counter.c
	gcc word_counter.c -Wall -o word_counter `pkg-config --cflags --libs glib-2.0`
