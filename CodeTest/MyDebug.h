#pragma once

#include <chrono>
#include <random>
#include <iostream>

using namespace std;

class MyDebugTimer
{
public:
	std::chrono::steady_clock::time_point start;

	void StartTimer()
	{
		start = std::chrono::steady_clock::now();
	}

	void EndTimer()
	{
		chrono::duration<double> sec;
		sec = std::chrono::steady_clock::now() - start;
		cout << sec.count() << "\n";
	}

	static MyDebugTimer* GetInstance()
	{
		static MyDebugTimer Inst = MyDebugTimer();
		return &Inst;
	}

private:
	MyDebugTimer() {}
};

class MyDebugRandom
{
public:
	random_device rd;
	mt19937 gen;

	int GetRandomNumber(int mn, int mx)
	{
		uniform_int_distribution<int> dis(mn, mx);
		return dis(gen);
	}

	static MyDebugRandom* GetInstance()
	{
		static MyDebugRandom Instance = MyDebugRandom();
		return &Instance;
	}

private:
	MyDebugRandom()
		: gen(rd())
	{
	}
};

#define D_INIT MyDebugRandom* InstRandom = MyDebugRandom::GetInstance();\
MyDebugTimer* InstTimer = MyDebugTimer::GetInstance()
