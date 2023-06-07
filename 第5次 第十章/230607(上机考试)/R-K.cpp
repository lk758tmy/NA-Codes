#include <cstdio>
#include <cmath>
#include <utility>
#define M(a,b) make_pair(a,b)
#define PDD pair<double,double>
using namespace std;
PDD func(double _x,PDD _y){
	double _y2=6*_y.first/_x/_x-2*_y.second/_x+5-_x*(6-7*_x);
	return M(_y.second,_y2);
}
PDD sum(PDD _a, PDD _b){
	return M(_a.first+_b.first,_a.second+_b.second);
}
PDD mul(double _a, PDD _b){
	return M(_a*_b.first,_a*_b.second);
}
PDD integ_R(int _N,double _s,double _e,PDD _0){
	PDD _y=_0,_k1,_k2,_k3,_k4;
	double _h=(_e-_s)/_N,_t=_s;
	double _h2=_h/2,_h6=_h/6;
	for(int i=0;i<_N;i++){
        _k1=func(_t,_y); _k2=func(_t+_h2,sum(_y,mul(_h2,_k1)));
		_k3=func(_t+_h2,sum(_y,mul(_h2,_k2))); _t+=_h;
		_k4=func(_t,sum(_y,mul(_h,_k3)));
		_y=sum(mul(_h6,(sum(sum(_k1,mul(2,_k2)),sum(mul(2,_k3),_k4)))),_y);
	}
	return _y;
}
int main() {
	double Real=4+4*log(2),_r,e[7];
	int N[7]={4,5,10,25,50,100,200};
	for(int i=0;i<7;i++){
		_r=integ_R(N[i],1,2,M(0.5,2)).first;
		e[i]=_r-Real;
		printf("Stepsize=1/%d\n",N[i]);
		printf("Result:%.15f\n",_r);
		printf("AError:%.15f\n",abs(e[i]));
		printf("RError:%.15f\n",abs(e[i]/Real));
		printf("       0.123456789012345\n\n");
	}
	printf("Order:\n");
	for(int i=0;i<6;i++)
		printf("%.2f ",log(e[i+1]/e[i])/log(double(N[i])/N[i+1]));
	getchar(); getchar();
	return 0;
}
