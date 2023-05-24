#define ullong unsigned long long
#include <cstdio>
using namespace std;
int main() {
	double *pf = 0;
	ullong *pui = 0;
	pui=new(ullong);
	char input_c;
	while(1){
		*pui=0;
		//printf("33222222222211111111110000000000\n");
		printf("seeeeeeeeeeeqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq\n");
		for(int i=63;i>-1;i--){
			scanf("%c",&input_c);
			while(input_c<'0' || input_c>'9'){
				scanf("%c",&input_c);
			}
			*pui+=(ullong)(((ullong)(input_c-'0'))<<i);
		}
		pf = (double *)pui;
		//printf("%d\n",*pui);
		printf("%.400f\n\n",*pf);
	}
	return 0;
}
