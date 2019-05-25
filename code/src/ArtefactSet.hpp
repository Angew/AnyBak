#pragma once

#include "ArtefactSet.hxx"

#include "Artefact.hpp"


inline auto ArtefactSet::takeAll() -> decltype(artefacts)
{
	return std::move(artefacts);
}
