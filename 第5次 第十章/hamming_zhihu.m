function sys=hamming()
%{
程序功能：
1、Hamming预测-校正法求解常微分方程
2、y(n+1)=y(n)+h*f(xn,yn)
%}
  clc,clear,close all;
  x1=0;
  y1=1;
  x2=1;
  h=0.1;
  n=(x2-x1)/h;
  
  x=zeros(n+1,1);
  y=zeros(n+1,1);
  ya=zeros(n+1,1);
  yr=zeros(n+1,1);
  e=zeros(n+1,1);
  fr=zeros(n+1,1);
  
  x(1)=x1;
  y(1)=y1;
  yr(1)=y(1);
  e(1)=0;
  fr(1)=f(x(1),y(1));
  
  %采用四阶标准Runge-Kutta法求出发值 
  for i=1:3
      
      k1=f(x(i),y(i));
      k2=f(x(i)+0.5*h,y(i)+0.5*h*k1);
      k3=f(x(i)+0.5*h,y(i)+0.5*h*k2);
      k4=f(x(i)+h,y(i)+h*k3);
      y(i+1)=y(i)+h*(k1+2*k2+2*k3+k4)/6;
      x(i+1)=x(i)+h;     
      fr(i+1)=f(x(i+1),y(i+1));
      
      yr(i+1)=(1+2*x(i+1))^(0.5);
      e(i+1)=abs(yr(i+1)-y(i+1));
      
  end
  
  %Hamming预测-校正
  for j=4:n
      
      x(j+1)=x(j)+h;
      ya(j+1)=y(j-3)+4*h*(2*fr(j)-fr(j-1)+2*fr(j-2))/3;
      y(j+1)=(9*y(j)-y(j-2)+3*h*(f(x(j+1),ya(j+1))+2*fr(j)-fr(j-1)))/8;      
      fr(j+1)=f(x(j+1),y(j+1)); 
      
      yr(j+1)=(1+2*x(j+1))^(0.5);
      e(j+1)=abs(yr(j+1)-y(j+1));
  end
  
  sys(:,1)=x;
  sys(:,2)=y;
  sys(:,3)=yr;
  sys(:,4)=e;
  
  draw(x,y,yr);
      
  
end

function sys=f(x,y)

  sys=y-2*x/y;
  
end

function draw(x,y,yr)
    set(0,'defaultfigurecolor','w')
    plot(x, y, '-b', x, yr, '--r')
    xlabel('X')
    ylabel('Y')
    title('The Euler Solution Chart')
    grid on
end