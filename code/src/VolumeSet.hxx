#pragma once

#include "ArtefactSet.hh"
#include "RuleSet.hh"
#include "Volume.hxx"

#include <vector>



class VolumeSet
{
public:
	static VolumeSet createFromArtefacts(const RuleSet &ruleSet, ArtefactSet artefacts);

	Volume& addVolume();

private:
	std::vector<Volume> volumes;
};
