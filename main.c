#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <dirent.h>

//Πρωτότυπα των συναρτήσεων που ορίζω παρακάτω
void  write_file(FILE * file_ptr);
void read_file(FILE * file_ptr);
void open_file();
void list_files();

int main(int argc, char **argv){ 
    
    //menu
    while(1){   
        puts("\n1.  List files");
        puts("2.  Change or read a file");
        puts("3.  Exit");
        char choice;
        scanf("%c", &choice);
        getchar();
        if (choice=='1')
           list_files();
        else if  (choice=='2')
            open_file();
        else if  (choice=='3')
            break;
        else 
            puts("choose among menu choices!!! \n");
    }
    
    //else puts("Πρέπει να επιλέξετε ανάμεσα σε r,w,a");
    return 0;
}

void list_files(){

    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
                    printf("%s\n", dir->d_name);
         closedir(d);
    }
//second way
//system("dir");
 }

void open_file(){
    FILE* my_file;
    char file_name[100];
    printf("Δώσε το όνομα του αρχείου : ");
    gets(file_name);
   
    puts("Για διάβασμα του αρχείου πληκτολογήστε 'r' για να δημιουργήσετε και να γράψετε πληκτρολογήστε 'w' για να προσθέσετε περιεχόμενο σε υπάρχων αρχείο 'a' \n");
    char r_w[2] ;
    scanf("%s" , r_w);
    getchar();//επειδή θα μείνει στο buffer ο χαρακτήρα νεας γραμμής
    my_file = fopen(file_name,  r_w);
     if (my_file==NULL){
        printf(" I cannt open file %s \n try again \n", file_name);
        exit(1);
    }
    if  (strcmp(r_w,"r")==0)
       read_file(my_file);
    else if (strcmp(r_w,"w")==0)
       write_file(my_file);
    else if (strcmp(r_w,"a")==0)
        write_file(my_file);  
   //second way
   //char coom [100]= "notepad ";
    //strcat(coom,file_name);
    //system(coom);
    return;
}

void  write_file(FILE * file_ptr){
    char str[100]; //εδώ θα αποθηκεύεται αυτό που διαβάζει από την consola η gets
    short lines=1;
    while(1){
        printf("Εισάγετε την %d γραμμή : ", lines);
        gets(str);
        if (strcmp(str,"end")== 0){
            printf("Now file is %d\n", fclose(file_ptr));
            break;
        }
        fputs(str, file_ptr );
        fputs("\n", file_ptr);
        lines++;
    }
}

void read_file(FILE * my_file){
    char str[100];
    while(1){
        fgets(str, sizeof(str), my_file); 
        if (feof(my_file))
            break; 
        printf("%s",str);
    }
    fclose(my_file);
}

