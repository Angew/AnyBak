#include "DevelopmentProfile.hpp"
#include "RuleSet.hpp"



int main()
{
	std::unique_ptr<Profile> profile = createDevelopmentProfile();
	RuleSet& ruleSet = profile->getRuleSet();
	VolumeRegistry& volumeRegistry = profile->getVolumeRegistry();
	ArtefactSet newArtefacts = ruleSet.getArtefactsNotIn(volumeRegistry);
	VolumeSet newVolumes = something.createVolumeSet(ruleSet, *newArtefacts);
	volumeRegistry->commit(newVolumes);
}
