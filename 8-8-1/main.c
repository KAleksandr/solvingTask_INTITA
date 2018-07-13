#include <stdio.h>
#include <conio.h>
#define N 30
typedef struct
{
   char name [N];
   char city[N];
   int place;
}Club;

int main()
{
    int count=0;
    int k=1;
    Club myClub[7];
    Club *pmyClub = &myClub[0];
    FILE * file, *temp;

    file = fopen("teams.dat", "ab");
    /*
     * створити цикл, в якому по черзі (не менше 7-ми разів!):
     *- ввести з клавіатури значення полів змінної типу Club;
     *- записати введену структуру (дані про клуб) у файл teams.dat ;
     */
    /*
     *Спочатку реалізував запис в змінну типу Club і кожного разу після введення даних в структуру,
     * відбувався запис в файл.
     * Потім переробив на масив типу Club, і перший запис в файл, буде тільки після наповнення масиву(не менше 7-ми).
     * Таким чином відбувається спочатку запис семи даних типу CLUB - в одну команду одразу!
     * Наступні записи в файл: або користувач припине введення даних,
     *                         або по досягненню наповнення масиву структур
     */
    while(k++){

        printf("Enter the name of the team: ");
        gets(pmyClub[count].name);
        printf("Enter the city of the team: ");
        gets(pmyClub[count].city);
        printf("Enter the place in the team championship: ");
        scanf("%d", &pmyClub[count].place);
        fflush(stdin);
        count++;
        if(count==7 || k>7){//(не менше 7-ми разів!)
            if(count==7){
                fwrite(pmyClub, sizeof(Club), count, file);
                count=0;
            }
            printf("You want to continue? (y/n):");//умова завершення введення
            char c;
            c =getch();
            if(c == 'n'|| c =='N'){
                if(count >0)
                    fwrite(pmyClub, sizeof(Club), count, file);
                k=0;
            }
            getch();
        }

    }
    fclose(file);
    file=fopen("teams.dat", "rb");


//після закриття файлу – відкрити його в режимі читання  і прочитати з нього перші 3 структури ;
    fread(myClub, sizeof(Club), 3, file);
//прочитані дані записати у новий двійковий файл (наприклад, teams1.dat);
    temp = fopen("teams1.dat", "wb");
    fwrite(myClub, sizeof(Club), 3,temp);
    fclose(file);
    fclose(temp);
//новостворений файл відкрити в режимі читання,
//вміст його вивести на екран, переконатися в коректності перенесення даних з іншого файлу.
    temp = fopen("teams1.dat","rb");
    fread(myClub, sizeof(Club), 3, temp);
    for(int i=0; i<3; i++)
        printf("\nRezult: %s %s - %d", myClub[i].name,myClub[i].city,myClub[i].place);
    fclose(temp);
    return 0;
}
