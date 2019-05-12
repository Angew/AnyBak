

int main()
{
	std::unique_ptr<Profile> profile = createDevelopmentProfile();
	std::unique_ptr<RuleSet> ruleSet = profile->getRuleSet();
	std::unique_ptr<VolumeRegistry> volumeRegistry = profile->getVolumeRegistry();
	ArtefactSet newArtefacts = ruleSet->getArtefactsNotIn(*volumeRegistry);
	VolumeSet newVolumes = something.createVolumeSet(*ruleSet, *newArtefacts);
	volumeRegistry->commit(newVolumes);
}
