#include <cstdio>
using namespace std;
int main() {
	float *pf = 0;
	unsigned int *pui = 0;
	pf=new(float);
	while(1){
		scanf("%f",pf);
		pui = (unsigned int *)pf;
		//printf("%d\n",*pui);
		for(int i=31;i>-1;i--)
			printf("%d",((*pui)>>i)%2);
		printf("\n\n");
	}
	return 0;
}
