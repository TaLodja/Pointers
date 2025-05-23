#pragma once
#include "constants.h"

template <typename T>T** push_col_back(T** arr, const int rows, int& cols);
template <typename T>T** push_col_front(T** arr, const int rows, int& cols);
template <typename T>T** insert_col(T** arr, const int rows, int& cols, const int index);