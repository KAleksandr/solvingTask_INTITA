#include <stdio.h>
#include<stdlib.h>
typedef struct {
    char name[50];
    char city[50];
    int score;
}Club;
void sortClub(Club *pmyClub, int size);//сортування за спаданням кількості очок клубів
int main()
{
    int n,hasRead = 3;
    printf("Input number (1...15): ");
    scanf("%i", &n);
    Club tmp;
    Club *myClub;
    //виділити динамічно пам’ять для масиву з n структур;
    myClub = (Club*) malloc(sizeof(Club)*n);
    Club *pmyClub, *ptmp;//покажчики на структури
    pmyClub = myClub;
    ptmp = &tmp;

    FILE *ft;
    ft = fopen("clubs.txt","r");
    if(ft==NULL){//перевірка відкриття файлу
        printf("File not found.");
        return 0;
    }
    int size=0;
    //прочитати у відповідний масив максимально можливу кількість
    //даних про клуби (якщо кількість клубів у файлі менше n);
    while (hasRead == 3 && size != n) {
        hasRead=fscanf(ft, "%s %s %i", pmyClub[size].name,pmyClub[size].city,&pmyClub[size].score);
        size++;
    }
    if(hasRead== -1)
        size--;
    fclose(ft);
    //size - кількість зчитаних елементів типу Club;

    //сортування
    sortClub(pmyClub,size);
    //перевірка сортування
    for(int i=0;i<size; i++){//перевірка відсортованих даних
        printf("%-12s %-15s - %3d\n",pmyClub[i].name,pmyClub[i].city, pmyClub[i].score);
    }

    FILE *fb = fopen("myClub.dat", "w+b");//відкриваємо бінарний файл на запис/читання
    fwrite(pmyClub, sizeof(Club),size,fb);
    free (myClub);//звільняємо місце в пам'яті виділеної для масиву.
    long int cl_size = ftell(fb)/sizeof(Club); //кількість записаних даних у файл
    //(можна було скористатися змінною size). Так званий контроль запису
    rewind(fb);//встановлює покажчик на початок файлу (потоку)


     int n_club;
    printf("\nInput club number in order of file: ");
    scanf("%i",&n_club);//ввести з клавіатури число n_club (номер клубу по порядку у файлі),

    // зчитування відбудеться тільки при умові
    if(n_club <= cl_size && n_club>0){
        fseek(fb,(long)sizeof(Club)*(n_club-1), SEEK_SET);
        fread(ptmp, sizeof(Club), 1, fb);
    }
    else{
        printf("There is no such record!!!");
        fclose(fb);
        return -1;
    }
    //контроль запису, вивід на екран шуканий запис
        printf("%-12s %-15s - %3d\n",ptmp->name,ptmp->city,ptmp->score);
    fclose(fb);
    return 0;
}
//сортування за спаданням кількості очок клубів
void sortClub(Club *pmyClub, int size)
{
    Club tmp;//з метою обміну структур місцями оголошую додаткову структуру
    int max;
    for(int i=0; i<size-1;i++){
        max=i;
        for(int j=i+1; j<size;j++){
            if(pmyClub[i].score < pmyClub[j].score)
                if(pmyClub[max].score< pmyClub[j].score)
                   max = j;
         }
        tmp=pmyClub[i];
        pmyClub[i]=pmyClub[max];
        pmyClub[max] = tmp;
    }
}
