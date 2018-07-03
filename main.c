#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//Ğñùôüôõğá ôùí óõíáñôŞóåùí ğïõ ïñßæù ğáñáêÜôù
void  write_file(FILE * file_ptr);
void read_file(FILE * file_ptr);

int main(int argc, char **argv)
{
    FILE* my_file;
    char file_name[100];
    printf("What is the filename : ");
    gets(file_name);
    puts("Want to read (r) or write (w) the file ");
    char r_w[2] ;
    scanf("%s" , r_w);
    getchar();//åğåéäŞ èá ìåßíåé óôï buffer ï ÷áñáêôŞñá íåáò ãñáììŞò
    my_file = fopen(file_name, r_w);
    if (my_file==NULL){
        printf("I cannt open file %s", file_name);
        exit(1);
        }
    if (strcmp(r_w,"r")==0){
        
        read_file(my_file);
    }
    if (strcmp(r_w,"w")==0){
      
        write_file(my_file);
    }
    return 0;
}

void  write_file(FILE * file_ptr){
    char str[100]; //åäş èá áğïèçêåıåôáé áõôü ğïõ äéáâÜæåé áğü ôçí consola ç gets
    short lines=1;
    while(1){
        printf("Enter %d line : ", lines);
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
