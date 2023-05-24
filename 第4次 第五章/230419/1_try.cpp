//Method1 Trapezoid
#include <cstdio>
#include <cmath>
using namespace std;
double h,h2; int N;
double func_1(double _x,int k){
	if(_x<1e-7) return 0;
	if(k==1) return _x*_x*_x/(exp(_x)-1);
	long long _n=1; double _r=1,_result=0;
	do{
		_r*=_x; _r/=_n;
		_result+=_r;
		_n++;
	}while(_r>h);
	_result=_x*_x*_x/_result;
	return _result;	
}
double func_2(double _y){
	if(_y<1e-7) return 0;
	return pow(_y,-5.0)/(exp(1/_y)-1);
}
void calc(){
	double result1=0,result2=0,tmp;
	double *funcValue11=(double*)malloc((N+1)*sizeof(double));
	double *funcValue12=(double*)malloc((N+1)*sizeof(double));
	double *funcValue2=(double*)malloc((N+1)*sizeof(double));
	funcValue11[0]=funcValue12[0]=funcValue2[0]=0;
	for(int i=1;i<=N;i++){
		tmp=h*i;
		funcValue11[i]=func_1(tmp,1);
		funcValue12[i]=func_1(tmp,2);
		funcValue2[i]=func_2(tmp);
		result1+=h2*(funcValue11[i]+funcValue11[i-1]);
		result2+=h2*(funcValue12[i]+funcValue12[i-1]);
		tmp=h2*(funcValue2[i]+funcValue2[i-1]);
		result1+=tmp; result2+=tmp;
	}
	for(int i=0;i<N;i++);
	printf("%.12f\n%.12f",result1,result2);
	return ;
}
int main() {
	printf("h=1/N, input N: >>");
	scanf("%d",&N);
	h=1.0/N; h2=h/2;
	calc();
	return 0;
}
