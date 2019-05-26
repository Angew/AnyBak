find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(ICU REQUIRED COMPONENTS i18n)
find_package(Boost REQUIRED)


function(GenerateFileSuite Result)
	set(Suite "")
	foreach(Base IN LISTS ARGN)
		list(APPEND Suite ${Base}.hh ${Base}.hpp ${Base}.hxx ${Base}.cpp)
	endforeach()
	set(${Result} ${Suite} PARENT_SCOPE)
endfunction()

function(EnsureFiles)
	foreach(File IN LISTS ARGN)
		if(NOT IS_ABSOLUTE ${File})
			set(File ${CMAKE_CURRENT_SOURCE_DIR}/${File})
		endif()
		if(NOT EXISTS ${File})
			file(TOUCH ${File})
		endif()
	endforeach()
endfunction()



GenerateFileSuite(Files
	src/Artefact
	src/ArtefactName
	src/ArtefactSet
	src/DevelopmentProfile
	src/Profile
	src/RuleSet
	src/Volume
	src/VolumeRegistry
	src/VolumeSet
)

EnsureFiles(${Files})


set(DevelopmentHeaderDir ${CMAKE_CURRENT_BINARY_DIR}/GeneratedFiles)
configure_file(
	cfg_in/Paths.hpp
	${DevelopmentHeaderDir}/development/Paths.hpp
)

add_executable(AnyBak
	${Files}
	src/main.cpp
	cfg_in/Paths.hpp
	${DevelopmentHeaderDir}/development/Paths.hpp
)

target_include_directories(AnyBak PRIVATE ${DevelopmentHeaderDir})
target_link_libraries(AnyBak PRIVATE Qt5::Core Boost::boost)
set_property(
	TARGET AnyBak
	PROPERTY VS_DEBUGGER_ENVIRONMENT
	"PATH=$<TARGET_FILE_DIR:Qt5::Core>;$<TARGET_FILE_DIR:ICU::i18n>/../bin64;$ENV{PATH}"
)
