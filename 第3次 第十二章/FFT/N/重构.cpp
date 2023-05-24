#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
struct cplx{
	double real,imag;
	cplx(double x=0,double y=0){real=x,imag=y;}
};
cplx operator + (cplx a,cplx b){return cplx(a.real+b.real,a.imag+b.imag);}
cplx operator - (cplx a,cplx b){return cplx(a.real-b.real,a.imag-b.imag);}
cplx operator * (cplx a,cplx b){
	return cplx(a.real*b.real-a.imag*b.imag,a.real*b.imag+a.imag*b.real);}
cplx bar(cplx x){
	x.imag=(-x.imag); return x;
}//������ʵ��
cplx* FFT(int n,cplx *data,cplx *w){
	//n:��2^n���� data:���� w:FFT��IFFT���һ������
	int N=(1<<n),N1=(N>>1),jMax,kMax,tmp; cplx *swapTmp;
	cplx *rslt=(cplx*)malloc(N*sizeof(cplx));
	for(int q=1;q<=n;q++){
		jMax=1<<(n-q); kMax=1<<(q-1);
		for(int j=0;j<jMax;j++) for(int k=0;k<kMax;k++){
			tmp=(j<<(q-1))+k;//���ֵʹ����4�Σ�����ǰ�����Խ�ʡʱ��
			rslt[(j<<q)+k]=data[tmp]+data[tmp+N1];
			rslt[(j<<q)+k+(1<<(q-1))]=(data[tmp]-data[tmp+N1])*w[j<<(q-1)];
		}
		swapTmp=data; data=rslt; rslt=swapTmp;
	}
	return data;
}//2^n�����FFT
cplx* bluestein(int N,cplx *data){
	int n=1; while((1<<n)<(3*N-2)) n++;
	//����������Ҫ3N-2����Ҳ�С��3N-2����С��2���ݣ����С����㡱
	int N1=2*N-1,N2=(1<<n),N3=(N2>>1); //��Ҫ����������
	cplx *w=(cplx*)malloc(N*sizeof(cplx));
	cplx *Nw=(cplx*)malloc(N3*sizeof(cplx));
	cplx *Niw=(cplx*)malloc(N3*sizeof(cplx));
	//w���ڹ�����Ҫ������������У�Nw����FFT��Niw����IFFT
	double tmpw=2*acos(-1)/N,tmpNw=2*acos(-1)/N2;
	for(int i=0;i<N;i++) w[i]=cplx(cos(i*tmpw),sin(i*tmpw));
	for(int i=0;i<N3;i++){
		Nw[i]=cplx(cos(i*tmpNw),-sin(i*tmpNw));
		Niw[i]=bar(Nw[i]);
	}//������Ԥ������,�����Ǽ��㲿��
	
	cplx *A=(cplx*)malloc(N2*sizeof(cplx));
	cplx *B=(cplx*)malloc(N2*sizeof(cplx));
	cplx *C=(cplx*)malloc(N2*sizeof(cplx));
	for(int i=N;i<N2;i++) A[i]=B[i]=0; //�ȰѺ��������Ϊ0��ע��N1>N
	for(int i=0;i<N;i++) A[i]=data[i]*w[(i*(i-1)/2)%N];
	for(int i=0;i<N1;i++) B[i]=bar(w[((N1-i-1)*(N1-i-2)/2)%N]);
	A=FFT(n,A,Nw); B=FFT(n,B,Nw);
	for(int i=0;i<N2;i++) C[i]=A[i]*B[i];
	C=FFT(n,C,Niw);//Ϊ��FFT��IFFTʹ��ͬһ�ӳ���û�г�N
	cplx tmpDiv=cplx(1.0/N2,0);
	for(int i=0;i<N2;i++) C[i]=C[i]*tmpDiv; //������
	
	cplx *rslt=(cplx*)malloc(N*sizeof(cplx));
	for(int i=0;i<N;i++) rslt[i]=w[(i*(i-1)/2)%N]*C[N1-i-1];
	return rslt;
}
int main(){
	int N;
	printf("N points, input N >>"); scanf("%d",&N);
	cplx *data=(cplx*)malloc(N*sizeof(cplx));
	double dataInput;
	printf("Input %d real numbers >>",N);
	for(int i=0;i<N;i++){//��������
		scanf("%lf",&dataInput);
		data[i]=cplx(dataInput,0);
	}
	data=bluestein(N,data);//����
	printf("Ressult:\n");
	for(int i=0;i<N;i++)//�������
		printf("%d (%.4f)+(%.4f)i\n",i,data[i].real,data[i].imag);
	getchar();getchar();
	return 0;
}
