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
int _main(int N) {
	time_point<steady_clock> s,e; double r;
	printf("Stepsize=10^(-N), N=%d\n",N);
	N=pow(10,N);
	s=steady_clock::now();
	r=calc(N,1.0/N);
	e=steady_clock::now();
	printf("Result: %.17f\nError: %.17f\n",r,REAL-r);
	printf("Time(ms): %.3f\n\n",(e-s).count()/1000000.0);
	return 0;
}
int main(){
	_main(1); _main(2); _main(3); _main(5); _main(7);
	getchar();getchar(); return 0;
}