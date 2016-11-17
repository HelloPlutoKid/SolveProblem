/*
   문제

   과학자 임문빈은 마법의 물약을 만든다. 임문빈은 많은 재료를 가지고 있고, 다음과 같은 식을 이용해서 만든다.

   S=N1×S1+...+Nk×Sk

   여기서 N1, ..., Nk는 1보다 크거나 같고, 9보다 작거나 같은 한 자리 숫자이고, S1, ..., Sk는 재료의 이름이다. 그리고, k는 1보다 크거나 같은 자연수이다. 마지막으로 S는 마법의 물약의 이름이다. 위의 식은 N1만큼 S1을 넣고, ..., Nk만큼 Sk를 넣으면 S가 1만큼 만들어 진다는 얘기와 같다.

   같은 물약을 만드는데 여러가지 재료법이 있을 수도 있다. 이 때는, 아무거나 사용하면 된다. 마법의 물약은 또 다른 물약을 만드는데 재료가 될 수도 있고, 이 중 어떤 재료는 시장에서 살 수 있다.

   임문빈은 이름이 LOVE인 마법의 물약을 만들려고 한다. (이 물약을 먹으면 임문빈을 사랑하게 된다) 시장에서 파는 재료와 그 가격이 주어지고, 임문빈이 만들 수 있는 모든 물약의 식이 주어진다. 이 때, LOVE를 1만큼 만드는데 드는 비용의 최솟값을 출력한다.
   입력

   첫째 줄에 시장에서 파는 재료의 개수 N과 임문빈이 만들 수 있는 물약의 식의 개수 M이 주어진다. 둘째 줄 부터 N개의 줄에는 시장에서 파는 재료의 이름과 그 가격이 공백으로 구분해서 주어진다. 재료의 이름은 오직 알파벳 대문자로만 이루어져 있고, 파는 재료는 중복되지 않는다. 그 다음 줄 부터 M개의 줄에는 물약의 식이 문제 상단과 같은 형식으로 주어진다. N은 50보다 작거나 같은 자연수이고, 재료의 이름의 길이는 최대 50이다. 가격은 100보다 작거나 같은 자연수이다. M은 50보다 작거나 같은 자연수 또는 0이다. 각 식의 길이도 최대 50이다.


   gcc -o 1050 1050.c 
   ./time ./1050 1050_num.txt

   result = 170;
   5 - WATER 2 , HONEY 6, HOP 6 ,TEST 1, GPPT 5 // 1 - 9
   4 - LOVE , BEER , LUT , TEPP // 1 - 99
   result = LOVE 


*/
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
	char phyChar[10][10] ={0,};
	char setChar[10][100] = {0,};
	char compareChar[10]={0,};

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
	int sum , mul ,temp = 0;
	while(!feof(fd)){
		data2=fgetc(fd);
		if(data2 != '\n'&& !feof(fd)){
			//if((data2 >= '0' && data2 <= '9')||(data2 >= 'A' && data2 <= 'Z')){
			setChar[i][j] = data2;			
			//printf("%c\n",setChar[i][j]);
			j++;
		}		
		else{
			//setChar[i][(strlen(setChar[i]))] = '\0';
			i++;
			j=0;
		}		
		}
		fclose(fd); //close fd
		int loop=0; // 3 + 2

		for(int i=0; i<strlen(setChar[0]); i++){
			if(setChar[0][i] != ' ') // 3 + 2
				loop = loop + (setChar[0][i]-'0'); // 5
		}
		for(int i=0; i<=loop; i++)
			printf("%s\n", setChar[i]); // print 1050_num.txt 

		setChar[loop+1][strlen(setChar[loop+1]) - 1] = '\0';
		printf("\n"); // \n

		/*j = 0; // setChar calc
		  for(int i=1; i<=(setChar[0][0]-'0'); i++){ //3 -> wather 2 honey 6 hop 9
		  sum = j = 0;
		  while(setChar[i][j] != ' '){
		  printf("%c : %d ",setChar[i][j],setChar[i][j]-'0');
		  sum = sum + (setChar[i][j] - '0');
		  j++;
		  }
		  printf(" sum = %d \n" , sum); // \n
		  }*/

		//printf(" (setChar[0][0]-'0')+2 %d\n", (setChar[0][0]-'0')+2);
		temp = sum = k = j = 0;
		for(int i = (setChar[0][0]-'0')+2; i <= loop; i++){ // out of LOVE 
			//memset(data, 0, sizeof(char) * 80); // init 
			k=0;
			//while(strlen(setChar[i]+1) != j){
			for(int j = 0; j<strlen(setChar[i]); j++){
				data[k++] = setChar[i][j];
				//printf("%c", setChar[i][j]);

				if(setChar[i][j] == '='){
					data[k-1] = '\0';
					printf("= : %s\n", data);
					sprintf(phyChar[loop-i],"%s",data);
					memset(data, 0, sizeof(char) * k); 
					sum = k = 0;
				}			
				else if(setChar[i][j] == '+'){
					data[k-1] = '\0';
					printf("+ %s\n", data);

					memset(compareChar, 0, sizeof(char) * strlen(compareChar)); // init 
					for(int i = 0; i < k; i++){
						compareChar[i] = data[i+1];
					}
					printf("%s\n",compareChar);
					for(int i = 1; i <= setChar[0][0]-'0'; i++){				
						if(!strncmp(setChar[i],compareChar,strlen(compareChar))){
							sum = sum + ((setChar[i][strlen(compareChar)+1])-'0') * (data[0] - '0');						
						}					
					}
					printf("%d\n",sum);

					memset(data, 0, sizeof(char) * k); 
					k=0;
				}
				else if(setChar[i][j] == '\0'){
					data[k-1] = '\0';
					printf("+ %s\n", data);
					k=0;
				}
				else{}

				//k++;
			}
			printf("last = %s\n", data);
			memset(compareChar, 0, sizeof(char) * strlen(compareChar)); // init 
			for(int i = 0; i < k; i++){
				compareChar[i] = data[i+1];
			}
			printf("%s\n",compareChar);
			for(int i = 1; i <= setChar[0][0]-'0'; i++){				
				if(!strncmp(setChar[i],compareChar,strlen(compareChar))){
					sum = sum + ((setChar[i][strlen(compareChar)+1])-'0') * (data[0] - '0');						
				}					
			}
			printf("%d\n",sum);
			sprintf(phyChar[loop-i],"%s %d",phyChar[loop - i],sum);
			j=0;
			printf("\n"); // \n
		}
		sum =0;	
		i =0;
		while(strlen(phyChar[i]) != 0){
			printf("phyChar : %s\n", phyChar[i]);
			i++;
		}
		temp = 0;
		sum = k = j = 0;
		memset(data, 0, sizeof(char) * 80); // init 
		int checkCompare = 1;
		for(int i = (setChar[0][0]-'0')+1; i <= (setChar[0][0]-'0')+1; i++){ // LOVE 
			while(strlen(setChar[i])+1 != j){
				data[k++] = setChar[i][j];
				//printf("%c", setChar[i][j]);

				if(setChar[i][j] == '='){
					memset(data, 0, sizeof(char) * k); // init 
					k=0;
				}
				else if(setChar[i][j] == '+' || (strlen(setChar[i])-1 == j)){
					if(setChar[i][j] == '+') data[k-1] = '\0';
					printf("%s\n",data);
					memset(compareChar, 0, sizeof(char) * strlen(compareChar)); // init 
					for(int i = 0; i < k; i++){
						compareChar[i] = data[i+1];
					}
					printf("compareChar : %s\n",compareChar);
					for(int i = 1; i <= setChar[0][0]-'0'; i++){				
						if(!strncmp(setChar[i],compareChar,strlen(compareChar))){
							sum = sum + ((setChar[i][strlen(compareChar)+1])-'0') * (data[0] - '0');
							checkCompare = 0;
						}					
					}
					printf("\n checkCompare %d \n ",checkCompare);
					if(checkCompare != 0){						
						while(strlen(phyChar[temp]) != 0){
							if(!strncmp(phyChar[temp],compareChar,strlen(compareChar))){
								printf("phrcharLen : %d phyChar : %s\n",strlen(phyChar[temp]), phyChar[temp]);
								for (int i = strlen(compareChar)+1; i < strlen(phyChar[temp]); i++)
								{								
									if(phyChar[temp][i]-'0' >= 0 && phyChar[temp][i]-'0' <= 9) 
										mul = (mul*10) + (phyChar[temp][i]-'0');
								}							
							}
							temp++;
						}
						sum = sum + mul * (data[0] - '0');
						printf("mul : %d\n", mul);	
						mul = temp = 0;
					}
					temp=0;
					checkCompare = 1;				
					printf("sum = %d\n",sum);
					memset(data, 0, sizeof(char) * k); // init 

					k=0;
				}
				else{}
				j++;
			}
		}
		printf("\n result : %d\n", sum);
		}

