#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc,char **argv){
	// printf("%d",argc);
	// for (int i=0;i<argc;i++){
	// 	printf("%s\n",argv[i]);
	// }
	int flag=0;
	char print[1000];
	if (argc==1){
		flag=1;
		time_t tim;
		time(&tim);
		printf("current date&time: %s",ctime(&tim));
	}
	
	
	else if (argc==2){
		

		if (strcmp(argv[1],"--version\n")==0){
			flag=1;
			FILE *ptr=fopen("date_version.txt","r");
			while (fscanf(ptr,"%[^\n]\n",print)!=EOF){
				printf("%s\n",print);
			}
			fclose(ptr);
		}
		if (strcmp(argv[1],"-gmt\n")==0){
			flag=1;
			time_t tim;
			time(&tim);
			struct tm *gtm = gmtime(&tim);
			printf("Current date&time: ");
			printf("%d:%d:%d %d/%d/%d\n",gtm->tm_hour,gtm->tm_min,gtm->tm_sec,gtm->tm_mday,gtm->tm_mon+1,gtm->tm_year+1900);

		}
	}
	if (flag==0){
		printf("wrong input, enter a valid input\n");
	}
	printf("$ ");
	return 0;
}