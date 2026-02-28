cmake_minimum_required( VERSION 3.21 )

project( meta
	VERSION 1.0
	LANGUAGES CXX
)

set( CMAKE_EXPORT_COMPILE_COMMANDS on )

set( CMAKE_CXX_STANDARD_REQUIRED on )
set( CMAKE_CXX_STANDARD 23 )

add_library( ${PROJECT_NAME}
	INTERFACE
)

target_include_directories( ${PROJECT_NAME}
	INTERFACE
	  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

get_target_property( INCL_DIRS ${PROJECT_NAME} INTERFACE_INCLUDE_DIRECTORIES )
message( STATUS "Includes for ${PROJECT_NAME}: ${INCL_DIRS}" )

enable_testing()

# Build tests if this is the root level project
set( BUILD_TESTING ON CACHE BOOL "Build tests" FORCE )
# set( BUILD_TESTING_DEFAULT ${PROJECT_IS_TOP_LEVEL} )
# option( BUILD_TESTING "Build tests" ${BUILD_TESTING_DEFAULT} )

if( BUILD_TESTING )
	message( STATUS "Building tests for ${PROJECT_NAME}" )
	include( CTest )

	find_package( GTest REQUIRED )

	include( GoogleTest )

	# define the test sources
	file( GLOB_RECURSE TEST_SOURCES
		CONFIGURE_DEPENDS
			"${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/test/**/*.cpp"
	)

	message( STATUS "Test sources: ${TEST_SOURCES}" )

	add_executable( ${PROJECT_NAME}_tests
			${TEST_SOURCES}
	)

	target_link_libraries( ${PROJECT_NAME}_tests
		PRIVATE
	  		GTest::gtest_main
			${PROJECT_NAME}
	)

	gtest_discover_tests( ${PROJECT_NAME}_tests
		TEST_PREFIX
			"${PROJECT_NAME}::"
	)
endif()
