//Method1 Trapezoid
#include <cstdio>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;
const double pi=3.1415926535897932;
double func(double _x){
	return 4.0/(1+_x*_x);
}
double calc(double h,int N){
	double result=0;
	result=func(0)+func(1);
	for(int i=1;i<N;i++)
		result+=2*func(h*i);
	result*=(h/2);
	return result;
}
int main() {
	int N; time_point<steady_clock> s,e;
	printf("h=1/N, input N: >>");
	scanf("%d",&N);
	double h=1.0/N,t,r;
	s=steady_clock::now();
	r=calc(h,N);
	e=steady_clock::now();
	printf("Result: %.15f\nError: %.15f\n",r,pi-r);
	printf("Time(ms): %.3f",(e-s).count()/1000000.0);
	getchar();getchar();
	return 0;
}
