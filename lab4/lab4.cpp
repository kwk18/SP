#include <iostream>
#include <iomanip>
#include "fsm.h"
using namespace std;

int main()
{
    tFSM Adec;
    addstr(Adec,0,"+",0);
    addstr(Adec,0,"-",0);
    addrange(Adec,0,'0','9',1);
    addrange(Adec,1,'0','9',1);
    addstr(Adec,1,".",2);
    addrange(Adec,2,'0','9',3);
    addrange(Adec,3,'0','9',3);
    addstr(Adec,3,"e",4);
    addstr(Adec,3,"E",4);
    addstr(Adec,4,"+",4);
    addstr(Adec,4,"-",4);
    addrange(Adec,4,'0','9',5);
    addrange(Adec,5,'0','9',5);
    Adec.final(5);
    //......................
    Adec.final(2);
    //......................
    ///////////////////////
    cout << "*** xxx Adec "
    << "size=" << Adec.size()
    << " ***\n";
    cout << endl;
    
    while(true)
    {
        char input[81];
        cout << ">";
        cin.getline(input,81);
        if(!*input) break;
        int res = Adec.apply(input);
        cout << setw(res?res+1:0) << "^"
        << endl;
    }
    return 0;
}

