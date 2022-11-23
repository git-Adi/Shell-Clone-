#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[]){
	int flag=0;
	int read=1;
	printf("aditya\n");
	// printf("%s\n",argv[1]);
	// printf("%d\n",argc);
	char print1[10000];
	if (argc==2 && argv[1][0]!='-'){
		flag=1;
		argv[1][strlen(argv[1])-1]='\0';
		// printf("Aditya down");
		FILE *fp=fopen(argv[1],"r");
		char print[1000];
		
		printf("output of the cat command is: \n");
		while (fscanf(fp,"%[^\n]\n",print)!=EOF){
			printf("%d) %s\n",read,print);
			read=read+1;

		}
		fclose(fp);
	}
	printf("$ ");
}