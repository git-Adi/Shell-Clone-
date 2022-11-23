#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[]){
	FILE *fp;
	// printf("%s\n",argv[1]);
    int ft,i=0;
    argv[1][strlen(argv[1])-1]='\0';
    fp=fopen(argv[1],"r");
    if(fp==NULL)
    {
        printf("Error identified");
        return 0;
    }
    fseek(fp,0,SEEK_END);
    ft=ftell(fp);
    while(i<ft)
    {
        i++;
        fseek(fp,-i,SEEK_END);
        printf("%c",fgetc(fp));
    }
    fclose(fp);
    printf("\n");
    printf("\n");
    printf("$ ");
    return 0;
}