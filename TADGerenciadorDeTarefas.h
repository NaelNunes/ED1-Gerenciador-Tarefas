#define MAXFILA 100

struct TpTarefas
{
	int tipo; // 1, 2 ou 3 para o nivel de prioridade
	int tempoConc; // Tempo de conclusão estimado
	char nomeTarefa[40]; // Nome da tarefa
	char devResp[20]; // Desenvolvedor Responsável
	char dataIni[9]; // Data do inicio
}

struct TpFila
{
	int FIM;
	TpTarefas FILAP[MAXFILA];
}

void Inicializar(TpFila &F);

void Inicializar(TpFila &F)
{
	F.FIM = -1;
}

void Inserir(TpFila &FP, TpElemento Elem)
{
	FP.FILAP[++FP.FIM] = Elem;
	int i = F.FIM;
	
	while(i > 0 && FP.FILAP[i-1].Prioridade > FP.FILAP[i].Prioridade)
	{
		FP.FILAP[i] = FP.FILAP[i - 1];
		FP.FILAP[i - 1] = Elem;
		i--;
	}
}

char Vazia(int FIM)
{
	return FIM == -1;
}

char Cheia(int FIM)
{
	return FIM == MAXFILA - 1;
}

TpTarefas Retirar(TpFila &FP)
{
    TpTarefas Elem = FP.FILAP[0];  

    for (int i = 0; i < FP.FIM; i++)
    {
        FP.FILAP[i] = FP.FILAP[i + 1];
    }

    FP.FIM--;
    
    return Elem;  
}

void Exibir(TpFila FP)
{
	while(!Vazia(FP.FIM))
		printf("\t%s",Retirar(FP));
}
