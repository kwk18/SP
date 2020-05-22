/*  CHNA_2020   */
#include "mlisp.h"
double a = 3;
double b = 5;
double fun(double x);
double golden__section__search(double a, double b);
double golden__start(double a, double b);
double set1(double a, double b, double xa, double xb, double ya, double yb);
double set2(double a, double b, double xa, double xb, double ya, double yb);
double mphi = ((double)(3 + ( - sqrt(5))) / 2);
double __CHNA_2020__try(double a, double b, double xa, double ya, double xb, double yb);
bool close__enough_Q(double x, double y);
double tolerance = ((double)1 / 100000);
double xmin = 0;
//________________ 
double fun(double x){
x = (x + ( - ((double)27 / 28)));
return ((x + sin(((2 * x) + ( - ((double)pi / 4)))) + log((x + 1))) + ( - ((double)1 / 2)));
}
double golden__section__search(double a, double b){
{
double xmin = ((a <= b) ? golden__start(a, b) : (golden__start(b, a)));
newline();
return xmin;
}

}
double golden__start(double a, double b){
{
double xa = (a + (mphi * (b + ( - a))));
double xb = (b + ( - (mphi * (b + ( - a)))));

return __CHNA_2020__try(a, b, xa, fun(xa), xb, fun(xb));
}

}
double set1(double a, double b, double xa, double xb, double ya, double yb){
b = xb;
xb = xa;
yb = ya;
xa = (a + (mphi * (b + ( - a))));
return __CHNA_2020__try(a, b, xa, fun(xa), xb, yb);
}
double set2(double a, double b, double xa, double xb, double ya, double yb){
a = xa;
xa = xb;
ya = yb;
xb = (b + ( - (mphi * (b + ( - a)))));
return __CHNA_2020__try(a, b, xa, ya, xb, fun(xb));
}
double __CHNA_2020__try(double a, double b, double xa, double ya, double xb, double yb){
return (close__enough_Q(a, b) ? ((double)(a + b) / 2) : (display("+"), ((ya <= yb) ? set1(a, b, xa, xb, ya, yb) : (set2(a, b, xa, xb, ya, yb)))));
}
bool close__enough_Q(double x, double y){
return (abs((x + ( - y))) <= tolerance);
}
int main(){
xmin = golden__section__search(a, b);
display("interval=\t[");
display(a);
display(" , ");
display(b);
display("]\n");
display("xmin=\t\t");
 display(xmin); newline();
display("f(xmin)=\t");
 display(fun(xmin)); newline();
std::cin.get();
 return 0;
}

