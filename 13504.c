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
	int arr1[10]={0,};
	int arr2[100]={0,};
	int arr4[100]={0,};
	int arr3[100][100] = {0,};

	if(argc < 2)
		printf("stderr, Check your file\n");

	if((fd = fopen(argv[1],"r"))== NULL)
		perror("Failed");
	else
		printf("File %s found\n",argv[1]);

	printf("%s",setChar );
	int i = 0;
	int j = 0;
	int k = 0;
	while(!feof(fd)){
		data2=fgetc(fd);
		if(data2 == ' ' || data2 == '\n' || feof(fd) ){
			//printf("%s\n", setChar);
			arr3[j][k++] = atoi(setChar);
			if(data2 == '\n'){ j++; k=0;}

			setChar[0] = setChar[1] = '\0';
			i=0;
			
		}
		else if(data2 >= '0' && data2 <= '9'){
			setChar[i]=data2;
			//sprintf(setChar,"%c",data2);
			//strcat(setChar2,setChar);
			i++;
			//setChar[2] = '\0';
			//strcat(setChar, data2);
			//printf("%c",data2);
		}
		else{

		}
	}
	fclose(fd);
	printf("\n%d\n",arr3[0][1] );
	int loop;	
	for(int i = 0; i< arr3[0][1]+2; i++){
		for(int j = 0; j < 3; j++)
		{
			printf("%d\t",arr3[i][j] );
		}
		printf("\n");
	}

	printf("\n");
	int temp=0;
	loop=0;
	int check = 0;
	for(int i = 0; i < arr3[0][2]; i++){
		temp = arr3[1][i];
		for(int j =3; j < arr3[0][1]; j++){
			if(arr3[j][0] == temp)
			{
				for(check =0; check<arr3[0][2]; check++){
					if(arr3[j][1] == arr3[1][check]){
						loop += 1;
					}
				}
				if(loop == 0){
					loop = arr3[j][1];
					arr3[j][0] = loop;
					arr3[j][1] = temp;
					loop = 0;
				}
				loop = 0;
			}
		}
	}

	for(int i = 0; i<arr3[0][1]+2; i++){
		for(int j = 0; j < 3; j++)
		{
			printf("%d\t",arr3[i][j] );
		}
		printf("\n");
	}


	
}

