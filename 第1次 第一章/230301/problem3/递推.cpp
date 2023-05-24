#include <cstdio>
using namespace std;
double x[21];
int main() {
	//scanf("%lf%lf",&x[0],&x[1]);
	int p,q;
	scanf("%d%d",&p,&q); x[0]=p/double(q);
	scanf("%d%d",&p,&q); x[1]=p/double(q);
	for(int i=2;i<31;i++){
		x[i]=13*x[i-1]/3-4*x[i-2]/3;
		printf("%.12f\n",x[i]);
	}
	return 0;
}
