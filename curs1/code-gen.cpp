/* $n27 */
#include "code-gen.h"
using namespace std;
int tCG::p01()
{ // S -> PROG
	string header = "/*  " + lex.Authentication() + "   */\n";
	header += "#include \"mlisp.h\"\n";
	header += declarations;
	header += "//________________ \n";
	S1->obj = header + S1->obj;
	return 0;
}
int tCG::p02()
{ //   PROG -> CALCS
	S1->obj = "int main(){\n" + S1->obj + "std::cin.get();\n return 0;\n}\n";
	return 0;
}
int tCG::p03()
{ //   PROG -> DEFS
	S1->obj += "int main(){\n"
			   " display(\"No calculations!\");newline();\n"
			   "std::cin.get();\nreturn 0;\n}\n";
	return 0;
}
int tCG::p04()
{ //   PROG -> DEFS CALCS
	S1->obj += "int main(){\n" + S2->obj + "std::cin.get();\n return 0;\n}\n";
	return 0;
}
int tCG::p05()
{ //      E -> $id
	S1->obj = decor(S1->name);
	return 0;
}
int tCG::p06()
{ //      E -> $int
	S1->obj = decor(S1->name);
	return 0;
}
int tCG::p07()
{ //      E -> $dec
	S1->obj = decor(S1->name);
	return 0;
}
int tCG::p08()
{ //      E -> ADD
	return 0;
}
int tCG::p09()
{ //      E -> SUB
	return 0;
}
int tCG::p10()
{ //      E -> DIV
	return 0;
}
int tCG::p11()
{ //      E -> MUL
	return 0;
}
int tCG::p12()
{ //      E -> COND
	return 0;
}
int tCG::p13()
{ //      E -> EASYLET
	return 0;
}
int tCG::p14()
{ //      E -> CPROC
	return 0;
}
int tCG::p15()
{ //    ADD -> HADD E )
	S1->obj += " + " + S2->obj + ")";
	return 0;
}
int tCG::p16()
{ //   HADD -> ( +
	S1->obj = "(";
	S1->count = 0;
	return 0;
}
int tCG::p17()
{ //   HADD -> HADD E
	if (S1->count != 0)
	{
		S1->obj += " + ";
	}
	S1->obj += S2->obj;
	S1->count++;
	return 0;
}
int tCG::p18()
{ //    SUB -> ( - E )
	S1->obj = "( - " + S3->obj + ")";
	return 0;
}
int tCG::p19()
{ //    DIV -> HDIV E )
	if (S1->count == 1)
	{
		S1->obj += "1 / " + S2->obj + ")";
	}
	else
		S1->obj += S2->obj + ")";
	return 0;
}
int tCG::p20()
{ //   HDIV -> ( /
	S1->obj = "((double)";
	S1->count = 1;
	return 0;
}
int tCG::p21()
{ //   HDIV -> HDIV E
	S1->obj += S2->obj + " / ";
	++S1->count;
	return 0;
}
int tCG::p22()
{ //    MUL -> HMUL E )
	S1->obj += " * " + S2->obj + ")";
	return 0;
}
int tCG::p23()
{ //   HMUL -> ( *
	S1->obj = "(";
	S1->count = 0;
	return 0;
}
int tCG::p24()
{ //   HMUL -> HMUL E
	if (S1->count != 0)
	{
		S1->obj += " * ";
	}
	S1->obj += S2->obj;
	S1->count++;
	return 0;
}
int tCG::p25()
{ //   COND -> HCOND ELSE )
	S1->obj += S2->obj + ")";
	return 0;
}
int tCG::p26()
{ //  HCOND -> ( cond
	S1->obj = "(";
	return 0;
}
int tCG::p27()
{ //  HCOND -> HCOND CLAUS
	S1->obj += S2->obj;
	return 0;
}
int tCG::p28()
{ //  CLAUS -> ( BOOL E )
	S1->obj = "" + S2->obj + " ? " + S3->obj + " : ";
	return 0;
}

int tCG::p29()
{ //   ELSE -> HELSE E )
	if (S1->count)
		S1->obj += ",";
	S1->obj += "(" + S2->obj;
	S1->obj += ")";
	return 0;
}
int tCG::p30()
{ //  HELSE -> ( else
	return 0;
}
int tCG::p31()
{ //  HELSE -> HELSE INTER
	if (S1->count)
		S1->obj += ",";
	S1->obj += S2->obj;
	++S1->count;
	return 0;
}
int tCG::p32()
{ //EASYLET -> HEASYL E )
	if (S1->count != 0)
		S1->obj += S2->obj + ";\n";
	S1->obj += S2->obj;
	++(S1->count);
	return 0;
}
int tCG::p33()
{ // HEASYL -> ( let ( )
	return 0;
}
int tCG::p34()
{ // HEASYL -> HEASYL INTER
	S1->obj += S2->obj + ", ";
	return 0;
}
int tCG::p35()
{ //    STR -> $str
	S1->obj = decor(S1->name);
	return 0;
}
int tCG::p36()
{ //  CPROC -> HCPROC )
	S1->obj = S1->obj + ")";
	return 0;
}
int tCG::p37()
{ // HCPROC -> ( $id
	S1->count = 0;
	S1->obj = decor(S2->name) + "(";
	return 0;
}
int tCG::p38()
{ // HCPROC -> HCPROC E
	if (S1->count != 0)
	{
		S1->obj += ", ";
	}
	S1->obj += S2->obj;
	S1->count++;
	return 0;
}
int tCG::p39()
{ //   BOOL -> $bool
	if (S1->name == "#t")
	{
		S1->obj = "true";
	}
	else if (S1->name == "#f")
	{
		S1->obj = "false";
	}
	return 0;
}
int tCG::p40()
{ //   BOOL -> $idq
	S1->obj = decor(S1->name);
	return 0;
}
int tCG::p41()
{ //   BOOL -> REL
	S1->obj = "(" + S1->obj + ")";
	return 0;
}
int tCG::p42()
{ //   BOOL -> ( not BOOL )
	S1->obj = "!(" + S3->obj + ")";
	return 0;
}
int tCG::p43()
{ //   BOOL -> CPRED
	S1->obj = S1->obj;
	return 0;
}
int tCG::p44()
{ //  CPRED -> HCPRED )
	S1->obj = S1->obj + ")";
	return 0;
}
int tCG::p45()
{ // HCPRED -> ( $idq
	S1->count = 0;
	S1->obj = decor(S2->name) + "(";
	return 0;
}
int tCG::p46()
{ // HCPRED -> HCPRED ARG
	if (S1->count != 0)
	{
		S1->obj += ", ";
	}
	S1->obj += S2->obj;
	S1->count++;
	return 0;
}
int tCG::p47()
{ //    ARG -> E
	return 0;
}
int tCG::p48()
{ //    ARG -> BOOL
	return 0;
}
int tCG::p49()
{ //    REL -> ( = E E )
	S1->obj = S3->obj + " == " + S4->obj;
	return 0;
}
int tCG::p50()
{ //    REL -> ( <= E E )
	S1->obj = S3->obj + " <= " + S4->obj;
	return 0;
}
int tCG::p51()
{ //    SET -> HSET E )
	S1->obj += S2->obj;
	return 0;
}
int tCG::p52()
{ //   HSET -> ( set! $id
	S1->obj = S3->name + " = ";
	S1->name = S3->name;
	return 0;
}
int tCG::p53()
{ //DISPSET -> ( display E )
	S1->obj = "display(" + S3->obj + ")";
	return 0;
}
int tCG::p54()
{ //DISPSET -> ( display BOOL )
	S1->obj = "display(" + S3->obj + ")";
	return 0;
}
int tCG::p55()
{ //DISPSET -> ( display STR )
	S1->obj = "display(" + S3->obj + ")";
	return 0;
}
int tCG::p56()
{ //DISPSET -> ( newline )
	S1->obj = "newline()";
	return 0;
}
int tCG::p57()
{ //DISPSET -> SET
	return 0;
}
int tCG::p58()
{ //  INTER -> DISPSET
	return 0;
}
int tCG::p59()
{ //  INTER -> E
	return 0;
}
int tCG::p60()
{ //  CALCS -> CALC
	return 0;
}
int tCG::p61()
{ //  CALCS -> CALCS CALC
	S1->obj += S2->obj;
	return 0;
}
int tCG::p62()
{ //   CALC -> E
	S1->obj = " display(" + S1->obj + "); newline();\n";
	return 0;
}
int tCG::p63()
{ //   CALC -> BOOL
	S1->obj = " display(" + S1->obj + "); newline();\n";
	return 0;
}
int tCG::p64()
{ //   CALC -> STR
	S1->obj = " display(" + S1->obj + "); newline();\n";
	return 0;
}
int tCG::p65()
{ //   CALC -> DISPSET
	S1->obj += ";\n";
	return 0;
}
int tCG::p66()
{ //   DEFS -> DEF
	return 0;
}
int tCG::p67()
{ //   DEFS -> DEFS DEF
	S1->obj += S2->obj;
	return 0;
}
int tCG::p68()
{ //    DEF -> PRED
	return 0;
}
int tCG::p69()
{ //    DEF -> VAR
	return 0;
}
int tCG::p70()
{ //    DEF -> PROC
	return 0;
}
int tCG::p71()
{ //   PRED -> HPRED BOOL )
	S1->obj += "return " + S2->obj + ";\n}\n";
	return 0;
}
int tCG::p72()
{ //  HPRED -> PDPAR )
	S1->obj += ")";
	declarations += S1->obj + ";\n";
	S1->obj += "{\n";
	return 0;
}
int tCG::p73()
{ //  PDPAR -> ( define ( $idq
	S1->obj = "bool " + decor(S4->name) + "(";
	S1->count = 0;
	return 0;
}
int tCG::p74()
{ //  PDPAR -> PDPAR $idq
	if (S1->count != 0)
	{
		S1->obj += ", ";
	}
	S1->obj += "bool " + decor(S2->name);
	S1->count++;
	return 0;
}
int tCG::p75()
{ //  PDPAR -> PDPAR $id
	if (S1->count)
		S1->obj += ", ";
	S1->obj += "double " + decor(S2->name);
	++(S1->count);
	return 0;
}
int tCG::p76()
{ //    VAR -> VARDCL E )
	S1->obj += " = " + S2->obj + ";\n";
	declarations += S1->obj;
	S1->obj = "";
	return 0;
}
int tCG::p77()
{ // VARDCL -> ( define $id
	S1->obj = "double " + decor(S3->name);
	return 0;
}
int tCG::p78()
{ //   PROC -> HPROC BLOCK )
	if (S1->count == 0)
	{
		S1->obj += "{\n";
	}
	S1->obj = S1->obj + S2->obj + "\n}\n";
	return 0;
}
int tCG::p79()
{ //   PROC -> HPROC E )
	if (S1->count == 0)
	{
		S1->obj += "{\n";
	}
	S1->obj += "return " + S2->obj + ";\n}\n";
	return 0;
}
int tCG::p80()
{ //  HPROC -> PCPAR )
	S1->obj += ")";
	S1->count = 0;
	declarations += S1->obj + ";\n";
	return 0;
}
int tCG::p81()
{ //  HPROC -> HPROC INTER
	if (S1->count == 0)
	{
		S1->obj += "{\n";
	}
	S1->obj += S2->obj + ";\n";
	S1->count++;
	return 0;
}
int tCG::p82()
{ //  PCPAR -> ( define ( $id
	S1->obj = "double " + decor(S4->name) + "(";
	S1->count = 0;
	return 0;
}
int tCG::p83()
{ //  PCPAR -> PCPAR $id
	if (S1->count)
		S1->obj += ", ";
	S1->obj += "double " + decor(S2->name);
	++(S1->count);
	return 0;
}
int tCG::p84()
{ //  BLOCK -> HBLOCK E )
	S1->obj = "{\n" + S1->obj + "return " + S2->obj + ";\n}\n";
	return 0;
}
int tCG::p85()
{ // HBLOCK -> BLVAR )
	return 0;
}
int tCG::p86()
{ // HBLOCK -> HBLOCK INTER
	S1->obj += S2->obj + ";\n";
	return 0;
}
int tCG::p87()
{ //  BLVAR -> ( let ( LOCDEF
	S1->obj = S4->obj;

	return 0;
}
int tCG::p88()
{ //  BLVAR -> BLVAR LOCDEF
	S1->obj += S2->obj + "\n";
	return 0;
}
int tCG::p89()
{ // LOCDEF -> ( $id E )
	S1->obj = "double " + decor(S2->name) + " = " + S3->obj + ";\n";
	return 0;
}
//_____________________
int tCG::p90() { return 0; }
int tCG::p91() { return 0; }
int tCG::p92() { return 0; }
int tCG::p93() { return 0; }
int tCG::p94() { return 0; }
int tCG::p95() { return 0; }
int tCG::p96() { return 0; }
int tCG::p97() { return 0; }
int tCG::p98() { return 0; }
int tCG::p99() { return 0; }
int tCG::p100() { return 0; }
int tCG::p101() { return 0; }
int tCG::p102() { return 0; }
int tCG::p103() { return 0; }
int tCG::p104() { return 0; }
int tCG::p105() { return 0; }
int tCG::p106() { return 0; }
int tCG::p107() { return 0; }
int tCG::p108() { return 0; }
int tCG::p109() { return 0; }
int tCG::p110() { return 0; }
