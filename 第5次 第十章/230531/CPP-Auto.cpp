#include <cstdio>
#define _USE_MATH_DEFINES //Use const M_PI_4 for pi/4
#include <cmath>
//#include <chrono>
using namespace std;
//using namespace std::chrono;
double func(double _t,double _y){
	return -(_y+1.0/_t)/_t-_y*_y;
}
double integ(int _m,int _N,double _s,double _e,double _0){
	double _y=_0,_h=(_e-_s)/_N,_t=_s;
	double _h2=_h/2,_h6=_h/6,_h4=_h/4,_h23=_h*2/3;
	double _f,_k1,_k2,_k3,_k4;
	switch(_m){
		case 1: //Euler方法
			for(int i=0;i<_N;i++,_t+=_h) _y=_y+_h*func(_t,_y);
			break;
		case 2: //改进的Euler方法
			for(int i=0;i<_N;i++){
				_f=func(_t,_y); _k1=_y+_h*_f;
				_t+=_h; _y=_y+_h2*(_f+func(_t,_k1));
			}
			break;
		case 3: //Heun公式
			for(int i=0;i<_N;i++,_t+=_h){
            	_f=func(_t,_y); _k1=_y+_h23*_f;
				_y=_y+_h4*(_f+3*func(_t+_h23,_k1));
			}
			break;
		case 4: //中点方法（变形的Euler方法）
			for(int i=0;i<_N;i++,_t+=_h){
            	_f=func(_t,_y); _k1=_y+_h2*_f;
				_y=_y+_h*func(_t+_h2,_k1);
			}
			break;
		case 5:	//四阶经典Runge-Kuta方法
			for(int i=0;i<_N;i++){
            	_k1=func(_t,_y); _k2=func(_t+_h2,_y+_h2*_k1);
				_k3=func(_t+_h2,_y+_h2*_k2); _t+=_h;
				_k4=func(_t,_y+_h*_k3);
				_y=_h6*(_k1+2*_k2+2*_k3+_k4)+_y;
			}
			break;
		default: //四阶Adams PECE方法
		;
	}
	return _y;
}
void output(int _m,int _N,double _t,double _e){
	switch(_m){
		case 1: printf("1 Euler Method\n"); break;
		case 2: printf("2 Improved Euler Method\n"); break;
		case 3: printf("3 Heun's Method \n"); break;
		case 4: printf("4 Midpoint Method\n"); break;
		case 5:	printf("5 Runge-Kutta 4th Order Method\n"); break;
		default: printf("0 Adams' PECE Method\n"); break;
	}
	printf("Stepsize=1/N N: %d\n",_N);
	//printf("Time(μs): %.3f\n",_t); 时间小于1μs
	printf("Error: %.15f\n",_e);
	printf(" digit 0.123456789012345\n\n");
	return ;
}
double ans(double _x){
	return -tan(log(_x)+M_PI_4)/_x;
}
int main() {
	double Real=ans(2),r;
	//time_point<steady_clock> s,e;
	for(int m=1;m<7;m++){
		for(int N=250;N<16001;N*=2){
			//s=steady_clock::now();
			r=integ(m,N,1,2,-1);
			//e=steady_clock::now();
			output(m,N,/*(e-s).count()/1000*/0,r-Real);
		}
	}
	return 0;
}
