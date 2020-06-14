//
//  lexer.h
//  
//
//  Created by kosha on 19/04/2020.
//

#ifndef lexer_h
#define lexer_h
//------------------------------------------------------------------------------------------------------------------------------------------------------------------//                 lexer.h 2020
#ifndef LEXER_H
#define LEXER_H
#include "baselexer.h"
//********************************************
//*        Developed by  xxx             *
//*             (c)  2020                    *
//********************************************
class tLexer:public tBaseLexer{
public:
    // ïåðñîíàëüíûé êîä ðàçðàáîò÷èêà ауе АУЕ
    std::string Authentication()const{
        return "xxx"
        +std::string("2020");}
    //êîíñòðóêòîð
    tLexer():tBaseLexer(){
        //ñîçäàòü àâòîìàòû:
        
        
        
        //  öåëîå Aint2
        addstr  (Aint,0,"+-", 2);
        addrange(Aint,2,'0','9',1);
        addrange(Aint,0,'0','9',1);
        addrange(Aint,1,'0','9',1);
        Aint.final(1);
        
        //________________________________________
        
        // âåùåñòâåííîå
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
        //________________________________________
        
        // èäåíòèôèêàòîð
        addrange(Aid,0,'a','z',1);
        addrange(Aid,0,'A','Z',1);
        addstr(Aid, 0, "!", 1);
        
        addstr(Aid, 1, "?", 3);
        addstr(Aid, 3, "-", 4);
        
        addstr(Aid, 0, "?", 2);
        addstr(Aid, 2, "?", 2);
        addstr(Aid, 2, "!", 1);
        addrange(Aid,2,'0','9',1);
        addrange(Aid,2,'a','z',1);
        addrange(Aid,2,'A','Z',1);
        addstr(Aid, 2, "-", 1);
        
        addrange(Aid,1,'a','z',1);
        addrange(Aid,1,'A','Z',1);
        addrange(Aid,1,'0','9',1);
        addstr(Aid, 1, "!", 1);
        addstr(Aid, 1, "-", 1);
        
        addstr(Aid, 1, "?", 2);
        
        
        Aid.final(1);
        
        //________________________________________
        
        // èäåíòèôèêàòîð ïðåäèêàòà
       addstr(Aidq,0,"-",2);
    addstr(Aidq,0,"!",2);
    addrange(Aidq,0,'a','z',2);
    addrange(Aidq,0,'A','Z',2);
 
    addstr(Aidq,0,"?",1);
 
    addstr(Aidq,2,"!",0);
    addrange(Aidq,2,'a','z',0);
    addrange(Aidq,2,'A','Z',0);
    addrange(Aidq,2,'0','9',0);
 
    addstr(Aidq,2,"?",1);
 
    addstr(Aidq,2,"-",3);
 
    addstr(Aidq,3,"!",0);
    addstr(Aidq,3,"-",0);
    addrange(Aidq,3,'a','z',0);
    addrange(Aidq,3,'A','Z',0);
    addrange(Aidq,3,'0','9',0);
    Aidq.final(1);
 
    }
};
#endif



