#pragma once

#include "Artefact.hxx"

#include <unordered_set>


class ArtefactSet
{
private:
	std::unordered_set<Artefact, Artefact::NameBased::Hash, Artefact::NameBased::Equality> artefacts;

public:
	bool add(const Artefact &);
	bool add(Artefact &&);

	decltype(artefacts) takeAll();

	auto begin() const { return artefacts.begin(); }
	auto end() const { return artefacts.end(); }

	auto cbegin() const { return artefacts.begin(); }
	auto cend() const { return artefacts.end(); }
};
