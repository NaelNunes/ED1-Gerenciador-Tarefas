#define MAXFILA 100

struct TpTarefas
{
	char tipo[12]; // 1, 2 ou 3 para o nivel de prioridade
	int tempoConc; // Tempo de conclusao estimado
	char nomeTarefa[40]; // Nome da tarefa
	char devResp[20]; // Desenvolvedor Responsavel
	char dataIni[11]; // Data do inicio
};

struct TpFila
{
	int FIM;
	TpTarefas FILAP[MAXFILA];
};

struct TpSimulacao
{
	int devs = 0;
	int tempo = 0;
};

struct TpRelatorio
{
	int tarefasConc;
	float tempoMedio;
	int tarefasIncomp;
};

// Escopo para fila
void Inicializar(TpFila &F);
void Inserir(TpFila &FP, TpElemento Elem);
char Vazia(int FIM);
char Cheia(int FIM);
TpTarefas Retirar(TpFila &FP);
void Exibir(TpFila FP);
//

// Escopo para arquivo
FILE* AbreArquivo(void);
TpTarefas LerArquivo(FILE *Ptr);
//




// Funcoes para fila
void Inicializar(TpFila &F)
{
	F.FIM = -1;
}

void Inserir(TpFila &FP, TpTarefas Elem)
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
//




// Funcoes para arquivo

FILE* AbreArquivo(void)
{
	FILE *Ptr = fopen("Arquivo.txt","r");
	return Ptr;
}

TpTarefas LerArquivo(FILE *Ptr)
{
	TpTarefas Reg;
	
	fscanf(Ptr,"%[^,],%d,%[^,],%[^,],%s\n", &Reg.tipo, &Reg.tempoConc, &Reg.nomeTarefa, &Reg.devResp, &Reg.dataIni);
	return Reg;
}
//





