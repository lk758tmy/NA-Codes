function y=pro2_f(n,x)
    z=legendre(n,x);
    y=z(1,:).*exp((x+1)./2);