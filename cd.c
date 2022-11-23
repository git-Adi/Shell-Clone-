#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void cd_L(char* path){
	int val= chdir("..");
	if(val==-1){
		perror("ERror");
		return;
	}
}

int main(int argc,char *argv[]){
	if (argv[2]!=NULL){
		if (argv[2][0]=='-'){
			if (strcmp(argv[2],"-L")==0){
				char *temp=argv[3];
				if (temp!=NULL){
					cd_L(temp);
				}else{
					printf("Invalid Input");
				}
			}
			else if(strcmp(argv[2],"--help")==0){
				char print[1000];
				FILE *ptr=fopen("cd_help.txt","r");
				while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
					printf("%s\n",print);
				}
				fclose(ptr);
			}
			else{
				printf("Invalid input -- %s\n",temp);
			}
		}
		else{
			if (chdir(argv[2])==-1){
				perror("Error");

			}
		}
	}
	else{
		if (chdir(getenv("HOME"))==-1){
			perror("Error");
		}
	}
}