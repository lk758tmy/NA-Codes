//Method2 Simpson
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
	double _r1=0,_r2=0,_P,_Q,_h=0.5; 
	int _m=1,_iMax=1;
	_P=(func(0)+func(1))/6; _Q=func(0.5)*2/3; _r2=_P+_Q;
	do{
		_m++; _iMax<<=1; _h/=2;
		_P=_P/2+_Q/4;
		_Q=0;		
		for(int _i=1;_i<=_iMax;_i++){
			_Q+=func((2*_i-1)*_h);
		}
		_Q*=(4.0/3*_h); _r1=_r2; _r2=_P+_Q;
	}while(_m<m||abs((_r2-_r1)/_r2)>_e);
	printf("Stepsize: 2^-%d\n",_m);
	printf("Result: %.17f\nError: %.17f\n",_r2,REAL-_r2);
	return _r2;
}
int _main(int N) {
	time_point<steady_clock> s,e;
	//printf("R-Error 10^-N, input N>>");
	//scanf("%d",&N);
	printf("R-Error 10^-N, N=%d\n",N);
	s=steady_clock::now();
	calc(pow(10,-N));
	e=steady_clock::now();
	printf("Time(ms): %.3f",(e-s).count()/1000000.0);
	printf("\n\n");
	//getchar(); getchar();
	return 0;
}
int main(){
	for(int N=3;N<16;N+=3) _main(N);
	getchar(); getchar();
	return 0;
}