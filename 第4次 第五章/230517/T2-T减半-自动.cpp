//Method1 Trapezoid
#include <cstdio>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;
const double REAL=6.49393940226682915;
const int m=5;
double func(double _x){
	if(_x<1e-7) return 0;
	return _x*_x*_x/(exp(_x)-1)+pow(_x,-5.0)/(exp(1/_x)-1);
}
double calc(double _e){
	double _r1,_r2,_h=1; int _m=0,_iMax=1;
	_r2=(func(0)+func(1))/2;
	do{
		_m++; _h/=2; _r1=_r2; _r2=0;
		for(int _i=1;_i<=_iMax;_i++)
			_r2+=func((2*_i-1)*_h);
		_r2=_r1/2+_h*_r2; _iMax<<=1;
	}while(_m<m||abs((_r2-_r1)/_r2)>_e);
	printf("Stepsize: 2^-%d\n",_m);
	printf("Result: %.15f\nError: %.15f\n",_r2,REAL-_r2);
	return _r2;
}
int _main(int N) {
	time_point<steady_clock> s,e;
	printf("R-Error 10^-N, N=%d\n",N);
	s=steady_clock::now();
	calc(pow(10,-N));
	e=steady_clock::now();
	printf("Time(ms): %.3f\n\n",(e-s).count()/1000000.0);
	return 0;
}
int main(){
	for(int i=3;i<16;i+=3) _main(i);
	getchar(); getchar(); return 0;
}
