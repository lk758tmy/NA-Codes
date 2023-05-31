#include <cstdio>
#define _USE_MATH_DEFINES //Use const M_PI_4 for pi/4
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;
double func(double _t,double _y){
	return -(_y+1.0/_t)/_t-_y*_y;
}
double real(double _x){
	return -tan(log(_x)+M_PI_4)/_x;
}
int main() {
	int _N=100; double _s=1,_e=2,_0=-1;
	
	double _y=_0,_h=(_e-_s)/_N,_t=_s;
	double _h2=_h/2,_h6=_h/6,_h24=_h/24,_k1,_k2,_k3,_k4;
	double *_ff=(double*)malloc((_N+1)*sizeof(double));
	double *appr=(double*)malloc((_N+1)*sizeof(double));
	_ff[0]=func(_s,_0); appr[0]=_0;
	for(int i=0;i<3;i++){
        _k1=func(_t,_y); _k2=func(_t+_h2,_y+_h2*_k1);
		_k3=func(_t+_h2,_y+_h2*_k2); _t+=_h;
		_k4=func(_t,_y+_h*_k3);
		_y=_h6*(_k1+2*_k2+2*_k3+_k4)+_y;
		_ff[i+1]=func(_t,_y); appr[i+1]=_y; 
	}
	for(int i=3;i<_N;){
		_k1=_y+_h24*(55*_ff[i]-59*_ff[i-1]+37*_ff[i-2]-9*_ff[i-3]);
        _t+=_h;
		_y=_y+_h24*(9*func(_t,_k1)+19*_ff[i]-5*_ff[i-1]+_ff[i-2]);
        i++; _ff[i]=(func(_t,_y)); appr[i]=_y; 
    }
    printf("0.123456789012345\n");
    for(int i=0;i<=_N;i++){
		printf("%.15f %d\n",abs(appr[i]-real(_s+i*_h)),i);
	}
	printf("0.123456789012345\n"); getchar(); getchar();
	return 0;
}
