#include "DevelopmentProfile.hpp"

#include "ArtefactSet.hpp"
#include "Profile.hpp"
#include "RuleSet.hpp"
#include "VolumeRegistry.hpp"

#include "development/Paths.hpp"



namespace {

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//
// Class DevelopmentRuleSet
//
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
class DevelopmentRuleSet : public RuleSet
{
public:
	ArtefactSet getArtefactsNotIn(const VolumeRegistry& volumeRegistry) const override
	{
		
	}
};



//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//
// Class DevelopmentVolumeRegistry
//
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
class DevelopmentVolumeRegistry : public VolumeRegistry
{

};



//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//
// Class DevelopmentProfile
//
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
class DevelopmentProfile : public Profile
{
public:
	DevelopmentProfile() :
		volumeRegistry{std::make_unique<DevelopmentVolumeRegistry>()}
	{}

protected:
	RuleSet& getRuleSet_impl() const override
	{
		return *ruleSet;
	}

	VolumeRegistry& getVolumeRegistry_impl() const override
	{
		return *volumeRegistry;
	}

private:
	std::unique_ptr<RuleSet> ruleSet;
	std::unique_ptr<VolumeRegistry> volumeRegistry;
};

} //namespace



std::unique_ptr<Profile> createDevelopmentProfile()
{
	return std::make_unique<DevelopmentProfile>();
}
