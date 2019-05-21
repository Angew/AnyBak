#pragma once

#include <QDir>

const char SourceArtefactDirectoryPath[] = "${AnyBak_SOURCE_DIR}/DevelopmentArtefacts";



inline const QDir& sourceArtefactDirectory()
{
	static const QDir dir{SourceArtefactDirectoryPath};
	return dir;
}
