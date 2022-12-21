
/****** Include Section *********/
#include "parser.h"
/****** Variables *********/
extern unsigned char exp[50];
int inp[50];

/****** Function Definitions *****/

void parser()
{
    // Debugging
    cout<<" \n ******* The Result of the Parser ********\n";
    cout<<"  The Result is : ";

    // copy the input expression to the local array
    copy_input_expression();

    // start parsing
    int parse_index=0;
    Start(parse_index);

}


static void accept()
{
    cout<<" Accept\n\n";
}
static void reject()
{
    cout<<" Reject\n\n";
}

static void copy_input_expression()
{
    // copying the 0s & 1s expression
    for(int i=0; i<50; ++i)
    {
        inp[i]=exp[i];
    }
}



/***

S ->  Idf Op S
S ->  Idf

S ->  10S | 1

***/

static void Start(int &parse_index)
{
    if(inp[parse_index]== 1)    // ->  1
    {
        parse_index++;
        if(inp[parse_index]==0)
        {
            // ->  10
            parse_index++;
            Start(parse_index);
            // ->  10S
        }
        else if(inp[parse_index]==2)
        {
            // -> 101
            accept();
        }
        else
        {
            // -> 11
            reject();
        }
    }
    else
    {
        reject();
    }
}

