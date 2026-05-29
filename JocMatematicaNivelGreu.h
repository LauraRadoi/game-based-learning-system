#pragma once
#include "Joc.h"


class JocMatematicaGreu : public Joc
{
public:
	JocMatematicaGreu(const std::string& profesorAdmin);
	int joaca() override;
};