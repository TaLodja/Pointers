#pragma once

template <typename T>T** pop_col_back(T** arr, const int rows, int& cols);
template <typename T>T** pop_col_front(T** arr, const int rows, int& cols);
template <typename T>T** erase_col(T** arr, const int rows, int& cols, const int index);