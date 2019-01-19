#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
#include "TData.h"
#include"Block.h"
#include"SHA256.h"
using namespace std;
class Blockchain
{
public:
	vector<Block> Chain;
	Blockchain()
	{
		Block Genisis = createGene();
		Chain.push_back(Genisis);
	}
	Block createGene()
	{
		time_t current;
		TData data(0.0, "Gene", "Gene", time(&current));
		//string toHash = to_string(data.amount) + data.Sender + data.Recevier +to_string(data.timeStamp);
		//string hash1=sha256(0);
		Block Genisis(0, data, to_string(0));
		return Genisis;
	}
	Block getLast()
	{
		return Chain.back();
	}
	void addBlock(TData in)
	{
		if (Chain.size() == 0)
		{
			Chain.push_back(createGene());
		}
		string lastHash = getLast().Hash;
		Block newBlock(Chain.size(), in, lastHash);
		Chain.push_back(newBlock);
	}
	bool IsChainValid()
	{
		vector<Block>::iterator i;
		string target = "";
		std::replace(target.begin(), target.end(), '\0', '0');
		for (i = Chain.begin(); i != Chain.end(); i++)
		{
			Block curr = *i;
			if (!curr.IsHashValid())
			{
				return false;
			}
			if (i != Chain.begin())
			{
				Block pre = *(i - 1);
				if (curr.PrevHash != pre.Hash)
				{
					return 0;
				}
				if (curr.Hash.substr(0, 0) != target)
				{
					cout << "This block was not mined" << endl;
					return 0;
				}
			}
		}
		return 1;
	}
	void Print()
	{
		vector<Block>::iterator i;
		for (i = Chain.begin(); i != Chain.end(); i++)
		{
			Block curr = *i;
			cout<<"Index:" << curr.index << endl;
			curr.data.Print();
			cout<<"Current Hash:" << curr.Hash << endl;
			cout << "Previous Hash:" << curr.PrevHash << endl << endl;
			//cout << curr.IsHashValid() << endl << endl;;
		}
	}
};