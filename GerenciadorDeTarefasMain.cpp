#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <conio2.h>
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

void Menu(void)
{
	
	
	
}

void InterfaceMenu(void)
{
	clrscr();
	//valores: (CL,LI,CF,LF,CorT,CorF,SupE,SupD,InfE,InfD)
	Moldura(1,1,100,30,0,1,201,187,200,188);
	//Titulo 
	Moldura(1,5,100,30,0,1,204,185,200,188); 
	textcolor(15);
	gotoxy(35,3);
	printf("### TITULO DO TRABALHO ###");
	//MENU
	Moldura(20,6,80,29,2,0,201,187,200,188);
}

void RelatorioLoop(void)
{
	
}

int main()
{
	//Para fazer a interface do MENU
	InterfaceMenu();
	getch();
	return 0;
}
