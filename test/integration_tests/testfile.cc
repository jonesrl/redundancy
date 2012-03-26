#include <string>
#include <iostream>
#include <boost/filesystem.hpp>

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include <boost/test/unit_test.hpp>
#pragma GCC diagnostic pop
#endif

#include "file.h"

struct TestFileFixture
{
    TestFileFixture()
    {
        // this will potentially throw -- let it fail noisely, since it would mean my test setup is broken
        cwd = boost::filesystem::current_path().generic_string();

        test_directory = cwd + "/test_directory/";
    }

    std::string cwd;
    std::string test_directory;
};


BOOST_AUTO_TEST_SUITE(FileIntegration)
/*
 $TEST_DIRECTORY/non-readable_non-executable_directory/readable_file
 $TEST_DIRECTORY/non-readable_non-executable_directory/nonreadable_file

 $TEST_DIRECTORY/non-readable_executable_directory/readable_file
 $TEST_DIRECTORY/non-readable_executable_directory/nonreadable_file

 $TEST_DIRECTORY/readable_executable_directory/readable_file
 $TEST_DIRECTORY/readable_executable_directory/nonreadable_file

$TEST_DIRECTORY/readable_non-executable_directory/readable_file
$TEST_DIRECTORY/readable_non-executable_directory/nonreadable_file


test case   directory is readable     directory is executable     file is readable
    1               0                         0                            0
    2               0                         0                            1
    3               0                         1                            0
    4               0                         1                            1
    5               1                         0                            0
    6               1                         0                            1
    7               1                         1                            0
    8               1                         1                            1
*/

//
// testing isReadable()
//
BOOST_FIXTURE_TEST_CASE(ANonReadableExistingFileInANonReadableNonExecutableDirectoryIsNotReadable, TestFileFixture)
{


    std::string pathName = test_directory + "non-readable_non-executable_directory/nonreadable_file";
    File f(pathName);

    BOOST_REQUIRE_EQUAL(false, f.isReadable());

}

BOOST_FIXTURE_TEST_CASE(AReadableExistingFileInANonReadableNonExecutableDirectoryIsNotReadable, TestFileFixture)
{


    std::string pathName = test_directory + "non-readable_non-executable_directory/readable_file";
    File f(pathName);
    BOOST_REQUIRE_EQUAL(false, f.isReadable());

}

BOOST_FIXTURE_TEST_CASE(ANonReadableExistingFileInANonReadableExecutableDirectoryIsNotReadable, TestFileFixture)
{


    std::string pathName = test_directory + "non-readable_executable_directory/nonreadable_file";
    File f(pathName);
    BOOST_REQUIRE_EQUAL(false, f.isReadable());

}

BOOST_FIXTURE_TEST_CASE(AReadableExistingFileInANonReadableExecutableDirectoryIsReadable, TestFileFixture)
{


    std::string pathName = test_directory + "non-readable_executable_directory/readable_file";
    File f(pathName);
    BOOST_REQUIRE_EQUAL(true, f.isReadable());

}

BOOST_FIXTURE_TEST_CASE(ANonReadableExistingFileInAReadableNonExecutableDirectoryIsNotReadable, TestFileFixture)
{


    std::string pathName = test_directory + "readable_nonexecutable_directory/nonreadable_file";
    File f(pathName);
    BOOST_REQUIRE_EQUAL(false, f.isReadable());

}

BOOST_FIXTURE_TEST_CASE(AReadableExistingFileInAReadableNonExecutableDirectoryIsNotReadable, TestFileFixture)
{


    std::string pathName = test_directory + "readable_nonexecutable_directory/readable_file";
    File f(pathName);
    BOOST_REQUIRE_EQUAL(false, f.isReadable());

}

BOOST_FIXTURE_TEST_CASE(ANonReadableExistingFileInAReadableExecutableDirectoryIsNotReadable, TestFileFixture)
{


    std::string pathName = test_directory + "readable_executable_directory/nonreadable_file";
    File f(pathName);
    BOOST_REQUIRE_EQUAL(false, f.isReadable());

}



BOOST_FIXTURE_TEST_CASE(AReadableExistingFileInAReadableExecutableDirectoryIsReadable, TestFileFixture)
{


    std::string pathName = test_directory + "readable_executable_directory/readable_file";
    File f(pathName);
    BOOST_REQUIRE_EQUAL(true, f.isReadable());

}

BOOST_FIXTURE_TEST_CASE(AllReadableFilesShouldBeCanonicalizeable, TestFileFixture)
{
    std::string pathName1 = test_directory + "readable_executable_directory/readable_file";
    File f1(pathName1);
    BOOST_REQUIRE_NO_THROW(f1.canonicalizeName());

    std::string pathName2 = test_directory + "non-readable_executable_directory/readable_file";
    File f2(pathName1);
    BOOST_REQUIRE_NO_THROW(f2.canonicalizeName());
}

//
// testing isReadable on links
//
BOOST_FIXTURE_TEST_CASE(ALinkToAReadableFileIsReadable,TestFileFixture)
{
    std::string pathName = test_directory + "link_to_readable_file";
    File f(pathName);
    BOOST_REQUIRE_EQUAL(true, f.isReadable());

}

BOOST_FIXTURE_TEST_CASE(ALinkToANonReadableFileIsNotReadable,TestFileFixture)
{
    std::string pathName = test_directory + "link_to_nonreadable_file";
    File f(pathName);
    BOOST_REQUIRE_EQUAL(false, f.isReadable());

}

//
// testing canonicalizeName()
// since canonicalizeName() is just a thin wrapper around the boost::filesystem library, I only testing
// that canonicalizeName() throws on errors, not on what the actual computed canonicalize name is. I am assuming
// that the boost library is debugged.
//
BOOST_FIXTURE_TEST_CASE(CanonicalizingANonReadableExistingFileInANonReadableNonExecutableDirectoryWillThrow,
                        TestFileFixture)
{
    std::string pathName = test_directory + "non-readable_non-executable_directory/nonreadable_file";
    File f(pathName);
    BOOST_REQUIRE_THROW(f.canonicalizeName(), boost::filesystem::filesystem_error);
}

BOOST_FIXTURE_TEST_CASE(CanonicalizingAReadableExistingFileInANonReadableNonExecutableDirectoryWillThrow,
                        TestFileFixture)
{


    std::string pathName = test_directory + "non-readable_non-executable_directory/readable_file";
    File f(pathName);
    BOOST_REQUIRE_THROW(f.canonicalizeName(), boost::filesystem::filesystem_error);

}

BOOST_FIXTURE_TEST_CASE(CanonicalizingANonReadableExistingFileInANonReadableExecutableDirectoryWillNotThrow,
                        TestFileFixture)
{


    std::string pathName = test_directory + "non-readable_executable_directory/nonreadable_file";
    File f(pathName);
    BOOST_REQUIRE_NO_THROW(f.canonicalizeName());

}

BOOST_FIXTURE_TEST_CASE(CanonicalizingAReadableExistingFileInANonReadableExecutableDirectoryWillNotThrow,
                        TestFileFixture)
{


    std::string pathName = test_directory + "non-readable_executable_directory/readable_file";
    File f(pathName);
    BOOST_REQUIRE_NO_THROW(f.canonicalizeName());
}

BOOST_FIXTURE_TEST_CASE(CanonicalizingANonReadableExistingFileInAReadableNonExecutableDirectoryWillThrow,
                        TestFileFixture)
{


    std::string pathName = test_directory + "readable_nonexecutable_directory/nonreadable_file";
    File f(pathName);
    BOOST_REQUIRE_THROW(f.canonicalizeName(), boost::filesystem::filesystem_error);

}

BOOST_FIXTURE_TEST_CASE(CanonicalizingAReadableExistingFileInAReadableNonExecutableDirectoryWillThrow, TestFileFixture)
{


    std::string pathName = test_directory + "readable_nonexecutable_directory/readable_file";
    File f(pathName);
    BOOST_REQUIRE_THROW(f.canonicalizeName(), boost::filesystem::filesystem_error);

}

BOOST_FIXTURE_TEST_CASE(CanonicalizingANonReadableExistingFileInAReadableExecutableDirectoryWillNotThrow,
                        TestFileFixture)
{


    std::string pathName = test_directory + "readable_executable_directory/nonreadable_file";
    File f(pathName);
    BOOST_REQUIRE_NO_THROW(f.canonicalizeName());

}



BOOST_FIXTURE_TEST_CASE(CanonicalizingAReadableExistingFileInAReadableExecutableDirectoryWillNotThrow, TestFileFixture)
{


    std::string pathName = test_directory + "readable_executable_directory/readable_file";
    File f(pathName);
    BOOST_REQUIRE_NO_THROW(f.canonicalizeName());

}



BOOST_AUTO_TEST_SUITE_END()
