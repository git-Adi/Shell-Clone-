#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <pthread.h>

void cd_help(){
    char print[1000];
    FILE *ptr=fopen("cd_help.txt","r");
            while (fscanf(ptr,"%[^\n]\n",print)!=EOF)
            {
                    printf("%s\n",print);
                }
            fclose(ptr);
    printf("$ ");
}

void ls_(char *arg){
    // printf("hello");
    // char *argument=char* arg;
    printf("%c\n",arg[0]);
    int flag=0;
    struct dirent *d;
    DIR *dh=opendir(".");
    if (arg[0]=='l' && arg[1]=='s'){
        flag=1;
        if (!dh){
            printf("unable to read directory");
        }
        
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
    else {
        if(arg[0]=='-' && arg[1]=='L'){
            flag=1;
            d=readdir(dh);
            while (d!=NULL){
            if (d->d_name[0]=='.'){
                d=readdir(dh);
                continue;
            }
            printf("%s  ",d->d_name);

            d=readdir(dh);
            printf("\n");

        }
        printf("\n");
        }
        if (arg[0]=='-' && arg[1]=='-' && arg[2]=='A'){
            flag=1;
            d=readdir(dh);
        while (d!=NULL){
            
            printf("%s  ",d->d_name);
            d=readdir(dh);
        }
        printf("\n");
        }
        if (arg[0]=='-' && arg[1]=='-' && arg[2]=='v'){
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
        }
        
    }
    if (flag==0){
        printf("wrong input,enter correct input\n");
    }
    printf("$ ");
    pthread_exit(0);

}



void date_(char *arg){
    char print[1000];
    int flag=0;
    if (strcmp(arg,"date")==0){
        flag=1;
        time_t tim;
        time(&tim);
        printf("current date&time: %s\n",ctime(&tim));
        
    }
    else{
        if (arg[0]=='-' && arg[1]=='g'){
            flag=1;
            time_t tim;
            time(&tim);
            struct tm *gtm = gmtime(&tim);
            printf("Current date&time: ");
            printf("%d:%d:%d %d/%d/%d\n",gtm->tm_hour,gtm->tm_min,gtm->tm_sec,gtm->tm_mday,gtm->tm_mon+1,gtm->tm_year+1900);
        }
        else if (arg[0]=='-' && arg[1]=='-' && arg[2]=='v'){
            flag=1;
            FILE *ptr=fopen("date_version.txt","r");
            while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
                printf("%s\n",print);
            }
            fclose(ptr);
        }
         
    }
    if (flag==0){
        printf("wrong input, enter valid input\n");
    }
    printf("$ ");
}

void rm_(char *arg){
    char print[1000];
    int flag=0;

    if (arg[0]!='-'){
        flag=1;
       
        if (remove(arg)!=0){
            printf("File not removed\n");
        }
    }
    else{
        if (arg[0]=='-' && arg[1]=='-' && arg[2]=='h'){
            flag=1;
            FILE *ptr=fopen("rm_help.txt","r");
        while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
                printf("%s\n",print);
            }
        fclose(ptr);
        }
        else if (arg[0]=='-' && arg[1]=='-' && arg[2]=='v'){
            flag=1;
            FILE *ptr=fopen("rm_version.txt","r");
        while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
                printf("%s\n",print);
            }
        fclose(ptr);
        }
    }
    if (flag==0){
        printf("wrong input, enter valid input\n");

    }
    printf("$ ");
}

void rm_i(char *arg){
    char in[1];
    //arg[strlen(argv[1])-1]='\0';
    printf("Are you sure you want to delete %s: ",arg);
    scanf("%s",in);
    // printf("yes");
    in[strlen(in)-1]='\0';
    if (strcmp(in,"y")==0 || strcmp(in,"Y")==0){
        char print[10000];
        int flag=0;
        if (arg[0]!='-'){
            flag=1;
            
            if (remove(arg)!=0){
                printf("File not removed\n");
            }
            
        }
    }
    else{
        printf("File won't be removed");
    }
    printf("$ ");
}

void rm_r(char *arg){
    int ret=0;
    // arg[strlen(argv[1])-1]='\0';
    ret = rmdir(arg);

    if (ret == 0)
        printf("Given empty directory removed successfully\n");
    else
        printf("Unable to remove directory %s\n", arg);

    printf("$ ");

}

void cat_(char *arg){
    int flag=0;
    char print[1000];
    if (arg[0]!='-'){
        // arg[strlen(arg)-1]='\0';
        // printf("Aditya down");
        FILE *fp=fopen(arg,"r");
        char print[1000];
        
        printf("output of the cat command is: ");
        while (fscanf(fp,"%[^\n]\n",print)!=EOF){
            printf("%s\n",print);

        }
        fclose(fp);
    }
    else{
        if (arg[0]=='-' && arg[1]=='-' && arg[2]=='h'){
            flag=1;
            FILE *ptr=fopen("cat_help.txt","r");
            while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
                    printf("%s\n",print);
                }
            fclose(ptr);
        }
        else if(arg[0]=='-' && arg[1]=='-' && arg[2]=='v'){
            flag=1;
            FILE *ptr=fopen("cat_version.txt","r");
            while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
                    printf("%s\n",print);
                }
            fclose(ptr);
        }
    }
    if (flag==0){
        printf("wrong input, enter a valid input\n");
    }
    printf("$ ");
}

void cat_r(char *arg){
   int flag=0;
   FILE *fp;
    printf("%s\n",arg);
    int ft,i=0;
    // argv[1][strlen(argv[1])-1]='\0';
    fp=fopen(arg,"r");
    if(fp==NULL)
    {
        printf("Error occured");
        
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
    printf("$ ");
    
}

void cat_n(char *arg){
    int flag=0;
    int read=1;
    printf("aditya\n");
    // printf("%s\n",argv[1]);
    // printf("%d\n",argc);
    char print1[10000];
    if (arg[0]!='-'){
        flag=1;
        //argv[1][strlen(argv[1])-1]='\0';
        // printf("Aditya down");
        FILE *fp=fopen(arg,"r");
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

void mkdir_(char *arg){
    int flag=0;
    printf("%s\n",arg);
    char print[1000];
    if (arg[0]!='-'){
        flag=1;
        printf("%s\n",arg);
        int ret = mkdir(arg, 0755);

        if (ret == 0)
            printf("Directory created successfully\n");
        else
            printf("Unable to create directory %s\n", arg);
    }
    
    if(flag==0){
        printf("wrong input, enter a valid input\n");
    }
    printf("$ ");
}
void pwd_(char *arg){
    int flag=0;
    char len[1000];
    char print[1000];
    if (arg[0]!='-'){
        flag=1;
        // arg[strlen(arg)-1]='\0';
        printf("The current directory is: %s",getcwd(len,1000));
        printf("\n");
    }
    else{
        if (strcmp(arg,"--help")==0){
            flag=1;
            FILE *ptr=fopen("pwd_help.txt","r");
        while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
                printf("%s\n",print);
            }
        fclose(ptr);
        }
        else if (strcmp(arg,"--version")==0){
            flag=1;
            FILE *ptr=fopen("pwd_version.txt","r");
        while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
                printf("%s\n",print);
            }
        fclose(ptr);
        }

    }
    if (flag==0){
        printf("wrong input, enter a vlid input\n");
    }
    printf("$ ");
}

void echo_(char *arg){

}

// void cd_help(){
//     char print[1000];
//     FILE *ptr=fopen("cd_help.txt","r");
//             while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
//                     printf("%s\n",print);
//                 }
//             fclose(ptr);
// }



int main()
{
    printf("welcome to Aditya's shell\n");
    printf("$ ");
    
    
    while (1){
        char str1[100];
    
        char newString[20][20]; 
        fgets(str1, sizeof(str1), stdin);	
        // printf("%s",str1);
        if(strcmp(str1,"exit\n")==0){
            break;
        }
        else{
            int i,j,ctr;
            int len=0;
            j=0; 
            ctr=0;
            for(i=0;i<=strlen(str1);i++)
            {
               
                if(str1[i]==' '|| str1[i]=='\0')
                {
                    newString[ctr][j]='\0';
                    ctr=ctr+1; 
                    j=0;   
                }
                else
                {
                    newString[ctr][j]=str1[i];
                    j=j+1;
                }
            }
            for(i=0;i < ctr;i++){
                len=len+1;
                // printf("%sthis is what we want",newString[i]);
            }
            // printf("%d\n",len);
            // printf("%s\n",newString[0]);
            if ((strcmp(newString[0],"date")==0 || strcmp(newString[0],"date\n")==0) && strcmp(newString[len-1],"&t\n")!=0){
                // printf("Aditya up\n");
                if (len==1){
                    // printf("Aditya");
                    pid_t id;
                    id = fork();
                    if (id==0){
                        char *argument[] ={"./date_",NULL,NULL};
                        // execvp("./date_",argument);
                        if (execvp("./date_",argument)==-1){
                            printf("execution unsuccessful\n$ ");
                        }

                    }
                    else if(id<0){
                    printf("Unsucccessful");
                    }
                }  
                else if (len==2){
                    // printf("hello\n");
                    pid_t id;
                    id = fork();
                    if (id==0){
                        char *argument[] ={"./date_", newString[1],NULL};
                        // execvp("./date_",argument);
                        if (execvp("./date_",argument)==-1){
                            printf("execution unsuccessful\n$ ");
                        }

                    }
                    else if(id<0){
                    printf("Unsucccessful");
                    }
                }       
            }
            else if ((strcmp(newString[0],"ls")==0 || strcmp(newString[0],"ls\n")==0) && strcmp(newString[len-1],"&t\n")!=0){
                if (len==1){
                    // printf("Aditya");
                    pid_t id;
                    id = fork();
                    if (id==0){
                        char *argument[] ={"./ls_",NULL,NULL};
                        // execvp("./date_",argument);
                        if (execvp("./ls_",argument)==-1){
                            printf("execution unsuccessful\n$ ");
                        }

                    }
                    else if(id<0){
                    printf("Unsucccessful");
                    }
                }  
                else if (len==2){
                    // printf("hello\n");
                    pid_t id;
                    id = fork();
                    if (id==0){
                        char *argument[] ={"./ls_", newString[1],NULL};
                        // execvp("./date_",argument);
                        if (execvp("./ls_",argument)==-1){
                            printf("execution unsuccessful\n$ ");
                        }

                    }
                    else if(id<0){
                    printf("Unsucccessful");
                    }
                }    

            }
            else if ((strcmp(newString[0],"cat")==0 || strcmp(newString[0],"cat\n")==0) && strcmp(newString[len-1],"&t\n")!=0){
                if (len==2 && newString[1][0]!='-'){
                    // printf("Aditya");
                    pid_t id;
                    id = fork();
                    if (id==0){
                        char *argument[] ={"./cat_",newString[1],NULL};
                        // execvp("./date_",argument);
                        if (execvp("./cat_",argument)==-1){
                            printf("execution unsuccessful\n$ ");
                        }

                    }
                    else if(id<0){
                    printf("Unsucccessful");
                    }
                }  
                else if (len==2){
                    // printf("hello\n");
                    pid_t id;
                    id = fork();
                    if (id==0){
                        char *argument[] ={"./cat_", newString[1],NULL};
                        // execvp("./date_",argument);
                        if (execvp("./cat_",argument)==-1){
                            printf("execution unsuccessful\n$ ");
                        }

                    }
                    else if(id<0){
                    printf("Unsucccessful");
                    }
                } 
                else if (len==3 && strcmp(newString[1],"-n")==0){
                    pid_t id;
                    id = fork();
                    if (id==0){
                        char *argument[] ={"./cat_n", newString[2],NULL};
                        // execvp("./date_",argument);
                        if (execvp("./cat_n",argument)==-1){
                            printf("execution unsuccessful\n$ ");
                        }

                    }
                    else if(id<0){
                    printf("Unsucccessful");
                    }
                }
                else if (len==3 && strcmp(newString[1],"-r")==0){
                    pid_t id;
                    id = fork();
                    if (id==0){
                        char *argument[] ={"./cat_r", newString[2],NULL};
                        // execvp("./date_",argument);
                        if (execvp("./cat_r",argument)==-1){
                            printf("execution unsuccessful\n$ ");
                        }

                    }
                    else if(id<0){
                    printf("Unsucccessful");
                    }
                }
                else{
                    printf("wrong input, enter a valid input\n");
                    printf("$ ");
                }  
            }
            else if (strcmp(newString[0],"rm")==0 && strcmp(newString[len-1],"&t\n")!=0){

                    pid_t id;
                    id = fork();
                    if (id==0){
                        if (len==2){
                            char *argument[] ={"./rm_", newString[1],NULL};
                            // execvp("./date_",argument);
                            if (execvp("./rm_",argument)==-1){
                                printf("execution unsuccessful\n$ ");
                            }
                        }
                        else if (len==3 && strcmp(newString[1],"-i")==0){
                            char *argument[] ={"./rm_i", newString[2],NULL};
                            // execvp("./date_",argument);
                            if (execvp("./rm_i",argument)==-1){
                                printf("execution unsuccessful\n$ ");
                            }
                        }
                        else if (len==3 && strcmp(newString[1],"-r")==0){
                            char *argument[] ={"./rm_r", newString[2],NULL};
                            // execvp("./date_",argument);
                            if (execvp("./rm_r",argument)==-1){
                                printf("execution unsuccessful\n$ ");
                            }
                        }
                        else{
                            printf("wrong input,enter a valid input\n");
                            printf("$ ");
                        }
                        

                    }
                    else if(id<0){
                    printf("Unsucccessful");
                    }
            }
            else if (strcmp(newString[0],"mkdir")==0 && strcmp(newString[len-1],"&t\n")!=0){
                    pid_t id;
                    id = fork();
                    if (len==2){
                        if (id==0){
                            char *argument[] ={"./mkdir_", newString[1],NULL};
                            // execvp("./date_",argument);
                            if (execvp("./mkdir_",argument)==-1){
                                printf("execution unsuccessful\n$ ");
                            }

                        }
                        else if(id<0){
                        printf("Unsucccessful");
                        }

                    }
                    else if (strcmp(newString[1],"-p")==0){
                        
                        if (id==0){
                          char *argument[] ={"./mkdir_a=r", newString[2],NULL};
                            // execvp("./date_",argument);
                            if (execvp("./mkdir_a=r",argument)==-1){
                                printf("execution unsuccessful\n$ ");
                            }  
                        }
                        else if(id<0){
                        printf("Unsucccessful");
                        }
                    }
                    else {
                        printf("wrong input,enter a valid input1\n");
                        printf("$ ");
                    }
                    
            }
            else if ((strcmp(newString[0],"pwd\n")==0 || strcmp(newString[0],"pwd")==0) && strcmp(newString[len-1],"&t\n")!=0){
                if (len==1){
                    pid_t id;
                    id = fork();
                    if (id==0){
                        char *argument[] ={"./pwd_", newString[0],NULL};
                        // execvp("./date_",argument);
                        if (execvp("./pwd_",argument)==-1){
                            printf("execution unsuccessful\n$ ");
                        }

                    }
                    else if(id<0){
                    printf("Unsucccessful");
                    }
                }
                else{
                    pid_t id;
                    id = fork();
                    if (id==0){
                        char *argument[] ={"./pwd_", newString[1],NULL};
                        // execvp("./date_",argument);
                        if (execvp("./pwd_",argument)==-1){
                            printf("execution unsuccessful\n$ ");
                        }

                    }
                    else if(id<0){
                    printf("Unsucccessful");
                    }
                }
            }
            else if (strcmp(newString[0],"echo")==0 && strcmp(newString[len-1],"&t\n")!=0){
                if (strcmp(newString[1],"-e")==0){
                    for (int i=2;i<len;i++){
                        if (newString[i][0]!='/' && newString[i][1]!='c'){
                            printf("%s ",newString[i]);
                        }

                    }
                    printf("\n");
                    printf("$ ");
                }
                
                else if (strcmp(newString[1],"-n")==0){
                    for (int i=2;i<len;i++){
                        if (i==len-1){
                            newString[i][strlen(newString[i])-1]='\0';
                            printf("%s ",newString[i]);
                        }else{
                            printf("%s ",newString[i]);
                        }
                        
                    }
                    printf("\n"); 
                    printf("$ ");
                }
                else{
                    for (int i=1;i<len;i++){
                        if (i!=len-1){
                            printf("%s ",newString[i]);
                        }else{
                            newString[i][strlen(newString[i])-1]='\0';
                            printf("%s ",newString[i]);
                        }
                    }
                    printf("$ ");
                }

            }
            else if ((strcmp(newString[0],"ls\n")==0 || strcmp(newString[0],"ls")==0) && strcmp(newString[len-1],"&t\n")==0){
                    pthread_t id;
                    int rc;
                    if (len==2){
                        int rc=pthread_create(&id,NULL,(void *)(char*)ls_,newString[0]);
                        pthread_join(id,NULL);

                    }
                    else if (len==3){
                        // printf("%s\n",newString[1]);
                        int rc=pthread_create(&id,NULL,(void *)(char*)ls_,newString[1]);
                        pthread_join(id,NULL);
                    }
                    else{
                        printf("Wrong input, enter a valid input\n");
                        printf("$ ");
                    }

            }
                else if ((strcmp(newString[0],"date\n")==0 || strcmp(newString[0],"date")==0) && strcmp(newString[len-1],"&t\n")==0){
                    pthread_t id;
                    int rc;
                    if (len==2){
                        int rc=pthread_create(&id,NULL,(void *)(char*)date_,newString[0]);
                        pthread_join(id,NULL);

                    }
                    else if (len==3){
                        // printf("%s\n",newString[1]);
                        int rc=pthread_create(&id,NULL,(void *)(char*)date_,newString[1]);
                        pthread_join(id,NULL);
                    }
                    else{
                        printf("Wrong input, enter a valid input\n");
                        printf("$ ");
                    }
                }
                else if ((strcmp(newString[0],"rm\n")==0 || strcmp(newString[0],"rm")==0)&& strcmp(newString[len-1],"&t\n")==0){
                    pthread_t id;
                    int rc;
                    if (len==2){
                        int rc=pthread_create(&id,NULL,(void *)(char*)rm_,newString[0]);
                        pthread_join(id,NULL);

                    }
                    else if (len==3){
                        // printf("%s\n",newString[1]);
                        int rc=pthread_create(&id,NULL,(void *)(char*)rm_,newString[1]);
                        pthread_join(id,NULL);
                    }
                    else if (len==4 && strcmp(newString[1],"-i")==0){
                        int rc=pthread_create(&id,NULL,(void *)(char*)rm_i,newString[2]);
                        pthread_join(id,NULL);
                    }
                    else if (len==4 && strcmp(newString[1],"-r")==0){
                        int rc=pthread_create(&id,NULL,(void *)(char*)rm_r,newString[2]);
                        pthread_join(id,NULL);
                    }
                    else{
                        printf("Wrong input, enter a valid input\n");
                        printf("$ ");
                    }
                }
                else if ((strcmp(newString[0],"cat\n")==0 || strcmp(newString[0],"cat")==0)&& strcmp(newString[len-1],"&t\n")==0){
                    pthread_t id;
                    int rc;
                    if (len==3){
                        int rc=pthread_create(&id,NULL,(void *)(char*)cat_,newString[1]);
                        pthread_join(id,NULL);

                    }
                    else if (len==4 && strcmp(newString[1],"-r")==0){
                        // printf("%s\n",newString[1]);
                        int rc=pthread_create(&id,NULL,(void *)(char*)cat_r,newString[2]);
                        pthread_join(id,NULL);
                    }
                    else if (len==4 && strcmp(newString[1],"-n")==0){
                        // printf("%s\n",newString[1]);
                        int rc=pthread_create(&id,NULL,(void *)(char*)cat_n,newString[2]);
                        pthread_join(id,NULL);
                    }
                    else{
                        printf("Wrong input, enter a valid input\n");
                        printf("$ ");
                    }
                }
                else if ((strcmp(newString[0],"mkdir\n")==0 || strcmp(newString[0],"mkdir")==0)&& strcmp(newString[len-1],"&t\n")==0){
                    pthread_t id;
                    int rc;
                    // if (len==2){
                    //     int rc=pthread_create(&id,NULL,(void *)(char*)mkdir_,newString[0]);
                    //     pthread_join(id,NULL);

                    // }

                    if (len==3){
                        // printf("%s\n",newString[1]);
                        int rc=pthread_create(&id,NULL,(void *)(char*)mkdir_,newString[1]);
                        pthread_join(id,NULL);
                    }
                    else if (strcmp(newString[1],"-v")==0){
                        for (int i=2;i<len-1;i++){
                            int rc=pthread_create(&id,NULL,(void *)(char*)mkdir_,newString[i]);
                            pthread_join(id,NULL);
                        }
                    }
                    // else if (len==5 && strcmp(newString[1],"-p")==0 && strcmp(newString[2],"-v")==0){
                    //     int rc=pthread_create(&id,NULL,(void *)(char*)mkdir_,newString[3]);
                    //     pthread_join(id,NULL);
                    // }
                    else{
                        printf("Wrong input, enter a valid input\n");
                        printf("$ ");
                    }
                }
                else if ((strcmp(newString[0],"pwd\n")==0 || strcmp(newString[0],"pwd")==0)&& strcmp(newString[len-1],"&t\n")==0){
                    pthread_t id;
                    int rc;
                    if (len==2){
                        int rc=pthread_create(&id,NULL,(void *)(char*)pwd_,newString[0]);
                        pthread_join(id,NULL);

                    }
                    else if (len==3){
                        // printf("%s\n",newString[1]);
                        int rc=pthread_create(&id,NULL,(void *)(char*)pwd_,newString[1]);
                        pthread_join(id,NULL);
                    }
                    else{
                        printf("Wrong input, enter a valid input\n");
                        printf("$ ");
                    }
                }
                else if ((strcmp(newString[0],"echo\n")==0 || strcmp(newString[0],"echo")==0)&& strcmp(newString[len-1],"&t\n")==0){
                    int temp=0;
                    if (strcmp(newString[1],"-e")!=0 && strcmp(newString[1],"-n")!=0){
                        for (int j=1;j<len-1;j++){

                                if (j==len-2){
                                    
                                    printf("%s ",newString[j]);
                                }
                                else{
                                    printf("%s ",newString[j]);
                                }
                            
                        }
                        
                    }
                    else if (strcmp(newString[1],"-e")==0){
                        temp=1;
                        
                            for (int j=2;j<len-1;j++){
                                if (newString[j][0]!='/' && newString[j][1]!='c')
                                     printf("%s ",newString[j]);
                                
                            }
                        
                    }
                    else if (strcmp(newString[1],"-n")==0){
                        temp=1;
                        for (int j=2;j<len-1;j++){
                            printf("%s ",newString[j]);
                        }
                    }
                    if (temp==1){
                        printf("\n");
                        printf("$ ");
                    }
                    else{
                        printf("$ ");
                    }
                    
                }


            else if(strcmp(newString[0],"cd\n")==0 || strcmp(newString[0],"cd")==0){
                    char *temp=newString[1];
                    if (temp!=NULL){
                        if(temp[0]=='-'){
                            if(strcmp(temp,"-L")==0 || strcmp(temp,"-L\n")==0){
                                temp=newString[2];
                                if (temp!=NULL){
                                    
                                    int st=chdir("..");
                                    printf("$ ");
                                    if(st==-1){
                                        printf("Error");
                                        printf("$ ");
                                    }
                                }
                                else{
                                    printf("Invalid input\n");
                                }
                            }else if (strcmp(temp,"--help\n")==0 || strcmp(temp,"--help")==0) {
                                cd_help();
                            }
                            else{
                                printf("Invalid input\n");
                            }
                        }else{
                            temp[strlen(temp)-1]='\0';
                            if(chdir(temp)==-1){
                                printf("error\n");
                            }
                        }
                    }
                    else{
                        if(chdir(getenv("HOME"))==-1){
                            printf("error\n");
                        }
                    }

                }
                else {
                    printf("wrong input,enter valid input\n");
                    printf("$ ");
                }

            
             
        }


    }
    
 
    return 0;
}