#include <cstdio>
#include <cmath>
using namespace std;
double A,B,x0,x1;
int main() {
	//scanf("%lf%lf",&x0,&x1);
	int p,q;
	scanf("%d%d",&p,&q); x0=p/double(q);
	scanf("%d%d",&p,&q); x1=p/double(q);
	A=(3*x1-x0)/11;
	B=(10*x0-3*x1)/11;
	for(int i=2;i<31;i++){
		printf("%.12f\n",A*pow(4,i)+B*pow(1/3.0,i));
	}
	return 0;
}
