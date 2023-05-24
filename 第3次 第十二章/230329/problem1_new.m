n=input("n=");
r=zeros(n+1,1);
for i=1:(n+1)
    r(i)=integral(@(x) exp(x).*(x.^(i-1)),0,1);
end
r=invhilb(n+1)*r;
r=flip(r);

x=0:0.0001:1;
y=polyval(r,x);

figure(1)
plot(x,y,x,exp(x));
title('Result');
xlabel('x');
ylabel('y');
legend("Poly","Original","Location","north")

figure(2)
plot(x,y-exp(x));
title('Difference');
xlabel('x');
ylabel('y');