#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int main(int argc,char **argv){
	char print[1000];
	int c=0;
	
	if (argv[0][0]=='.' && argv[0][1]=='/' && argv[0][2]=='a' && argv[0][3]=='.' && argv[1][0]!='-'){
		for (int i=1;i<argc;i++){
			printf("%s ",argv[i]);
		}
	}
	
	//if (argv[1][0]=='.' && argv[1][1]=='/' && argv[1][2]=='a' && argv[1][3]=='.' && argv[2][0]=='e' && argv[2][1]=='c' && argv[2][2]=='h' && argv[2][3]=='o' && argv[3][0]=='-' && argv[3][0]=='-' && argv[3][0]=='h')
	if ( argv[1][0]=='-' &&argv[1][1]=='e'){
		for (int i=2;i<argc;i++){
			if (argv[i][0]!='/' && argv[i][1]!='c'){
				printf("%s ",argv[i]);
			}

		}
	}
	printf("\n");
	if (argv[1][0]=='-' &&argv[1][1]=='n'){
		for (int i=1;i<argc;i++){
			printf("%s ",argv[i]);
		}
	}
}