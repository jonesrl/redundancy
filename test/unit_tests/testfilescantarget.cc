// avoid tons of warnings that I can't fix
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include <boost/test/unit_test.hpp>
#pragma GCC diagnostic pop
#endif

#include "filescantarget.h"
#include "file.h"

BOOST_AUTO_TEST_SUITE(FileScanTargetUnit)

BOOST_AUTO_TEST_CASE(TargetsShouldBeAbleToProvideTheirName)
{
    std::string aFilePathName = "/this/is/a/pathname.txt";
    boost::shared_ptr<File> file(new File(aFilePathName));
    FileScanTarget f(file);

    BOOST_REQUIRE_EQUAL(aFilePathName, f.getName());
}



BOOST_AUTO_TEST_SUITE_END()
