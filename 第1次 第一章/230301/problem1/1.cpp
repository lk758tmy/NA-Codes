#include <cstdio>
#include <utility>
#include <cmath>
#define Pii pair<int,int>
using namespace std;
double _calc(double _x,int _b){
	double _result=_x-sin(_x);
	if(_result/_x>0.5)
		return _result;
	//printf("d");
	double _tmp=(_x*_x*_x/6);
	double _epsilon=pow(10,-_b-1);
	int _cnt=3;
	_result=_tmp;
	while(abs(_tmp)>_epsilon){
		_tmp=(_tmp*_x*_x*(-1)/(_cnt+1)/(_cnt+2));
		_result+=_tmp;
		_cnt+=2;
	}
	return _result;
}
/* x-sin(x)=x-(x-x^3/3!+x^5/5!-...)
=x^3/3!-x^5/5!+x^7/7!-...
设x=a[0]a[1]...a[s].a[s+1]...a[n]
则最多丢失一位要求(x^n/n!)<5*10^(s-n) */
Pii _input(double *x){
	*x=0;
	int _a=0,_b=0;
	double _tmp=1;
	char _c=getchar();
	while(_c!='.'){
		(*x)*=10;
		(*x)+=(_c-'0');
		_a++;
		_c=getchar();
	}
	_c=getchar();
	while(_c>='0' && _c<='9'){
		_b++;
		_tmp/=10.0;
		//printf("%.6f ",((double)(_c-'0'))*_tmp);
		(*x)+=((double)(_c-'0'))*_tmp;
		//printf("%.6f\n",*x);
		_c=getchar();
	}
	return make_pair(_a,_b);
} 
int main() {
	Pii length;
	double x,r;
	length=_input(&x);
	//printf("%.6f",x);
	//printf("%d %d",length.first,length.second);
	r=_calc(x,length.second);
	printf("%.12f\n",r);
	return 0;
}
