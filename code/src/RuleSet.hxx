#pragma once

#include "ArtefactSet.hh"
#include "VolumeRegistry.hh"



class RuleSet
{
public:
	virtual ArtefactSet getArtefactsNotIn(const VolumeRegistry&) const = 0;
};
