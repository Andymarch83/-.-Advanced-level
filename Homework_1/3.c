/* Преподаватели Geek Brains создали набор, содержащий N (1 ≤ N ≤ 1 000 000)
натуральных чисел, не превосходящих 1 000 000. Известно, что ровно одно
число в этом наборе встречается один раз, а остальные — ровно по два раза.
Помогите им найти это число. Входные данные: в первой входной строке
вводится число N, затем по одному числу в строке вводятся N натуральных
чисел, не превосходящих 2 000 000 000. Выходные данные: ваша программа
должна определить число, встречающееся один раз, и вывести его на экран.
Указание: использовать массивы запрещается.
Данные на входе: Натуральное число N (N > 0), после которого следует
последовательность из N целых чисел.
Данные на выходе: Одно целое число.
*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(){
    uint32_t quantity = 0;
    uint32_t result = 0;
    uint32_t number = 0;
    scanf("%u", &quantity);
    if(quantity > UINT32_MAX / sizeof(number)) {
        fprintf(stderr, "Too many numbers to process\n");
        return 1;
    }
    for (size_t i = 0; i < quantity; i++)
    {
        if (scanf("%u", &number) != 1 || number > UINT32_MAX) {
            fprintf(stderr, "Invalid input\n");
            return 1;
        }
        result ^= number;
    }
    printf("%u\n", result);
    return 0;
}
