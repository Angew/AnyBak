#include "Artefact.hpp"


Artefact::Artefact(ArtefactName name, QFileInfo originalPath, QFileInfo archivePath) :
	name(std::move(name)),
	originalPath(std::move(originalPath)),
	archivePath(std::move(archivePath))
{}
