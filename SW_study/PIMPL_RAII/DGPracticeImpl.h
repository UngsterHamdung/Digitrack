#pragma once
#include <iostream>
#include <string>

class DGPracticeImpl
{
	std::string InternName;

public:
	DGPracticeImpl(const std::string name);
	void MakeQt() const;
	void MakeAndroidApp() const;
	void StudyCPP() const;
	void SecreteManufacture() const;
private:
	std::string secreteGoods = "µ§Æ® ºñÀü";
};