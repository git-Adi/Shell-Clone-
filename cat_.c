#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[]){
	int flag=0;
	// printf("aditya\n");
	// printf("%s\n",argv[1]);
	// printf("%d\n",argc);
	char print1[10000];
	if (argc==2 && argv[1][0]!='-'){
		flag=1;
		argv[1][strlen(argv[1])-1]='\0';
		// printf("Aditya down");
		FILE *fp=fopen(argv[1],"r");
		char print[1000];
		
		printf("output of the cat command is: ");
		while (fscanf(fp,"%[^\n]\n",print)!=EOF){
			printf("%s\n",print);

		}
		fclose(fp);
	}
	else if (argc==2 && argv[1][0]=='-'){
		// printf("Aditya down2");
		if (strcmp(argv[1],"--help\n")==0){
			flag=1;
			FILE *ptr=fopen("cat_help.txt","r");
			while (fscanf(ptr,"%[^\n]\n",print1)!=EOF){
					printf("%s\n",print1);
				}
			fclose(ptr);
		}
		else if (strcmp(argv[1],"--version\n")==0){
			flag=1;
			FILE *ptr=fopen("cat_version.txt","r");
			while (fscanf(ptr,"%[^\n]\n",print1)!=EOF){
					printf("%s\n",print1);
				}
			fclose(ptr);
		}
	}// else{
	// 	printf("wrong input,enter a valid input\n");
	// }
	if (flag==0){
		printf("wrong input,enter a valid input\n");
	}
	printf("$ ");
}