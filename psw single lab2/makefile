#Quantez Merchant

#Makefile for lab 1-4.  You need to add you name to this file in the comments
# You will need to add a entry to create your zip file

#change the last dependency for each new lab
all:  tags headers lab2

#this entry has to change for lab 2 - 4
# NEVER compile .c files with this rule - it lacks needed compile time flags
# There is an entry below that turns .c files into .o files

lab2: lab2.o psw.o output.o events.o mode.o
	gcc -g -o $@ $^ -lncurses -L. -los

#this is where you create an entry to build your zip file
#it will also update with new labs
lab2.zip: makefile *.c *.h *.a README_LAB2
	#zip lab2
	zip lab2.zip $^
	#remove old install folder
	rm -rf install
	#create new install folder
	mkdir install
	#unzip to the install folder
	unzip lab2.zip -d install
	#make only the lab2 target, not lab2.zip
	make -C install lab2

#Deletes all o files and the lab executable
clean: 
	rm -rf *.o lab2

#This is a prototype file to be graded, it tests the formatting for the output table
outputTest: outputTest.o
	gcc -g -o $@ $^

#This is a prototype file to be graded, it tests the unpacking process on the psw
unpackPSWTest: unpackPSWTest.o
	gcc -g -o $@ $^

#This is a prototype file to be graded, it tests looping until the end of a file and scanf
inputTest: inputTest.o
	gcc -g -o $@ $^

#This is a prototype file to be graded, it tests the packing process on the psw
packPSWTest: packPSWTest.o
	gcc -g -o $@ $^

#This is a prototype file to be graded, it tests the graphic building parts of libos
graphicsPrototype: graphicsPrototype.o
	gcc -g -o $@ $^ -lncurses -L. -los

#this entry stays for C code labs
tags: *.c
	ctags -R .

# this entry stays for C code labs
headers: *.c tags
	headers.sh


# this entry takes care of C files depending on header files
# It has the flags for compiling the c code
# It you don't like makefiles, consider typing the following line a few
# thousand times this semester and reconsider.
# Be sure that this one doesn't get an inserted line break anywhere
%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -Wconversion -g -c $< -o $@


