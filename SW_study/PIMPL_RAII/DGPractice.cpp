#include "DGPractice.h"
#include "DGPracticeImpl.h"

using namespace std;

DGPractice::DGPractice(const string name){
	DGimpl = new DGPracticeImpl(name);
}

DGPractice::~DGPractice()
{
	delete DGimpl;
}

void DGPractice::StudyCPP() const
{
	DGimpl->StudyCPP();
}

void DGPractice::MakeQt() const
{
	DGimpl->MakeQt();
}

void DGPractice::MakeAndroidApp() const
{
	DGimpl->MakeAndroidApp();
}

void DGPractice::SecreteManufacture() const
{
	DGimpl->SecreteManufacture();
}