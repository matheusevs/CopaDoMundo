#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define EST 12
#define HOR 4

typedef struct {
	char name [4] [50];
	int sco [4], vic [4], def [4], draw [4], goals [4], cgoal [4], bal [4];
} ficha_da_selecao;

void Rodada_FaseDeGrupos (ficha_da_selecao *group, int g, int t1, int t2, int G1, int G2) {
	if (G1 > G2) {
		group [g].sco [t1] += 3;
		group [g].vic [t1]++;
		group [g].def [t2]++;
		group [g].goals [t1] += G1;
		group [g].cgoal [t1] += G2;
		group [g].goals [t2] += G2;
		group [g].cgoal [t2] += G1;
	}	
	else if (G1 < G2) {
		group [g].sco [t2] += 3;
		group [g].vic [t2]++;
		group [g].def [t1]++;
		group [g].goals [t2] += G2;
		group [g].cgoal [t2] += G1;
		group [g].goals [t1] += G1;
		group [g].cgoal [t1] += G2;
	}	
	else {
		group [g].sco [t1]++;
		group [g].sco [t2]++;
		group [g].draw [t1]++;
		group [g].draw [t2]++;
		group [g].goals [t1] += G1;
		group [g].cgoal [t1] += G2;
		group [g].goals [t2] += G2;
		group [g].cgoal [t2] += G1;
	}	
	return;
}

int Conversor_Opcao (char op []) {
	int n_op;
	
	if (isalpha (op [0]) || isalpha (op [1])) {
		n_op = 0;
	}
	else {
		n_op = atoi (op);
	}
	
	return n_op-1;
}

void Menu (int n2, char stadium [] [n2], int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		printf ("%d- %s\n", i+1, stadium [i]);
	}
	printf ("\n>> ");
	
	return;
}

int main ()
{
	setlocale (LC_ALL, "Portuguese");	
	ficha_da_selecao group [8];
	char lgroup, option, op [2], stadium [EST] [50], team [32] [50], r16 [16] [50], mr16 [16] [50], qt [8] [50], sf [4] [50], final [2] [50], podium[4] [50], third[2] [50], m_time [HOR] [6];
	int i, ii, ti; // Manipuladores de laço
	int p, pp, fsco, ssco, fbal, sbal, same, same2; // Sistema de pontuação
	int year, month = 6, day, sel, s_sel, flag, reg = 0, perfumary = 0, aux = 0, count = 0, random [32];
	
	srand (time(NULL));	
	for (i = 0; i < 32; i++) {
		random [i] = rand () % 32;
		for (ii = 0; ii < i; ii++) {
			if (random [ii] == random [i]) {
				i--;
			}
		}
	}
	printf("     o o    o o    o o       o         o o       o o       oo   oo  o     o  o     o  o o       o o    \n");
	printf("    o     o     o  o  o     o o        o   o   o     o     o o o o  o     o  o o   o  o   o   o     o   \n");
	printf("    o     o     o  o  o    o   o       o    o  o     o     o  o  o  o     o  o  o  o  o    o  o     o    \n");
	printf("    o     o     o  ooo    ooooooo      o    o  o     o     o     o  o     o  o   o o  o    o  o     o     \n");
	printf("    o     o     o  o     o       o     o   o   o     o     o     o  o     o  o    oo  o   o   o     o      \n");
	printf("     o o    o o    o    o         o    o o       o o       o     o    o o    o     o  o o       o o         \n");
	printf("                                                                                          By: Equipe Power Rangers");
	printf("\n\n");
	system ("pause");
	
	do {
		printf ("Ano da Copa: ");
		scanf ("%d", &year);
		printf ("Dia de início: ");
		scanf ("%d", &day);
		if (day < 1 || day > 30) {
			system ("cls");
			printf ("OPÇÃO INVÁLIDA!");
			sleep (1);
		}
		system ("cls");
	} while (day < 1 || day > 30);
	
	do {
		printf ("....::: CADASTRO DAS SELEÇÕES :::....\n\n");
		printf ("1- Cadastrar manualmente\n");
		printf ("2- Preenchimento automático (seleções da Copa de 2018)\n\n");
		printf (">> ");
		fflush (stdin);
		scanf ("%c", &option);
		system ("cls");
		
		switch (option) {				
			case '1':
				printf ("....::: CADASTRO DAS SELEÇÕES :::....\n\n");	
				for (i = 0; i < 32; i++) {
					printf ("Time %d: ", i+1);
					fflush (stdin);
					gets (team [random [i]]);
				}
				break;
				
			case '2':				
				strcpy (team [random [0]], "RÚSSIA");
				strcpy (team [random [1]], "FRANÇA");
				strcpy (team [random [2]], "PORTUGAL");
				strcpy (team [random [3]], "ALEMANHA");
				strcpy (team [random [4]], "SÉRVIA");
				strcpy (team [random [5]], "POLÓNIA");
				strcpy (team [random [6]], "INGLATERRA");
				strcpy (team [random [7]], "ESPANHA");
				strcpy (team [random [8]], "BÉLGICA");
				strcpy (team [random [9]], "ISLÂNDIA");
				strcpy (team [random [10]], "SUÍÇA");
				strcpy (team [random [11]], "CROÁCIA");
				strcpy (team [random [12]], "SUÉCIA");
				strcpy (team [random [13]], "DINAMARCA");
				strcpy (team [random [14]], "IRÃ");
				strcpy (team [random [15]], "COREIA DO SUL");
				strcpy (team [random [16]], "JAPÃO");
				strcpy (team [random [17]], "ARÁBIA SAUDITA");
				strcpy (team [random [18]], "AUSTRÁLIA");
				strcpy (team [random [19]], "TUNÍSIA");
				strcpy (team [random [20]], "NIGÉRIA");
				strcpy (team [random [21]], "MARROCOS");
				strcpy (team [random [22]], "SENEGAL");
				strcpy (team [random [23]], "EGITO");
				strcpy (team [random [24]], "MÉXICO");
				strcpy (team [random [25]], "COSTA RICA");
				strcpy (team [random [26]], "PANAMÁ");
				strcpy (team [random [27]], "BRASIL");
				strcpy (team [random [28]], "URUGUAI");
				strcpy (team [random [29]], "ARGENTINA");
				strcpy (team [random [30]], "COLÔMBIA");
				strcpy (team [random [31]], "PERU");
				break;
				
			default:
				printf ("\nOpção inválida!\n");
				option = '0';
				sleep (1);
				break;
		}
		
		system ("cls");
	} while (option == '0');
	
	for (i = 0; i < 8; i++) {					
		for (ii = 0; ii < 4; ii++) {
			strcpy (group [i].name [ii], team [aux]);
			group [i].sco [ii] = 0;
			group [i].vic [ii] = 0;
			group [i].def [ii] = 0;
			group [i].draw [ii] = 0;
			group [i].goals [ii] = 0;
			group [i].cgoal [ii] = 0;
			aux++;
		}
	}
	
	lgroup = 'A';
	
	for (i = 0; i < 8; i++) {
		printf (" ______________________\n");
		printf ("|________GRUPO %c_______|\n\n", lgroup++);
		for (ii = 0; ii < 4; ii++) {
			printf ("%s\n", group [i].name [ii]);
		}
		printf ("\n");
	}	

	system ("pause");
	system ("cls");
	
	do {
		printf ("....::: CADASTRO DOS ESTÁDIOS :::....\n\n");
		printf ("1- Cadastrar manualmente\n");
		printf ("2- Preenchimento automático (estádios da Copa de 2018)\n\n");
		printf (">> ");
		fflush (stdin);
		scanf ("%c", &option);
		system ("cls");
		
		switch (option) {
			case '1':
				printf ("....::: CADASTRO DOS ESTÁDIOS :::....\n\n");
				for (i = 0; i < 12; i++) {
					printf ("Estádio %d: ",i+1);
					fflush (stdin);
					gets (stadium [i]);					
				}
				break;
				
			case '2':
				strcpy (stadium [0], "ARENA KAZAN");
				strcpy (stadium [1], "ARENA ECATERIMBURGO");
				strcpy (stadium [2], "OLÍMPICO FISHT");
				strcpy (stadium [3], "KALININGRADO");
				strcpy (stadium [4], "LUZHNIKI");
				strcpy (stadium [5], "ARENA OTKRYTIYE (SPARTAK)");
				strcpy (stadium [6], "NIZHNY NOVGOROD");
				strcpy (stadium [7], "ARENA ROSTOV");
				strcpy (stadium [8], "KRESTOVSKY (ZENIT)");
				strcpy (stadium [9], "ARENA COSMOS (SAMARA)");
				strcpy (stadium [10], "ARENA MORDÓVIA");
				strcpy (stadium [11], "ARENA VOLGOGRADO");
				break;
				
			default:
				printf ("OPÇÃO INVÁLIDA!");
				sleep (1);
				break;
		}
		
		system ("cls");
	} while (option != '1' && option != '2');
	
	do {
		printf ("....::: CADASTRO DOS HÓRARIOS DOS JOGOS :::....\n\n");
		printf ("Horário 1: ");
		fflush (stdin);
		gets (m_time [0]);
		printf ("Horário 2: ");
		fflush (stdin);
		gets (m_time [1]);
		printf ("Horário 3: ");
		fflush (stdin);
		gets (m_time [2]);
		printf ("Horário 4: ");
		fflush (stdin);
		gets (m_time [3]);
		
		printf ("\nC- Corrigir\n");
		printf ("Enter- Confirmar\n\n");
		printf (">> ");
		fflush (stdin);
		scanf ("%c", &option);
		system ("cls");
	} while (option == 'c' || option == 'C');
	
	do{
		printf("....::: CADASTRO DOS PLACARES :::....\n\n");
		printf ("1- Digitar os Placares\n");
		printf ("2- Randomizar placares\n\n");
		printf (">> ");
		fflush(stdin);
		scanf("%c", &option);
		system ("cls");
		
		if (option != '1' && option != '2') {
			printf ("OPÇÃO INVÁLIDA!");
			option = '0';
			sleep (1);
			system ("cls");
		}
		
		else {
			printf ("....::: PRIMEIRA RODADA :::....\n\n");
			for (i = 0; i < 8; i++) {
				int goals1 = 0, goals2 = 0;
				
				if (day == 31) {
					day = 1;
					month++;
				}
				
				if (option == '1') {
					do {
						printf ("\tSELECIONE UM ESTÁDIO\n\n");
						Menu (50, stadium, EST);
						fflush (stdin);
						gets (op);
						sel = Conversor_Opcao (op);
						
						if (sel <= -1 || sel >= 12) {
							printf ("OPÇÃO INVÁLIDA!");
							sleep (1);
						}
						system ("cls");
					} while (sel <= -1 || sel >= 12);
					
					do {
						printf ("\tSELECIONE UM HORÁRIO\n\n");
						Menu (6, m_time, HOR);
						fflush (stdin);
						gets (op);
						s_sel = Conversor_Opcao (op);
						
						if (s_sel <= -1 || s_sel >= 4) {
							printf ("OPÇÃO INVÁLIDA!");
							sleep (1);
						}
						system ("cls");
					} while (s_sel <= -1 || s_sel >= 4);
					
					printf("\t%s\n", stadium [sel]);
					printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [s_sel]);
					printf ("%s X %s\n", group [i].name [0], group [i].name [1]);
					printf ("Gol(s) do time %s: ", group [i].name [0]);
					scanf ("%d", &goals1);
					printf ("Gol(s) do time %s: ", group [i].name [1]);
					scanf ("%d", &goals2);
					system ("cls");
				}
								
				if  (option == '2')	{
					goals1 = 1 + rand () % 5;
					goals2 = 1 + rand () % 5;	
					printf("\t%s\n", stadium [rand () % 12]);
					printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [rand () % 4]);
					printf ("%s [%d] X [%d] %s\n\n", group [i].name [0], goals1, goals2, group [i].name [1]);
					printf ("______________________________________\n\n");
					sleep (1);
				}
										
				Rodada_FaseDeGrupos (group, i, 0, 1, goals1, goals2);						
				goals1 = goals2 = 0;
				
				if (option == '1') {
					do {
						printf ("\tSELECIONE UM ESTÁDIO\n\n");
						Menu (50, stadium, EST);
						fflush (stdin);
						gets (op);
						sel = Conversor_Opcao (op);
						
						if (sel <= -1 || sel >= 12) {
							printf ("OPÇÃO INVÁLIDA!");
							sleep (1);
						}
						system ("cls");
					} while (sel <= -1 || sel >= 12);
					
					do {
						printf ("\tSELECIONE UM HORÁRIO\n\n");
						Menu (6, m_time, HOR);
						fflush (stdin);
						gets (op);
						s_sel = Conversor_Opcao (op);
						
						if (s_sel <= -1 || s_sel >= 4) {
							printf ("OPÇÃO INVÁLIDA!");
							sleep (1);
						}
						system ("cls");
					} while (s_sel <= -1 || s_sel >= 4);
					
					printf("\t%s\n", stadium [sel]);
					printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [s_sel]);
					printf ("%s X %s\n", group [i].name [2], group [i].name [3]);			
					printf ("Gol(s) do time %s: ", group [i].name [2]);
					scanf ("%d", &goals1);
					printf ("Gol(s) do time %s: ", group [i].name [3]);
					scanf ("%d", &goals2);
					system ("cls");
				}
					
				if (option == '2') {
					goals1 = 1 + rand () % 5;
					goals2 = 1 + rand () % 5;	
					printf("\t%s\n", stadium [rand () % 12]);
					printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [rand () % 4]);
					printf ("%s [%d] X [%d] %s\n\n", group [i].name [2], goals1, goals2, group [i].name [3]);
					printf ("______________________________________\n\n");
					sleep (1);							
				}
				
				if (i == 1 || i == 3 || i == 5 || i == 7) {
					day++;
				}
				
				Rodada_FaseDeGrupos (group, i, 2, 3, goals1, goals2);					
			}
			
		if (option == '2') {
			system ("pause");
		}
			
		printf ("\n\n....::: SEGUNDA RODADA :::....\n\n");
			for (i = 0; i < 8; i++) {
				int goals1 = 0, goals2 = 0;
				
				if (day == 31) {
					day = 1;
					month++;
				}
				
				if (option == '1') {
					do {
						printf ("\tSELECIONE UM ESTÁDIO\n\n");
						Menu (50, stadium, EST);
						fflush (stdin);
						gets (op);
						sel = Conversor_Opcao (op);
						
						if (sel <= -1 || sel >= 12) {
							printf ("OPÇÃO INVÁLIDA!");
							sleep (1);
						}
						system ("cls");
					} while (sel <= -1 || sel >= 12);
					
					do {
						printf ("\tSELECIONE UM HORÁRIO\n\n");
						Menu (6, m_time, HOR);
						fflush (stdin);
						gets (op);
						s_sel = Conversor_Opcao (op);
						
						if (s_sel <= -1 || s_sel >= 4) {
							printf ("OPÇÃO INVÁLIDA!");
							sleep (1);
						}
						system ("cls");
					} while (s_sel <= -1 || s_sel >= 4);
					
					printf("\t%s\n", stadium [sel]);
					printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [s_sel]);
					printf ("%s X %s\n", group [i].name [0], group [i].name [2]);
					printf ("Gol(s) do time %s: ", group [i].name [0]);
					scanf ("%d", &goals1);
					printf ("Gol(s) do time %s: ", group [i].name [2]);
					scanf ("%d", &goals2);
					system ("cls");
				}
				
				if (option == '2') {
					goals1 = 1 + rand () % 5;
					goals2 = 1 + rand () % 5;	
					printf("\t%s\n", stadium [rand () % 12]);
					printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [rand () % 4]);
					printf ("%s [%d] X [%d] %s\n\n", group [i].name [0], goals1, goals2, group [i].name [2]);
					printf ("______________________________________\n\n");
					sleep (1);
				}
		
				Rodada_FaseDeGrupos (group, i, 0, 2, goals1, goals2);				
				goals1 = goals2 = 0;
				
				if (option == '1') {
					do {
						printf ("\tSELECIONE UM ESTÁDIO\n\n");
						Menu (50, stadium, EST);
						fflush (stdin);
						gets (op);
						sel = Conversor_Opcao (op);
						
						if (sel <= -1 || sel >= 12) {
							printf ("OPÇÃO INVÁLIDA!");
							sleep (1);
						}
						system ("cls");
					} while (sel <= -1 || sel >= 12);
					
					do {
						printf ("\tSELECIONE UM HORÁRIO\n\n");
						Menu (6, m_time, HOR);
						fflush (stdin);
						gets (op);
						s_sel = Conversor_Opcao (op);
						
						if (s_sel <= -1 || s_sel >= 4) {
							printf ("OPÇÃO INVÁLIDA!");
							sleep (1);
						}
						system ("cls");
					} while (s_sel <= -1 || s_sel >= 4);
					
					printf("\t%s\n", stadium [sel]);
					printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [s_sel]);
					printf ("%s X %s\n", group [i].name [1], group [i].name [3]);
					printf ("Gol(s) do time %s: ", group [i].name [1]);
					scanf ("%d", &goals1);
					printf ("Gol(s) do time %s: ", group [i].name [3]);
					scanf ("%d", &goals2);
					system ("cls");
				}
				
				if (option == '2') {
					goals1 = 1 + rand () % 5;
					goals2 = 1 + rand () % 5;						
					printf("\t%s\n", stadium [rand () % 12]);
					printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [rand () % 4]);
					printf ("%s [%d] X [%d] %s\n\n", group [i].name [1], goals1, goals2, group [i].name [3]);
					printf ("______________________________________\n\n");
					sleep (1);
				}
				
				if (i == 1 || i == 3 || i == 5 || i == 7) {
					day++;
				}
					
				Rodada_FaseDeGrupos (group, i, 1, 3, goals1, goals2);
			}
			
		if (option == '2') {
			system ("pause");
		}
		
		printf ("\n\n....::: TERCEIRA RODADA :::....\n\n");
			for (i = 0; i < 8; i++) {
				int goals1 = 0, goals2 = 0;
				
				if (day == 31) {
					day = 1;
					month++;
				}
				
				if (option == '1') {
					do {
						printf ("\tSELECIONE UM ESTÁDIO\n\n");
						Menu (50, stadium, EST);
						fflush (stdin);
						gets (op);
						sel = Conversor_Opcao (op);
						
						if (sel <= -1 || sel >= 12) {
							printf ("OPÇÃO INVÁLIDA!");
							sleep (1);
						}
						system ("cls");
					} while (sel <= -1 || sel >= 12);
					
					do {
						printf ("\tSELECIONE UM HORÁRIO\n\n");
						Menu (6, m_time, HOR);
						fflush (stdin);
						gets (op);
						s_sel = Conversor_Opcao (op);
						
						if (s_sel <= -1 || s_sel >= 4) {
							printf ("OPÇÃO INVÁLIDA!");
							sleep (1);
						}
						system ("cls");
					} while (s_sel <= -1 || s_sel >= 4);
					
					printf("\t%s\n", stadium [sel]);
					printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [s_sel]);
					printf ("%s X %s\n", group [i].name [0], group [i].name [3]);
					printf ("Gol(s) do time %s: ", group [i].name [0]);
					scanf ("%d", &goals1);
					printf ("Gol(s) do time %s: ", group [i].name [3]);
					scanf ("%d", &goals2);
					system ("cls");
				}
				
				if (option == '2') {
					goals1 = 1 + rand () % 5;
					goals2 = 1 + rand () % 5;
					printf("\t%s\n", stadium [rand () % 12]);
					printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [rand () % 4]);
					printf ("%s [%d] X [%d] %s\n\n", group [i].name [0], goals1, goals2, group [i].name [3]);
					printf ("______________________________________\n\n");
					sleep (1);
				}
		
				Rodada_FaseDeGrupos (group, i, 0, 3, goals1, goals2);				
				goals1 = goals2 = 0;
				
				if (option == '1') {
					do {
						printf ("\tSELECIONE UM ESTÁDIO\n\n");
						Menu (50, stadium, EST);
						fflush (stdin);
						gets (op);
						sel = Conversor_Opcao (op);
						
						if (sel <= -1 || sel >= 12) {
							printf ("OPÇÃO INVÁLIDA!");
							sleep (1);
						}
						system ("cls");
					} while (sel <= -1 || sel >= 12);
					
					do {
						printf ("\tSELECIONE UM HORÁRIO\n\n");
						Menu (6, m_time, HOR);
						fflush (stdin);
						gets (op);
						s_sel = Conversor_Opcao (op);
						
						if (s_sel <= -1 || s_sel >= 4) {
							printf ("OPÇÃO INVÁLIDA!");
							sleep (1);
						}
						system ("cls");
					} while (s_sel <= -1 || s_sel >= 4);
					
					printf("\t%s\n", stadium [sel]);
					printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [s_sel]);
					printf ("%s X %s\n", group [i].name [1], group [i].name [2]);
					printf ("Gol(s) do time %s: ", group [i].name [1]);
					scanf ("%d", &goals1);
					printf ("Gol(s) do time %s: ", group [i].name [2]);
					scanf ("%d", &goals2);
					system ("cls");
				}
				
				if (option == '2') {
					goals1 = 1 + rand () % 5;
					goals2 = 1 + rand () % 5;				
					printf("\t%s\n", stadium [rand () % 12]);
					printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [rand () % 4]);
					printf ("%s [%d] X [%d] %s\n\n", group [i].name [1], goals1, goals2, group [i].name [2]);
					printf ("______________________________________\n\n");
					sleep (1);
				}
				
				if (i == 1 || i == 3 || i == 5 || i == 7) {
					day++;
				}
	
				Rodada_FaseDeGrupos (group, i, 1, 2, goals1, goals2);
			}
			
			if (option == '2') {
				system ("pause");
			}
		}

		system ("cls");
	} while(option == '0');	
	
	lgroup = 'A';	
	for (i= 0; i < 8; i++) {		
		for (ii = 0; ii < 4; ii++) {
			group [i].bal [ii] = group [i].goals [ii] - group [i].cgoal [ii];
		}		
	}
	
	for (i = 0; i < 8; i++) {		
		for (ii = 0; ii < 4; ii++) {			
			if (strlen (group [i].name [ii]) > perfumary) {
				perfumary = strlen (group [i].name [ii]);
			}
		}
	}
	
	lgroup='A';
	perfumary += 2;
	printf ("SELEÇÕES");	
	for (i = 0; i < 14; i++) {
		printf (" ");
	}	
	printf ("V  D  E  P  GM  GS   S\n\n");	
	for (i = 0; i < 8; i++) {
		printf("******GRUPO %c******\n\n", lgroup++);		
		for (ii = 0; ii < 4; ii++) {
			printf ("%s", group [i].name [ii]);			
			for (ti = 0; ti < perfumary - strlen (group [i].name [ii]); ti++) {
				printf (" ");
			}			
			printf ("      %d  %d  %d  %d  %d   %d  %d\n", group [i].vic [ii], group [i].def [ii], group [i].draw [ii], group [i].sco [ii], group [i].goals [ii], group [i].cgoal [ii], group [i].bal [ii]);
		}
		printf ("\n");
	}

	for (i = 0; i < 8; i++) {
		fsco = 0;
		ssco = 0;
		fbal = 0;
		sbal = 0;
		p = 0;
		pp = 0;
		flag = 0;
		same = 0;
		same2 = 0;
		
		for (ii = 0; ii < 4; ii++) {			
			if (ii == 0) {
				fsco = group [i].sco [ii];
				p = ii;
			}			
			if (fsco < group [i].sco [ii]) {
				fsco = group [i].sco [ii];
				p = ii;
			}
		}
		
		for (ii = 0; ii < 4; ii++) {			
			if (group [i].sco [ii] != fsco) {
				ssco = group [i].sco [ii];
				pp = ii;
			}			
			if (ssco < group [i].sco [ii] && group [i].sco [ii] != fsco) {
				ssco = group [i].sco [ii];
				pp = ii;
			}
		}
		
		for (ii = 0; ii < 4; ii++) {			
			if (group [i].sco [ii] == fsco) {
				same++;
			}
		}
		
		if (same == 1) {			
			for (ii = 0; ii < 4; ii++) {				
				if (group [i].sco [ii] == ssco) {
					same2++;
				}
			}
			
			if (same2 >= 2) {				
				for (ii = 0; ii < 4; ii++) {					
					if (group [i].sco [ii] == ssco && flag == 0) {
						sbal = group [i].bal [ii];
						pp = ii;
						flag = 1;
					}
					
					if (group [i].sco [ii] == ssco && group [i].bal [ii] > sbal) {
						sbal = group [i].bal [ii];
						pp = ii;
					}
				}
			}
		}
		
		else {			
			for (ii = 0; ii < 4; ii++) {				
				if (group [i].sco [ii] == fsco && flag == 0) {
					fbal = group [i].bal [ii];
					p = ii;
					flag = 1;
				}				
				if (group [i].sco [ii] == fsco && group [i].bal [ii] > fbal) {
					fbal = group [i].bal [ii];
					p = ii;
				}
			}
			
			flag = 0;
			
			for (ii = 0; ii < 4; ii++) {					
				if (group [i].sco [ii] == fsco && ii != p && flag == 0) {
					sbal = group [i].bal [ii];
					pp = ii;
					flag = 1;
				}				
				if (group [i].sco [ii] == fsco && ii != p && group [i].bal [ii] > sbal) {
					sbal = group [i].bal [ii];
					pp = ii;
				}
			}
		}
		
		strcpy (r16 [count], group [i].name [p]);
		count++;
		strcpy (r16 [count], group [i].name [pp]);
		count++;
	}
	
	system ("pause");
	system ("cls");	

	printf ("\n******OITAVAS DE FINAL******\n\n");
	
	for (i = 0; i < 16; i += 4) {
		strcpy (mr16 [i], r16 [i]);
		strcpy (mr16 [i+1], r16 [i+3]);
		strcpy (mr16 [i+2], r16 [i+1]);
		strcpy (mr16 [i+3], r16 [i+2]);
	}
	
	for (i = 0; i < 16; i++) {
		printf ("%s\n", mr16 [i]);
	}
	
	printf ("\n");
	system ("pause");
	system ("cls");
	
	for (i = 0, ii = 0; i < 16; i += 2, ii++) {
		int goals1, goals2;
		
		if (day == 31) {
			day = 1;
			month++;
		}
		
		do {
			printf ("\tSELECIONE UM ESTÁDIO\n\n");
			Menu (50, stadium, EST);
			fflush (stdin);
			gets (op);
			sel = Conversor_Opcao (op);
			
			if (sel <= -1 || sel >= 12) {
				printf ("OPÇÃO INVÁLIDA!");
				sleep (1);
			}
			system ("cls");
			} while (sel <= -1 || sel >= 12);
		
		do {
			printf ("\tSELECIONE UM HORÁRIO\n\n");
			Menu (6, m_time, HOR);
			fflush (stdin);
			gets (op);
			s_sel = Conversor_Opcao (op);
			
			if (s_sel <= -1 || s_sel >= 4) {
				printf ("OPÇÃO INVÁLIDA!");
				sleep (1);
			}
			system ("cls");
		} while (s_sel <= -1 || s_sel >= 4);
		
		printf("\t%s\n", stadium [sel]);
		printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [s_sel]);		
		printf ("%s x %s\n\n", mr16 [i], mr16 [i+1]);
		printf ("Gols da seleção %s: ", mr16 [i]);
		scanf ("%d", &goals1);
		printf ("Gols da seleção %s: ", mr16 [i+1]);
		scanf ("%d", &goals2);
		
		if (goals1 > goals2) {
			printf ("\nSeleção %s Venceu!\n\n", mr16 [i]);
			strcpy (qt [ii], mr16 [i]);			
		}
		
		else if (goals1 < goals2) {
			printf ("\nSeleção %s Venceu!\n\n", mr16 [i+1]);
			strcpy (qt [ii], mr16 [i+1]);			
		}
		
		else {
			
			do {
				printf ("\n\tPÊNALTIS\n");
				printf ("Digite a opção para selecionar a seleção vencedora.\n\n");
				printf ("1) %s\n", mr16 [i]);
				printf ("2) %s\n", mr16 [i+1]);
				printf ("\nOpção: ");
				fflush (stdin);
				scanf ("%c", &option);
			
				if (option == '1') {
					printf ("\nSeleção %s Venceu!\n\n", mr16 [i]);
					strcpy (qt [ii], mr16 [i]);
				}
				
				else if (option == '2') {
					printf ("\nSeleção %s Venceu!\n\n", mr16 [i+1]);
					strcpy (qt [ii], mr16 [i+1]);
				}
				
				else {
					printf ("\nOpção inválida!");
					option = '0';
					sleep (1);
					system ("cls");
				}
			} while (option == '0');
		}
		
		if (i == 2 || i == 6 || i == 10 || i == 14) {
			day++;
		}
		
		system ("pause");
		system ("cls");		
	}
	
	printf ("******QUARTAS DE FINAL******\n\n");
	
	for (i = 0; i < 8; i++) {
		printf ("%s\n", qt [i]);
	}
	
	printf("\n");
    system ("pause");
	system ("cls");
	
	for (i = 0, ii = 0; i < 8; i += 2, ii++) {
		int goals1, goals2;
		
		if (day == 31) {
			day = 1;
			month++;
		}
		
		do {
			printf ("\tSELECIONE UM ESTÁDIO\n\n");
			Menu (50, stadium, EST);
			fflush (stdin);
			gets (op);
			sel = Conversor_Opcao (op);
			
			if (sel <= -1 || sel >= 12) {
				printf ("OPÇÃO INVÁLIDA!");
				sleep (1);
			}
			system ("cls");
			} while (sel <= -1 || sel >= 12);
		
		do {
			printf ("\tSELECIONE UM HORÁRIO\n\n");
			Menu (6, m_time, HOR);
			fflush (stdin);
			gets (op);
			s_sel = Conversor_Opcao (op);
			
			if (s_sel <= -1 || s_sel >= 4) {
				printf ("OPÇÃO INVÁLIDA!");
				sleep (1);
			}
			system ("cls");
		} while (s_sel <= -1 || s_sel >= 4);
		
		printf("\t%s\n", stadium [sel]);
		printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [s_sel]);		
		printf ("%s x %s\n\n", qt [i], qt [i+1]);
		printf ("Gols da seleção %s: ", qt [i]);
		scanf ("%d", &goals1);
		printf ("Gols da seleção %s: ", qt [i+1]);
		scanf ("%d", &goals2);
		
		if (goals1 > goals2) {
			printf ("\nSeleção %s Venceu!\n\n", qt [i]);
			strcpy (sf [ii], qt [i]);			
		}
		
		else if (goals1 < goals2) {
			printf ("\nSeleção %s Venceu!\n\n", qt [i+1]);
			strcpy (sf [ii], qt [i+1]);			
		}
		
		else {
			do{
				printf ("\n\tPÊNALTIS\n");
				printf ("Digite a opção para selecionar a seleção vencedora.\n\n");
				printf ("1) %s\n", qt [i]);
				printf ("2) %s\n", qt [i+1]);
				printf ("\nOpção: ");
				fflush (stdin);
				scanf ("%c", &option);
				
				if (option == '1') {
					printf ("\nSeleção %s Venceu!\n\n", qt [i]);
					strcpy (sf [ii], qt [i]);
				}
			
				else if (option == '2') {
					printf ("\nSeleção %s Venceu!\n\n", qt [i+1]);
					strcpy (sf [ii], qt [i+1]);
				}
				
				else {
					printf ("\nOpção inválida!");
					option = '0';
					sleep (1);
					system ("cls");
				}
			} while (option == '0');
		}
		
		if (i == 2 || i == 6) {
			day++;
		}
		
		system ("pause");
		system ("cls");
	}
	
	day += 4;
	printf ("******SEMIFINAL******\n\n");
		
	for (i = 0; i < 4; i++) {
		printf ("%s\n", sf [i]);
	}
	
	printf ("\n");
	system ("pause");
	system ("cls");
	
	for (i = 0, ii = 0; i < 4; i += 2, ii++) {
		int goals1, goals2;
		
		if (day == 31) {
			day = 1;
			month++;
		}
		
		do {
			printf ("\tSELECIONE UM ESTÁDIO\n\n");
			Menu (50, stadium, EST);
			fflush (stdin);
			gets (op);
			sel = Conversor_Opcao (op);
			
			if (sel <= -1 || sel >= 12) {
				printf ("OPÇÃO INVÁLIDA!");
				sleep (1);
			}
			system ("cls");
			} while (sel <= -1 || sel >= 12);
		
		do {
			printf ("\tSELECIONE UM HORÁRIO\n\n");
			Menu (6, m_time, HOR);
			fflush (stdin);
			gets (op);
			s_sel = Conversor_Opcao (op);
			
			if (s_sel <= -1 || s_sel >= 4) {
				printf ("OPÇÃO INVÁLIDA!");
				sleep (1);
			}
			system ("cls");
		} while (s_sel <= -1 || s_sel >= 4);
		
		printf("\t%s\n", stadium [sel]);
		printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [s_sel]);
		printf ("%s x %s\n\n", sf [i], sf [i+1]);
		printf ("Gols da seleção %s: ", sf [i]);
		scanf ("%d", &goals1);
		printf ("Gols da seleção %s: ", sf [i+1]);
		scanf ("%d", &goals2);
		
		if (goals1 > goals2) {
			printf ("\nSeleção %s Venceu!\n\n", sf [i]);
			strcpy (final [ii], sf [i]);
			strcpy (third [ii], sf [i+1]);			
		}
		
		else if (goals1 < goals2) {
			printf ("\nSeleção %s Venceu!\n\n", sf [i+1]);
			strcpy (final [ii], sf [i+1]);	
			strcpy (third [ii], sf [i]);			

		}
		
		else {
			do {
				printf ("\n\tPÊNALTIS\n");
				printf ("Digite a opção para selecionar a seleção vencedora.\n\n");
				printf ("1) %s\n", sf [i]);
				printf ("2) %s\n", sf [i+1]);
				printf ("\nOpção: ");
				fflush (stdin);
				scanf ("%c", &option);
				
				if (option == '1') {
					printf ("\nSeleção %s Venceu!\n\n", sf [i]);
					strcpy (final [ii], sf [i]);
					strcpy (third [ii], sf [i+1]);
				}
			
				else if (option == '2') {
					printf ("\nSeleção %s Venceu!\n\n", sf [i+1]);
					strcpy (final [ii], sf [i+1]);
					strcpy (third [ii], sf [i]);
				}
				
				else {
					printf ("\nOpção inválida!");
					option = '0';
					sleep (1);
					system ("cls");
				}
			} while (option == '0');
		}
		
		day++;
		system ("pause");
		system ("cls");
	}
	
	day += 5;
	printf ("******TERCEIRO LUGAR******\n\n");
		
	for (i = 0; i < 2; i++) {
		printf ("%s\n", third [i]);
	}
	
	printf ("\n");
	system ("pause");
	system ("cls");
	
	int goals1, goals2;
	
	do {
			printf ("\tSELECIONE UM ESTÁDIO\n\n");
			Menu (50, stadium, EST);
			fflush (stdin);
			gets (op);
			sel = Conversor_Opcao (op);
			
			if (sel <= -1 || sel >= 12) {
				printf ("OPÇÃO INVÁLIDA!");
				sleep (1);
			}
			system ("cls");
			} while (sel <= -1 || sel >= 12);
		
		do {
			printf ("\tSELECIONE UM HORÁRIO\n\n");
			Menu (6, m_time, HOR);
			fflush (stdin);
			gets (op);
			s_sel = Conversor_Opcao (op);
			
			if (s_sel <= -1 || s_sel >= 4) {
				printf ("OPÇÃO INVÁLIDA!");
				sleep (1);
			}
			system ("cls");
		} while (s_sel <= -1 || s_sel >= 4);
		
	printf("\t%s\n", stadium [sel]);
	printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [s_sel]);
	printf ("%s x %s\n\n", third [0], third [1]);
	printf ("Gols da seleção %s: ", third [0]);
	scanf ("%d", &goals1);
	printf ("Gols da seleção %s: ", third [1]);
	scanf ("%d", &goals2);
		
	if (goals1 > goals2) {
		printf ("\nSeleção %s Venceu!\n\n", third [0]);
		strcpy(podium[2],third[0]);
		strcpy(podium[3],third[1]);
	}
	
	else if (goals1 < goals2) {
		printf ("\nSeleção %s Venceu!\n\n", third [1]);
		strcpy(podium[2],third[1]);
		strcpy(podium[3],third[0]);
	}
	
	else {
		do {
			printf ("\n\tPÊNALTIS\n");
			printf ("Digite a opção para selecionar a seleção vencedora.\n\n");
			printf ("1) %s\n", third [0]);
			printf ("2) %s\n", third [1]);
			printf ("\nOpção: ");
			fflush (stdin);
			scanf ("%c", &option);
			
			if (option == '1') {
				printf ("\nSeleção %s Venceu!\n\n", third [0]);
				strcpy(podium[2],third[0]);
				strcpy(podium[3],third[1]);
			}
	
			else if (option == '2') {
				printf ("\nSeleção %s Venceu!\n\n", third [1]);
				strcpy(podium[2],third[1]);
				strcpy(podium[3],third[0]);
			}
				
			else {
				printf ("\nOpção inválida!");
				option = '0';
				sleep (1);
				system ("cls");
			}
		} while (option == '0');
	}

	system ("pause");
	system ("cls");	
	
	day++;
	printf ("******FINAL******\n\n");

	if (day == 31) {
		day = 1;
		month++;
	}
	
	for (i = 0; i < 2; i++) {
		int goals1, goals2;
		printf ("%s\n", final [i]);
	}	
	
	printf ("\n");
	system ("pause");
	system ("cls");
	
	do {
			printf ("\tSELECIONE UM ESTÁDIO\n\n");
			Menu (50, stadium, EST);
			fflush (stdin);
			gets (op);
			sel = Conversor_Opcao (op);
			
			if (sel <= -1 || sel >= 12) {
				printf ("OPÇÃO INVÁLIDA!");
				sleep (1);
			}
			system ("cls");
			} while (sel <= -1 || sel >= 12);
		
		do {
			printf ("\tSELECIONE UM HORÁRIO\n\n");
			Menu (6, m_time, HOR);
			fflush (stdin);
			gets (op);
			s_sel = Conversor_Opcao (op);
			
			if (s_sel <= -1 || s_sel >= 4) {
				printf ("OPÇÃO INVÁLIDA!");
				sleep (1);
			}
			system ("cls");
		} while (s_sel <= -1 || s_sel >= 4);
		
	printf("\t%s\n", stadium [sel]);
	printf ("Data: %d/%d/%d\t\tHorário: %s\n\n", day, month, year, m_time [s_sel]);		
	printf ("%s x %s\n\n", final [0], final [1]);
	printf ("Gols da seleção %s: ", final [0]);
	scanf ("%d", &goals1);
	printf ("Gols da seleção %s: ", final [1]);
	scanf ("%d", &goals2);
		
	if (goals1 > goals2) {
		printf ("\nSeleção %s Venceu!\n\n", final [0]);
		strcpy(podium[0],final[0]);
		strcpy(podium[1],final[1]);
	}
	
	else if (goals1 < goals2) {
		printf ("\nSeleção %s Venceu!\n\n", final [1]);
		strcpy(podium[0],final[1]);
		strcpy(podium[1],final[0]);
	}
	
	else {
		do {
			printf ("\n\tPÊNALTIS\n");
			printf ("Digite a opção para selecionar a seleção vencedora.\n\n");
			printf ("1) %s\n", final [0]);
			printf ("2) %s\n", final [1]);
			printf ("\nOpção: ");
			fflush (stdin);
			scanf ("%c", &option);
			
			if (option == '1') {
				printf ("\nSeleção %s Venceu!\n\n", final [0]);
				strcpy(podium[0],final[0]);
				strcpy(podium[1],final[1]);
			}
	
			else if (option == '2') {
				printf ("\nSeleção %s Venceu!\n\n", final [1]);
				strcpy(podium[0],final[1]);
				strcpy(podium[1],final[0]);
			}
				
			else {
				printf ("\nOpção inválida!");
				option = '0';
				sleep (1);
				system ("cls");
			}
		} while (option == '0');
	}

	system ("pause");
	system ("cls");	

	printf("**********PÓDIO**********\n\n");
	printf("\t1º %s\n\n",podium[0]);
	printf("2º %s\n\t",podium[1]);
	printf("\t3º %s\n\n",podium[2]);
	
	system ("pause");

	return 0;
}