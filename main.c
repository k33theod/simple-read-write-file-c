#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//��������� ��� ����������� ��� ����� ��������
void  write_file(FILE * file_ptr);
void read_file(FILE * file_ptr);

int main(int argc, char **argv)
{
	FILE* my_file;
    char file_name[100];
    printf("What is the filename : ");
    gets(file_name);
    puts("Want to read (1) or write (2) the file ");
    char r_w ;
    scanf("%c" , &r_w);
    getchar();//������ �� ������ ��� buffer � ��������� ���� �������
    if (r_w=='1'){
        my_file = fopen(file_name,"r");//��� �������� ������ �� ����� ������� �� � ���� ��� my_file ����� NULL
        read_file(my_file);
    }
    if (r_w=='2'){
        my_file = fopen(file_name,"w"); //��� ��� ����� ������� ��� �� my_file
        write_file(my_file);
    }
    return 0;
}

void  write_file(FILE * file_ptr){
    char str[100]; //��� �� ������������ ���� ��� �������� ��� ��� consola � gets
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