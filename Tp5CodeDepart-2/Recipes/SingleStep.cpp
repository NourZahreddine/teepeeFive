///////////////////////////////////////////////////////////
//  SingleStep.cpp
//  Implementation of the Class SingleStep
//  Created on:      19-mars-2022 11:14:24
//  Original author: francois
///////////////////////////////////////////////////////////

#include "SingleStep.h"

SingleStep::SingleStep(std::string description, int duration)
	: AbsStep(description, duration)
{
}

SingleStep* SingleStep::clone() const 
{
	// À compléter pour construire une nouvelle étape simple en appelant le constructeur de copie
	return nullptr; // À remplacer
}

std::ostream& SingleStep::printToStream(std::ostream& o) const 
{
	// À compléter pour imprimer sur un stream une étape
	return o;
}