#pragma once
#include "stdafx.h"
#include "constants.h"

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n, int minRand = 0, int maxRand = 256);


void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols, int minRand = 0, int maxRand = 256);