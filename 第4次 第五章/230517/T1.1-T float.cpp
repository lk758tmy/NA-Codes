//Method1 Trapezoid
#include <cstdio>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;
const float pi=3.14159265358979323846;
float func(float _x){
	return 4.0/(1+_x*_x);
}
float calc(float h,int N){
	float result=0;
	result=func(0)+func(1);
	for(int i=1;i<N;i++)
		result+=2*func(h*i);
	result*=(h/2);
	return result;
}
int _main(int N) {
	time_point<steady_clock> s,e;
	printf("h=1/N, N=%d\n",N);
	float h=1.0/N,r;
	s=steady_clock::now();
	r=calc(h,N);
	e=steady_clock::now();
	printf("Result: %.19f\nError: %.19f\n",r,pi-r);
	printf("Time(ms): %.3f\n\n",(e-s).count()/1000000.0);
	return 0;
}
int main(){
	for(int n=10;n<1e9;n*=10) _main(n);
	return 0;
}