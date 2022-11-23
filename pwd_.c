#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char **argv){
	int flag=0;
	char len[1000];
	char print[1000];
	if (argc==2 & argv[1][0]!='-'){
		flag=1;
		argv[1][strlen(argv[1])-1]='\0';
		printf("The current directory is: %s",getcwd(len,1000));
		printf("\n");
	}
	
	if (argc==2 && strcmp(argv[1],"--help\n")==0){
		flag=1;
		FILE *ptr=fopen("pwd_help.txt","r");
		while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
				printf("%s\n",print);
			}
		fclose(ptr);
	}
	if (argc==2 && strcmp(argv[1],"--version\n")==0){
		flag=1;
		FILE *ptr=fopen("pwd_version.txt","r");
		while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
				printf("%s\n",print);
			}
		fclose(ptr);
	}
	if (flag==0){
		printf("wrong input,enter a valid input\n");
	}
	printf("$ ");
	return 0;
}