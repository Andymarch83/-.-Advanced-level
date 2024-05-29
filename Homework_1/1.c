/*На стандартном потоке ввода задается натуральное число N (N > 0), после
которого следует последовательность из N целых чисел.
На стандартный поток вывода напечатайте, сколько раз в этой
последовательности встречается максимум.*/

#include <stdio.h>

int main() {
    int N, max, count = 1, num; 
    scanf("%d", &N);
    scanf("%d", &max);
    while (--N > 0) {
        scanf("%d", &num);
        if (num == max) {
            count++;
        } else if (num > max) {
            max = num;
            count = 1;
        }
    }
    printf("%d\n", count);
    return 0;
}
