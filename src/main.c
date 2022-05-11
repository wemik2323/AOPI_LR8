#include <stdio.h>

#include "funcs.h"

int main() {
    puts(
        "Курсовая работа по АОПИ, ИКПИ-14\n"
        "Авторы: Крылов Артём, Хохлов Тихон, Дунаев Владислав\n");

    void (*funcs[])() = {emul_1, emul_2, emul_3};
    while (1) {
        int n;
        puts(
            "Введите номер задания [1-3]:\n"
            "Для завершения работы введите 0");
        scanf("%d", &n);

        if (!n) break;
        funcs[n - 1]();
        puts("");
    }
    return 0;
}
