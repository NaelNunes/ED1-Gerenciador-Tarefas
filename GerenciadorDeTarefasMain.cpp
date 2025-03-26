//////////////////////////////////////////////////////////////////////////////////////////////////////////
//																										//
//																										//
//			Nathanael Nunes				Felipe de Oliveira Barbosa				Vitor Lacerda			//
// 																										//
// 																										//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <conio2.h>
#include <time.h>
#include "TADGerenciadorDeTarefas.h"

void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF,int SupE,int SupD,int InfE,int InfD)
{
	int i;
	textcolor(CorT);
	textbackground(CorF);
	gotoxy(CI,LI);
	printf("%c",SupE);
	gotoxy(CI,LF);
	printf("%c",InfE);
	gotoxy(CF,LI);
	printf("%c",SupD);
	gotoxy(CF,LF);
	printf("%c",InfD);
	for(i=CI+1; i<CF; i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1; i<LF; i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		gotoxy(CF,i);
		printf("%c",186);
	}
	textcolor(7);
	textbackground(0);
}

void InterfaceMenu(void)
{
	clrscr();
	//valores: (CL,LI,CF,LF,CorT,CorF,SupE,SupD,InfE,InfD)
	Moldura(1,1,106,30,0,1,201,187,200,188);
	//Titulo 
	Moldura(1,5,106,30,0,1,204,185,200,188); 
	textcolor(15);
	gotoxy(38,3);
	printf("### GERENCIADOR DE TAREFAS ###");//Decidir ainda o nome
}

void InterfaceRelatorio(void)
{
	clrscr();
	//valores: (CL,LI,CF,LF,CorT,CorF,SupE,SupD,InfE,InfD)
	Moldura(1,1,106,30,0,1,201,187,200,188);
	//Titulo 
	Moldura(1,5,106,30,0,1,204,185,200,188); 
	textcolor(4);
	gotoxy(25,3);
	printf("# # #  R E L A T O R I O  D O  P R O G R A M A  # # #");//Decidir ainda o nome
}

void Simulacao(TpFila &RegFila, FILE *Ptr)
{
	
}

void NomeiaDevs(TpDev RegDev[], int limiteDev)
{
	char *nomesDev[10] = {
    "Nathanael", "Vitor", "Felipe", "Willian", "Leandro",
    "Haroldo", "Silvio Antonio", "JoÃ£o Cezario", "Flavio", "Francisco"
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
		TpFila RegFila;
		TpTarefas RegTarefa;
		int cont, i, y, pos, limiteDev, DevsOcupados = 0, Linha, Coluna;
		int duracaoTempo, Cont_1_Task = 0, Cont_2_Task = 0, Cont_3_Task = 0, Som_1_Task = 0, Som_2_Task = 0, Som_3_Task = 0;
		float media;
		Inicializar(RegFila);
		srand(time(NULL));// Sempre sortear novos numeros	
		FILE *Ptr = fopen("DadoArquivo.txt","r");
		Moldura(28,9,71,19,3,0,201,187,200,188);
		gotoxy(31,10);
		textcolor(13);
		printf("# # #  P R O G R A M A D O R E S  # # #");
		gotoxy(32,13);
		textcolor(2);
		printf("Nathanael Nunes");
		gotoxy(43,15);
		printf("Vitor Lacerda");
		gotoxy(50,17);
		printf("Felipe Barbosa");
		getch();
		InterfaceMenu();
		//Moldura das perguntas
		Moldura(28,9,72,19,2,0,201,187,200,188);
		gotoxy(31,12);
		textcolor(4);
		printf("Digite o numero de devs: ");
		textcolor(7);
		scanf("%d", &limiteDev);
		TpDev RegDev[limiteDev];
		NomeiaDevs(RegDev,limiteDev);
		gotoxy(31,15);
		textcolor(4);
		printf("Digite o tempo maximo de simulacao: ");
		textcolor(7);
		scanf("%d", &duracaoTempo);
		 
		for(cont = 0; cont < duracaoTempo; cont++)
		{
			
		if(rand() % 2 == 0) // sortear se vai entrar ou nao nesse loop
			{
				fscanf(Ptr,"%[^,],%d,%[^,],%[^,],%s\n", &RegTarefa.tipo, &RegTarefa.tempoConc, &RegTarefa.nomeTarefa, &RegTarefa.devResp, &RegTarefa.dataIni);				
				
				Insere(RegFila, RegTarefa); 
			}
			
			pos = CheckDevs(RegDev, limiteDev);
			if(pos != -1)//Caso haja Devs disponiveis
			{
				RegDev[pos].Tarefa_Dev = Retirar(RegFila);
				RegTarefa.in_time = cont;
				RegDev[pos].status = 1;
				RegDev[pos].Tarefa_Dev.tempoTotal = RegDev[pos].Tarefa_Dev.tempoConc;
				DevsOcupados++;	
			}
			InterfaceMenu();
			gotoxy(8,8);
			textcolor(6);
			printf("Tarefas sendo executadas: ");
			Linha = 10;
			Coluna = 4;
			for(y = 0; y < DevsOcupados; y++)
				{
				if(RegDev[y].status == 1 && RegDev[y].Tarefa_Dev.tempoConc > 0)
					{
							Sleep(500);
							gotoxy(Coluna,Linha++);
							textcolor(13);
							printf("Dev - %s: Prioridade: %s - %s - Tempo Restante: %d", RegDev[y].Nome, RegDev[y].Tarefa_Dev.tipo ,RegDev[y].Tarefa_Dev.nomeTarefa, RegDev[y].Tarefa_Dev.tempoConc);
							BarraCarregamento(RegDev[y].Tarefa_Dev.tempoTotal, RegDev[y].Tarefa_Dev.cont,Coluna,Linha);
					}
				}
			gotoxy(8,++Linha);
			textcolor(8);
			printf("Tarefas na fila: ");
			Linha+=2;	
			Exibir(RegFila, Coluna, Linha);
			Sleep(500);
			//getch();
			
						
			for(i = 0; i < DevsOcupados && cont < duracaoTempo; i++)//Decrementar tempo da tarefa
				{

			
				if(RegDev[i].status == 1)
					{

					RegDev[i].Tarefa_Dev.tempoConc--;
					RegDev[i].Tarefa_Dev.cont++;
					if(RegDev[i].Tarefa_Dev.tempoConc == 0)
						{
							RegDev[i].status = 0;
							DevsOcupados--;
							RegDev[i].Tarefa_Dev.Out_time = cont;
							if(strcmp(RegDev[i].Tarefa_Dev.tipo,"Critico") == 0)
								{
									Cont_1_Task++;
									Som_1_Task += RegDev[i].Tarefa_Dev.tempoTotal;
								}
							
							else if(strcmp(RegDev[i].Tarefa_Dev.tipo,"Importante") == 0)
								{
									Cont_2_Task++;
									Som_2_Task += RegDev[i].Tarefa_Dev.tempoTotal;
								}
							
							else
								{
									Cont_3_Task++;
									Som_3_Task += RegDev[i].Tarefa_Dev.tempoTotal;
								}
							
						}
					
					}


				}
				
		}	
		getch();
		InterfaceRelatorio();
		//Moldura do relatorio concluido
		Moldura(20,7,83,28,15,0,201,187,200,188);
		Linha = 11;
		gotoxy(25,Linha-2);
		textcolor(2);
		printf("CRITICO: ");
		gotoxy(24,Linha);
		textcolor(14);
		// CASO NAO TENHA TASK SEJA 0 ELE NAO DIVIDE PODE DAR ERRO (ARRUMADO)
		if (Cont_1_Task > 0) {
			printf("Tarefas Completadas = %d", Cont_1_Task);
			gotoxy(24,++Linha);
    		printf("Tempo medio das Tarefas = %.2f", (float)Som_1_Task / Cont_1_Task);
    		
		} else {
    		printf("Nenhuma tarefa foi realizada.");
		}
		Linha+=2;
		gotoxy(24,Linha++);
		textcolor(7);
		printf("------------------------------------------------------");
		gotoxy(25,++Linha);
		textcolor(5);
		printf("IMPORTANTE: ");
		Linha+=2;
		gotoxy(24,Linha);
		textcolor(14);
		if (Cont_2_Task > 0) {
			
			printf("Tarefas Completadas = %d", Cont_2_Task);
			gotoxy(24,++Linha);
    		printf("Tempo medio das Tarefas = %.2f", (float)Som_2_Task / Cont_2_Task);
		} else {
    		printf("Nenhuma tarefa foi realizada.");
		}	
		Linha+=2;
		gotoxy(24,Linha++);
		textcolor(7);
		printf("------------------------------------------------------");
		gotoxy(25,++Linha);
		textcolor(12);
		printf("MELHORIA: ");
		Linha+=2;
		gotoxy(24,Linha);
		textcolor(14);
		if (Cont_3_Task > 0) {
			printf("Tarefas Completadas = %d", Cont_3_Task);
			gotoxy(24,++Linha);
    		printf("Tempo medio das Tarefas = %.2f", (float)Som_3_Task / Cont_3_Task);
		} else {
    		printf("Nenhuma tarefa foi realizada.");
		}
		getch();
		InterfaceRelatorio();
		if(RegFila.Qtde + DevsOcupados > 0)
		{
			Linha = 10;
			//Moldura de tarefas nao concluidas
			Moldura(17,7,86,28,15,0,201,187,200,188);
			gotoxy(34,Linha - 2);
			textcolor(12);
			printf ("TAREFAS QUE NAO FORAM CONCLUIDAS = %d" , RegFila.Qtde + DevsOcupados);
			gotoxy(25,Linha++);
			textcolor(6);
			printf("Tarefas que nao foram resolvidas: ");
			Linha++;
			Coluna = 19; 	
			Exibir(RegFila, Coluna, Linha);
			getch();
			InterfaceRelatorio();
			Linha = 10;
			gotoxy(34,Linha - 2);
			textcolor(12);
			printf ("TAREFAS QUE NAO FORAM CONCLUIDAS = %d" , RegFila.Qtde + DevsOcupados);
			gotoxy(15,Linha++);
			textcolor(14);
			printf("Tarefas que ficaram na fila: ");
			Linha++;
			Coluna = 10; 
			for(y = 0; y < DevsOcupados; y++)
			{
				if(RegDev[y].status == 1 && RegDev[y].Tarefa_Dev.tempoConc > 0)
				{
					//Sleep(500);
					gotoxy(Coluna,Linha++);
					textcolor(13);
					printf("Dev - %s: Prioridade: %s - %s - Tempo Restante: %d", RegDev[y].Nome, RegDev[y].Tarefa_Dev.tipo ,RegDev[y].Tarefa_Dev.nomeTarefa, RegDev[y].Tarefa_Dev.tempoConc);
				}
			}
		}
		else
		{
			//Moldura de tarefas nao concluidas
			Moldura(28,11,70,19,15,0,201,187,200,188);
			gotoxy(31,15);
			textcolor(10);
			printf ("TAREFAS QUE NAO FORAM CONCLUIDAS = %d" , RegFila.Qtde + DevsOcupados);
		}
		
		
		getch();
		InterfaceMenu();
		//Moldura de realizar outra simulaÃ§Ã£o
		Moldura(28,11,71,19,15,0,201,187,200,188);
		gotoxy(31,15);
		textcolor(6);
		printf("Deseja realizar outra simulacao? (S/N)");
		fclose(Ptr); // FALTOU FECHAR 
	} while(toupper(getche()) == 'S');
	
			
	return 0;
}
