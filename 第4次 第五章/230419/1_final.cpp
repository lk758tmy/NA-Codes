//Method1 Trapezoid
#include <cstdio>
#include <cmath>
using namespace std;
double h,h2; int N;
double func_1(double _x){
	if(_x<1e-7) return 0;
	return _x*_x*_x/(exp(_x)-1);
}
double func_2(double _y){
	if(_y<1e-7) return 0;
	return pow(_y,-5.0)/(exp(1/_y)-1);
}
void calc(){
	double result=0,tmp,A=0,B;
	for(int i=1;i<=N;i++){
		tmp=h*i;
		B=(func_1(tmp)+func_2(tmp));
		result+=h2*(A+B);
		A=B;
	}
	printf("Result: %.12f",result);
	return ;
}
int main() {
	printf("h=1/N, input N: >>");
	scanf("%d",&N);
	h=1.0/N; h2=h/2;
	calc();
	return 0;
}
