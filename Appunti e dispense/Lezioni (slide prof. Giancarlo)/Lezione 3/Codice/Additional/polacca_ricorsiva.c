#include <stdio.h>
#include <string.h>

char **buff;

int i=0;

char *solve(char *c,char *d)
{
 char *ch;
 
 ch = buff[i];

 switch (*ch)
 {
  case '+' : itoa(atoi(c)+atoi(d),c,10);
	  return(solve(c,buff[i+1]));
	  break;
  case '*' : itoa(atoi(c)*atoi(d),c,10);
	  return(solve(c,buff[i+1]));
	  break;
  case '-' : itoa(atoi(c)-atoi(d),c,10);
	  return(solve(c,buff[i+1]));break;
  case '/' : itoa(atoi(c)/atoi(d),c,10);
	  return(solve(c,buff[i+1]));break;
  default :  i++; return(ch);
 }
}

int main(int argc, char* argv[])
{
 char *ss;
 i=2;

 buff=&argv[1];
 
 i=2;
 ss=buff[i-2];

 while(i<argc)
 {
	 ss=solve(ss,buff[i-1]);
  ss=ss;
 }
 printf("%s\n",ss);
 
 return 0;
}