//Method2 Simpson
#include <cstdio>
#include <cmath>
using namespace std;
double h,h2,h6; int N;
double func_1(double _x){
	if(_x<1e-7) return 0;
	return _x*_x*_x/(exp(_x)-1);
}
double func_2(double _y){
	if(_y<1e-7) return 0;
	return pow(_y,-5.0)/(exp(1/_y)-1);
}
void calc(){
	double result=0,tmp,A=0,B,C;
	for(int i=1;i<=N;i++){
		tmp=h*i;
		B=(func_1(tmp-h2)+func_2(tmp-h2));
		C=(func_1(tmp)+func_2(tmp));
		result+=h6*(A+B*4+C);
		A=C;
	}
	for(int i=0;i<N;i++);
	printf("Result: %.12f",result);
	return ;
}
int main() {
	printf("h=1/N, input N: >>");
	scanf("%d",&N);
	h=1.0/N; h2=h/2; h6=h2/3;
	calc();
	return 0;
}
