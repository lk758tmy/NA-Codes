#include <cstdio>
using namespace std;
int main() {
	float *pf = 0;
	unsigned int *pui = 0;
	pui=new(unsigned int);
	char input_c;
	while(1){
		*pui=0;
		//printf("33222222222211111111110000000000\n");
		printf("seeeeeeeeqqqqqqqqqqqqqqqqqqqqqqq\n");
		for(int i=31;i>-1;i--){
			scanf("%c",&input_c);
			while(input_c<'0' || input_c>'9'){
				scanf("%c",&input_c);
			}
			*pui+=(input_c-'0')<<i;
		}
		pf = (float *)pui;
		//printf("%d\n",*pui);
		printf("%.50f\n\n",*pf);
	}
	return 0;
}
