/*
 * =====================================================================================
 *
 *       Filename:  PG3.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/03/22 10:05:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#import <stdio.h>
int main(){
	printf("\n entrez votre premier nombre : \n ");
	int first;
	scanf("%d",&first);
	printf("\n entrez votre second nombre : \n ");
	int second;
	scanf("%d",&second);
	printf("\n entrez votre opération: \n ");
	char c;
	scanf(" %c",&c);
	int res;
	switch(c){
			case '+' : res = first + second;
				break;
			case '-': res = first - second;
				break;
			case '/': res = first / second;
				break;
			case '*' : res = first * second;
				break;
			default:
				break;
	}
	printf("%d",res);
	return 0;
}
