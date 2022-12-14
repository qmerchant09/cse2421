# Quantez Merchant

all:  tags headers lab3

headers: *.c tags
	headers.sh

tags: *.c
	ctags -R .

#This is a prototype file to be graded, it tests the formatting for the output table
outputPrototype: outputPrototype.o
	gcc -g -o $@ $^

#This is a prototype file to be graded, it tests the creation of the jump table
jumpTablePrototype: jumpTablePrototype.o
	gcc -g -o $@ $^

#This is a prototype file to be graded, it tests moving things from one list to another
moveListPrototype: moveListPrototype.o
	gcc -g -o $@ $^ -L. -los -llinkedlist -lncurses

#This is a prototype file to be graded, it tests the insert and deleteSome functions 
insertDeletePrototype: insertDeletePrototype.o
	gcc -g -o $@ $^ -L. -los -llinkedlist -lncurses

#This is a prototype file to be graded, it tests the four list structure
fourListPrototype: fourListPrototype.o psw.o
	gcc -g -o $@ $^ -L. -los -llinkedlist -lncurses

lab3: lab3.o psw.o event.o output.o input.o callbacks.o allocation.o
	gcc -g -o $@ $^ -L. -los -llinkedlist -lncurses

lab3.zip: makefile *.c *.h *.a README_LAB3
	#zip lab3
	zip lab3.zip $^
	#remove old install folder
	rm -rf install
	#create new install folder
	mkdir install
	#unzip to the install folder
	unzip lab3.zip -d install
	#make only the lab3 target, not lab3.zip
	make -C install lab3

# One rule to compile them all!
CFLAGS = -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -Wconversion

%.o:%.c *.h
	gcc $(CFLAGS) -g -c $< -o $@

