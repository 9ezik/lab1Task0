all: main test remove

main: tsk0.c
	gcc tsk0.c -o tsk0 -lm 
test: tsk0
	./tsk0
remove: tsk0
	rm tsk0
