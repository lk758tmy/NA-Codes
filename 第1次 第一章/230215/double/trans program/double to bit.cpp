#define ullong unsigned long long
#include <cstdio>
using namespace std;
int main() {
	double *pf = 0;
	ullong *pui = 0;
	pf=new(double);
	while(1){
		scanf("%lf",pf);
		pui = (ullong *)pf;
		//printf("%lld %lf\n",*pui,*pf);
		for(int i=63;i>-1;i--)
			printf("%d",(ullong)((ullong)(*pui)>>i)%2);
		printf("\n\n");
	}
	return 0;
}
