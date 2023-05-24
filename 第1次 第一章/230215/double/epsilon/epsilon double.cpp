#define ullong unsigned long long
#include <random>
using namespace std;
double epsilon(double a, double b){
	return (a-b)/(a+b);
}
int main() {
	ullong *pui = new(ullong);
	double *pf = (double *)pui;
	*pf = 1.0;
	double a,b,max_ep=-1.0;
	for(int i=0;i<1073741824;i++){ //2^30
		a=*pf;
		*pui+=1;
		b=*pf;
		max_ep=max(max_ep,epsilon(b,a));
		*pui+=((ullong)1<<20);
	}
	printf("%.30f",max_ep);
	return 0;
}