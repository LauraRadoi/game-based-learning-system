#pragma once 
#include "Joc.h"

class JocMatematicaUsor : public Joc
{
public:
	JocMatematicaUsor(const std::string& profesorAdmin);
	int joaca() override;
};
