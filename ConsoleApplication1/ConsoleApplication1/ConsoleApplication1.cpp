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
	cout << "Velocidade do programa em ms:\n";
	cin >> velocidadeProgram;
	cout << "até quanto vai: " << endl;
	cout << "até 850: 1 " << endl;
	cout << "até 2,300: 2 " << endl;
	cout << "até 4k: 3 " << endl;
	cout << "até 7k: 4 " << endl;
	cout << "até 10k: 5 " << endl;
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


	colCarta = 1112;
	linCarta = 286;

	colPergunta = 739;
	linPergunta = 387;

	colBan = colCarta + 20;
	linBan = linCarta - 45;
	myfile << "Dados da execução:\n";

	for (e = 0; e < quantidadeCiclo; e++)
	{

		std::cout << "Novo Ciclo \n \n";
		for (int i = 0; i < buyNow; i++)
		{

			std::cout << "\n Nova Pesquisa \n \n";
			Sleep(150);
			aumentarBin();
			std::cout << "Aumentou bid \n";
			Sleep(velocidadeProgram);

			pesquisar();
			std::cout << "Pesquisou\n";




			std::cout << "Ciclo: " << e << endl;
			std::cout << "Rodada: " << i << endl;
			std::cout << "Compras: " << compras << endl;
			Sleep(150);

			hdcBan = GetDC(0);
			clrfBan = GetPixel(hdcBan, colBan, linBan);
			int rBan = GetRValue(clrfBan);
			int gBan = GetGValue(clrfBan);
			int bBan = GetBValue(clrfBan);

			if (rBan == 227) {
				myfile << "Numero de ciclos: " << e << " numero de compras: " << compras << "\n";
				if (rBan == 227)
					cout << "Banzinho meu galo, da uma segurada.\n";

				Beep(500, 500);
				return -1;
				Sleep(9999999);
				Sleep(9999999);
				Sleep(9999999);
				return -1;
			}
			for (int h = 1; h < 500; h++) {

				Sleep(4);
				comprar();
				hdc = GetDC(0);
				clrf = GetPixel(hdc, colCarta, linCarta);
				int r = GetRValue(clrf);
				int g = GetGValue(clrf);
				int b = GetBValue(clrf);
				hdc1 = GetDC(0);
				clrf1 = GetPixel(hdc1, colPergunta, linPergunta);
				int r1 = GetRValue(clrf1);
				int g1 = GetGValue(clrf1);
				int b1 = GetBValue(clrf1);

				hdcBan = GetDC(0);
				clrfBan = GetPixel(hdcBan, colBan, linBan);
				int rBan = GetRValue(clrfBan);
				int gBan = GetGValue(clrfBan);
				int bBan = GetBValue(clrfBan);

				if (h == 5) {
					std::cout << "R: " << r << endl;
					std::cout << "B: " << b << endl;
					std::cout << "G: " << g << endl;
				}


				if (r == 6 || rBan == 227) {
					myfile << "Numero de ciclos: " << e << " numero de compras: " << compras << "\n";
					if (rBan == 227)
					{
						cout << "Banzinho meu galo, da uma segurada.\n";
					}
					else {
						cout << "Acerta os bixo e volta. Abraços \n";
					}

					Beep(500, 500);
					return -1;
					Sleep(9999999);
					Sleep(9999999);
					Sleep(9999999);
				}
				if (r == 255) {
					if (h % 2 == 0) {
						std::cout << "acabou " << endl;
						Beep(523, 500);
						comprar();
						return -1;
						Sleep(9999999);
						Sleep(9999999);
						Sleep(9999999);
						Sleep(9999999);
						Sleep(9999999);
						Sleep(9999999);
					}
				}
				if (b1 > 220) {
					voltar();
					std::cout << "Voltando. " << endl;
					h = 600;
				}
				else {
					if (r > 23 && b > 40) {
						gravarTela();
						std::cout << r;
						std::cout << b;
						std::cout << colCarta;
						std::cout << linCarta;
						//if (b >= 71 & b <= 81) {
							//if (g >= 64 & g <= 74) {
						for (int z = 0; z < 2; z++) {
							comprar();
							std::cout << "comprou\n";
							cout << '\a';
							cout << r << '\a';



						}
						Sleep(1000);
						compras++;
						gravarTela();
						std::cout << "Parou\n";
						Sleep(3000);
						std::cout << "Voltou\n";
						h = 500;
						//exit(0);

				//}

					}









				}

			}


			voltar();

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