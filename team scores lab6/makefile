# Quantez Merchant
# CSE 2421 AU 21 Your name goes here
# basics provied by Professor Kirby

lab6: lab6.o sshim.o stats.s oshim.o team.s print.o mshim.o margin.s
	gcc -m64 -g -o $@ $^

otest: otest.o sshim.o stats.s oshim.o team.s print.o
	gcc -m64 -g -o $@ $^

stest: stest.o sshim.o stats.s
	gcc -m64 -g -o $@ $^

lab6.zip: makefile *.c *.h *.s sshim.o oshim.o mshim.o print.o README_LAB6
	#zip lab
	zip $@ $^
	#remove old install folder
	rm -rf install
	#create new install folder
	mkdir install
	#unzip to the install folder
	unzip $@ -d install	
	#make only the lab6 target, not lab6.zip
	make -C install lab6

# this is not your zip target - build your own
l6files.zip: oshim.o sshim.o mshim.o print.o makefile record.h *.c lab6.output
	zip $@ $^


# One rule to compile them all!
CFLAGS = -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -Wconversion

%.o:%.c *.h
	gcc $(CFLAGS) -g -c $< -o $@

