/* Quantez Merchant */

#include <stdio.h>
#include <stdlib.h>

int f (FILE **fp, char* a[]){
	if ((*fp = fopen(a[1],"r")) == NULL){
		return 0;
	}
	return 1;
}

int main (int argc, char *argv[]){
	FILE *fp;
	int i = 0;
	unsigned long val = 0;
	if (argc == 2){	
		if(!(f(&fp,argv))){
			printf("ERROR opening file\n");
		}else{
			while(fscanf(fp,"%d %lX",&i,&val) != EOF ){
				printf("%d %lX\n",i,val);
			}
			fclose(fp);
		}
	}
	return 0;

}
