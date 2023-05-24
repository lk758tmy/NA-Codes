//#include <cstdio>
//#include <ctime>
#include <random>
using namespace std;
double epsilon(double a, double b){
	return (a-b)/(a+b);
}
int main() {
	//srand(time(0))
	unsigned int *pui = new(unsigned int);
	float *pf = (float *)pui;
	*pf = 1.0;
	float a,b;
	double max_ep=-1.0;
	for(int i=0;i<4194304;i++){ //2^22
		//*pui+=(1<<12)*(rand()-);
		a=*pf;
		*pui+=1;
		b=*pf;
		//printf("%.30f\n",epsilon(b,a));
		max_ep=max(max_ep,epsilon(b,a));
		//*pui+=1;//*pui+=(1<<14);
	}
	printf("%.30f",max_ep);
	return 0;
}

