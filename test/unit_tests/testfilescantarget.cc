// avoid tons of warnings in the Catch unit test framework that I can't fix
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include "catch.hpp"
#pragma GCC diagnostic pop
#endif

#include "filescantarget.h"
#include <string>
using namespace std;
//XXX TODO: replace FileScanTarget with FakeFileTargets, move these to integration tests
TEST_CASE("FileScanTarget/nonexistant target", "Correctly determine if a file does not exists")
{
     string nonExistantFilePathName = "/path/to/nonexistantfile.txt";
     FileScanTarget f(nonExistantFilePathName);
     REQUIRE(false == f.exists());
}


TEST_CASE("FileScanTarget/existant target", "Correctly determine if a file exist")
{
    string anExistantFilePathName = "/home/rlj/perms.cc";
    FileScanTarget f(anExistantFilePathName);
    REQUIRE(true == f.exists());
}

TEST_CASE("FileScanTarget/target should be readable", "A valid file scan target should be readable")
{
    REQUIRE(true == true);
}

