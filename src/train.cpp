// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCar(bool light) {
  Car* tempCar = new Car;
  if (first == nullptr) {
    first = tempCar;
    *first = {light, first, first};
    return;
  }
  Car* oldFirstPrev = first->prev;
  oldFirstPrev->next = first->prev = tempCar;
  *tempCar = {light, first, oldFirstPrev};
}

int Train::getLength() {
  // Проверка отсутствия вагонов
  if (first == nullptr) {
    return 0;
  }
  Car* tempCar = first;
  first->light = true;
  countOp = 0;
  int countCar = 1, reverseCountCar;
  do {
    // Переходим на следующий вагон
    tempCar = tempCar->next;
    ++countOp;
    ++countCar;
    // Если лампочка включена, то выключаем её и проверяем, 
    // что не выключили первую лампочку
    if (tempCar->light == true) {
      tempCar->light = false;
      // Пора проверить не выключили ли мы первую лампочку
      reverseCountCar = countCar;
      while (reverseCountCar != 1) {
        tempCar = tempCar->prev;
        --reverseCountCar;
        ++countOp;
      }
      // Все-таки выключили
      if (tempCar->light == false) {
        return countCar - 1;
      }
      countCar = 1;
    }
  } while (true);
}

int Train::getOpCount() {
  return countOp;
}
