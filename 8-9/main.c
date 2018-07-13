#include <stdio.h>
#include <string.h>
#include<conio.h>

typedef struct{
    char name[50];
    char city[50];
    int place;
}Club;
void inputClub1(Club * club1, FILE *fb);////копіювання структур за допомогою покажчиків поля змінної
void printbin(FILE * fb);//виведення вмісту бінарного файлу  на екран;
void inputClub2(Club * club1, FILE *fb);//копіювання структур - за допомогою команди memcpy();
void inputClub3(Club * club1, FILE *fb);//шляхом звичайного переприсвоювання змінних структур.
int main()
{
    Club club1;
    FILE* fb;
    //виконання пунктів пп. 4-6,
    //---------------------------------
    fb = fopen("teams.dat", "ab");
    inputClub1(&club1, fb);
    fclose(fb);
    fb=fopen("teams.dat","rb");
    printbin(fb);
    fclose(fb);
    //виконання пункту 7 -а,
    //---------------------------------
    fb= fopen("teams.dat","ab");
    inputClub2(&club1,fb);
    fclose(fb);
    fb=fopen("teams.dat","rb");
    printbin(fb);
    fclose(fb);
    //виконання пункту 7 -б,
    //---------------------------------
    fb= fopen("teams.dat","ab");
    inputClub3(&club1,fb);
    fclose(fb);
    fb=fopen("teams.dat","rb");
    printbin(fb);
    fclose(fb);

    return 0;
}
//копіювання структур за допомогою покажчиків поля змінної
void inputClub1(Club * club1, FILE *fb){
    int exit=0;
    Club club2;
    Club *pclub1, *pclub2;
    pclub1 = club1;
    pclub2 = &club2;
    while(1){
        printf("Input name club: ");
        gets(pclub1->name);
        printf("Enter city club:");
        gets(pclub1->city);
        printf("Enter place: ");
        scanf("%d",&pclub1->place);
        strcpy(pclub2->name, pclub1->name);
        strcpy(pclub2->city, pclub1->city);
        pclub2->place=pclub1->place;
        fwrite(pclub2, sizeof(Club),1, fb);
        exit++;
        fflush(stdin);
        if(exit>=7){
            printf("For exit press key (q):\n");
            char c;
            c= getch();
            if(c=='q' || c=='Q')
                break;
        }
    }
    printf("Record data completed.");
}
//копіювання структур - за допомогою команди memcpy();
void inputClub2(Club * club1, FILE *fb){
    int exit=0;
    Club club2;
    Club *pclub1, *pclub2;
    pclub1 = club1;
    pclub2 = &club2;
    while(1){
        printf("Input name club: ");
        gets(pclub1->name);
        printf("Enter city club:");
        gets(pclub1->city);
        printf("Enter place: ");
        scanf("%d",&pclub1->place);
        memcpy(pclub2,pclub1,sizeof(Club));
        fwrite(pclub2, sizeof(Club),1, fb);
        exit++;
        fflush(stdin);
        if(exit>=7){
            printf("For exit press key (q):\n");
            char c;
            c= getch();
            if(c=='q' || c=='Q')
                break;
        }
    }
    printf("Record data completed.");
}
//шляхом звичайного переприсвоювання змінних структур.
void inputClub3(Club * club1, FILE *fb){
    int exit=0;
    Club club2;

    while(1){
        printf("Input name club: ");
        gets(club1->name);
        printf("Enter city club:");
        gets(club1->city);
        printf("Enter place: ");
        scanf("%d",&club1->place);
        club2 = *club1;//структура club1 побітово копіюється до структури club2
        fwrite(&club2, sizeof(Club),1, fb);//запис даних у файл
        exit++;
        fflush(stdin);
        if(exit>=7){//умова введення не менше 7-ми разів!
            printf("For exit press key (q):\n");
            char c;
            c= getch();
            if(c=='q' || c=='Q')
                break;
        }
    }
    printf("Record data completed.");
}
//виведення вмісту бінарного файлу  на екран;
void printbin(FILE * fb){
    Club club2, *pclub2;
    pclub2 = &club2;
    long int count;
    fseek(fb,sizeof(Club), SEEK_END);
    count = ftell(fb)/sizeof(Club);//визначаємо кількість записів в файлі
    rewind(fb);
    if(count){
        printf("\nReading..................................\n\n");
        while(count--){
            fread(pclub2,sizeof(Club), 1,fb);//зчитуємо дані в структуру
            printf("%s %s - %d\n", pclub2->name, pclub2->city, pclub2->place);//виводимо на екран
        }
        printf("\nReading is complete.\n");
    }
}
