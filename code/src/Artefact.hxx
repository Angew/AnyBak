#pragma once

#include "ArtefactName.hxx"

#include <QFileInfo>
#include <QHash>

#include <cstddef>


class Artefact
{
public:
	Artefact(ArtefactName name, QFileInfo originalPath, QFileInfo archivePath);

	const ArtefactName& getName() const { return name; }
	const QFileInfo& getOriginalPath() const { return originalPath; }
	const QFileInfo& getArchivePath() const { return archivePath; }

	struct NameBased
	{
		struct Hash
		{
			std::size_t operator() (const Artefact &arg) const { return qHash(arg.getName()); }
		};

		struct Equality
		{
			bool operator() (const Artefact &lhs, const Artefact &rhs) const { return lhs.getName() == rhs.getName(); }
		};
	};

private:
	ArtefactName name;
	QFileInfo originalPath;
	QFileInfo archivePath;
};
