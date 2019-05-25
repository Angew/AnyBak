#include "DevelopmentProfile.hpp"
#include "Profile.hpp"
#include "RuleSet.hpp"
#include "VolumeSet.hpp"



int main()
{
	auto profile = createDevelopmentProfile();
	RuleSet& ruleSet = profile->getRuleSet();
	VolumeRegistry& volumeRegistry = profile->getVolumeRegistry();
	auto newArtefacts = ruleSet.getArtefactsNotIn(volumeRegistry);
	auto newVolumes = VolumeSet::createFromArtefacts(ruleSet, std::move(newArtefacts));
	profile->createVolumes(newVolumes);
	//volumeRegistry.commit(newVolumes);
}
