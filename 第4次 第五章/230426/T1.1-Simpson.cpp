//Method2 Simpson
#include <cstdio>
#include <cmath>
#include <chrono> //#include <ctime>
using namespace std;
using namespace std::chrono;
const double pi=3.1415926535897932;
double func(double _x){
	return 4.0/(1+_x*_x);
}
double calc(double h,int N){
	double result=0;
	result=0.5*(func(0)-func(1));
	for(int i=1;i<=N;i++)
		result+=2*func(2*h*i)+func(2*h*i-1);
	result*=((h*2)/3);
	return result;
}
int main() {
	int N; time_point<steady_clock> s,e;//clock_t s,e;
	printf("h=1/2N, input N: >>");
	scanf("%d",&N);
	double h=0.5/N,/*t,*/r;
	s=steady_clock::now();//s=clock();
	r=calc(h,N);
	e=steady_clock::now();//e=clock();
	printf("Result: %.15f\nError: %.15f\n",r,pi-r);
	//t=(double)(e-s)/CLOCKS_PER_SEC*1000;
	printf("Time(ms): %.3f",(e-s).count()/1000000.0);
	getchar();getchar();
	return 0;
}
