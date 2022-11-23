#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc,char **argv){

     
	argv[1][strlen(argv[1])-1]='\0';                                                                
    
    if (mkdir(argv[1],0755)==-1){
        printf("\nERROR\n");
    } else { 
    	printf("Directory created\n");
    }
    printf("$ ");

	return 0;
}
