#ifndef PARSER
#define PARSER


#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

static void Start(int &parse_index);
static void reject();
static void accept();
static void copy_input_expression();

void parser();

#endif
