#include <cstdio>
#include <cmath>
using namespace std;
struct cplx{
	double real,imag;
	cplx(double _x=0,double _y=0){real=_x,imag=_y;}
};
cplx operator + (cplx a,cplx b){return cplx(a.real+b.real,a.imag+b.imag);}
cplx operator - (cplx a,cplx b){return cplx(a.real-b.real,a.imag-b.imag);}
cplx operator * (cplx a,cplx b){
	return cplx(a.real*b.real-a.imag*b.imag,a.real*b.imag+a.imag*b.real);}
cplx* FFT(int n,cplx *data,cplx *w){ 
	int N=(1<<n),N2=(N>>1);
	cplx *result=(cplx*)malloc(N*sizeof(cplx));
	int j_M,k_M,tmp0,tmp1,tmp2; cplx *swap_tmp;
	for(int q=1;q<=n;q++){
		j_M=1<<(n-q); k_M=1<<(q-1);
		for(int j=0;j<j_M;j++) for(int k=0;k<k_M;k++){
			tmp0=(j<<q)+k; tmp1=(j<<(q-1))+k; tmp2=tmp1+N2;
			result[tmp0]=data[tmp1]+data[tmp2];
			result[tmp0+(1<<(q-1))]=(data[tmp1]-data[tmp2])*w[j<<(q-1)];
		}
		swap_tmp=data; data=result; result=swap_tmp;
	}
	return data;
}
int main(){
	int N,n,NN,N2,NB; double data_input;
	printf("N points. Input N >>"); scanf("%d",&N);
	n=1; while((1<<n)<(3*N-2)) n++;
	NN=(1<<n); N2=(NN>>1); NB=2*N-1;
	double tmpw=2*acos(-1)/N,tmpNw=2*acos(-1)/NN,tmpiw,tmpc,tmps;
	cplx *w=(cplx*)malloc(N*sizeof(cplx));
	cplx *iw=(cplx*)malloc(N*sizeof(cplx));
	cplx *Nw=(cplx*)malloc(N2*sizeof(cplx));
	cplx *Niw=(cplx*)malloc(N2*sizeof(cplx)),tmp_N=cplx(1.0/NN,0);
	for(int i=0;i<N;i++){
		tmpiw=i*tmpw; tmpc=cos(tmpiw); tmps=sin(tmpiw);
		w[i]=cplx(tmpc,-tmps); iw[i]=cplx(tmpc,tmps);
	}
	for(int i=0;i<N2;i++){
		tmpiw=i*tmpNw; tmpc=cos(tmpiw); tmps=sin(tmpiw);
		Nw[i]=cplx(tmpc,-tmps); Niw[i]=cplx(tmpc,tmps);
	}
	cplx *data=(cplx*)malloc(N*sizeof(cplx));
	printf("Input data:\n>>");
	for(int i=0;i<N;i++){
		scanf("%lf",&data_input); data[i]=cplx(data_input,0);}
	cplx *A=(cplx*)malloc(NN*sizeof(cplx));
	cplx *B=(cplx*)malloc(NN*sizeof(cplx));
	cplx *C=(cplx*)malloc(NN*sizeof(cplx));
	cplx *result=(cplx*)malloc(NN*sizeof(cplx));
	for(int i=N;i<NN;i++) A[i]=B[i]=0;
	for(int i=0;i<N;i++) A[i]=data[i]*iw[(i*(i-1)/2)%N];
	for(int i=0;i<NB;i++) B[i]=w[((NB-i-1)*(NB-i-2)/2)%N];
	A=FFT(n,A,Nw); B=FFT(n,B,Nw);
	for(int i=0;i<NN;i++) C[i]=A[i]*B[i];
	C=FFT(n,C,Niw); for(int i=0;i<NN;i++) C[i]=C[i]*tmp_N;
	for(int i=0;i<N;i++) result[i]=iw[(i*(i-1)/2)%N]*C[NB-i-1];
	printf("No. Real Imag\n");
	for(int i=0;i<N;i++)
		printf("%d %.4f %.4f\n",i,result[i].real,result[i].imag);
	getchar();getchar();
	return 0;
}