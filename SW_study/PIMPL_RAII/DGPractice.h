#pragma once
#include <string>
class DGPracticeImpl;

class DGPractice
{
	DGPracticeImpl* DGimpl;

public:
	DGPractice(const std::string name);
	~DGPractice();
	void MakeQt() const;
	void MakeAndroidApp() const;
	void StudyCPP() const;
	void SecreteManufacture() const;
};