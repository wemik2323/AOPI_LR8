#include "funcs.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

void emul(char *alphabet, char *string, int carriage_pos, int num_of_states,
          char **table) {
    int state = 1;

    for (int count = 0;; ++count) {
        // вывод строки
        printf("%2d %s\n", count, string);
        for (int i = 0; i < carriage_pos; ++i) printf(" ");
        printf("   %d\n", state);
        if (!state) break;

        // считывание символа и нужной клетки в таблице
        char symbol = string[carriage_pos];
        int symbol_index = 0;
        while (symbol != alphabet[symbol_index]) ++symbol_index;
        char *instruction = table[symbol_index * num_of_states + state - 1];

        // выполнение сожержимого клекти
        string[carriage_pos] = instruction[0];
        if (instruction[1] == '>')
            ++carriage_pos;
        else if (instruction[1] == '<')
            --carriage_pos;
        int new_state = 0;  // у Тихона больше 10 состояний :)
        for (int i = 1;; ++i) {
            char c = instruction[(int)strlen(instruction) - i];
            if (c < '0' || '9' < c) break;
            new_state += (c - 48) * (int)pow(10, i - 1);
        }
        state = new_state;
    }
}

void emul_1() {
    char s[] = " 11 111    ";
    char *t[] = {"1.2", "2>3", "1>3", "1>4", "1>5", "1<6", "XXX",
                 "XXX", "XXX", "XXX", "XXX", "XXX", "2>2", "1<7",
                 " >1", " <7", " >4", " >5", "1<6", " <6", " .0"};
    emul("12 ", s, 0, 7, t);
}

void emul_2() {
    char s[] = " 5-9 ";
    char *t[] = {"9<1", "0<2", "9<3", "0>4", "XXX", " >6",
                 "0<2", "1<2", "9<4", "1>4", "XXX", "XXX",
                 "1<2", "2<2", "1>4", "2>4", "XXX", "XXX",
                 "2<2", "3<2", "2>4", "3>4", "XXX", "XXX",
                 "3<2", "4<2", "3>4", "4>4", "XXX", "XXX",
                 "4<2", "5<2", "4>4", "5>4", "XXX", "XXX",
                 "5<2", "6<2", "5>4", "6>4", "XXX", "XXX",
                 "6<2", "7<2", "6>4", "7>4", "XXX", "XXX",
                 "7<2", "8<2", "7>4", "8>4", "XXX", "XXX",
                 "8<2", "9<2", "8>4", "9>4", " <6", "XXX",
                 "->5", "-<3", "XXX", "->1", " .5", " .5",
                 " <1", " >5", " >5", " >5", " .0", " >6"};
    // каретка всегда на последнем символе строки
    emul("0123456789- ", s, (int)strlen(s) - 1, 6, t);
}

void emul_3() {
    char s[] = "       ^111^ ";
    char *t[] = {"^.0", "^<5",  "^<4",  "^>6",  "^>0",  "1.0",  "^<7", "^<8", "^>10", "^>11", "^<12", "^<12", "^<13", "^>14",
                 "*.1", "1<2",  "1>3",  "1>2",  "^<5",  "XXX",  "XXX", "1<2", "1>9",  "XXX",  "*.7",  "1<12", "1<13", "1>14",
                 "*<7", "*>3",  "*>2",  "^<4",  "^<5",  "XXX",  "*<7", "XXX", "XXX",  "XXX",  "*>11", "*<12", "XXX",  "*.2",
                 "XXX", " .9",  "XXX",  "XXX",  "XXX",  "XXX",  " <8", "^<9", "1>9",  " >10", "XXX",  " <13", "^>14", " >14"};
    int car_pos = 0;
    // каретка всегда на первой единице
    while (s[car_pos] != '1') ++car_pos;
    emul("^1* ", s, car_pos, 14, t);
}
