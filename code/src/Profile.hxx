#pragma once

#include "RuleSet.hh"
#include "VolumeRegistry.hh"

#include <memory>



class Profile
{
public:
	const RuleSet& getRuleSet() const { return getRuleSet_impl(); }
	RuleSet& getRuleSet() { return getRuleSet_impl(); }

	const VolumeRegistry& getVolumeRegistry() const { return getVolumeRegistry_impl(); }
	VolumeRegistry& getVolumeRegistry() { return getVolumeRegistry_impl(); }

protected:
	virtual RuleSet& getRuleSet_impl() const = 0;
	virtual VolumeRegistry& getVolumeRegistry_impl() const = 0;
};
