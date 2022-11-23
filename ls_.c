#include <stdio.h>
#include <dirent.h>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc,char *argv[]){
	int flag=0;
	struct dirent *d;
	DIR *dh=opendir(".");
	if (!dh){
		printf("unable to read directory");
	}
	if (argc==1){
		flag=1;
		d=readdir(dh);
	while (d!=NULL){
		if (d->d_name[0]=='.'){
			d=readdir(dh);
			continue;
		}
		printf("%s   ",d->d_name);
		d=readdir(dh);
	}
	printf("\n");
	}
	else if (argc==2){
		if (argv[1][0]=='-' &&argv[1][1]=='a'){
			flag=1;
			d=readdir(dh);
		while (d!=NULL){
			
			printf("%s   ",d->d_name);
			d=readdir(dh);
		}
		printf("\n");
	}
	
	
	else if (argv[1][0]=='-' && argv[1][1]=='L'){
		flag=1;
			d=readdir(dh);
			while (d!=NULL){
			if (d->d_name[0]=='.'){
				d=readdir(dh);
				continue;
			}
			printf("%s",d->d_name);

			d=readdir(dh);
			printf("\n");

		}
		printf("\n");
	}
	else if (argv[2][0]=='-'&& argv[2][1]=='-'&& argv[2][2]=='v'){
		flag=1;
		printf("ls (GNU coreutils) 2.40");
		printf("\n");
		printf("Copyright (C) 2018 Free Software Foundation, Inc.");
		printf("\n");
		printf("License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.");
		printf("\n");
		printf("This is free software: you are free to change and redistribute it.");
		printf("\n");
		printf("There is NO WARRANTY, to the extent permitted by law.");
		printf("\n");
		printf("Written by Aditya Arya");
		exit(EXIT_FAILURE);
	}
	}
	else if (flag==0){
		perror("wrong input, enter a valid input\n");
	}
	printf("$ ");
}
