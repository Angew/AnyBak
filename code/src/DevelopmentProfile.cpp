#include "DevelopmentProfile.hpp"

#include "ArtefactSet.hpp"
#include "Profile.hpp"
#include "RuleSet.hpp"
#include "VolumeRegistry.hpp"
#include "VolumeSet.hpp"

#include "development/Paths.hpp"

#include <QDate>



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
	ArtefactSet getArtefactsNotIn(const VolumeRegistry &volumeRegistry) const override
	{
		static const ArtefactName names[] = {
			sourceArtefactDirectory().absoluteFilePath("a1.txt")
		};

		ArtefactSet result;
		for (const auto &name : names) {
			if (!volumeRegistry.contains(name)) {
				result.add({name, {name}, {QFileInfo{name}.fileName()}});
			}
		}

		return result;
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
public:
	bool contains(const ArtefactName &/*queriedName*/) const override
	{
		return false;
	}
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
		ruleSet{std::make_unique<DevelopmentRuleSet>()},
		volumeRegistry{std::make_unique<DevelopmentVolumeRegistry>()}
	{}

	bool createVolumes(VolumeSet &volumes) const override
	{
		auto stage = volumeStageDirectory();
		stage.mkpath(".");
		int retries = 5;
		const auto date = QDate::currentDate();
		static const QString StagePattern{"%1-%2-%3-stage"};
		auto stageName = StagePattern
			.arg(date.year(), 4, 10, QLatin1Char{'0'})
			.arg(date.month(), 2, 10, QLatin1Char{'0'})
			.arg(date.day(), 2, 10, QLatin1Char{'0'})
		;
		int suffix = 1;
		while (retries) {
			static const QString NumberPattern{"%1"};
			stageName.append(NumberPattern.arg(suffix++, 3, 10, QLatin1Char{'0'}));
			if (stage.mkdir(stageName)) {
				stage.cd(stageName);
				break;
			}
			if (!stage.exists(stageName)) {
				--retries;
			}
			stageName.chop(3);
		}
		if (!retries) {
			return false;
		}

		int volumeNumber = 1;
		static const QString volumeDirPattern{"volume%1"};
		for (auto &volume : volumes) {
			auto volumeName = volumeDirPattern.arg(volumeNumber++, 2, 10, QLatin1Char{'0'});
			stage.mkdir(volumeName);
			auto volumeDir = stage;
			volumeDir.cd(volumeName);
			for (const auto &artefact : volume) {
				QFile::copy(
					artefact.getOriginalPath().filePath(),
					volumeDir.absoluteFilePath(artefact.getArchivePath().filePath())
				);
			}
		}

		return true;
	}

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
