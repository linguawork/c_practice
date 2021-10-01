/*
Название файла: hashtable2.c
2021 09 01
источник: https://benhoyt.com/writings/hash-table-in-c/

На сайте был представлен код линейного поиска
Я добавил библиотеки

Если в main менять ключи (имена) то при компиляции выдаст значение (которое привязано к
ключу)
Можно поиграться чтобы понять линейный поиск (он не будет быстрее чем бинарный так как
бинарный делит пополам и ищет, соответственно ищет быстрее в 2 раза)

в следующем файле hasht_binary_search.c можно посмотреть код бинарного поиска
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char* key;
    int value;
} item;

item* linear_search(item* items, size_t size, const char* key) {
    for (size_t i=0; i<size; i++) {
        if (strcmp(items[i].key, key) == 0) {
            return &items[i];
        }
    }
    return NULL;
}

int main(void) {
    item items[] = {
        {"foo", 10}, {"bar", 42}, {"bazz", 36}, {"buzz", 7},
        {"bob", 11}, {"jane", 100}, {"x", 200}};
    size_t num_items = sizeof(items) / sizeof(item);

    item* found = linear_search(items, num_items, "jane");
    if (!found) {
        return 1;
    }
    printf("linear_search: value of 'jane' is %d\n", found->value);
    return 0;
}
