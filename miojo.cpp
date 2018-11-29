#include <bits/stdc++.h>
using namespace std;

//Verificacao das entradas
bool verifyInput(int amp1, int amp2, int timer){
	if(timer < amp1 and timer < amp2){
		return false;
	}
	else{
		return true;
	}
	return true;
}

//Acha o mdc entre dois numeros
int gcd(int a, int b){
	if (b == 0) 
        return a; 
    return gcd(b, a % b);
}

int main(){

	//Declarar variaveis e receber elas
	int amp1, amp2, timer;
	printf("Entre com o tempo da primeira ampulheta, da segunda e depois do tempo de cozimento\n");
	scanf("%d %d %d", &amp1, &amp2, &timer);

	//Verificar entradas
	if(verifyInput(amp1, amp2, timer)){
		printf("Os temps inseridos estão incorretos\n");
		return 0;
	}

	//Verifica se o tempo de cozimento nao for multiplo do mdc das ampulhetas
	int g = gcd(amp1, amp2);
	if((timer % g) != 0){
		printf("Não é possivel obter esse tempo de cozimento\n");
		return 0;
	}

	//Loop para encontrar as iteracoes necessarias
	int newAmp1 = amp1;
	int newAmp2 = amp2;
	int totalTime = 0;

	while(true){
		//Achar menor tempo entre as ampulhetas e verificar se é o tempo de cozimento
		int t;
		if(newAmp1 > newAmp2){
			t = newAmp2;
		}
		else{
			t = newAmp1;
		}
		if(t == timer){
			totalTime += t;
			break;
		}
		
		//Testando os tempos
		if(newAmp1 > newAmp2){
			newAmp1 -= newAmp2;
			totalTime += newAmp2;
			newAmp2 = amp2;
		}
		if(newAmp2 > newAmp1){
			newAmp2 -= newAmp1;
			totalTime += newAmp1;
			newAmp1 = amp1;
		}
	}

	printf("Tempo total: %d\n", totalTime);

	return 0;
}