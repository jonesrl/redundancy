#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include <boost/test/unit_test.hpp>
#pragma GCC diagnostic pop
#endif

#include "file.h"

// TODO: boost::filesystem does not expand ~ to $HOME, like one might expect on *nix boxes, so I add
//       that functionality to IFileSystemObject
BOOST_AUTO_TEST_SUITE(FileUnit)

BOOST_AUTO_TEST_CASE(ConstructorShouldThrowRuntimeExceptionIfFileNameIsEmpty)
{

    BOOST_REQUIRE_THROW(File f(""), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(ConstructorShouldNotThrowRuntimeExceptionIfFileNameIsNotEmpty)
{
    BOOST_REQUIRE_NO_THROW(File f("this is not empty"));
}


BOOST_AUTO_TEST_CASE(ShouldThrowIfRequestingCanonicalNameBeforeCalculatingCanonicalName)
{
    File f("ARandomFileNameGoesHere");
    BOOST_REQUIRE_THROW(f.getCanonicalizedName(), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()
