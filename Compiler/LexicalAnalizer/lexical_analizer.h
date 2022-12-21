#ifndef ANALIZER
#define ANALIZER

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

static void print_exp();
static bool isOperator(char c);
static bool isKeyword(char buffer[]);
void lexical_analyzer();

static void identifier_only(char buffer[],int &j,int &k);
static void identifier_operator(char buffer[],int &j, char ch, int &k);
static void operator_only(char ch, int &k);

#endif
