#pragma once
#include "stdafx.h"
#include "constants.h"

template <typename T>void pop_col_back(T** arr, const int rows, int& cols);
template <typename T>void pop_col_front(T** arr, const int rows, int& cols);
template <typename T>void erase_col(T** arr, const int rows, int& cols, const int index);