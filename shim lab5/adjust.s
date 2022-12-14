# Quantez Merchant
# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENERATED OR TAKEN FROM MACHINE GENERATED CODE

.file "adjust.s" #optional directive
.section .rodata #required directives for rodata
.data	#required for file scope data
.globl adjust	#required directive for every function
	.type adjust, @function	#required directive
.text	#required directive - code begins here
adjust:
	pushq	%rbp	#set up stack frame
	movq	%rsp, %rbp	#set up stack frame part 2

	movl $0, %eax	#holds the return value
	movl $0, %esi	#holds the carry value
	movl $8, %edx	#holds the loop count
	movl $0x0F, %ecx	#low order nibble holder
	movl $9, %r8d	#value to check against nibble
	movl $6, %r9d	#value to add to nibble if greater than 9
	movl $0, %r10d	#temporary value

loop:
	decl %edx	#decrement count
	jl exit		#break loop when count is zero
	sall $4, %eax	#prepare return value for the low order nibble
	and %edi, %ecx	#take low order nibble from parameter
	addl %esi, %ecx	#add carry value to low order nibble
	cmpl %r8d, %ecx	#check if low order nibble is greater than 9
	jg addNinePath	#jump to new code
	or %ecx, %eax	#assign the low order nibble to the return value
	shrl $4, %ecx	#get the carry value
	movl %ecx, %esi	#assign the carry value 
	shrl $4, %edi	#get new low order nibble
	movl $0x0F, %ecx	#reset low order nibble holder
	jmp loop	#restart loop

addNinePath:
	add %r9d, %ecx		#add the 6 to the low order nibble to get correct hex value 
	movl $0x0F, %r10d	#prepare the temp value
	and %ecx, %r10d		#put low order nibble into a temp holder	
	or %r10d, %eax		#assign low order nibble to return value
	shrl $4, %ecx		#get new carry value
	movl %ecx, %esi		#assign new carry value 
	shrl $4, %edi		#get new low order nibble
	movl $0x0F, %ecx	#reset low order nibble holder
	jmp loop		#restart loop

exit:
	leave	#teardown the stack frame
	ret	#return the adjusted int
.size	adjust, .-adjust	#required directive
