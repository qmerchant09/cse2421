#Quantez Merchant

#Makefile for lab 1-4.  You need to add you name to this file in the comments
# You will need to add a entry to create your zip file

#change the last dependency for each new lab
all:  tags headers lab1

#this entry has to change for lab 2 - 4
# NEVER compile .c files with this rule - it lacks needed compile time flags
# There is an entry below that turns .c files into .o files

lab1: lab1.o 
	gcc -g -o $@ $^ 

#this is where you create an entry to build your zip file
#it will also update with new labs
lab1.zip: makefile lab1.c *.h README_LAB1
	#zip lab1
	zip lab1.zip $^
	#remove old install folder
	rm -rf install
	#create new install folder
	mkdir install
	#unzip to the install folder
	unzip lab1.zip -d install
	#make only the lab1 target, not lab1.zip
	make -C install lab1

#This entry creates a file called stuff
#that lists everything in the directory 
#from most recent to least recent
stuff: makefile
	date > stuff
	ls -lt >> stuff

#Creates a file called zd
zd: zd.o
	gcc -g -o $@ $^
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
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@


