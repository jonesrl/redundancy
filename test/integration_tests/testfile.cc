#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include <boost/test/unit_test.hpp>
#pragma GCC diagnostic pop
#endif

#include "file.h"
#include <string>
BOOST_AUTO_TEST_SUITE(file)

BOOST_AUTO_TEST_CASE(ShouldDetermineIfFileDoesNotExist)
{
    std::string nonExistantFile("thisreallyshouldnotexist");
    File f(nonExistantFile);
    BOOST_REQUIRE_EQUAL(false, f.exists());
}

BOOST_AUTO_TEST_CASE(ShouldDetermineIfFileDoesExist)
{
    std::string existingFile("/home/rlj/.bashrc");
    File f(existingFile);
    BOOST_REQUIRE_EQUAL(true, f.exists());
}

BOOST_AUTO_TEST_SUITE_END()
