#include <cstdio>
#include <cmath>
using namespace std;
struct cplx{
	double real,imag;
	cplx(double _x=0,double _y=0){real=_x,imag=_y;}
} *w,*A0,*A1;
cplx operator + (cplx a,cplx b){
	return cplx(a.real+b.real,a.imag+b.imag);}
cplx operator - (cplx a,cplx b){
	return cplx(a.real-b.real,a.imag-b.imag);}
cplx operator * (cplx a,cplx b){
	return cplx(a.real*b.real-a.imag*b.imag,a.real*b.imag+a.imag*b.real);}
int n,N,N2;
int main(){ 
	printf("2^n points, input n:\n>>");
	scanf("%d",&n); N=1<<n; N2=N>>1;
	A0=(cplx*)malloc(N*sizeof(cplx));
	A1=(cplx*)malloc(N*sizeof(cplx));
	w=(cplx*)malloc(N2*sizeof(cplx));
	printf("Input %d datas:\n>>",N);
	double data;
	for(int i=0;i<N;i++){
		scanf("%lf",&data); A0[i]=cplx(data,0);
	}
	double tmpw=2*acos(-1)/N;
	for(int i=0;i<N2;i++) w[i]=cplx(cos(i*tmpw),-sin(i*tmpw));
	int j_M,k_M,tmp0,tmp1,tmp2; cplx *tmpA;
	for(int q=1;q<=n;q++){
		j_M=1<<(n-q); k_M=1<<(q-1);
		for(int j=0;j<j_M;j++) for(int k=0;k<k_M;k++){
			tmp0=(j<<q)+k; tmp1=(j<<(q-1))+k; tmp2=tmp1+N2;
			A1[tmp0]=A0[tmp1]+A0[tmp2];
			A1[tmp0+(1<<(q-1))]=(A0[tmp1]-A0[tmp2])*w[j<<(q-1)];
		}
		tmpA=A0; A0=A1; A1=tmpA;
	}
	printf("Result:\nNo. Real Imag\n");
	for(int i=0;i<N;i++)
		printf("%d %.6f %.6f\n",i,A0[i].real,A0[i].imag);
	getchar(); getchar();
	return 0;
}