#pragma once
#include "stdafx.h"
#include "constants.h"

template <typename T>T** Allocate(const int rows, const int cols);
template <typename T>void Clear(T** arr, const int rows);