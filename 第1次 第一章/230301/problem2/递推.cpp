#include <cstdio>
#include <cmath>
using namespace std;
double y[21];
int main() {
	y[0]=exp(1)-1;
	for(int i=1;i<21;i++){
		y[i]=exp(1)-i*y[i-1];
		printf("%.12f\n",y[i]);
	}
	return 0;
}
