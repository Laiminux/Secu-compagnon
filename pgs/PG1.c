#include <stdlib.h>
#include <stdio.h>

int main(){
	int a,b;
	printf("entrez un premier nombre");
	scanf("%d",&a);
	printf("entrez un deuxieme nombre");
	scanf("%d",&b);
	int res;
	while(1){
		res = a%b;
		if(res==0){
			break;
		}
		a = b;
		b= res;
		
	}
	printf("%i",b);
	return 0;
}
