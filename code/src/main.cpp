#include "DevelopmentProfile.hpp"
#include "RuleSet.hpp"



int main()
{
	auto profile = createDevelopmentProfile();
	RuleSet& ruleSet = profile->getRuleSet();
	VolumeRegistry& volumeRegistry = profile->getVolumeRegistry();
	auto newArtefacts = ruleSet.getArtefactsNotIn(volumeRegistry);
	VolumeSet newVolumes = VolumeSet::createFromArtefacts(ruleSet, std::move(newArtefacts));
	volumeRegistry.commit(newVolumes);
}
