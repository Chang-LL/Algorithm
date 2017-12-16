/*
	��ˮ����ҵ�������� ��flow shop schedule��
	��һ����ˮ������n����ҵJ={J0,J1...Jn-1}��m̨�豸P={P1,P2...Pm}��
	ÿ����ҵ������ִ��m���������е�j������ֻ���ڵ�j̨�豸��ִ��
	ÿ̨�豸��һʱ��ֻ�ܴ���һ������
	����ִ��:��j-1������δ���ʱ�����Դ����j������
	���i����ҵ�ĵ�j������Tij����ʱ��Ϊtij��
	��n * m����������m̨�豸
*/
#include"stdafx.h"
#include<math.h>
#include<algorithm>
struct Triplet
{
	int operator<(Triplet b)const { return t < b.t; }
	int jobNo, t, ab;//��ҵ�ţ�����ʱ�䣬�豸��
};


void FLowShop(int n, int*a, int*b, int *c)
{
	//a[i]��b[i]�ֱ�Ϊ��ҵi����̨�豸�ϵĴ���ʱ��
	const int mSize = 100;
	Triplet d[mSize] = { {0,0,0} };
	for (int i = 0; i < n; i++)//������Ԫ���
		if (a[i] < b[i]) {
			d[i].jobNo = i;
			d[i].ab = 0;
			d[i].t = a[i];
		}
		else {
			d[i].jobNo = i;
			d[i].ab = 1;
			d[i].t = b[i];
		}
	std::sort(d, d+n);//����
	int left = 0, right = n - 1;
	for (int i = 0; i < n; i++)//�������Ž�
		if (d[i].ab == 0)c[left++] = d[i].jobNo;
		else c[right--] = d[i].jobNo;
}