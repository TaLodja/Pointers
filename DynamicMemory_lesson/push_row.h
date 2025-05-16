#pragma once

template <typename T>T** push_row_back(T** arr, int& rows, const int cols);
template <typename T>T** push_row_front(T** arr, int& rows, const int cols);
template <typename T>T** insert_row(T** arr, int& rows, const int cols, const int index);