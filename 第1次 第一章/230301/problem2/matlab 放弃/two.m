N=input('');
n=0;
while(n<=N)
    disp(integral(@(x)two_function(x,n),0,1));
    !disp(n);
    n=n+1;
end
