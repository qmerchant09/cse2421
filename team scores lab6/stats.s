# Quantez Merchant
# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENERATED OR TAKEN FROM MACHINE GENERATED CODE

.file "stats.s" #optional directive
.section .rodata #required directives for rodata
.data   #required for file scope data
.globl stats  #required directive for every function
	.type stats, @function        #required directive
.text   #required directive - code begins here
stats:
	pushq   %rbp    	#set up stack frame
	movq    %rsp, %rbp      #set up stack frame part 2
			   
	movq $6, %rax   #holds subtracted total and loop count and array value
	movq $0, %rsi	#holds the tie 
	movq $0, %rdx	#holds the loss
	movq $0, %rcx	#holds the win
	movq $0, %r8	#holds our total
	movq $0, %r9	#holds opponenet total
	movq $0, %r10	#holds our score
	movq $0, %r11	#holds opponent score

	
loop:
	decq %rax			#decrement loop, and array value
	movw 16(%rdi,%rax,2), %r10w	#get our score    
	movw 28(%rdi,%rax,2), %r11w     #get opponent score
	jl exit				#exit loop if rax is 0
	cmp %r11, %r10			#compare our socre to theirs
	jl loss				#go to loss path if our score is lower
	je tie				#go to tie path if we tied 
	jg win				#go to win path if we won
	jmp loop			#restart loop

tie:
	incq %rsi		#increment the tie count 
	addw %r10w, %r8w	#get our total score 
	addw %r11w, %r9w	#get their total score
	jmp loop		#go back to loop

win:
	incq %rcx		#increment win count 
	addw %r10w, %r8w	#get our total score 
	addw %r11w, %r9w	#get their total score
	jmp loop		#go back to loop

loss:
	incq %rdx		#increment loss count 
	addw %r10w, %r8w	#get out total score
	addw %r11w, %r9w	#get their total score 
	jmp loop		#increment loop

exit:
	movq $0,%rax		#clear total holder
	addq %r8, %rax		#add our socre to the total holder
	subq %r9, %rax		#subtract their points from our points 
	movl %esi, 48(%rdi)	#put the ties in place	
	movl %edx, 44(%rdi)	#put the losses in place
	movl %ecx, 40(%rdi)	#put the wins in place 
	
	leave   		#teardown the stack frame
	ret     		#return the total
.size   stats, .-stats      	#required directive

