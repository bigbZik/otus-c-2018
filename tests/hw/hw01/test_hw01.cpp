#define BOOST_TEST_MODULE test_hw01
#include "../../../src/hw/hw01/hw01_lib.h"
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(test_version)

	BOOST_AUTO_TEST_CASE(test_valid_version)
	{
		BOOST_CHECK(version() > 0);
	}

}
