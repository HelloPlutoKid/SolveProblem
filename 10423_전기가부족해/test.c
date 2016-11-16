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
	int arr1[10]={0,};
	int arr2[100]={0,};
	int arr4[100]={0,};
	int arr3[3][40] = {0,};

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
		if((i==0) && ((data2-'0')<0)){
			arr1[j++] = atoi(setChar);			
			k=0;
			printf(" arr 1 : %d setChar : %s \n",arr1[j-1],setChar );		
			setChar[0] = setChar[1] = setChar[2] = '\0';
		}
		else if((i == 1) && ((data2-'0')<0)){			
			arr4[j++] = atoi(setChar);

			arr2[j-1] = arr4[j-1];
			printf(" arr 4 : %d setChar : %s \n",arr4[j-1],setChar );		
			k=0;
			setChar[0] = setChar[1] = setChar[2] = '\0';			
		}
		else if((i >= 2) && ((data2-'0')<0)){			
			arr3[i-2][j++] = atoi(setChar);		
			printf(" arr 3 : %d setChar : %s \n",arr3[i-2][j-1] ,setChar );				
			k=0;
			setChar[0] = setChar[1] = setChar[2] = '\0';			
		}
		else{
			setChar[k++]=data2;
		}
		if(data2 == '\n' ){
			++i;
			j = 0;
			k=0;
			setChar[0] = setChar[1] = setChar[2] = '\0';
		}
		//fgets(data,80,fd);
		//printf("%c",data2);
	}
	for(int j = 0; j < 3; j++){
		printf("%d\t", arr2[j]);	
	}
	
	for(int i = 0; i < arr1[1]; i++){
		printf("\n");
		for(int j = 0; j < 3; j++){
			printf("%d\t", arr3[i][j]);
		}
	}

	int temp=0;
	for(int j = 0; j < 3; j++){
		printf("arr2 : %d\n", arr2[j]);
		for(int i = 0; i< arr1[1]; i++){
			if(arr3[i][0] == arr2[j]){
				printf("%d %d %d \n", arr3[i][0] , arr3[i][1] , arr2[j] );
				temp = arr3[i][0];
				arr3[i][0] = arr3[i][1];
				arr3[i][1] = temp;
			}
		}
	}
	printf("\n");
	for(int i = 0; i < 9; i++){
		printf("\n");
		for(int j = 0; j < 3; j++){
			printf("%d\t", arr3[i][j]);
		}
	}
	//for(int i=0; i< sizeof(arr3)/sizeof(int); i++)	

	fclose(fd);
}

