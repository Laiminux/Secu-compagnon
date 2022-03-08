#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if (argc !=3) {
	    printf("usages : %s nom_fichier", argv[0]);  
        return (1);
    }

    int df, df2, cpt_effectif, cpt_effectif2; 
    char buf[100];
    df = open(argv[1], O_RDONLY); //ouverture du fichier à copier
    df2 = open(argv[2],  O_WRONLY | O_CREAT, 0644);   //écriture du fichier 2
    if (df < 0) {
	    printf ("erreur : %s n’a pu être ouvert", argv[1]);
        return (2);
    }
    if ( df2<0 ){
        printf("erreur : %s n’a pu être ouvert", argv[2]);
        return(2);
    }
    cpt_effectif = read(df, buf, 10); //lit le fichier
    cpt_effectif2 = write (df2, buf, cpt_effectif); //ecrit le contenu du fichier 1
    close (df); 
    close (df2);

    return 0;
}
