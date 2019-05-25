#pragma once

#include "RuleSet.hh"
#include "VolumeRegistry.hh"
#include "VolumeSet.hh"

#include <memory>



class Profile
{
public:
	const RuleSet& getRuleSet() const { return getRuleSet_impl(); }
	RuleSet& getRuleSet() { return getRuleSet_impl(); }

	const VolumeRegistry& getVolumeRegistry() const { return getVolumeRegistry_impl(); }
	VolumeRegistry& getVolumeRegistry() { return getVolumeRegistry_impl(); }

	virtual bool createVolumes(VolumeSet &volumes) const = 0;

protected:
	virtual RuleSet& getRuleSet_impl() const = 0;
	virtual VolumeRegistry& getVolumeRegistry_impl() const = 0;
};
