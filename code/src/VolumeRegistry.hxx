#pragma once

#include "ArtefactName.hh"



class VolumeRegistry
{
public:
	virtual bool contains(const ArtefactName &) const = 0;
};
