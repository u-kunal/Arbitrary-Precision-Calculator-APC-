#include "apc.h"
static const char* operators = "+-/xX";
int read_and_validations(data_t argc,char **argv)
{
    if(argc==4)
    {
        int i=0;
        if((argv[1][0]=='+')||(argv[1][0]=='-')){
            i=1;
        }
        else{
            i=0;
        }
        while(argv[1][i]){  
            if(!isdigit(argv[1][i])){
                    return FAILURE;
            }
            i++;
        }
        i=0;
        if((argv[3][0]=='+')||(argv[3][0]=='-')){
            i=1;
        }
        else{
            i=0;
        }
        while(argv[3][i]){
            if(!isdigit(argv[3][i])){
                return FAILURE;
            }
            i++;
        }
        i=0;
        if(strlen(argv[2])!=1){
            return FAILURE;
        }
        else{
            i=0;
            while(operators[i]){
                if(operators[i]==argv[2][0]){
                    return SUCCESS;
                }
                i++;
            }
            return FAILURE;
        }
        
        
    }
    return FAILURE;
}

