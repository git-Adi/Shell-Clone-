#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc,char ** argv){
	int ret=0;
	argv[1][strlen(argv[1])-1]='\0';
	ret = rmdir(argv[1]);

    if (ret == 0)
        printf("Given empty directory removed successfully\n");
    else
        printf("Unable to remove directory %s\n", argv[1]);

    printf("$ ");

	return 0;
}