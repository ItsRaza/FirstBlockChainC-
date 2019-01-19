#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"BlockChain.h"
#include"TData.h"
#include"SHA256.h"
#include "Block.h"
using namespace std;
int main()
{
	Blockchain bla;
	time_t curr;
	TData D(10.2, "Raza", "Hur", time(&curr));
	bla.addBlock(D);
	TData D2(113.1, "Faraz", "Raza", time(&curr));
	bla.addBlock(D2);
	bla.Print();
	cout << endl;
	cout << bla.IsChainValid() << endl;
	system("Pause");
}