#include <stdio.h>

int main(){
	int i;
  int idade[100];
	int otimo = 0;
	int bom = 0;
	int regular = 0;
	int ruim = 0;
	int pessimo = 0;
	float mediaIdadeRuim = 0;
	int maiorIdadeOtimo = 0;
	int maiorIdadeRuim = 400;
	int maiorIdadePessimo = 0;
	
    printf("Entre com os dados: Idade e Opiniao (sendo 1-Otimo, 2-Bom, 3-Regular, 4-Ruim e 5-Pessimo)\n");
    for(i = 0; i < 100; i++){
		int idade, opiniao;
        scanf("%d %s", &idade, &opiniao);
		if(opiniao == 1){
			otimo++;
			if(idade>maiorIdadeOtimo){
				maiorIdadeOtimo = idade;
			}
		}else if(opiniao == 2){
			bom++;
		}else if(opiniao==3){
			regular++;
		}else if(opiniao == 4){
			mediaIdadeRuim++;
			ruim++;
			if (idade > maiorIdadeRuim){
				maiorIdadeRuim = idade;
			}	
		}else if(opiniao == 5){
			pessimo++;
			if(idade > maiorIdadePessimo){
				maiorIdadePessimo = idade;
			}
		}
	}
	printf("Quantidade de Otimo: %d", otimo);
	float percentualBom = bom/100;
	float percentualRegular = regular/100;
	printf("Diferenca Percentual entre bom e regular: %f", (percentualBom - percentualRegular));
	printf("A media da idade das pessoas que responderam ruim: %f", mediaIdadeRuim/ruim);
	float percentualPessimo = pessimo/100;
	printf("Maior idade que respondeu pessimo: %d Porcentagem de respostas pessimo: %f", maiorIdadePessimo, percentualPessimo);
	printf("Diferenca de idade: %d", (maiorIdadeOtimo - maiorIdadeRuim));
	while(1){}
}