# Quantez Merchant
all:  tags headers lab4

headers: *.c tags
	headers.sh

tags: *.c
	ctags -R .

union: union.o
	gcc -g -o $@ $^

#This is a prototype file to be graded, it tests the iterate function
iteratePrototype: iteratePrototype.o
	gcc -g -o $@ $^

#This is a prototype file to be graded, it tests the insert function
insertPrototype: insertPrototype.o
	gcc -g -o $@ $^

#This is a prototype file to be graded, it tests the deleteSome function 
deletePrototype: deletePrototype.o
	gcc -g -o $@ $^

#This is a prototype file to be graded, it tests command line inputs
commandPrototype: commandPrototype.o
	gcc -g -o $@ $^

lab4: lab4.o psw.o input.o output.o dynamic.o functions.o event.o linkedlist.o reliable.o
	gcc -g -o $@ $^ -L. -los -lncurses 

lab4u: lab4.o psw.o input.o output.o dynamic.o functions.o event.o linkedlist.o unreliable.o
	gcc -g -o $@ $^ -L. -los -lncurses 

lab4.zip: makefile *.c *.h *.txt headers.* *.a README_LAB4 reliable.o unreliable.o
	#zip lab
	zip $@ $^
	#remove old install folder
	rm -rf install
	#create new install folder
	mkdir install
	#unzip to the install folder
	unzip $@ -d install
	#make only the lab4 target, not lab4.zip
	make -C install lab4

# One rule to compile them all!
CFLAGS = -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -Wconversion

%.o:%.c *.h
	gcc $(CFLAGS) -g -c $< -o $@


