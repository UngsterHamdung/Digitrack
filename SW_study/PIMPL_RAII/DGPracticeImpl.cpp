#include "DGPracticeImpl.h"

using namespace std;

DGPracticeImpl::DGPracticeImpl(const string name) {
	this->InternName = name;
}

void DGPracticeImpl::StudyCPP() const
{

	cout << "CPP�� class������ ������ �߿���" << endl;
	cout << "class �̸��� �´� �޼��� ��� ���� �̸��� �� ���Ѿ� ��" << endl;
}

void DGPracticeImpl::MakeQt() const
{
	cout << "QT�� ���������� �̸��� �´� �޼��� ��� ������ �߿�" << endl;
	cout << "������ ����ų� ����Ҷ��� �����Ҵ��� �̿��ϸ� ����" << endl;
}

void DGPracticeImpl::MakeAndroidApp() const
{
	cout << "���� WristDiagnosis UI�� �ۼ��߿� ����" << endl;
}

void DGPracticeImpl::SecreteManufacture() const 
{
	cout << this->secreteGoods << endl;
}