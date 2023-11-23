#include <iostream>                          /* biblioteca para entrada e saida               */
#include <windows.h>                         /* bibliteca para usar o windows                 */
#include <conio.h>
#include "../../headersFifa.h"
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 7)
	{
		std::cout << "Error. Usage: " << argv[0] << " colCarta linCarta colPergunta linPergunta colBan linBan\n";
		exit(0);
	}

	// This structure will be used to create the keyboard
	// input event.
	INPUT ip;
	int buyNow;

	int colCarta, linCarta;										  /* coluna e linha da tela                        */
	int colPergunta, linPergunta;
	int colBan, linBan;
	int ciclo;
	int velocidadeProgram = 1000;

	colCarta = atoi(argv[1]);
	linCarta = atoi(argv[2]);

	colPergunta = atoi(argv[3]);
	linPergunta = atoi(argv[4]);

	colBan = atoi(argv[5]);
	linBan = atoi(argv[6]);

	cout << "colCarta: " << colCarta << "\nlinCarta: " << linCarta << "\ncolPergunta: " << colPergunta << "\nlinPergunta: " << linPergunta << "\ncolBan: " << colBan << "\nlinBan: " << linBan << "\n";

	cout << "Velocidade do programa em ms:\n";
	cin >> velocidadeProgram;
	cout << "até quanto vai: " << endl;
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

	POINT pt;											 /* para usar as coordenadas do mouse             */
	HDC hdc = GetDC(0);									 /* HDC é o buffer da tela Toda                   */
	COLORREF clrf;										 /* para trabalhar com cores                      */
	POINT pt1;
	HDC hdc1 = GetDC(0);
	COLORREF clrf1;

	POINT ptBan;											 /* para usar as coordenadas do mouse             */
	HDC hdcBan = GetDC(0);									 /* HDC é o buffer da tela Toda                   */
	COLORREF clrfBan;										 /* para trabalhar com cores                      */


	colCarta = 1233;
	linCarta = 508;

	colPergunta = 760;
	linPergunta = 412;

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

			pesquisar();
			//std::cout << "Pesquisou\n";

			//std::cout << "Ciclo: " << e << endl;
			//std::cout << "Rodada: " << i << endl;
			//std::cout << "Compras: " << compras << endl;
			Sleep(40);


			bool entrei = false;
			for (int h = 1; h < 10400; h++) {
				
				//hdc = GetDC(0);
				clrf = GetPixel(hdc, colCarta, linCarta);
				int r = GetRValue(clrf);
				//int g = GetGValue(clrf);
				//int b = GetBValue(clrf);


				
				if (r > 215) {
					for (int z = 0; z < 4; z++) {
						comprar();
						std::cout << "comprou\n";
						cout << '\a';
						cout << r << '\a';
					}
					gravarTela();
					std::cout << r;
					cout << '\a';
					//std::cout << b;
					cout << '\a';
					std::cout << colCarta;
					cout << '\a';
					std::cout << linCarta;
					cout << '\a';
					Sleep(1300);
					compras++;
					gravarTela();
					std::cout << "Parou\n";
					Sleep(4000);
					std::cout << "Voltou\n";
					break;
				}

				hdc1 = GetDC(0);
				clrf1 = GetPixel(hdc1, colPergunta, linPergunta);
				int r1 = GetRValue(clrf1);
				int g1 = GetGValue(clrf1);
				int b1 = GetBValue(clrf1);
				if (b1 > 204) {
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
	Sleep(9999999);
	Sleep(9999999);
	Sleep(9999999);
	Sleep(9999999);
	Sleep(9999999);
	Sleep(9999999);
	Sleep(9999999);
	Sleep(9999999);
	Sleep(9999999);
	Sleep(9999999);
	Sleep(9999999);
	Sleep(9999999);
	Sleep(9999999);
	Sleep(9999999);
	Sleep(9999999);

	return 0;
}
