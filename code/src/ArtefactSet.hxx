#pragma once

#include "Artefact.hxx"

#include <unordered_set>


class ArtefactSet
{
public:
	bool add(const Artefact &);
	bool add(Artefact &&);

private:
	std::unordered_set<Artefact, Artefact::NameBased::Hash, Artefact::NameBased::Equality> artefacts;
};
