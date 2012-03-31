#include <limits.h>

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


BOOST_FIXTURE_TEST_CASE(AReadableExecutableDirectoryShouldBeReadable, TestDirectoryFixture)
{
    std::string pathName = test_directory + "readable_executable_directory";
    Directory d(pathName);
    BOOST_REQUIRE_EQUAL(true, d.isReadable());
}


BOOST_FIXTURE_TEST_CASE(ANonReadableNonExecutableDirectoryShouldNotBeReadable, TestDirectoryFixture)
{
    std::string pathName = test_directory + "non-readable_non-executable_directory";
    Directory d(pathName);
    BOOST_REQUIRE_EQUAL(false, d.isReadable());
}


BOOST_FIXTURE_TEST_CASE(ANonReadableExecutableDirectoryShouldNotBeReadable, TestDirectoryFixture)
{
    std::string pathName = test_directory + "non-readable_non-executable_directory";
    Directory d(pathName);
    BOOST_REQUIRE_EQUAL(false, d.isReadable());
}

BOOST_FIXTURE_TEST_CASE(AReadableNonExecutableDirectoryShouldBeReadable, TestDirectoryFixture)
{
    std::string pathName = test_directory + "readable_non-executable_directory";
    Directory d(pathName);
    BOOST_REQUIRE_EQUAL(true, d.isReadable());
}

BOOST_FIXTURE_TEST_CASE(ANonReadableNonExecutableDirectoryShouldNotBeExecutable, TestDirectoryFixture)
{
    std::string pathName = test_directory + "non-readable_non-executable_directory";
    Directory d(pathName);
    d.isExecutable();

    BOOST_REQUIRE_EQUAL(false, d.isExecutable());
}

BOOST_FIXTURE_TEST_CASE(AReadableNonExecutableDirectoryShouldNotBeExecutable, TestDirectoryFixture)
{
    std::string pathName = test_directory + "readable_non-executable_directory";
    Directory d(pathName);
    d.isExecutable();

    BOOST_REQUIRE_EQUAL(false, d.isExecutable());
}

BOOST_FIXTURE_TEST_CASE(ANonReadableExecutableDirectoryShouldExecutable, TestDirectoryFixture)
{
    std::string pathName = test_directory + "non-readable_executable_directory";
    Directory d(pathName);
    d.isExecutable();

    BOOST_REQUIRE_EQUAL(true, d.isExecutable());
}

BOOST_FIXTURE_TEST_CASE(AReadableExecutableDirectoryShouldBeExecutable, TestDirectoryFixture)
{
    std::string pathName = test_directory + "readable_executable_directory";
    Directory d(pathName);
    d.isExecutable();

    BOOST_REQUIRE_EQUAL(true, d.isExecutable());
}

BOOST_FIXTURE_TEST_CASE(AttemptingToDetermineIfANonExistingDirectoryIsExecutableShouldFail, TestDirectoryFixture)
{
    std::string pathName = test_directory + "this_directory_should_not_exist";
    Directory d(pathName);

    BOOST_REQUIRE_THROW(d.isExecutable(), boost::system::system_error);
}

BOOST_AUTO_TEST_CASE(AttemptingToDetermineIfADirectoryWithANameThatExceedsTheMaximumPathLengthShouldThrow)

{
    std::string pathName(PATH_MAX+1,'x');
    Directory d(pathName);

    BOOST_REQUIRE_THROW(d.isExecutable(), boost::system::system_error);

}

BOOST_AUTO_TEST_SUITE_END()

