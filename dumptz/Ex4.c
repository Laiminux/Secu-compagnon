#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char*argv[]) 
{
	if(argc == 2)
	{
			char buff[1];
			int id = open(argv[1], O_RDONLY);
			if( id > 0 )
			{
				int finf = lseek(id,0,SEEK_END);
				lseek(id,0,SEEK_SET);

				int cur=0;
				int numligne=1;
				printf("\n");
				printf("\t%d\t", numligne);
				while(cur<finf){  //tant que le nombre de caractères n'est pas égal ua nombre total de cractères du fichier
					ssize_t readSize = read(id, buff, 1);
					if(buff[0]=='\n')           //si le caractère lu est "\n" on retourne à la ligne et incrémente le nombre de lignes
					{
						numligne++;
						write(1, buff, readSize);
						ssize_t readSize = read(id, buff, 1);
						printf("\t%d\t", numligne);
					}
					write(1, buff, readSize);
					cur=lseek(id,0,SEEK_CUR);
				}
				close(id);
				printf("\n");
		}
	}else{
		int numligne=0;
		while(1){ //tant que l'utilisateur n'a pas effectué de CTRL+C l'application continue
			char buff[128];
			open(0, O_RDONLY);
			ssize_t readSize = read(0, buff, 128); //lecture du terminal et affichage ( pb de double affichage + num ligne pas au même niveau à régler)
			numligne++;
			printf("%d", numligne);
			write(1, buff, readSize);
			printf("\n");
		}
	}
	return 0;
}