#pragma once

#include "ArtefactSet.hxx"


inline auto ArtefactSet::takeAll() -> decltype(artefacts)
{
	return std::move(artefacts);
}
