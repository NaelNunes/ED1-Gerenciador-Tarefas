#define MAXFILA 100

struct TpTarefas{
	char tipo[12]; // 1, 2 ou 3 para o nivel de prioridade
	int tempoConc; // Tempo de conclusao estimado
	char nomeTarefa[50]; // Nome da tarefa
	char devResp[20]; // Desenvolvedor Responsavel
	char dataIni[11]; // Data do inicio
	int in_time, Out_time;
};

struct TpFila{
	int Inicio, Fim, Qtde;
	TpTarefas FILA[MAXFILA];
};


struct TpRelatorio
{
	int tarefasConc;
	float tempoMedio;
	int tarefasIncomp;
};

struct TpDev{
	char Nome[50];
	int status;
	TpTarefas Tarefa_Dev;	
};


// Escopo para arquivo
//FILE* AbreArquivo(void);
//TpTarefas LerArquivo(FILE *Ptr);
//



//Operações Associadas
void Inicializar(TpFila &F);
void Insere(TpFila &F, TpTarefas Reg);
TpTarefas Retirar(TpFila &F);
char FilaVazia(int Qtde);
char FilaCheia(int Qtde);
void Exibir(TpFila F);
int CheckDevs(TpDev RegDev, int limiteDev);



void Inicializar(TpFila &F)
{
	F.Inicio = 0;
	F.Fim = -1;
	F.Qtde = 0;
}

int CheckDevs(TpDev RegDev[], int limiteDev){
	int i = 0;
	
	while(i < limiteDev && RegDev[i].status == 1)
	{
		i++;
	}
		
		
		
	if(i < limiteDev)
		return i;
	else
		return -1;
}


void Insere(TpFila &F, TpTarefas Reg)
{
	int i;
	if(F.Qtde != MAXFILA)
	{
		i = F.Fim;
		while(i != F.Inicio && strcmp(F.FILA[i].tipo, Reg.tipo) > 0) // ESTAVA USANDO < PARA COMPARAR STRING BIXAAAAA (ARRUMADO)
		{
			if(i == 0)
			{
				F.FILA[MAXFILA - 1]= F.FILA[i];
				i = MAXFILA;
			}
			else
				F.FILA[i + 1] = F.FILA[i];
			i--;
		}
		/*eu não entendi esse i>0
		Outra coisa ainda nao sei pq,
		mas não tá fazendo prioridade com primeiro da fila*/
		if(i > 0 && strcmp(F.FILA[i-1].tipo, Reg.tipo) > 0)
		{
			F.FILA[i + 1] = F.FILA[i];
			i--;
		}
    	F.FILA[i + 1] = Reg;
		if(F.Fim == MAXFILA - 1)
			F.Fim = -1;
    	F.Fim++;
    	F.Qtde++;
	}
}



TpTarefas Retirar(TpFila &F)
{
	TpTarefas Aux;
	Aux = F.FILA[F.Inicio];
	if(F.Inicio == MAXFILA - 1)
		F.Inicio=0;
	else
		F.Inicio++;
	F.Qtde--;
	
	return Aux;	
}

char FilaVazia(int Qtde)
{
	return Qtde == 0;
}

char FilaCheia(int Qtde)
{
	return Qtde == MAXFILA;
}


//Esse Exibir é para ir exibindo a fila
void Exibir(TpFila F)
{
    int i = F.Inicio;
    int count = F.Qtde;
    
    while(count > 0) 
    {
        printf("%s \t%d \t%s\n", F.FILA[i].tipo, F.FILA[i].tempoConc, F.FILA[i].nomeTarefa);
        Sleep(200);
        i++;
        if (i == MAXFILA) {
            i = 0;
        }
        count--;
    }
}
