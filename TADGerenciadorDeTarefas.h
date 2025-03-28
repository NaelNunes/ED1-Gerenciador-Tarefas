#define MAXFILA 100

struct TpTarefas{
	char tipo[12]; // 1, 2 ou 3 para o nivel de prioridade
	int tempoConc; // Tempo de conclusao estimado
	char nomeTarefa[50]; // Nome da tarefa
	char devResp[20]; // Desenvolvedor Responsavel
	char dataIni[11]; // Data do inicio
	int in_time, Out_time; 
	int cont = 0;
	int tempoTotal;
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



//OperaÃ§Ãµes Associadas
void Inicializar(TpFila &F);
void Insere(TpFila &F, TpTarefas Reg);
TpTarefas Retirar(TpFila &F);
char FilaVazia(int Qtde);
char FilaCheia(int Qtde);
void Exibir(TpFila F);
int CheckDevs(TpDev RegDev, int limiteDev);
char BarraCarregamento(TpDev RegDev[]);


void BarraCarregamento(int tempo, int contador, int &Coluna, int &Linha) {
    int largura = 20; // Largura da barra de carregamento
    int parcela = largura * contador / tempo; // Calcula a posição atual da barra

    // Imprime a barra de carregamento
    textcolor(10);
    gotoxy(Coluna,Linha);
    printf("[");
    for (int i = 0; i < largura; i++) {
        if (i < parcela) {
        	textcolor(32);
            printf(" ");
			textcolor(10); // Parte preenchida da barra
        } else {
            printf(" "); // Parte não preenchida da barra
        }
    }
    printf("] %d%%", contador * 100 / tempo); // Exibe a porcentagem
    Linha++;
}




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
		if(F.Qtde == 0)
		{

    		F.FILA[(F.Fim + 1) % MAXFILA] = Reg;
		} 
		else 
		{
			while(strcmp(F.FILA[i].tipo, Reg.tipo) > 0) // ESTAVA USANDO < PARA COMPARAR STRING BIXAAAAA (ARRUMADO)
			{
				F.FILA[(i + 1) % MAXFILA] = F.FILA[i];
				
				if(i == 0)
				{
					i = MAXFILA - 1;	
				} else {
					i--;
				}
							
			}
			F.FILA[(i + 1) % MAXFILA] = Reg;
		}
		
		F.Fim = (F.Fim + 1) % MAXFILA;
    	F.Qtde++;
	}
}

TpTarefas Retirar(TpFila &F)
{
	TpTarefas Aux;
	
	if(F.Qtde > 0){
	Aux = F.FILA[F.Inicio++];
	
	if(F.Inicio == MAXFILA)
		F.Inicio=0;
	
	F.Qtde--;
	return Aux;	
	}
}

char FilaVazia(int Qtde)
{
	return Qtde == 0;
}

char FilaCheia(int Qtde)
{
	return Qtde == MAXFILA;
}


//Esse Exibir Ã© para ir exibindo a fila
void Exibir(TpFila F, int &Coluna, int &Linha)
{
    int i = F.Inicio;
    int count = F.Qtde;
    
    while(count > 0) 
    {
    	gotoxy(Coluna,Linha++);
		textcolor(4);
        printf("%s \t%d \t%s", F.FILA[i].tipo, F.FILA[i].tempoConc, F.FILA[i].nomeTarefa);
        Sleep(200);
        i++;
        if (i == MAXFILA) {
            i = 0;
        }
        count--;
    }
    
}
