//Method1 Trapezoid
#include <cstdio>
#include <cmath>
using namespace std;
const double pi=3.1415926535897932;
double func(double _x){
	return _x*_x*(_x-1)*(_x-1)*(cos(pi*_x)+1);
}
double calc(int N){
	double result=0,h=1.0/N,Real=1.0/30;
	result=func(0)+func(1);
	for(int i=1;i<N;i++)
		result+=2*func(h*i);
	result*=(h/2);
	printf("%.15f\n",result);
	return abs(Real-result);
}
int main() {
	double a=calc(10),b;
	for(int N=20;N<101;N+=10){
		b=calc(N);
		printf("%.2f ",log(b/a)/log(double(N-10)/N));
		a=b;
	}
}
