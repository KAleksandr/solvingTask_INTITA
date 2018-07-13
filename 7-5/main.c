#include <stdio.h>
#define N 20
//Створюю свій тип даних Contact
typedef struct
{
    char firstName[N];
    char lastName[N];
    float age;
    unsigned number;
}Contact;

void createPerson(FILE* fcont);
void printInfo(FILE* info);
void revers(FILE* values);

int main()
{

    FILE *fcont =NULL;
    fcont= fopen("contacts.dat", "w+b");

    if(fcont ==NULL){
        printf("Error. File not opening.");
        return -1;
    }
    createPerson(fcont);//Вводимо і записуємо дані в файл
    printInfo(fcont);//перевіряю записані дані
    revers(fcont);//виконую реверс даних у файлі
    printInfo(fcont);
    fclose(fcont);
    return 0;
}
//фунція приймає дані і записує у файл
void createPerson(FILE* fcont){
    Contact pinfo;
    char buffer[2];
    int repeat = 1;
    int counter = 0;//Кількість елементів в файлі
    //Резервую місце для запису кількості елементів в файлі
    fwrite(&counter, sizeof(counter), 1, fcont);
    //freopen("c://persons.txt", "r",stdin);//зчитування з файлу данних, заміна введення з консолі
    printf("CREATE PERSONS\n");
    do {
        printf("First Name: ");
        scanf("%20s", pinfo.firstName);
        printf("Last Name: ");
        scanf("%20s", pinfo.lastName);
        printf("Age(Year.month): ");
        scanf("%f", &(pinfo.age));
        printf("Telephon: ");
        scanf("%6d", &(pinfo.number));
        fwrite(&pinfo, sizeof(pinfo), 1, fcont);
        getchar();
        printf("\nYet another one? [y/n]");//Запит на повторне введення даних
        scanf("%1s", buffer);
        counter++;
        if (buffer[0] != 'y' && buffer[0] != 'Y') {
            repeat = 0;
        }
    } while(repeat);
    //Повертаємось на початок і записуємо кількість створених контактів
    rewind(fcont);
    fwrite(&counter, sizeof(counter), 1, fcont);
}

//виведення на екран даних у файлі
void printInfo(FILE* fout) {
    Contact out;
    int countOut=0;
    rewind(fout);
    fread(&countOut, sizeof(int), 1,fout);//зчитування з файлу кількість записів
    printf("\nRead the file...");
    while (countOut--) {
        fread(&out, sizeof(Contact), 1, fout);
        printf("\nName: %-10s %-15s age: %-.4g tel: %i", out.firstName, out.lastName, out.age, out.number);
    }
    printf("\n");
}
/*
 * Організуйте “дзеркальну” перестановку записів - перший поміняти з останнім,
 * другий - з передостаннім і т.д. Результати перестановки записати в початковий двійковий файл
 */
void revers(FILE* values){
    int countOut=0;
    Contact Start, End;
    rewind(values);
    fread(&countOut, sizeof(int), 1,values);//зчитування з файлу кількість елементів
    for(int i=0; i <= countOut/2; i++){
        fseek(values,sizeof(int)+i*sizeof(Contact),SEEK_SET);
        fread(&Start,sizeof(Contact),1, values);
        fseek(values,(-(i+1)*sizeof(Contact)),SEEK_END);
        fread(&End, sizeof(Contact), 1, values);
        fseek(values,(-(i+1)*sizeof(Contact)),SEEK_END);
        fwrite(&Start, sizeof(Contact), 1, values);
        fseek(values,sizeof(int)+i*sizeof(Contact),SEEK_SET);
        fwrite(&End, sizeof(Contact), 1, values);
    }
    rewind(values);
    printf("\nReversing...\n");
}
