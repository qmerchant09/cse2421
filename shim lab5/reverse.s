# Quantez Merchant
# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENERATED OR TAKEN FROM MACHINE GENERATED CODE

.file "reverse.s" #optional directive
.section .rodata #required directives for rodata
.data	#required for file scope data
.globl reverse	#required directive for every function
	.type reverse, @function	#required directive
.text	#required directive - code begins here
reverse:
	pushq	%rbp	#set up stack frame
	movq	%rsp, %rbp	#set up stack frame part 2
				
	movl $0, %eax	#holds the return value
	movl $8, %esi	#holds the count for the loop 
	movl $0x0F, %edx	#the low order nibble holder
loop:
	decl %esi	#decrement the count
	jl exit		#break the loop if the count is 0
	sall $4, %eax	#prepare the answer for the low order nibble
	and %edi,%edx	#take the low order nibble from the parameter and put it in holder
	or %edx,%eax	#assign the holder value to the return value
	shrl $4, %edi	#get rid of old low order nibble, and prepare new low order nibble
	movl $0x0F, %edx	#reinitialize the low order nibble holder
	jmp loop	#restart loop

exit:
	leave	#teardown the stack frame
	ret	#return the reversed int
.size	reverse, .-reverse	#required directive
