#include "ArtefactSet.hpp"



bool ArtefactSet::add(const Artefact &newArtefact)
{
	return artefacts.insert(newArtefact).second;
}
//--------------------------------------------------------------------------------------------------
bool ArtefactSet::add(Artefact &&newArtefact)
{
	return artefacts.insert(std::move(newArtefact)).second;
}
