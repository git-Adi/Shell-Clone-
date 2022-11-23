#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[])
{
    int flag=0;
    // printf("aditya");
    // printf("%s\n",argv[1]);
    if (argv[1][0]!='-'){
        flag=1;
        printf("%s\n",argv[1]);
        argv[1][strlen(argv[1])-1]='\0';
        int ret = mkdir(argv[1], 0755);

        if (ret == 0)
            printf("Directory created successfully\n");
        else
            printf("Unable to create directory %s\n", argv[1]);

    }
    else{
        char print1[1000];
        
         if (strcmp(argv[1],"--version\n")==0){
            flag=1;
            FILE *ptr=fopen("mkdir_version.txt","r");
            while (fscanf(ptr,"%[^\n]\n",print1)!=EOF){
                    printf("%s\n",print1);
                }
            fclose(ptr);
        }
    }
    if (flag==0){
        printf("wrong input,enter a valid input\n");
    }
    printf("$ ");
    
    return 0;
}
