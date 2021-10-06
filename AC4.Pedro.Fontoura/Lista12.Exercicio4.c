# include <stdio.h>

int conversao_binaria(int n, int *vetor_binario, int tamanho, int tamanho_fixo){ // o "tamanho_fixo" é usado somente na última chamada da função no vetor_binário
    vetor_binario[tamanho] = (n % 2); // as últimas posições do vetor receberão o resto dessa divisão
    printf("vetor_binario[%d] = %d\n", tamanho, (n%2));
    n /= 2; // o "n" precisa ser divido para continuar os próximos cálculos corretamente
    if(tamanho > 0){ // esse "if" é usado em todas as funções recursivas exceto a última chamada quando o tamamho for igual a zero
        tamanho--; // a função a ser chamada receberá um tamanho decrementado
        printf("O tamanho agr e %d, pois foi decrementado para o proximo valor: \n", tamanho);
        return conversao_binaria(n, vetor_binario, tamanho, tamanho_fixo); // chama a função recursivamente com tamanho decrementado
    }
    if(tamanho == 0){ // apenas na última chamada será feito isso
        int indice, binario; // binário será para armazenar os valores convertidos em binário e valor de retorno
        binario = 0;
        for(indice = 0; indice < tamanho_fixo; indice++){
            if(indice == 0){
                if(vetor_binario[indice] == 0){ // se o vetor tem o valor zero
                    binario = 0;
                }
                else{ // se o vetor tem o valor 1
                    binario = 1;
                }
            }
            else{
                if(vetor_binario[indice] == 0){ // se o valor de tal posição (indice) do vetor for igual a zero, então acrescenta um zero ao valor de binário
                    binario *= 10;
                }
                else{
                    binario = (binario * 10) + 1; // se o valor de tal posição (indice) for igual a 1, então acrescenta um "1" ao valor de binário
                }
            }
        }
        return binario;
    }
}

int main(void){
    int n; // numero a ser convertido em binário
    printf("Insira um valor inteiro em decimal para ser convertido em binario:\n"); // pergunta ao usuário
    scanf("%d", &n); // leitura do numero a ser convertido em binário
    int indice, tamanho, tamanho_fixo, numero_binario;

    printf("O numero em decimal antes da conversao: %d\n", n); //mostrando o numero antes de começar a conversao

    tamanho = 0; // zerando o tamanho do vetor
    for(indice = n; indice > 0; ){
        indice /= 2; // laço para especificar o tamanho do vetor
        tamanho++;
    }
    printf("O valor do indice: %d\n", indice);
    printf("O valor do tamanho: %d\n", tamanho);
    tamanho_fixo = tamanho; // usado na função recursiva
    int vetor_binario[tamanho]; // vetor com o tamanho encontrado anteriormente no laço
    tamanho -= 1; // decrementa o tamanho para ser usado nessa forma na função
    numero_binario = conversao_binaria(n, vetor_binario, tamanho, tamanho_fixo); // a função retornará um inteiro formatado como um "binário"
    printf("\nO numero digitado em binario: %d", numero_binario);
    return 0;
}