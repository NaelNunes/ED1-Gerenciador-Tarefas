// Nathanael Nunes, Felipe Oliveira Barbosa, Vitor Lacerda
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <conio2.h>
#include <time.h>
#include "TADGerenciadorDeTarefas.h"


void InterfaceMenu(void)
{
	
}

void RelatorioLoop(void)
{
	
}

void Simulacao(TpFila &RegFila, FILE *Ptr)
{
	
}

void NomeiaDevs(TpDev RegDev[], int limiteDev)
{
	char *nomesDev[10] = {
    "Nathanael", "Vitor", "Felipe", "Willian", "Leandro",
    "Haroldo", "Silvio Antonio", "João Cezario", "Flavio", "Francisco"
	};
	
	for(int i = 0; i < limiteDev; i++)
	{
		strcpy(RegDev[i].Nome,nomesDev[i]);
	}
}

int main()
{
	do
	{
		TpFila RegFila, RegTeste;
		TpTarefas RegTarefa;
		int cont, i, pos, limiteDev;
		int duracaoTempo, Cont_1_Task = 0, Cont_2_Task = 0, Cont_3_Task = 0, Som_1_Task = 0, Som_2_Task = 0, Som_3_Task = 0;
		float media;
		Inicializar(RegFila);
		srand(time(NULL));// Sempre sortear novos numeros	
		FILE *Ptr = fopen("DadoArquivo.txt","r");
		
		printf("Digite o numero de devs: ");
		scanf("%d", &limiteDev);
		TpDev RegDev[limiteDev];
		NomeiaDevs(RegDev,limiteDev);
		printf("Digite o tempo maximo de simulacao: ");
		scanf("%d", &duracaoTempo);
		 
		for(cont = 0; cont < duracaoTempo; cont++)
		{
			printf("\n\nTarefas sendo executadas: \n\n");
			for(int y = 0; y < limiteDev; y++)
			{
				if(RegDev[y].status == 1 && RegDev[y].Tarefa_Dev.tempoConc > 0)
				{
						Sleep(500);
						printf("Dev - %s: %s - Tempo Restante: %d\n", RegDev[y].Nome, RegDev[y].Tarefa_Dev.nomeTarefa, RegDev[y].Tarefa_Dev.tempoConc);
				}
			}
		
			printf("\n\nTarefas na fila: \n\n");
			//if(!FilaVazia(RegFila.Qtde))
//			{
				Exibir(RegFila);
//			}
			//if(rand() % 2 == 0) // sortear se vai entrar ou nao nesse loop
			//{
				fscanf(Ptr,"%[^,],%d,%[^,],%[^,],%s\n", &RegTarefa.tipo, &RegTarefa.tempoConc, &RegTarefa.nomeTarefa, &RegTarefa.devResp, &RegTarefa.dataIni);				RegTarefa.in_time = cont;
				Insere(RegFila, RegTarefa); 
				//Insere(RegTeste, RegTarefa);
//				Exibir(RegTeste); 
			//}
			
			pos = CheckDevs(RegDev, limiteDev);
			if(pos != -1)//Caso haja Devs disponiveis
			{
				RegDev[pos].Tarefa_Dev = Retirar(RegFila);
				RegDev[pos].status = 1;	
			}
						
			for(i = 0; i < limiteDev; i++)//Decrementar tempo da tarefa
				{
			
				if(RegDev[i].status == 1)
				{
					
					RegDev[i].Tarefa_Dev.tempoConc--;
					if(RegDev[i].Tarefa_Dev.tempoConc == 0)
						{
							RegDev[i].status = 0;
							RegDev[i].Tarefa_Dev.Out_time = cont;
							if(strcmp(RegDev[i].Tarefa_Dev.tipo,"Critico") == 0)
								{
									Cont_1_Task++;
									Som_1_Task += (RegDev[i].Tarefa_Dev.Out_time - RegDev[i].Tarefa_Dev.in_time);
								}
							
							else if(strcmp(RegDev[i].Tarefa_Dev.tipo,"Importante") == 0)
								{
									Cont_2_Task++;
									Som_2_Task += (RegDev[i].Tarefa_Dev.Out_time - RegDev[i].Tarefa_Dev.in_time);
								}
							
							else
								{
									Cont_3_Task++;
									Som_3_Task += (RegDev[i].Tarefa_Dev.Out_time - RegDev[i].Tarefa_Dev.in_time);
								}
							
						}
					}
				}
				getch();
				system("cls");
				
		}	
		
		
		
			
	
		// CASO NAO TENHA TASK SEJA 0 ELE NAO DIVIDE PODE DAR ERRO (ARRUMADO)
		if (Cont_1_Task > 0) {
    		printf("Tempo medio das Tarefas Critico = %.2f\n", (float)Som_1_Task / Cont_1_Task);
		} else {
    		printf("Nenhuma tarefa Critico foi realizada.\n");
		}

		if (Cont_2_Task > 0) {
    		printf("Tempo medio das Tarefas Importante = %.2f\n", (float)Som_2_Task / Cont_2_Task);
		} else {
    		printf("Nenhuma tarefa Importante foi realizada.\n");
		}	

		if (Cont_3_Task > 0) {
    		printf("Tempo medio das Tarefas Melhoria = %.2f\n", (float)Som_3_Task / Cont_3_Task);
		} else {
    		printf("Nenhuma tarefa Melhoria foi realizada.\n");
		}
		
		
		printf("Deseja realizar outra simulacao? (S/N)");
		fclose(Ptr); // FALTOU FECHAR 
	} while(toupper(getche()) == 'S');
	
			
	return 0;
}
