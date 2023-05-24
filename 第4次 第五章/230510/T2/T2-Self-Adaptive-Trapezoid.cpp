//Method4 Trapezoid Self-Adaptive
#include <cstdio>
#include <cmath>
#include <chrono>
#define DB double
using namespace std;
using namespace std::chrono;
const double REAL=6.49393940226682915;
int depthMax=0;
double func(double _x){
	if(_x<1e-7) return 0;
	return _x*_x*_x/(exp(_x)-1)+pow(_x,-5.0)/(exp(1/_x)-1);
}
double backtrack(DB _s,DB _e,DB _fs,DB _fe,DB _err,DB _r,int depth){
	if(depth>depthMax) depthMax++;
	double _h=(_e-_s)/2,_mid=_s+_h,_fmid=func(_mid);
	double _r_left=_h*(_fs+_fmid)/2,_r_right=_h*(_fmid+_fe)/2;
	double _r_new=_r_left+_r_right;
	//printf("%d %.15f\n",depth,_r_new);
	if(abs(_r-_r_new)>_err){
		return backtrack(_s,_mid,_fs,_fmid,_err/2,_r_left,depth+1)
			+backtrack(_mid,_e,_fmid,_fe,_err/2,_r_right,depth+1);
	}else return _r_new;
}
int main() {
	int N; time_point<steady_clock> s,e; double r;
	printf("Error limit=10^-N, input N: >>");
	scanf("%d",&N);
	s=steady_clock::now();
	double fs=func(0),fe=func(1);
	r=backtrack(0,1,fs,fe,pow(10,-N),(fs+fe)/2,1);
	e=steady_clock::now();
	printf("Result: %.15f\nError: %.15f\n",r,REAL-r);
	printf("Max depth: %d\n",depthMax);
	printf("Time(ms): %.3f",(e-s).count()/1000000.0);
	getchar();getchar();
	return 0;
}
