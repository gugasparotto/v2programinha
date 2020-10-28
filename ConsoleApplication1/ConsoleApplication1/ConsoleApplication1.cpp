#include <iostream>                          /* biblioteca para entrada e saida               */
#include <windows.h>                         /* bibliteca para usar o windows                 */
#include <conio.h>
#include "../../headersFifa.h"
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <string>
#include <chrono>
#include <ctime> 
#include <sstream>
using namespace std;
#pragma warning(disable : 4996)
int main()
{
	
	// This structure will be used to create the keyboard
	// input event.
	INPUT ip;
	int buyNow;

	int ciclo;
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
		buyNow = 120;
	}



	int quantidadeCiclo = buyNow - 1;
	int e;
	int compras = 0;
	int compras1 = 0;

	// Pause for 5 seconds.
	Sleep(2000);
	//for (int i = 0; i < buyNow; i++)
	//{
	//	aumentarBin();
	//	Sleep(2);
	//}
	//Sleep(9999);

	int col, lin;										  /* coluna e linha da tela                        */
	POINT pt;											 /* para usar as coordenadas do mouse             */
	HDC hdc = GetDC(0);									 /* HDC é o buffer da tela Toda                   */
	COLORREF clrf;										 /* para trabalhar com cores                      */
	int col1, lin1;
	POINT pt1;
	HDC hdc1 = GetDC(0);
	COLORREF clrf1;

	ofstream myfile;
	stringstream nn;
	string myfilename = "test";
	int counter = 1;
	nn << myfilename << counter << ".txt";

	myfile.open(nn.str(), std::ios_base::app);

	auto end = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	myfile << "Aberto programa em: " << std::ctime(&end_time) << "\n";

	for (e = 0; e < quantidadeCiclo; e++)
	{

		std::cout << "Novo Ciclo \n \n";
		for (int i = 0; i < buyNow; i++)
		{
			std::cout << "\n Novaa Pesquisa \n \n";
			myfile << "\n Novaa Pesquisa \n \n";
			Sleep(150);
			aumentarBin();
			std::cout << "Aumentou bid \n";
			myfile << "Aumentou bid \n";
			Sleep(500);

			pesquisar();
			std::cout << "Pesquisou\n";

			Sleep(400);
			comprar();
			comprar();
			Sleep(400); //valor real= 150
			comprar();
			comprar();
			Sleep(400);
			comprar();
			comprar();
			Sleep(500);
			comprar();
			comprar();
			
			
			std::cout << "Edicao" << e << endl;
			std::cout << "Rodada" << i << endl;
			std::cout << "compras" << compras << endl;
			std::cout << "compras V2" << compras1 << endl;
			for (int h = 1; h < 40; h++) { //valor de h= 70 e sleep =10
				Sleep(20);
				col = 1436;
				lin = 318;
				hdc = GetDC(0);/* reseta o hdc                                  */
				clrf = GetPixel(hdc, col, lin);/* o valor int da cor nessa posção               */
				int r = GetRValue(clrf);/* r recebe a quantidade de vermelho dessa pixel */
				int g = GetGValue(clrf);/* g recebe a quantidade de verde    dessa pixel */
				int b = GetBValue(clrf);/* b recebe a quantidade de azul     dessa pixel */
				if (h == 5) {
					std::cout << "linha: " << lin << endl;
					std::cout << "coluna: " << col << endl;
					std::cout << "R: " << r << endl;
					std::cout << "B: " << b << endl;
					std::cout << "G: " << g << endl;
				}

				Sleep(20);
				if (r == 6) {
					cout << "travou";
					Beep(500, 500);
					Sleep(9999999);
					Sleep(9999999);
					Sleep(9999999);
				}
				if (r == 255) {
					if (h % 2 == 0) {
						std::cout << "acabou " << endl;
						Beep(523, 500);
						comprar();

						Sleep(9999999);
						Sleep(9999999);
						Sleep(9999999);
						Sleep(9999999);
						Sleep(9999999);
						Sleep(9999999);
					}
				}
				else {
					if (r > 23 & b > 40) {
						std::cout << r;
						std::cout << b;
						std::cout << col;
						std::cout << lin;
						//if (b >= 71 & b <= 81) {
							//if (g >= 64 & g <= 74) {
						for (int z = 0; z < 2; z++) {
							comprar();
							std::cout << "comprou\n";
							cout << '\a';
							cout << r << '\a';



						}
						Sleep(6000);
						compras++;
						std::cout << "parou\n";
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
	myfile.close();
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
