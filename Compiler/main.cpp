#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;

#include "LexicalAnalizer/lexical_analizer.h"
#include "Parser/parser.h"


int main()
{
    lexical_analyzer();
    parser();

    return 0;
}

