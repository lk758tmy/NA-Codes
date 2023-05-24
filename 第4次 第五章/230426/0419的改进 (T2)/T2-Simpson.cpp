//Method2 Simpson
#include <cstdio>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;
const double REAL=6.49393940226682915;
double func_1(double _x){
	if(_x<1e-7) return 0;
	return _x*_x*_x/(exp(_x)-1);
}
double func_2(double _y){
	if(_y<1e-7) return 0;
	return pow(_y,-5.0)/(exp(1/_y)-1);
}
double calc(double h,int N){
	double result=0,tmp1,tmp2;
	result=0.5*(func_1(0)+func_2(0)-func_1(1)-func_2(1));
	for(int i=1;i<=N;i++){
		tmp2=2*h*i; tmp1=tmp2-h;
		result+=2*(func_1(tmp1)+func_2(tmp1));
		result+=(func_1(tmp2)+func_2(tmp2));
	}
	result*=((h*2)/3);
	return result;
}
int main() {
	int N; time_point<steady_clock> s,e;
	printf("h=1/2N, input N: >>");
	scanf("%d",&N);
	double h=0.5/N,t,r;
	s=steady_clock::now();
	r=calc(h,N);
	e=steady_clock::now();
	printf("Result: %.15f\nError: %.15f\n",r,REAL-r);
	printf("Time(ms): %.3f",(e-s).count()/1000000.0);
	getchar(); getchar();
	return 0;
}
