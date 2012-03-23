#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include <boost/test/unit_test.hpp>
#pragma GCC diagnostic pop
#endif

#include "file.h"
// when canonicalizing relative path names, boost filesystem will assume the the pathname
// is relative to the current working directory. Maybe I need to mock out getcwd()?
// then again, this test is essentially just unit testing the boost filesystem framework,
// which I should probably assume is already debugged.
// boost will still compute the complete path name when given a path name to a file that does
// not exist
// use a test double!
// step 1 - assume the boost functionality is well-tested
// step 2 - assuming the lib is correct, test that it interacts with the functionality that I write
// step 3 - profit?

// boost::filesystem does not expand ~ to $HOME, like one might expect on *nix boxes, so I am adding
// that functionality to my boost::filesystem::path wrapper class
BOOST_AUTO_TEST_SUITE(FileUnit)

BOOST_AUTO_TEST_CASE(ConstructorShouldThrowRuntimeExceptionIfFileNameIsEmpty)
{

    BOOST_REQUIRE_THROW(File f(""), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(ConstructorShouldNotThrowRuntimeExceptionIfFileNameIsNotEmpty)
{
    BOOST_REQUIRE_NO_THROW(File f("this is not empty"));
}


BOOST_AUTO_TEST_CASE(ShouldThrowIfRequestingCanonicalNameBeforeCalculatingCanonicalName)
{
    File f("ThisFileShouldNotExistAndThereforeShouldHaveAnEmptyCanonicalizedName");
    BOOST_REQUIRE_THROW(f.getCanonicalizedName(), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()
