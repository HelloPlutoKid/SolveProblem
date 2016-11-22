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

	char setChar[2] = {0,};
	char *setChar2 = "";
	int calc=0;
	int sortArr[100]={0,};
	int arr4[100]={0,};
	int settingChar[100][100] = {0,};

	if(argc < 2)
		printf("stderr, Check your file\n");

	if((fd = fopen(argv[1],"r"))== NULL)
		perror("Failed");
	else
		printf("File %s found\n",argv[1]);

	int i,sum,temp = 0;
	int j = 0;
	int k = 0;
	while(!feof(fd)){
		data2=fgetc(fd);
		if(data2 == ' '){
			settingChar[i][j++] = temp;
			temp = 0;
		}
		else if(data2 != ' ' && data2 != '\n'){
			temp = temp * 10 + (data2 - '0');
		}
		else if(data2 == '\n'){
			settingChar[i][j]= temp;
			i++;
			temp = j = 0;
		}
		else if(feof(fd)){
			settingChar[i][j]= temp;
		}
	}
	fclose(fd); //close fd

/*	for (int i = 0; i <=6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d\t",settingChar[i][j]);
		}
		printf("\n");
	}*/
	temp = 0;
	printf("Test case %d\n",settingChar[0][0] );

	for(int i=1; i<=(settingChar[0][0])*2;i++){
		if((i % 2) == 1){
			printf("sequence %d\n", (int)(i+2)/2 );
		}
		else{
			for (int j = 0; j < settingChar[i-1][0]; j++)
			{	
				printf("temp : %d settingChar %d\n",temp , settingChar[i][j] );
				temp = temp | settingChar[i][j];
				//printf("%d\n", settingChar[i][j]);	
			}
			printf("result : %d\n", temp);		
		}
			temp = sum = 0;
	//printf("\n");
	}
	//printf("%d ^ %d  = %d\n",settingChar[2][0],settingChar[2][1],settingChar[2][0] ^settingChar[2][1]);
	//printf("\nresult : %d\n", sum);

}

