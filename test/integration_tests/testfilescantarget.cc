#include <string>
#include <boost/shared_ptr.hpp>

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include <boost/test/unit_test.hpp>
#pragma GCC diagnostic pop
#endif

#include "filescantarget.h"
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

BOOST_AUTO_TEST_SUITE(filescantarget)


BOOST_FIXTURE_TEST_CASE(ConstructingAFileScanTargetWithAnUnreadableFileShouldThrow, TestFileFixture)
{

    std::string pathName1 = test_directory + "non-readable_non-executable_directory/nonreadable_file";
    boost::shared_ptr<File> file1(new File(pathName1));
    BOOST_REQUIRE_THROW(FileScanTarget target1(file1,1,false), std::runtime_error);

    std::string pathName2 = test_directory + "non-readable_non-executable_directory/readable_file";
    boost::shared_ptr<File> file2(new File(pathName2));
    BOOST_REQUIRE_THROW(FileScanTarget target2(file2,1,false), std::runtime_error);

    std::string pathName3 = test_directory + "non-readable_executable_directory/nonreadable_file";
    boost::shared_ptr<File> file3(new File(pathName3));
    BOOST_REQUIRE_THROW(FileScanTarget target3(file3,1,false), std::runtime_error);

    std::string pathName4 = test_directory + "readable_nonexecutable_directory/nonreadable_file";
    boost::shared_ptr<File> file4(new File(pathName4));
    BOOST_REQUIRE_THROW(FileScanTarget target4(file4,1,false), std::runtime_error);

    std::string pathName5 = test_directory + "readable_nonexecutable_directory/readable_file";
    boost::shared_ptr<File> file5(new File(pathName5));
    BOOST_REQUIRE_THROW(FileScanTarget target5(file5,1,false), std::runtime_error);

    std::string pathName6 = test_directory + "readable_executable_directory/nonreadable_file";
    boost::shared_ptr<File> file6(new File(pathName6));
    BOOST_REQUIRE_THROW(FileScanTarget target6(file6,1,false), std::runtime_error);

}

BOOST_FIXTURE_TEST_CASE(ConstructingAFileScanTargetWithAReadableFileShouldNotThrow, TestFileFixture)
{
    std::string pathName1 = test_directory + "non-readable_executable_directory/readable_file";
    boost::shared_ptr<File> file1(new File(pathName1));
    BOOST_REQUIRE_NO_THROW(FileScanTarget target1(file1,1,false));

    std::string pathName2 = test_directory + "readable_executable_directory/readable_file";
    boost::shared_ptr<File> file2(new File(pathName2));
    BOOST_REQUIRE_NO_THROW(FileScanTarget target2(file2,1,false));

}



BOOST_AUTO_TEST_SUITE_END()
