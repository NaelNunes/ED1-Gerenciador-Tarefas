#include <stdio.h>
#include <stdlib.h>
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

void Simulacao(TpFila &RegFila, FILE *Ptr)
{
	
}

int main()
{
	do
	{
		TpFila RegFila;
		int cont, i, pos;
		float media;	
		FILE *Ptr = AbreArquivo();
		int limiteDev;
		int duracaoTempo, Cont_1_Task = 0, Cont_2_Task = 0, Cont_3_Task = 0, Som_1_Task = 0, Som_2_Task = 0, Som_3_Task = 0;
		
		printf("Digite o numero de devs: ");
		scanf("%d", &limiteDev);
		TpDev RegDev[limiteDev];
		printf("Digite o tempo maximo de simulacao: ");
		scanf("%d", &duracaoTempo);
		 
		for(cont = 0; cont < duracaoTempo; cont++)
		{
			
			fscanf(Ptr,"%[^,],%d,%[^,],%[^,],%s\n", RegFila.FILA[RegFila.Fim].tipo, RegFila.FILA[RegFila.Fim].tempoConc, RegFila.FILA[RegFila.Fim].nomeTarefa, RegFila.FILA[RegFila.Fim].devResp, RegFila.FILA[RegFila.Fim].dataIni);
			RegFila.FILA[RegFila.Qtde].in_time = cont;
			Insere(RegFila, RegFila.FILA[RegFila.Qtde]);
			pos = CheckDevs(RegDev, limiteDev);
			if(pos != -1)//Caso haja Devs disponíveis
			{
				RegDev[i] = RegFila.FILA[RegFila.Inicio];
				RegDev[i].status = 1;	
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
							if(strcmp(RegDev[i].Tarefa_Dev.tipo == "Critico"))
								{
								Cont_1_Task++;
								Som_1_Task += (RegDev[i].Tarefa_Dev.Out_time - RegDev[i].Tarefa_Dev.in_time);
								}
							
							else if(strcmp(RegDev[i].Tarefa_Dev.tipo == "Importante"))
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
		}	
			
	
		
		printf("Tempo medio das Tarefas Critico = %.2f\n", media = Som_1_Task/Cont_1_Task*1.0);
		printf("Tempo medio das Tarefas Importante = %.2f\n", media = Som_2_Task/Cont_2_Task*1.0);
		printf("Tempo medio das Tarefas Melhoria = %.2f\n", media = Som_3_Task/Cont_3_Task*1.0);
		
		
		printf("Deseja realizar outra simulacao? (S/N)");
	} while(toupper(getch()) == 'S');
	
		
	
	
	return 0;
}
