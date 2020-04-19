#include <iostream>
#include "mlisp.h"

double xmin= 0.;

double tolerance= 0.00001;
double mphi = (3. - sqrt(5.)) /2.;
double a = 3.;
double b = 5.;
double fun( double x ){
    x = x - 27./28.;
    return (x + sin(2*x - 0.25*pi) + log(x+1) - 0.5);
}


double golden__section__search(double a, double b);
double golden__start(double a,double b);
double _VVV_try(double a,double b,double xa,double ya,double xb,double yb);
bool close__enough_Q(double x,double y);

double golden__start(double a,double b){
    double xa;
    double xb;
    double ya;
    double yb;
    xa=a+mphi*(b-a);
    xb=b-mphi*(b-a);
    return _VVV_try(a,b,xa,fun(xa),xb,fun(xb));
}

double golden__section__search(double a, double b){
    (a<b)? xmin=golden__start(a,b) : xmin=golden__start(b,a);
    newline();
    return xmin;
}

bool close__enough_Q(double x, double y)
{{
    return (abs(x-y)<tolerance);
}}

double _VVV_try(double a,double b,double xa,double ya,double xb,double yb){
    return close__enough_Q(a,b)? ((a+b)*0.5):(
                                              display("+"),
                                              (ya<yb)?(
                                                       b=xb,
                                                       xb=xa,
                                                       yb=ya,
                                                       xa=a+mphi*(b-a),
                                                       _VVV_try(a,b,xa,fun(xa),xb,yb)
                                                       ):
                                              (
                                               a=xa,
                                               xa=xb,
                                               ya=yb,
                                               xb=b-mphi*(b-a),
                                               _VVV_try(a,b,xa,ya,xb,fun(xb))
                                               
                                               )
                                              );
}

int main(){
    xmin=golden__section__search(a,b);
    display("interval=\t[");
    display(a);
    display(" , ");
    display(b);
    display("]\n");
    display("xmin=\t\t");
    display(xmin);
    newline();
    display("f(xmin)=\t");
    display(fun(xmin));
    newline();
}
//++++++++++++++++++++++++++
// interval=    [3 , 5]
// xmin=        3.361231604454761
// f(xmin)=        2.357495721703149
