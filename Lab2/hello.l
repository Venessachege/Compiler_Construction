/*count number of spaces between words */
%{
int a=0;
%}

%%
[ ] a++;
%%

main() {
/* call the rules */
yylex();
printf("\n Spaces= %d \n",a);
}