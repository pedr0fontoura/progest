/* O programa ira imprimir:
 32 e 18
 18 e 14
 14 e 4
 4 e 2

 pois começando pelo 32 e 18, como o resto de a / b != 0, vai retornar 18 e 14 (32 % 18)
 entao agr a = 18 e b = 14, vai repetir o processo, como 18 % 14 != 0, retorna 14 e 4 (18 % 14)
 e assim por diante até o a % b == 0 que é quando o b = 2
*/

#include <stdio.h>

int mdc_recursiva(int a, int b) {
    printf("\n%d e %d", a, b);
    if (a % b == 0) return b;
    return mdc_recursiva (b, a % b);
}
int main() {
    int a=32, b=18;
    printf("\nResultado=%d",mdc_recursiva(a, b));
}