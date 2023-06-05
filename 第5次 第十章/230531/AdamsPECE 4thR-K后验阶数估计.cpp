#include <cstdio>
#define _USE_MATH_DEFINES //Use const M_PI_4 for pi/4
#include <cmath>
using namespace std;
double func(double _t,double _y){
	return -(_y+1.0/_t)/_t-_y*_y;
}
double integ_R(int _N,double _s,double _e,double _0){
	double _y=_0,_h=(_e-_s)/_N,_t=_s;
	double _h2=_h/2,_h6=_h/6,_k1,_k2,_k3,_k4;
	for(int i=0;i<_N;i++){
        _k1=func(_t,_y); _k2=func(_t+_h2,_y+_h2*_k1);
		_k3=func(_t+_h2,_y+_h2*_k2); _t+=_h;
		_k4=func(_t,_y+_h*_k3);
		_y=_h6*(_k1+2*_k2+2*_k3+_k4)+_y;
	}
	return _y;
}
double integ_A(int _N,double _s,double _e,double _0){
	double _y=_0,_h=(_e-_s)/_N,_t=_s;
	double _h2=_h/2,_h6=_h/6,_h24=_h/24;
	double _k1,_k2,_k3,_k4;
	double *_ff=(double*)malloc((_N+1)*sizeof(double));
	_ff[0]=func(_s,_0);
	for(int i=0;i<3;i++){
        _k1=func(_t,_y); _k2=func(_t+_h2,_y+_h2*_k1);
		_k3=func(_t+_h2,_y+_h2*_k2); _t+=_h;
		_k4=func(_t,_y+_h*_k3);
		_y=_h6*(_k1+2*_k2+2*_k3+_k4)+_y;
		_ff[i+1]=func(_t,_y);
	}
	for(int i=3;i<_N;){
		_k1=_y+_h24*(55*_ff[i]-59*_ff[i-1]+37*_ff[i-2]-9*_ff[i-3]);
        _t+=_h;
		_y=_y+_h24*(9*func(_t,_k1)+19*_ff[i]-5*_ff[i-1]+_ff[i-2]);
        i++; _ff[i]=(func(_t,_y));
    }
	return _y;
}
int main() {
	double Real=-tan(log(2)+M_PI_4)/2;
	double eA[20],eR[20],h[20],th;
	for(int i=0,N=500;i<20;i++,N+=500){
		h[i]=1.0/N;
		eA[i]=abs(Real-integ_A(N,1,2,-1));
		eR[i]=abs(Real-integ_R(N,1,2,-1));
	}
	printf("Admas R-K\n");
	for(int i=0;i<19;i++){
		th=1.0/log(h[i+1]/h[i]);
		printf("%.2f ",log(eA[i+1]/eA[i])*th);
		printf("%.2f\n",log(eR[i+1]/eR[i])*th);
	}
	getchar(); getchar();
	return 0;
}
