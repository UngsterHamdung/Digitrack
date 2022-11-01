#include <iostream>
#include "DGPractice.h"
#include <memory>

void ExecuteRAII()
{
	std::unique_ptr<DGPractice> p(new DGPractice("TaeHwan"));
	p->MakeAndroidApp();
	p->MakeQt();
	p->SecreteManufacture();
	p->StudyCPP();
}

int main()
{
	ExecuteRAII();
	return 0;
}