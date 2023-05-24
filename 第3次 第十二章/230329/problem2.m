n=input("n=");
r=zeros(n+1,1);
for i=1:(n+1)
    r(i)=(i-0.5)*integral(@(x) pro2_f(i-1,x),-1,1);
end

x=0:0.0001:1;
y=0.*x;
for i=1:(n+1)
    z=legendre(i-1,2.*x-1);
    y=y+z(1,:)*r(i);
end

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