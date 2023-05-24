//Method3 Romberg
#include <cstdio>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;
const double pi=3.1415926535897932;
double func(double _x){
	return 4.0/(1+_x*_x);
}
void calc(double _e){
	int i,j,_kMax; double _h=1;
	double *_A=(double*)malloc(15*sizeof(double));
	double *_B=(double*)malloc(15*sizeof(double)), *_tmp=0;
	_A[0]=(func(0)+func(1))/2;
	for(i=1;i<15;i++){
		_B[0]=0; _kMax=(1<<(i-1))+1;
		for(int k=1;k<_kMax;k++){
			_B[0]+=func(_h*(k-0.5));
		}
		_B[0]=((_B[0]*_h)+_A[0])/2;
		for(j=1;j<=i;j++){
			_B[j]=((2<<(2*j))*_B[j-1]-_A[j-1])/((2<<(2*j))-1);
			if(abs(_B[j]-_B[j-1])<_e) goto FINISH;
		}
		_tmp=_A; _A=_B; _B=_tmp; _h/=2.0;
	}
	printf("FAIL\n"); getchar(); exit(1);
	FINISH:
	printf("Result: %.15f\nError: %.15f\n",_B[j],pi-_B[j]);
	printf("Stepsize: 2^(-%d)\n",i);
	return ;
}
int main() {
	int N; time_point<steady_clock> s,e;
	printf("TOL = 10^-N, input N: >>");
	scanf("%d",&N);
	s=steady_clock::now();
	calc(pow(10,-N));
	e=steady_clock::now();
	printf("Time(ms): %.3f",(e-s).count()/1000000.0);
	getchar();getchar();
	return 0;
}
