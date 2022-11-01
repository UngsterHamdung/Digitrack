#include "DGPracticeImpl.h"

using namespace std;

DGPracticeImpl::DGPracticeImpl(const string name) {
	this->InternName = name;
}

void DGPracticeImpl::StudyCPP() const
{

	cout << "CPP는 class마다의 역할이 중요해" << endl;
	cout << "class 이름에 맞는 메서드 멤버 변수 이름을 잘 지켜야 함" << endl;
}

void DGPracticeImpl::MakeQt() const
{
	cout << "QT도 마찬가지로 이름에 맞는 메서드 멤버 변수가 중요" << endl;
	cout << "위젯을 만들거나 사용할때는 동적할당을 이용하면 편함" << endl;
}

void DGPracticeImpl::MakeAndroidApp() const
{
	cout << "현재 WristDiagnosis UI를 작성중에 있음" << endl;
}

void DGPracticeImpl::SecreteManufacture() const 
{
	cout << this->secreteGoods << endl;
}