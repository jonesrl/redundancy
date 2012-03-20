#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include <boost/test/unit_test.hpp>
#pragma GCC diagnostic pop
#endif


BOOST_AUTO_TEST_SUITE(file)
BOOST_AUTO_TEST_CASE(Test1)
{
    BOOST_REQUIRE(true == true);
}
BOOST_AUTO_TEST_SUITE_END()
