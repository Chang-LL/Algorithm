#pragma once
//n皇后问题
//判断两个皇后是否在同一列或者同一斜线上
bool Place(int k, int i, int*x);
void NQueens(int k, int n, int*x);
void NQueens(int n, int *x);