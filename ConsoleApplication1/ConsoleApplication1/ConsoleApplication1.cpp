#include <iostream>                          /* biblioteca para entrada e saida               */
#include <windows.h>                         /* bibliteca para usar o windows                 */
#include <conio.h>
#include "../../headersFifa.h"
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{

	// This structure will be used to create the keyboard
	// input event.
	INPUT ip;
	int buyNow;

	int ciclo;
	int velocidadeProgram = 1000;
	cout << "Velocidade do programa em ms:1\n";
	cin >> velocidadeProgram;
	cout << "até quanto vai1: " << endl;
	cout << "até 850: 1 " << endl;
	cout << "até 2,300: 2 " << endl;
	cout << "até 4k: 3 " << endl;
	cout << "até 7k: 4 " << endl;
	cout << "até 10k: 5 " << endl;
	cout << "até 350: 6 " << endl;
	cin >> ciclo;
	if (ciclo == 1) {
		buyNow = 14;
	}
	else if (ciclo == 2) {
		buyNow = 30;
	}
	else if (ciclo == 3) {
		buyNow = 50;
	}
	else if (ciclo == 4) {
		buyNow = 80;
	}
	else if (ciclo == 5) {
		buyNow = 11120;
	}
	else if (ciclo == 6) {
		buyNow = 5;

	}

	ofstream myfile;
	myfile.open("SaidaDados.txt");


	int quantidadeCiclo = buyNow - 1;
	int e;
	int compras = 0;
	// Pause for 5 seconds.
	Sleep(2000);
	//for (int i = 0; i < buyNow; i++)
	//{
	//	aumentarBin();
	//	Sleep(2);
	//}
	//Sleep(9999);

	int colCarta, linCarta;										  /* coluna e linha da tela                        */
	POINT pt;											 /* para usar as coordenadas do mouse             */
	HDC hdc = GetDC(0);									 /* HDC é o buffer da tela Toda                   */
	COLORREF clrf;										 /* para trabalhar com cores                      */
	int colPergunta, linPergunta;
	int colBan, linBan;
	POINT pt1;
	HDC hdc1 = GetDC(0);
	COLORREF clrf1;

	POINT ptBan;											 /* para usar as coordenadas do mouse             */
	HDC hdcBan = GetDC(0);									 /* HDC é o buffer da tela Toda                   */
	COLORREF clrfBan;										 /* para trabalhar com cores                      */


	colCarta = -582;
	linCarta = 553;

	colPergunta = -919;
	linPergunta = 488;

	colBan = 1296;
	linBan = 246;
	myfile << "Dados da execução:\n";

	for (e = 0; e < quantidadeCiclo; e++)
	{

		std::cout << "Novo Ciclo \n \n";
		for (int i = 0; i < buyNow; i++)
		{

			std::cout << "\n Nova Pesquisa \n \n";
			Sleep(150);
			if (i != 0) {
				aumentarBin();
			}
			std::cout << "Aumentou bid \n";
			Sleep(velocidadeProgram);
			std::cout << "passei 1 \n";
			bool entrei = false;
			pesquisar();
			//std::cout << "Pesquisou\n";

			//std::cout << "Ciclo: " << e << endl;
			//std::cout << "Rodada: " << i << endl;
			//std::cout << "Compras: " << compras << endl;
			Sleep(10);


			for (int h = 1; h < 10400; h++) {

				//hdc = GetDC(0);
				clrf = GetPixel(hdc, colCarta, linCarta);
				int r = GetRValue(clrf);
				int g = GetGValue(clrf);
				//int b = GetBValue(clrf);
				std::cout << r;


				if (r == 252 && g == 252) {
					comprar();
					comprar();
					comprar();
					comprar();
					comprar();
					cout << '\a';
					std::cout << "comprou\n";
					std::cout << r;
					cout << '\a \n';
					//std::cout << b;
					cout << '\a';
					std::cout << colCarta;
					cout << '\a';
					std::cout << linCarta;
					cout << '\a';
					comprar();
					Sleep(4);
					comprar();
					Sleep(4);
					std::cout << "caralhooooooooooooooooooo\n";
					comprar();
					Sleep(4);
					comprar();
					Sleep(19300);
					compras++;
					std::cout << "Parou\n";
					//Sleep(7000);
					std::cout << "Voltou\n";
					break;
				}

				hdc1 = GetDC(0);
				clrf1 = GetPixel(hdc1, colPergunta, linPergunta);
				int r1 = GetRValue(clrf1);
				int g1 = GetGValue(clrf1);
				int b1 = GetBValue(clrf1);
				if (b1 == 247 && g1 == 252) {
					entrei = true;
					voltar();
					std::cout << "Voltando1. " << endl;
					break;
				}


				Sleep(2);

				//ban 
				hdcBan = GetDC(0);
				clrfBan = GetPixel(hdcBan, colBan, linBan);
				int rBan = GetRValue(clrfBan);
				int gBan = GetGValue(clrfBan);
				int bBan = GetBValue(clrfBan);
				if (rBan > 209 && rBan < 214) {

					std::cout << "banzinho meu rei. " << endl;
					exit(3);

				}


			}

			if (!entrei) {
				std::cout << "Voltando2. " << endl;
				voltar();
			}

		}

		std::cout << "Fim loop\n";

		resetBin();
		std::cout << "Reseta o BIN\n";
		Sleep(390);

		aumentarBin();
		std::cout << "Aumentou bid \n";
		Sleep(390);
		aumentarBid();
		std::cout << "Aumentar o bid \n";
		Sleep(390);
		for (int n = 1; n < e; n++) {
			aumentarBid();
			std::cout << "Aumentar o bid \n";
		}
		buyNow--;
		std::cout << "Diminui quantidade de ciclo em 1 \n";


	}
	// Exit normally
	cout << '\a';
	cout << '\a';
	cout << '\a';
	cout << '\a';
	Sleep(9999999);


	return 0;
}
