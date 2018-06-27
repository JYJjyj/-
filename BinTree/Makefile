.PHONY:clean
main:BinTree.c
	gcc $^ -o $@
%.o:%.c
	gcc -c -g $^ -o $@
clean:main
	rm -rf *.o
