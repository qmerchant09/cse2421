# Quantez Merchant
# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENERATED OR TAKEN FROM MACHINE GENERATED CODE

.file "everything.s" #optional directive
.section .rodata #required directives for rodata
.data	#required for file scope data
.globl everything	#required directive for every function
	.type everything, @function	#required directive
.text	#required directive - code begins here
everything:
	pushq	%rbp	#set up stack frame
	movq	%rsp, %rbp	#set up stack frame part 2
				
	movl $0, %eax	#holds the return value
	
	call ashim	#adjust the broken sum 
	movl %eax, %edi	
	call rshim	#reverse the broken sum

	leave	#teardown the stack frame
	ret	#return the reversed int
.size	everything, .-everything	#required directive
