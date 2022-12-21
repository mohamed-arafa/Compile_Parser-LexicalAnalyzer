#include "lexical_analizer.h"
unsigned char exp[50];

void lexical_analyzer()
{
    string args;
    cout<<"enter the name of your file: ";
    cin>>args;
    ifstream fin(args);

    char ch, buffer[50];
    int buffer_index=0,k=0;
    if(!fin.is_open())
    {
        cout<<"error while opening the file\n";
        exit(0);
    }

    cout<<" ******* The output of the Analyser is *********\n";
    while(!fin.eof())
    {
        ch = fin.get();                 //read the next character.
        bool operator_flag =isOperator(ch);      //check if it's an operator.

        if(isalnum(ch)){                // check if it's an alphabet or a number.
            buffer[buffer_index++] = ch;
        }

        else if((ch == ' ' || ch == '\n') && (buffer_index != 0)){
            identifier_only(buffer, buffer_index, k);
        }
        else if( operator_flag==true && buffer_index!=0 ){
            identifier_operator(buffer,buffer_index,ch,k);
        }
        else if(operator_flag == true){
            operator_only(ch, k);
        }
    }
    fin.close();
    exp[k]=2;
    print_exp();
}


static bool isKeyword(char buffer[])
{
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                             "do","double","else","enum","extern","float","for","goto",
                             "if","int","long","register","return","short","signed",
                             "sizeof","static","struct","switch","typedef","union",
                             "unsigned","void","volatile","while"
                            };
    bool flag = 0;
    for(int i = 0; i < 32; ++i)
    {
        if(strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

static bool isOperator(char c)
{
    bool flag=false;
    char operators[] = "+-*/%=><!~|&^";
    for(int i = 0; i < 6; ++i)
    {
        if(c == operators[i])
        {
            flag = true;
            break;
        }
    }
    return flag;
}

static void operator_only(char ch, int &k)
{
    cout<<ch<<" is operator\n";
    exp[k]=0;
    k++;
}

static void identifier_only(char buffer[],int &buffer_index,int &k)
{
    buffer[buffer_index] ='\0';
    buffer_index = 0;

    if(isKeyword(buffer) == 1){
        cout<<buffer<<" is keyword\n";
    }
    else{
        cout<<buffer<<" is indentifier\n";
        exp[k]=1;
        k++;
    }
}

static void identifier_operator(char buffer[],int &j, char ch, int &k)
{
    buffer[j] = '\0';
    j = 0;

    if(isKeyword(buffer) == 1){
        cout<<buffer<<" is keyword\n";
    }
    else{
        cout<<buffer<<" is indentifier\n";
        exp[k]=1;
        k++;
    }

    cout<<ch<<" is operator\n";
    exp[k]=0;
    k++;

}


static void print_exp()
{
    cout<<" The Input Expression to The Parser: ";
    for(int i=0; exp[i]!=2; ++i)
    {
        ((int)exp[i])?cout<<"Idf"<<" ":cout<<"Op"<<" ";

    }
    cout<<"END_M";
}
