#include "VolumeSet.hpp"

#include "ArtefactSet.hpp"

#include <set>



//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//
// Class VolumeSet
//
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
VolumeSet VolumeSet::createFromArtefacts(const RuleSet &/*ruleSet*/, ArtefactSet artefactSet)
{
	VolumeSet result;
	auto inputArtefacts = artefactSet.takeAll();
	std::set<Artefact, Artefact::SizeBased::OrderingFromHighest> artefacts{
		std::make_move_iterator(inputArtefacts.begin()),
		std::make_move_iterator(inputArtefacts.end())
	};
	auto& volume = result.addVolume();
	while (!artefacts.empty()) {
		volume.add(std::move(*artefacts.begin()));
		artefacts.erase(artefacts.begin());
	}
	return result;
}
//--------------------------------------------------------------------------------------------------
Volume& VolumeSet::addVolume()
{
	volumes.emplace_back();
	return volumes.back();
}
