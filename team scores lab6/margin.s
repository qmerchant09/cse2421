# Quantez Merchant
# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENERATED OR TAKEN FROM MACHINE GENERATED CODE

.file "margin.s" #optional directive
.section .rodata #required directives for rodata
.LC0:
	.string "bestMargin: "
.LC1:
	.string "%c"
.LC2:
	.string " has highest margin at %d."
.data   #required for file scope data
.globl bestMargin  #required directive for every function
	.type bestMargin, @function        #required directive
.text   #required directive - code begins here
bestMargin:
	pushq   %rbp    	#set up stack frame
	movq    %rsp, %rbp      #set up stack frame part 2

	pushq %rbx 	#save 
	pushq %r12	#all
	pushq %r13	#the
	pushq %r14	#callee
	pushq %r15	#registers

	movq $0, %rax		#hold the best address
	movq %rdi, %rbx		#hold a copy of the score struct 
	movq %rsi, %r13		#hold a copy of the count of teams 
	call oshim		#get and display the data for the first team
	movq %rax, %r12		#put the best margin into a holder
	movq $1, %r15		#setup loop counter

findBestMargin:
	addq $52, %rbx		#get the next team data 
	movq %rbx, %rdi		#prepare that team data for display
	call oshim		#get and display team data 
	cmp %r12, %rax		#see if new  margin is best margin
	cmovg %rbx, %r12	#move address of team data to holder
	cmovg %rax, %r14	#move the best margin to holder
	incq %r15		#increment loop
	cmp %r13, %r15		#check to see if loop needs to end 
	jge printSetup		#end loop if needed 
	jmp findBestMargin	#restart loop

printSetup:
	movq $.LC0, %rdi	#prepare to print best margin
	movq $0, %rax		#clear the return value 	
	call print		#print the first part of best margin
	movq $0, %r15		#set up loop counter
printLoop:
	movq $.LC1, %rdi		#prepare to print team name 
	movq (%r12, %r15,1), %rsi	#get one letter from team name 
	movq $0, %rax			#clear return value 
	call print 			#print team name letter
	incq %r15			#increment loop
	cmp $15, %r15			#check to see if loop needs to end
	jge exit			#end loop
	jmp printLoop			#restart loop
exit:
	movq $.LC2, %rdi		#prepare to print the rest of best margin
	movq %r14, %rsi			#get the best margin value ready 
	movq $0, %rax			#clear return value
	call print			#print the rest of best margin
	movq %r12, %rax			#put the team address in return value 

	popq %r15		#restore
	popq %r14		#all
	popq %r13		#the
	popq %r12		#callee
	popq %rbx		#registers
	
	leave   			#teardown the stack frame
	ret     			#return team address
.size   bestMargin, .-bestMargin      	#required directive

