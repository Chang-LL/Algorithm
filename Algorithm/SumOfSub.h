#pragma once
//�Ӽ������㷨
/*
	��֪n����ͬ������wi(0<=i<=n-1)�ļ���
	��ü������������������Ӽ�
	ʹ��ÿ���Ӽ��е�����֮�͵��ڸ�������һ������M
*/
//ǰ������
//wi<=wi+1(0<=i<n-1) s+r>=m&&s+wk<=m 
//(s=(i:0 - k-1)���wixi,r=(i:k - n-1)���wi
//��������
//����x0,x1...xkΪ����������������״̬
void SumOfSub(float s, int k, float r, int*x, float m, float*w);
void SumOfSub(int*x, int n, float m, float*w);