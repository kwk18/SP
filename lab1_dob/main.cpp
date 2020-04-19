//
//  main.cpp
//  lab1_dob
//
//  Created by kosha on 16/02/2020.
//  Copyright © 2020 kosha. All rights reserved.
//
#include "mlisp.h"

double dd=18;
double mm=9;
double yyyy=1999;

double even__bits(double n);
double odd__bits(double n);
double bit__count(double n);
double report__results(double n);

double even__bits(double n){
    return (n == 0) ? 1  :
    (remainder(n, 2) == 0) ? even__bits(quotient(n, 2))  :
    true ? odd__bits(quotient(n, 2)) :
    _infinity;
}

double odd__bits(double n){
    return ((n == 0) ? 0  :
            ((remainder(n, 2) == 0) ? odd__bits(quotient(n, 2))  :
             even__bits(quotient(n, 2))));
}


double bit__count(double n) {
    return (n == 0 ? 0
            : remainder(n, 2) + bit__count(quotient(n, 2)));
}

double report__results(double n) {
    display("Happy birthday to you!\n\t");
    display(n);
    newline();
    display("\teven?\t");
    display((even__bits(n) == 1) ? "yes" : "no");
    newline();
    display("\todd?\t");
    display((odd__bits(n) == 1)? "yes" : "no");
    newline();
    display("bit__count = ");
    return bit__count(n);
}

int main() {
    display(report__results((dd * 1000000) + (mm * 10000) + yyyy));
    newline();
    std::cin.get();
    return 0;
}

