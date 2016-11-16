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
		if(data2 != '\n'){
			if(data2 == ' ' || feof(fd) ){
				printf("%s\n", setChar);
				arr3[j][k++] = atoi(setChar);
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
		else{
			arr3[j][k++] = atoi(setChar);
			setChar[0] = setChar[1] = '\0';
			i=0;
			j++;
			k = 0;
		}
	}
	fclose(fd); //close fd

	//printf("\n%d\n",arr3[0][1] );
	
	int loop;	
	for(int i = 0; i< arr3[0][1]+2; i++){
		for(int j = 0; j < arr3[0][2]; j++)
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
		for(int j =2; j < arr3[0][1]+2; j++){
			if(arr3[j][0] == temp)
			{
				for(check =0; check<arr3[0][2]; check++){
					printf(" arr3[1][%d] %d\n",check,arr3[1][check]);
					if(arr3[j][1] == arr3[1][check]){
						printf("arr3[%d][1] = %d \n ", j,arr3[j][1]);
						loop += 1;
						arr3[j][2] = 0;
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
	printf("Change\n");
	for(int i = 0; i<arr3[0][1]+2; i++){
		for(int j = 0; j < arr3[0][2]; j++)
		{
			printf("%d\t",arr3[i][j] );
		}
		printf("\n");
	}

	for(int i = 2; i< arr3[0][1]+2; i++) {

		if(arr1[arr3[i][0]] == 0){
			arr1[arr3[i][0]] = arr3[i][2];
		}
		else{
			if(arr1[arr3[i][0]] > arr3[i][2]) arr1[arr3[i][0]] = arr3[i][2];
		}

		for(int i = 1; i<=arr3[0][0]; i++) 
			printf("%d : %d\t", i ,arr1[i]);//check calc	
		printf("\n");
	}
	int sum = 0;
	printf("\ncalc\n");
	for(int i = 1; i<=arr3[0][0]; i++) {
		printf("%d : %d\t", i ,arr1[i]);
		sum += arr1[i];
	}
	printf("\nresult : %d\n", sum);
	
}

