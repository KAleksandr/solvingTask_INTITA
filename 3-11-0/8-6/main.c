#include <stdio.h>
#define N 20
#define SIZE 7
typedef struct {
    char name[N];
    char city[N];
    unsigned place;
}Club;

void InputClubs(Club* club2018);
void printStruct(Club* cl);
void sortStruct(Club* clubs);//sort by place

int main()
{
    Club club2018[SIZE];// оголошуємо масив club2018 з SIZE структур типу Club
    InputClubs(club2018);//заповнюю масив структур з клавіатури;
    printStruct(club2018);//вивести отримані структури (дані про клуби) по черзі на екран;
    puts(" ");
    sortStruct(club2018);//сортування структури в порядку зростання значення поля place
    printStruct(club2018);//вивести на екран отримані структури (відсортовані в порядку зростання значення поля place)
    getchar();
    return 0;
}
//введення даних в структуру
void InputClubs(Club* club2018){
    for(int i=0; i <SIZE; i++){
        printf("Input name club[%i]: ",i+1);
        gets(club2018[i].name);
        printf("Input city: ");
        gets(club2018[i].city);
        fflush(stdin);
        printf("Input place: ");
        scanf("%i", &club2018[i].place);
        fflush(stdin);
    }
}
//виведення на екран структури
void printStruct(Club* cl){
    for(int i=0; i < SIZE; i++){
        printf("Name club: %s, city: %s, place: %d\n", cl[i].name,cl[i].city,cl[i].place);
    }
}
//sort by place  ( Selection sort )
void sortStruct(Club* clubs){
    Club tmp;
    for(int i =0; i < SIZE-1; i++){
        int least = i;
        for( int j = i +1; j < SIZE;j++)
            if(clubs[i].place > clubs[j].place)
               least = j;
        tmp = clubs[i];
        clubs[i] = clubs[least];
        clubs[least] = tmp;
    }
}
