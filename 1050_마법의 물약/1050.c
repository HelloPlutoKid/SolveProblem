#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
int main(int argc , char *argv[]){
	FILE *fd;
	int index;
	char data[80];
	char data2;
	char setChar[10][100] = {0,};
	
	int arr1[10]={0,};
	int arr2[100]={0,};
	

	if(argc < 2)
		printf("stderr, Check your file\n");

	if((fd = fopen(argv[1],"r"))== NULL)
		perror("Failed");
	else
		printf("File %s found\n",argv[1]);

	int i = 0;
	int j = 0;
	int k = 0;

	while(!feof(fd)){
		data2=fgetc(fd);
		if(data2 != '\n'){
			setChar[i][j++] = data2;
		}
		else{
			i++;
			j=0;
		}
	}
	int loop=0;
	for(int i=0; i<strlen(setChar[0]); i++){
		if(setChar[0][i] != ' ')
			loop = loop + (setChar[0][i]-'0');
	}
	for(int i=0; i<=loop; i++)
		printf("%s\n", setChar[i]);


	fclose(fd); //close fd

	//printf("\n%d\n",arr3[0][1] );
}

