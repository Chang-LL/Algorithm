#include "stdafx.h"
#include "BatchJob.h"

BatchJob::BatchJob(int sz, int * aa, int * bb, int up)
{
	n = sz; U = up; f = f1 = 0;
	a = new int[n]; b = new int[n];
	f2 = new int[n]; y = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = aa[i]; b[i] = bb[i]; y[i] = i;
	}
}

BatchJob::~BatchJob()
{
}


// �����ŵ��ȷ�������СFTֵ
int BatchJob::JobSch(int* x)
{
	//һά����x����������ҵ���ȷ���
	//������СFT
	JobSch(0,x);
	return U;
}


// �ݹ麯��
void BatchJob::JobSch(int i, int* x)
{
	if (i == n) {//��¼����Ϊֹ�����Ž�
		for (int i = 0; i < n; i++)
		{
			x[i] = y[i];
		}
		U = f;
	}
	else
	{
		for (int j = i; j < n; j++) {//����ʣ����ҵ�ĸ��ֿ�������
			f1 += a[y[j]];//��i��������ҵj
			f2[i] = ((f2[i - 1] > f1) ? f2[i - 1] : f1)
				+ b[y[j]];//p2ִ�б�����f1+a[i]ʱ��֮��ʼ
			f += f2[i];//�ۼ���ҵi�����ʱ��f2[i]
			if (f < U) {
				std::swap(y[i],y[j]);
				JobSch(i + 1, x);
				std::swap(y[i], y[j]);//ѡ���µ�����
			}
			f1 -= a[y[j]]; f -= f2[i];//�ָ�ԭ����f��f1ֵ
		}
	}
}
