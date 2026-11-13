#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int mainz1() {
    setlocale(LC_ALL, "RUS");
    char name[50];
    char greeting[100];

    // Шаг 1: Приглашение к вводу
    puts("Пожалуйста, введите ваше имя: ");

    // Шаг 2: Считывание имени
    scanf("%49s", name);

    // Модификация 1.2: Перевод имени в верхний регистр
    for (int i = 0; name[i] != '\0'; i++) {
        name[i] = toupper((unsigned char)name[i]);
    }

    // Шаг 3: Формирование приветствия
    strcpy(greeting, "Привет, ");
    strcat(greeting, name);

    // Модификация 1.3: Дополнение восклицательными знаками до 40 символов
    while (strlen(greeting) < 40) {
        strcat(greeting, "!");
    }

    // Шаг 4: Вывод результата
    puts(greeting);

    return 0;
}

int mainz2() {
    setlocale(LC_ALL, "RUS");
    char name[50];
    int choice;

    printf("Введите имя: ");
    scanf("%49s", name);
    int len = strlen(name);

    printf("Выберите пункт (1-12): ");
    scanf("%d", &choice);

    printf("Результат: Привет, ");
    switch (choice) {
    case 1: // Удвоить последнюю букву
        printf("%s%c!", name, name[len - 1]);
        break;
    case 2: // 1-я строчная, остальные ЗАГЛАВНЫЕ
        printf("%c", tolower(name[0]));
        for (int i = 1; i < len; i++) printf("%c", toupper(name[i]));
        break;
    case 3: // Поменять 1-ю и 2-ю местами
        if (len > 1) {
            printf("%c%c", name[1], name[0]);
            for (int i = 2; i < len; i++) printf("%c", name[i]);
        }
        else printf("%s", name);
        break;
    case 4: // Подчеркивание перед последней буквой
        for (int i = 0; i < len - 1; i++) printf("%c", name[i]);
        printf("_%c", name[len - 1]);
        break;
    case 5: // Наоборот (Оля-Яло)
        for (int i = len - 1; i >= 0; i--) printf("%c", name[i]);
        break;
    case 6: // Исчезает 2-я буква
        printf("%c", name[0]);
        for (int i = 2; i < len; i++) printf("%c", name[i]);
        break;
    case 7: // Половина строчная, половина ЗАГЛАВНАЯ
        for (int i = 0; i < len / 2; i++) printf("%c", tolower(name[i]));
        for (int i = len / 2; i < len; i++) printf("%c", toupper(name[i]));
        break;
    case 8: // Первые 3 буквы и ...
        for (int i = 0; i < 3 && i < len; i++) printf("%c", name[i]);
        printf("...");
        break;
    case 9: // Пробел после каждой буквы
        for (int i = 0; i < len; i++) printf("%c ", name[i]);
        break;
    case 10: // Замена 'а' на '@'
        for (int i = 0; i < len; i++) {
            if (name[i] == 'а' || name[i] == 'А') printf("@");
            else printf("%c", name[i]);
        }
        break;
    case 11: // Предпоследняя буква на тире
        for (int i = 0; i < len; i++) {
            if (i == len - 2) printf("-");
            else printf("%c", name[i]);
        }
        break;
    case 12: // Утроить заглавную первую букву
        printf("%c%c%c", toupper(name[0]), toupper(name[0]), toupper(name[0]));
        for (int i = 1; i < len; i++) printf("%c", name[i]);
        break;
    default:
        printf("%s", name);
    }
    printf("!\n");
    return 0;
}

int mainz3() {
    setlocale(LC_ALL, "RUS");
    char str[256];
    int max_len = 0, cur_len = 0;
    int max_start = 0;

    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin); // Читает строку с пробелами

    int len = strlen(str);

    for (int i = 0; i <= len; i++) {
        // Если текущий символ не пробел и не конец строки
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
            cur_len++;
        }
        else {
            // Если слово закончилось, проверяем его длину
            if (cur_len > max_len) {
                max_len = cur_len;
                max_start = i - cur_len; // Запоминаем начало слова
            }
            cur_len = 0; // Сбрасываем счетчик для следующего слова
        }
    }

    printf("Самое длинное слово: ");
    for (int i = max_start; i < max_start + max_len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}

int main() {

    mainz1();
    mainz2();
    mainz3();

    return 0;
}