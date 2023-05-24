#include <cstdio>
#include <cmath>
using namespace std;
int n;
double _f(double _x){
	double _r=1;
	for(int i=0;i<n;i++) _r*=_x;
	_r*=exp(_x);
	return _r;
}
int main() {
	scanf("%d",&n);
	double len,start,end;
	scanf("%lf%lf%lf",&len,&start,&end);
	double x=start+len/2,S=0;
	while(x<end){
		S+=(_f(x)*len);
		x+=len;
	}
	printf("%.12f",S);
	return 0;
}
