# Quantez Merchant
# Don't forget to create a proper lab 5 zip target
#
# Most of this is instructor- supplied code.
#

# test out adjust
lab5: lab5.o adjust.s ashim.o reverse.s rshim.o everything.s eshim.o
	gcc -g -o $@ $^

lab5bonus: lab5bonus.s adjust.s ashim.o reverse.s rshim.o everything.s eshim.o
	gcc -g -o $@ $^

# test out reverse
atest: atest.o adjust.s ashim.o
	gcc -g -o $@ $^

# test out reverse
rtest: rtest.o reverse.s rshim.o
	gcc -g -o $@ $^

lab5.zip: makefile *.c *.h *.s *.o README_LAB5
	#zip lab
	zip $@ $^
	#remove old install folder
	rm -rf install
	#create new install folder
	mkdir install
	#unzip to the install folder
	unzip $@ -d install
	#make only the lab5 target, not lab5.zip
	make -C install lab5

# One rule to compile them all!
CFLAGS = -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -Wconversion

%.o:%.c *.h
	gcc $(CFLAGS) -g -c $< -o $@


# THIS IS NOT FOR STUDENTS:  this is how the lab 5 files you need make it
# to a zip file.  Please create a lab5.zip target and leave this alone

l5files.zip: makefile lab5.c atest.c rtest.c eshim.o ashim.o rshim.o l5.h
	zip $@ $^
