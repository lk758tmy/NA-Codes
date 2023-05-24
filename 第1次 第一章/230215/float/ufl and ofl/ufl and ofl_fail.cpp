#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int i=0;
	float a=1.0,b=1.0,c;
	while(1){
		b=a*(1.0+pow(2.0,-i/1000000));
		if(b==a) break;
		c=a;
		a=b;
		i++;
	}
	//printf("%d ",i);
	printf("%.30f %.30f\n",a,c);
	return 0;
}
