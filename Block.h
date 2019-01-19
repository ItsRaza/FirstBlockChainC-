#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#include "TData.h"
#include"SHA256.h"
#pragma once
using namespace std;
class Block
{
private:
	
public:
	int index;
	string Hash;
	string PrevHash;
	TData data;
	int nonce;
	Block(){}
	Block(int indx, TData in, string PrevHash_in)
	{
		index = indx;
		data = in;
		PrevHash = PrevHash_in;
		Hash = Hash_fn();
	}
	string Hash_fn()
	{
		string toHash = to_string(data.amount) + data.Sender + data.Recevier +to_string(data.timeStamp)+to_string(nonce);
		return sha256(toHash);

	}
	bool IsHashValid()
	{
		return Hash_fn() == Hash;
	}
	void MineBlock(int diff)
	{
		string target = "";
		std::replace(target.begin(), target.end(), '\0', '0');
		while (Hash.substr(0, diff) != target)
		{
			nonce++;
			Hash = Hash_fn();
		}
		cout << "Block Mined with hash:" << Hash << endl;
	}
};