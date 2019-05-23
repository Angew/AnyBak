#pragma once

#include "ArtefactSet.hh"
#include "RuleSet.hh"



class VolumeSet
{
public:
	static VolumeSet createFromArtefacts(const RuleSet &ruleSet, ArtefactSet artefacts);
};
