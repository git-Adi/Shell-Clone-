#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char ** argv){
	char in[1];
	argv[1][strlen(argv[1])-1]='\0';
	printf("Are you sure you want to delete %s: ",argv[1]);
	scanf("%s",in);
	// printf("yes");
	in[strlen(in)-1]='\0';
	int x=1;
	if (strcmp(in,"y")==0 || strcmp(in,"Y")==0){
		char print[10000];
		int flag=0;
		if (argv[1][0]!='-'){
			flag=1;
			
			if (remove(argv[1])!=0){
				printf("File not removed\n");
			}
			
		}
	}
	else{
		printf("File won't be removed");
	}

	printf("$ ");

	return 0;
}