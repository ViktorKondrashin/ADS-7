// Copyright 2022 NNTU-CS
#include <iostream>
#include <ctime>
#include <random>
#include "train.h"

// 0 - все лампочки включены 1 - все выключены
// 2 - рандомное распределение
void runTest(int n, char initLight) {
  Train t;
  int isNoRand = 1;
  if (initLight == 2) isNoRand = 0;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::bernoulli_distribution coin(0.5);
  for (int i = 1; i < n; ++i) {
    if (isNoRand) {
      t.addCar(initLight);
    } else {
      t.addCar(coin(gen));
    }
    if (i % 100 == 0) {
      int length = t.getLength();
      int ops = t.getOpCount();
      std::cout
      << length << " "
      << ops
      << std::endl;
    }
  }
}

// 0 - все лампочки включены 1 - все выключены
// 2 - рандомное распределение
void runTestT(int n, char initLight) {
  clock_t sum = 0;
  Train t;
  int isNoRand = 1;
  if (initLight == 2) isNoRand = 0;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::bernoulli_distribution coin(0.5);
  for (int i = 1; i < n; ++i) {
    if (isNoRand) {
      t.addCar(initLight);
    } else {
      t.addCar(coin(gen));
    }
    if (i % 100 == 0) {
      clock_t t_start = std::clock();
      int length = t.getLength();
      clock_t t_end = std::clock();
      sum += 1000.0 * static_cast<double>(t_end - t_start) / CLOCKS_PER_SEC;
      std::cout
          << length << " "
          << sum
          << std::endl;
    }
  }
}

int main() {
  //необхолимо использовать два теста поочередно
  runTest(1000, 1);
  runTestT(10001, 2);
  return 0;
}
