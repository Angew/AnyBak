#pragma once

#include <QDir>

const char SourceArtefactDirectoryPath[] = "${AnyBak_SOURCE_DIR}/DevelopmentArtefacts";

const char VolumeStagePath[] = "${AnyBak_BINARY_DIR}/VolumeStage";



inline const QDir& sourceArtefactDirectory()
{
	static const QDir dir{SourceArtefactDirectoryPath};
	return dir;
}
//--------------------------------------------------------------------------------------------------
inline const QDir& volumeStageDirectory()
{
	static const QDir dir{VolumeStagePath};
	return dir;
}
