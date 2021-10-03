/*    In C Celciuc to Fahrenheit  */
#include<stdio.h>
int main()
{
    float celc, fahren;
    printf("enter temp ::: ");
    scanf("%f",&celc);
    fahren = celc*9/5+32;
    printf("in fahrenheit ::: %.2f",fahren);
    return 0;
}
