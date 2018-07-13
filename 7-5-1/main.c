#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PersonInfo {

    char firstName[64];
    char lastName[128];
    unsigned age;
    unsigned number;
} PersonInfo;

/*
 Функция запрашивает у пользователя данные и пишет их подряд в два файла
*/
void createOnePerson(FILE *keys, FILE *values) {
    static long long id = 0;
    PersonKey pkey;
    PersonInfo pinfo;

    pkey.id = id++;
    //Так как все значения пишутся друг за другом, то текущее положение
    //указателя во втором файле будет позицией для новой записи
    pkey.offset = ftell(values);

    printf("Login: ");
    scanf("%63s", pkey.login);
    printf("Password: ");
    scanf("%63s", pkey.password);
    printf("Age: ");
    scanf("%d", &(pinfo.age));
    printf("First Name: ");
    scanf("%63s", pinfo.firstName);
    printf("Last Name: ");
    scanf("%127s", pinfo.lastName);

    fwrite(&pkey, sizeof(pkey), 1, keys);
    fwrite(&pinfo, sizeof(pinfo), 1, values);
}

void createPersons(FILE *keys, FILE *values) {
    char buffer[2];
    int repeat = 1;
    int counter = 0;//Количество элементов в файле
    //Резервируем место под запись числа элементов
    fwrite(&counter, sizeof(counter), 1, keys);
    printf("CREATE PERSONS\n");
    do {
        createOnePerson(keys, values);
        printf("\nYet another one? [y/n]");
        scanf("%1s", buffer);
        counter++;
        if (buffer[0] != 'y' && buffer[0] != 'Y') {
            repeat = 0;
        }
    } while(repeat);
    //Возвращаемся в начало и пишем количество созданных элементов
    rewind(keys);
    fwrite(&counter, sizeof(counter), 1, keys);
}


/*
 Функция открывает сразу два файла. Чтобы упростить задачу, возвращаем массив файлов.
*/
FILE** openFiles(const char *keysFilename, const char *valuesFilename) {
    FILE **files = (FILE**)malloc(sizeof(FILE*)*2);
    files[0] = fopen(keysFilename, "w+b");
    if (!files[0]) {
        return NULL;
    }
    files[1] = fopen(valuesFilename, "w+b");
    if (!files[1]) {
        fclose(files[0]);
        return NULL;
    }
    return files;
}

/*
 Две вспомогательные функции для вывода ключа и информации
*/
void printKey(PersonKey pk) {
    printf("%d. %s [%s]\n", (int)pk.id, pk.login, pk.password);
}

void printInfo(PersonInfo info) {
    printf("%d %s %s\n", info.age, info.firstName, info.lastName);
}

/*
 Функция по ключу (вернее, по его полю offset)
 достаёт нужное значение из второго файла
*/
PersonInfo readInfoByPersonKey(PersonKey pk, FILE *values) {
    PersonInfo out;
    rewind(values);
    fseek(values, pk.offset, SEEK_SET);
    fread(&out, sizeof(PersonInfo), 1, values);
    return out;
}

void getPersonsInfo(PersonKey *keys, FILE *values, int size) {
    int index;
    PersonInfo p;
    do {
    printf("Enter position of element. To exit print bad index: ");
    scanf("%d", &index);
        if (index < 0 || index >= size) {
            printf("Bad index");
            return;
        }
        p = readInfoByPersonKey(keys[index], values);
        printInfo(p);
    } while (1);
}

void main() {
    int size;
    int i;
    PersonKey *keys = NULL;
    FILE **files = openFiles("C:/c/keys.bin", "C:/c/values.bin");
    if (files == 0) {
        printf("Error opening files");
        goto FREE;
    }
    createPersons(files[0], files[1]);
    keys = readKeys(files[0], &size);

    for (i = 0; i < size; i++) {
        printKey(keys[i]);
    }

    getPersonsInfo(keys, files[1], size);

    fclose(files[0]);
    fclose(files[1]);
FREE:
    free(files);
    free(keys);
    _getch();
}
