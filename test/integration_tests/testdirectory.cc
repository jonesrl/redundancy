#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include <boost/test/unit_test.hpp>
#pragma GCC diagnostic pop
#endif

#include "directory.h"

struct TestDirectoryFixture
{
    TestDirectoryFixture()
    {
        // this will potentially throw -- let it fail noisely, since it would mean my test setup is broken
        cwd = boost::filesystem::current_path().generic_string();

        test_directory = cwd + "/test_directory/";
    }

    std::string cwd;
    std::string test_directory;
};

BOOST_AUTO_TEST_SUITE(DirectoryIntegration)

// can cd and ls
BOOST_FIXTURE_TEST_CASE(AReadableExecutableDirectoryShouldBeReadable, TestDirectoryFixture)
{
    std::string pathName = test_directory + "readable_executable_directory";
    Directory d(pathName);
    BOOST_REQUIRE_EQUAL(true, d.isReadable());
}

// can't cd or ls
BOOST_FIXTURE_TEST_CASE(ANonReadableNonExecutableDirectoryShouldNotBeReadable, TestDirectoryFixture)
{
    std::string pathName = test_directory + "non-readable_non-executable_directory";
    Directory d(pathName);
    BOOST_REQUIRE_EQUAL(false, d.isReadable());
}

// can cd but not ls
BOOST_FIXTURE_TEST_CASE(ANonReadableExecutableDirectoryShouldNotBeReadable, TestDirectoryFixture)
{
    std::string pathName = test_directory + "non-readable_non-executable_directory";
    Directory d(pathName);
    BOOST_REQUIRE_EQUAL(false, d.isReadable());
}

BOOST_FIXTURE_TEST_CASE(AReadableNonExecutableDirectoryShouldNotBeReadable, TestDirectoryFixture)
{
    std::string pathName = test_directory + "readable_non-executable_directory";
    Directory d(pathName);
    BOOST_REQUIRE_EQUAL(false, d.isReadable());
}

BOOST_AUTO_TEST_SUITE_END()

