#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <math.h>
//gcc -o 1072 1072.c -lm
int main(int argc, char const *argv[])
{
	int num = 100451322;
	int count = 1;
	int calc = 0;
	printf("init number : %d\n", num);
	while(num >= 10){
		
		while(num >= (int)pow(10,count)){			
			count++;
		}		
		//printf("count %d\n", count);

		for(int i=0; i<count; i++){
			calc = (num % 10) + calc;
			//printf("clac : %d\n", calc);
			num = (int)num * 0.1;
			//printf("num : %d\n", num);
		}
		num = calc;
		//printf("resutl num : %d\n", num);
		//getchar();
		count = 1;
		calc = 0;

	}
	printf("result : %d\n", num);
	return 0;
}