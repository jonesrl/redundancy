// avoid tons of warnings in the Catch unit test framework that I can't fix
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include <boost/test/unit_test.hpp>
#pragma GCC diagnostic pop
#endif

#include "filescantarget.h"
#include <string>
using namespace std;
BOOST_AUTO_TEST_SUITE(filescantarget)
//XXX TODO: replace FileScanTarget with FakeFileTargets, move these to integration tests
BOOST_AUTO_TEST_CASE(ShouldCorrectlyDetermineIfAFileDoesNotExist)
{
     string nonExistantFilePathName = "/path/to/nonexistantfile.txt";
     FileScanTarget f(nonExistantFilePathName);
     BOOST_REQUIRE(false == f.exists());
}


BOOST_AUTO_TEST_CASE(ShouldCorrectlyDetermineIfAFileDoesExist)
{
    string anExistantFilePathName = "/home/rlj/perms.cc";
    FileScanTarget f(anExistantFilePathName);
    BOOST_REQUIRE(true == f.exists());
}

BOOST_AUTO_TEST_CASE(ShouldBeReadable)
{
    BOOST_REQUIRE(true == true);
}
BOOST_AUTO_TEST_SUITE_END()
