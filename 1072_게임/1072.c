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
	float game = 53;
	float win = 47;
	float percent = floorf(((win/game)+0.01)*100)/100;
	/*
	float val = 37.777779;
	float rounded_down = floorf(val * 100) / 100;   내림: 37.77 
	float nearest = roundf(val * 100) / 100;   반올림: 37.78 
	float rounded_up = ceilf(val * 100) / 100;       올림: 37.78 
	 */
	double x ;
	printf("%lf\n", percent);
	x = ((game * percent) - win)/(1-percent);
	printf("more win game %lf\n", x);
	printf("more win game %d\n", (int)x+1);

	printf("%lf \t %lf \n", win/game , (double)(win+(int)x+1)/(game+(int)x+1));
	return 0;
}