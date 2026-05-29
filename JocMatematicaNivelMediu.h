#pragma once
#include "Joc.h"


class JocMatematicaMediu : public Joc
{
public:
	JocMatematicaMediu(const std::string& profesorAdmin);
	int joaca() override;
};