/*  CHNA_2020   */
#include "mlisp.h"
double VARIANT = 27;
double LAST____DIGIT____OF____GROUP____NUMBER = 7;
double KINDS____OF____COINS = 4;
double cc(double amount, double kinds__of__coins);
double count__change(double amount, double kinds__of__coins);
double first__denomination(double kinds__of__coins);
double GR__AMOUNT();
//________________ 
double cc(double amount, double kinds__of__coins){
return ((amount == 0) ? 1 : !((0 <= amount)) ? 0 : (kinds__of__coins == 0) ? 0 : ((cc(amount, (kinds__of__coins + ( - 1))) + cc((amount + ( - first__denomination(kinds__of__coins))), kinds__of__coins))));
}
double count__change(double amount, double kinds__of__coins){
display("count__change for ");
display(amount);
display(" ");
display(kinds__of__coins);
display(" \t= ");
return (!((amount <= 0)) ? (!((kinds__of__coins <= 0)) ? (!((first__denomination(kinds__of__coins) <= 0)) ? cc(amount, kinds__of__coins) : (display("(improper parameter value) "), 0)) : (display("(improper parameter value) "), 0)) : (display("(improper parameter value) "), 0));
}
double first__denomination(double kinds__of__coins){
return ((kinds__of__coins == 1) ? 1 : (kinds__of__coins == 2) ? 3 : (kinds__of__coins == 3) ? 20 : (kinds__of__coins == 4) ? 25 : (0));
}
double GR__AMOUNT(){
return remainder(((100 * LAST____DIGIT____OF____GROUP____NUMBER) + VARIANT), 137);
}
int main(){
display("CHNA variant ");
display(VARIANT);
newline();
display("1__3__20__25");
newline();
display(count__change(100, KINDS____OF____COINS));
newline();
display(count__change(GR__AMOUNT(), KINDS____OF____COINS));
newline();
display(count__change(100, 100));
std::cin.get();
 return 0;
}

