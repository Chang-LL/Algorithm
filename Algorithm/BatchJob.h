#pragma once
//��������ҵ����
class BatchJob
{
public:
	BatchJob(int sz,int*aa,int*bb,int up);
	~BatchJob();
	// �����ŵ��ȷ�������СFTֵ
	int JobSch(int* x);
private:
	int* a;
	int* b;
	int n;
	int U;//������������
	int f, f1, *f2, *y;//�ֲ�����
	// �ݹ麯��
	void JobSch(int i, int* x);
};

