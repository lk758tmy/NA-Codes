//Method5 Guass-Legendre
#include <cstdio>
#include <cmath>
#include <chrono>
#define DB double
using namespace std;
using namespace std::chrono;
const double REAL=6.49393940226682915,sr3=1.0/sqrt(3);
double func(double _x){
	if(_x<1e-7) return 0;
	return _x*_x*_x/(exp(_x)-1)+pow(_x,-5.0)/(exp(1/_x)-1);
}
double calc(int _N,double _h){
	double _result=0,_h2=_h/2,_x;
	for(int i=1;i<=_N;i++){
		_x=(i-0.5)*_h;
		_result+=func(_x-_h2*sr3)+func(_x+_h2*sr3);
	}
	_result*=_h2;
	return _result;
}
int main() {
	int N; time_point<steady_clock> s,e; double r;
	printf("Stepsize=1/N, input N: >>");
	scanf("%d",&N);
	s=steady_clock::now();
	r=calc(N,1.0/N);
	e=steady_clock::now();
	printf("Result: %.15f\nError: %.15f\n",r,REAL-r);
	printf("Time(ms): %.3f",(e-s).count()/1000000.0);
	getchar();getchar();
	return 0;
}
