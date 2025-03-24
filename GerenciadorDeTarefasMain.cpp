#include <stdio.h>
#include <stlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include "TADGerenciadorDeTarefas.h"

void InterfaceMenu(void)
{
	
}

void RelatorioLoop(void)
{
	
}

void Simulacao(TpFila &RegFila, TpSimulacao &RegSim, FILE *Ptr)
{
	Inserir(RegFila,LerArquivo(Ptr));
	
}

int main()
{
	do
	{
		TpFila RegFila;
		TpSimulacao RegSim;
	
		FILE *Ptr = AbreArquivo();
		int limiteDev;
		int duracaoTempo;
		
		printf("Digite o numero de devs: ");
		scanf("%d", &limiteDev);
		printf("Digite o tempo maximo de simulacao: ");
		scanf("%d", &duracaoTempo);
		 
		while(!Cheia(RegFila.FIM) && RegSim.devs < limiteDev && RegSim.tempo < duracaoTempo)
		{
			
		}	
			
		
		
		
		printf("Deseja realizar outra simulacao? (S/N)");
	} while(toupper(getch()) == 'S');
	
		
	
	
	return 0;
}
