#include "VolumeSet.hpp"



VolumeSet VolumeSet::createFromArtefacts(const RuleSet &ruleSet, ArtefactSet artefactSet)
{
	VolumeSet result;
	auto inputArtefacts = artefactSet.takeAll();
	std::set<Artefact, Artefact::SizeBased::OrderingFromHighest> artefacts{
		std::make_move_iterator(inputArtefacts.begin()),
		std::make_move_iterator(inputArtefacts.end())
	};
}
