#pragma once

#include <chrono>
#include <random>
#include <iostream>

std::chrono::system_clock::time_point start;
std::chrono::duration<double> sec;
std::random_device rd;
std::mt19937 gen(rd());

#define D_DIS(mn, mx)			uniform_int_distribution<int> dis(mn, mx)
#define D_DISONE(mn, mx)		uniform_int_distribution<int> dis1(mn, mx)
#define D_DISTWO(mn, mx)		uniform_int_distribution<int> dis2(mn, mx)
#define D_DISTHREE(mn, mx)	uniform_int_distribution<int> dis3(mn, mx)
#define D_DISFOUR(mn, mx)		uniform_int_distribution<int> dis4(mn, mx)

#define D_CURTIME		start = std::chrono::system_clock::now()
#define D_ELAPSETIME	sec = std::chrono::system_clock::now() - start; \
						cout << sec.count() << "\n"

	

