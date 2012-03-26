#include <stdexcept>
#include <boost/shared_ptr.hpp>

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include <boost/test/unit_test.hpp>
#pragma GCC diagnostic pop
#endif

#include "filescantarget.h"
#include "fakefile.h"

BOOST_AUTO_TEST_SUITE(FileScanTargetUnit)

BOOST_AUTO_TEST_CASE(TargetsShouldBeAbleToProvideTheirName)
{
    std::string aFilePathName = "/this/is/a/pathname.txt";
    boost::shared_ptr<FakeFile> file(new FakeFile(aFilePathName));
    file->mIsReadable=true;
    int64_t priority=1;
    bool recursive=false;
    FileScanTarget f(file, priority, recursive);

    BOOST_REQUIRE_EQUAL(aFilePathName, f.getName());
}

BOOST_AUTO_TEST_CASE(AttemptingToConstructAFileScanTargetWithAReadableFileShouldNotThrow)
{
    std::string pathName = "aPathToAReadableFile";
    boost::shared_ptr<FakeFile> readableFile(new FakeFile(pathName));
    readableFile->mIsReadable = true;
    int64_t priority=1;
    bool recursive=false;

    BOOST_REQUIRE_NO_THROW(FileScanTarget target(readableFile,priority, recursive));

}

BOOST_AUTO_TEST_CASE(AttemptingToConstructAFileScanTargetWithAnUnreadableFileShouldThrow)
{
    std::string pathName = "aPathToAnUnreadableFile";
    boost::shared_ptr<FakeFile> unreadableFile(new FakeFile(pathName));
    unreadableFile->mIsReadable = false;
    int64_t priority=1;
    bool recursive=false;

    BOOST_REQUIRE_THROW(FileScanTarget target(unreadableFile,priority, recursive), std::runtime_error);

}

BOOST_AUTO_TEST_CASE(AttemptingToConstructATargetWithANegativePriorityShouldThrow)
{
    std::string pathName = "aPathToAReadableFile";
    boost::shared_ptr<FakeFile> readableFile(new FakeFile(pathName));
    readableFile->mIsReadable = true;
    int64_t priority=-42;
    bool recursive=false;

    BOOST_REQUIRE_THROW(FileScanTarget target(readableFile, priority, recursive), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(AttemptingToConstructATargetWithAZeroPriorityShouldThrow)
{
    std::string pathName = "aPathToAReadableFile";
    boost::shared_ptr<FakeFile> readableFile(new FakeFile(pathName));
    readableFile->mIsReadable = true;
    int64_t priority=0;
    bool recursive=false;

    BOOST_REQUIRE_THROW(FileScanTarget target(readableFile, priority, recursive), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(AttemptingToConstructATargetWithAPriorityOfOneShouldNotThrow)
{
    std::string pathName = "aPathToAReadableFile";
    boost::shared_ptr<FakeFile> readableFile(new FakeFile(pathName));
    readableFile->mIsReadable = true;
    int64_t priority=1;
    bool recursive=false;

    BOOST_REQUIRE_NO_THROW(FileScanTarget target(readableFile, priority, recursive));
}

BOOST_AUTO_TEST_CASE(AttemptingToConstructATargetWithAPositivePriorityGreaterThanOneShouldNotThrow)
{
    std::string pathName = "aPathToAReadableFile";
    boost::shared_ptr<FakeFile> readableFile(new FakeFile(pathName));
    readableFile->mIsReadable = true;
    int64_t priority=42;
    bool recursive=false;

    BOOST_REQUIRE_NO_THROW(FileScanTarget target(readableFile, priority, recursive));
}

BOOST_AUTO_TEST_CASE(AttemptingToConstructATargetMarkedAsRecursiveShouldThrow)
{
    std::string pathName = "aPathToAReadableFile";
    boost::shared_ptr<FakeFile> readableFile(new FakeFile(pathName));
    readableFile->mIsReadable = true;
    int64_t priority=1;
    bool recursive=true;

    BOOST_REQUIRE_THROW(FileScanTarget target(readableFile, priority, recursive), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(AttemptingToConstructATargetMarkedAsNonRecursiveShouldNotThrow)
{
    std::string pathName = "aPathToAReadableFile";
    boost::shared_ptr<FakeFile> readableFile(new FakeFile(pathName));
    readableFile->mIsReadable = true;
    int64_t priority=1;
    bool recursive=false;

    BOOST_REQUIRE_NO_THROW(FileScanTarget target(readableFile, priority, recursive));
}

BOOST_AUTO_TEST_SUITE_END()
