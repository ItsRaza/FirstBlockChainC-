#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<string>
#pragma once
using namespace std;
class TData
{
public:
	double amount;
	string Sender;
	string Recevier;
	time_t timeStamp;
	TData(){}
	TData(double amt, string S, string R, time_t T)
	{
		amount = amt;
		Sender = S;
		Recevier = R;
		timeStamp = T;
	}
	void Print()
	{
		cout<<"Amount:" << amount << endl;
		cout<<"Sender:" << Sender << endl;
		cout<<"Recevier:" << Recevier << endl;
		cout<<"Time:" << timeStamp << endl;
	}
};