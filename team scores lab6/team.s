# Quantez Merchant
# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENERATED OR TAKEN FROM MACHINE GENERATED CODE

.file "team.s" #optional directive
.section .rodata #required directives for rodata
.LC0:
	.string "\noneTeam: "
.LC1: 
	.string "%c"
.LC2:
	.string "\n"
.LC3:
	.string "%d to %d\n"
.LC4:
	.string "Total margin of victory is %d\nRecord is %d Win, %d lost, %d tie (W-L = %d)\n"
.data   #required for file scope data
.globl oneTeam  #required directive for every function
	.type oneTeam, @function        #required directive
.text   #required directive - code begins here
oneTeam:
	pushq   %rbp    	#set up stack frame
	movq    %rsp, %rbp      #set up stack frame part 2
	
	pushq %rbx	#save
        pushq %r12	#the callee registers

	movq $0, %rax		#holds the margin 
	movq $0, %rbx		#hold the loop counter and a copy of the total margin 
	movq %rdi, %r12		#hold a copy of the point data 
	movq $0, %rsi		#holds our socre, and holds a copy of total margin 
	movq $0, %rdx		#holds opponent score, and holds wins
	movq $0, %rcx		#holds losses
	movq $0, %r8		#holds ties
	movq $0, %r9		#holds wins minus losses number 
	movq $.LC0, %rdi 	#prepare to print function name
	call print 		#print function name
printLoop:
	movq $.LC1, %rdi		#prepare to print letter of team name
	movq (%r12, %rbx, 1), %rsi	#get letter of team name 
	call print			#print the letter of team name
	incq %rbx			#increment loop
	cmp $15, %rbx			#break loop when char array is at end
	jge newline			#break loop
	jmp printLoop			#restart loop
newline:
	movq $0, %rbx		#reset the loop counter
	movq $.LC2, %rdi	#prepare to print a newline 
	call print		#print a newline 
scoreLoop:
	movq $0, %rsi 			#clears junk from score holder 
	movq $0, %rdx			#clears junk from score holder
	movw 16(%r12, %rbx,2), %si 	#get our score value
	movw 28(%r12, %rbx,2), %dx	#get opponent score value
	movq $.LC3, %rdi		#prepare to print score data 
	call print			#print scores
	incq %rbx			#increment loop
	cmp $6, %rbx			#check if loop needs to break 
	jge exit			#break loop
	jmp scoreLoop			#go through another loop cycle 


exit:
	movq %r12, %rdi		#give score data to score data holder
	call sshim		#get wins/loss/ties/margin
	movq %rax, %rsi		#give margin to margin holder
	movq %rax, %rbx		#give margin to call survivning margin holder
	movq $.LC4, %rdi	#prepare to print win/loss/tie/margin 
	movl 48(%r12), %r8d	#get ties
	movl 44(%r12), %ecx	#get losses
	movl 40(%r12), %edx	#get wins
	movq $0, %r9		#clean junk from wins minus loss holder 
	addl %edx, %r9d		#set up calculation for win minus loss
	subl %ecx, %r9d		#calculate win minus loss
				
	call print		#print win/loss/tie/margin 
	movq %rbx, %rax		#retrive margin 
	
	popq %r12		#restore 
	popq %rbx		#the callee registers

	leave   		#teardown the stack frame
	ret     		#return the total
.size   oneTeam, .-oneTeam      #required directive

