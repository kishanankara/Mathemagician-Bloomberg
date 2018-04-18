 //Problem        : Lannisters of Justice
//Language       : C
//Compiled Using : GCC
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void push(char);
char pop();
char peek();



char operator_stack[100]={'\0'};
int operator_counter=-1;



int preference(char symbol)
{

    if(symbol=='-') { return 4;}
    if(symbol=='/') { return 3;}
    if(symbol=='+') { return 2;}
    if(symbol=='*') { return 1;}
return 500;
}
void push(char element)
{
  operator_counter++;
  operator_stack[operator_counter]=element;
}

char pop()
{
  char ret=operator_stack[operator_counter];
  operator_counter--;
  return ret;
}

char peek()
{
  return operator_counter==-1? '\0': operator_stack[operator_counter];
}

int main() {

  char arr[100]={'2','+','3','*','2','4','/','6','-','2','/','3','\0'};
    arr[strlen(arr)]=':';
    int val;
    char operators[100]={};
    int parsed[100]={};
    int i=0;
    int row_counter=0;
    int temp_counter=0;
    int stack_counter=0;
    char s='+';
    char temp[100];


    while(i<strlen(arr))
    {
      if((arr[i]=='+' || arr[i]=='-' || arr[i]=='*' || arr[i]=='/' || arr[i]==':'))
      {

          val=atoi(temp);
          parsed[row_counter]=val;
          memset(temp,0,sizeof(temp));
          temp_counter=0;
          row_counter++;

      }
      else{
        temp[temp_counter]=arr[i];
        // printf("%c",arr[i]);
        temp_counter++;
      }
      i++;
    }

// int k;
// int size=sizeof(parsed)/sizeof(parsed[0]);
// printf("Printing operands now: ");
// for(k=0;k<size;k++)
// {
//   printf("%d,",parsed[k]);
// }
//
// printf("\n");
// printf("\n");



int output_array[100]={};
int final_counter=-1;
int output_counter=-1;

int x=0;
int counter;
      while(x<strlen(arr))
      {

        if ((arr[x]=='+' || arr[x]=='-' || arr[x]=='*' || arr[x]=='/' ))
        {

          int my_xclusivecounter=0;

          if(peek()!='\0')
              {
                char top='\0';
                top=peek();
                int while_counter=0;
                while((preference(arr[x])<=preference(peek())) )
                {

                  while_counter++;

                  if((peek()!='\0'))
                  {
                      counter=0;



                      char operand=pop();

                                switch(operand)
                                {
                                  case '-':
                                  {
                                    if(while_counter==1)
                                    {
                                    final_counter++;
                                    output_counter++;
                                    output_array[output_counter]=parsed[final_counter];
                                    }
                                    int element2= output_array[output_counter];
                                    output_array[output_counter]=0;
                                    output_counter--;
                                    int element1=output_array[output_counter];
                                    output_array[output_counter]=0;
                                    output_counter--;
                                    int result=element1-element2;
                                    output_counter++;
                                    output_array[output_counter]=result;


                                    break;
                                  }
                                  case '+':
                                  {
                                    if(while_counter==1)
                                    {
                                    final_counter++;
                                    output_counter++;
                                    output_array[output_counter]=parsed[final_counter];
                                    }
                                    int element2= output_array[output_counter];
                                    output_array[output_counter]=0;
                                    output_counter--;
                                    int element1=output_array[output_counter];
                                    output_array[output_counter]=0;
                                    output_counter--;
                                    int result=element1+element2;
                                    output_counter++;
                                    output_array[output_counter]=result;

                                    break;

                                  }
                                  case '/':
                                  {
                                    if(while_counter==1)
                                    {
                                    final_counter++;
                                    output_counter++;
                                    output_array[output_counter]=parsed[final_counter];
                                    }
                                    int element2= output_array[output_counter];
                                    output_array[output_counter]=0;
                                    output_counter--;
                                    int element1=output_array[output_counter];
                                    output_array[output_counter]=0;
                                    output_counter--;
                                    int result=element1/element2;
                                    output_counter++;
                                    output_array[output_counter]=result;
                                    break;
                                  }
                                  case '*':
                                  {
                                    if(while_counter==1)
                                    {
                                    final_counter++;
                                    output_counter++;
                                    output_array[output_counter]=parsed[final_counter];
                                    }
                                    int element2= output_array[output_counter];
                                    output_array[output_counter]=0;
                                    output_counter--;
                                    int element1=output_array[output_counter];
                                    output_array[output_counter]=0;
                                    output_counter--;
                                    int result=element1*element2;
                                    output_counter++;
                                    output_array[output_counter]=result;

                                    break;
                                  }

                                  default:break;
                                } //End of switch.
                }
                if(peek()=='\0')
                {
                  break;
                }
                if( peek()=='\0')
                {
                break;
                }
                if(preference(arr[i])< preference(peek()))
                {
                  break;
                }


              } //end while.

              if(preference(arr[x])>preference(top))
              {
                final_counter++;
                output_counter++;
                output_array[output_counter]=parsed[final_counter];

              }
                push(arr[x]);

              }

              if(peek()=='\0')
              {
                final_counter++;
                output_counter++;
                output_array[output_counter]=parsed[final_counter];
                    push(arr[x]);

              }

         }

         int while_counter=0;

         if(arr[x]==':')
         {
           while(peek()!='\0')
           {
             while_counter++;
             int operator=pop();
             switch(operator)
             {
               case '-':
               {
                 if(while_counter==1)
                 {
                 final_counter++;
                 output_counter++;
                 output_array[output_counter]=parsed[final_counter];
                 }
                 int element2= output_array[output_counter];
                 output_array[output_counter]=0;
                 output_counter--;
                 int element1=output_array[output_counter];
                 output_array[output_counter]=0;
                 output_counter--;
                 int result=element1-element2;
                 output_counter++;
                 output_array[output_counter]=result;


                 break;
               }
               case '+':
               {
                 if(while_counter==1)
                 {
                 final_counter++;
                 output_counter++;
                 output_array[output_counter]=parsed[final_counter];
                 }
                 int element2= output_array[output_counter];
                 output_array[output_counter]=0;
                 output_counter--;
                 int element1=output_array[output_counter];
                 output_array[output_counter]=0;
                 output_counter--;
                 int result=element1+element2;
                 output_counter++;
                 output_array[output_counter]=result;

                 break;

               }
               case '/':
               {
                 if(while_counter==1)
                 {
                 final_counter++;
                 output_counter++;
                 output_array[output_counter]=parsed[final_counter];
                 }
                 int element2= output_array[output_counter];
                 output_array[output_counter]=0;
                 output_counter--;
                 int element1=output_array[output_counter];
                 output_array[output_counter]=0;
                 output_counter--;
                 int result=element1/element2;
                 output_counter++;
                 output_array[output_counter]=result;
                 break;
               }
               case '*':
               {
                 if(while_counter==1)
                 {
                 final_counter++;
                 output_counter++;
                 output_array[output_counter]=parsed[final_counter];
                 }
                 int element2= output_array[output_counter];
                 output_array[output_counter]=0;
                 output_counter--;
                 int element1=output_array[output_counter];
                 output_array[output_counter]=0;
                 output_counter--;
                 int result=element1*element2;
                 output_counter++;
                 output_array[output_counter]=result;

                 break;
               }

               default:break;
             }
           }
         }

        x++;
      }





        printf("%d", output_array[0]);

    return 0;
}
