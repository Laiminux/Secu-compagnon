/*
 * =====================================================================================
 *
 *       Filename:  PG2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/02/22 14:39:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>

int main(){
	while(1){
		printf("\n Choisissez entre pierre ( p ), feuille ( f ) et ciseaux ( c ) : \n");
		char c;
		scanf("%c",&c);
		int x = rand()%3;
		char k; 
		switch(x){
			case 1 : k='f';
					break;
			case 2: k='p';
					break;
			case 0: k='c';
					break; 
		}
		if(c=='f'){
			switch(k){
			case 'f' : printf("draw \n");
                                        break;
                        case 'p': printf("win \n");
                                        break;
                        case 'c': printf("lose \n");
                                        break;

			}
		}
		else if(c=='p'){
                        switch(k){
                        case 'p' : printf("draw \n");
                                        break;
                        case 'c': printf("win \n");
                                        break;
                        case 'f': printf("lose \n");
                                        break;

                        }
                }
		else if(c=='c'){
                        switch(k){
                        case 'c' : printf("draw \n");
                                        break;
                        case 'f': printf("win \n");
                                        break;
                        case 'p': printf("lose \n");
                                        break;

                        }
                }


	}
	return 0;
}


