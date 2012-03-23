#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include <boost/test/unit_test.hpp>
#pragma GCC diagnostic pop
#endif

#include "filescantarget.h"
#include "file.h"
#include <string>

BOOST_AUTO_TEST_SUITE(filescantarget)



BOOST_AUTO_TEST_CASE(TargetsThatAreNonExistantFilesShouldNotBeReadable)
{
     std::string nonExistantFilePathName = "/path/to/nonexistantfile.txt";
     boost::shared_ptr<File> file(new File(nonExistantFilePathName));
     FileScanTarget f(file);
     BOOST_REQUIRE_EQUAL(false, f.isReadable());
}


BOOST_AUTO_TEST_CASE(TargetsThatAreReadableFilesShouldBeReadable)
{
    std::string anExistantFilePathName = "/home/rlj/perms.cc";
    boost::shared_ptr<File> file(new File(anExistantFilePathName));
    FileScanTarget f(file);
    BOOST_REQUIRE(true == f.isReadable());
}

BOOST_AUTO_TEST_SUITE_END()
