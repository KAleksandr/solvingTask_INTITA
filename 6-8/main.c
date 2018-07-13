#include <stdio.h>

int main(void)

{

    char s[80]={0};

    FILE *fp;

    fp = fopen ( "input.dat", "r" );
    if ( fp == NULL ) { // якщо файл не існує -
        printf("File is not found\n");
        return 0; // вихід з програми (функції main())
    }

    fscanf ( fp, "%s", s );

    printf ( "The word is read from the file - %s", s );
    fgets(s, 80, fp);
    printf ( "\nThe string is read from the file - %s", s );


    fclose ( fp );

    getchar();

}
