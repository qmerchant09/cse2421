# Quantez Merchant
# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENERATED OR TAKEN FROM MACHINE GENERATED CODE

.file "lab5bonus.s" #optional directive
.section .rodata #required directives for rodata
.LC0:
	.string "Lab5: All in one go: %x\n"
.LC1:
	.string "Everything gave %x\n"
.data	#required for file scope data
.globl main	 #required directive for every function
	.type main, @function	#required directive
.text	#required directive - code begins here
main:
	pushq	%rbp	#set up stack frame
	movq	%rsp, %rbp	#set up stack frame part 2
	
	movl $0x12345678, %edi	#holds the first value to sum
	movl $0x55555555, %esi	#holds the second value to sum
	movl $0, %ebx	#holds the broken sum
	movl $0, %eax	#holds the fixed sum	
	
	addl %edi,%esi	#gets the broken sum
	movl %esi, %ebx	#creates a copy of the broken sum
	movl $.LC0, %edi	#address of string "Lab5: All in one go"to %edi
	call printf	#prints "Lab5: All in one go" and the broken sum 
	
	movl %ebx, %edi #sets the first parameter to the value of the broken sum
	call eshim	#fixes the broken sum
	
	movl %eax, %esi	#sets the second parameter to the value of the fixed sum
	movl $0, %eax	#needs to be zero for printf 
	movl $.LC1, %edi #address of string "Everything gave" to %edi
	call printf	#prints "Everything gave" and the fixed sum
	movl $0, %eax	#set return value to zero

	leave	#teardown the stack frame
	ret	#return 0
.size	main, .-main	#required directive
