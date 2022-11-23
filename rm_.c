#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char ** argv){
	char print[10000];
	int flag=0;
	if (argc==2 && argv[1][0]!='-'){
		flag=1;
		argv[1][strlen(argv[1])-1]='\0';
		if (remove(argv[1])!=0){
			printf("File not removed\n");
		}
		
	}
	else if (argc==2){
		
		if (argv[1][0]=='-' && argv[1][1]=='-' && argv[1][2]=='h'){
			flag=1;
			FILE *ptr=fopen("rm_help.txt","r");
			while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
					printf("%s\n",print);
				}
			fclose(ptr);
		}
		else if (argv[1][0]=='-' && argv[1][1]=='-' && argv[1][2]=='v'){
			flag=1;
			FILE *ptr=fopen("rm_version.txt","r");
			while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
					printf("%s\n",print);
				}
			fclose(ptr);
		}
	}
	if (flag==0){
		printf("wrong input, enter a valid input\n");
	}
	printf("$ ");

}