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

	auto begin() { return volumes.begin(); }
	auto end() { return volumes.end(); }

	auto begin() const { return volumes.begin(); }
	auto end() const { return volumes.end(); }

	auto cbegin() const { return volumes.begin(); }
	auto cend() const { return volumes.end(); }

private:
	std::vector<Volume> volumes;
};
