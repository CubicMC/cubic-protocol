#include "cubic-protocol/s2c/status.hpp"
#include "cubic-protocol/primitives/string.hpp"
#include "cubic-protocol/utils.hpp"

namespace cubic::protocol::s2c::status {

auto StatusResponse::serialize(std::vector<uint8_t> &out, const StatusResponse &data) -> void
{
    CUBIC_INIT_BASIC_PACKET_SER();

    CUBIC_PSER(string, data.json_response);

    CUBIC_END_BASIC_PACKET_SER();
}
} // namespace cubic::protocol::s2c::status

#ifdef UNIT_TESTS

#include <criterion/criterion.h>

TestSuite(s2c_status, .timeout = 1);

Test(s2c_status, basic_ser)
{
    using namespace cubic::protocol::s2c::status;
    StatusResponse value = { "{\"funny\":\"bruh\"}" };
    std::vector<uint8_t> out;
    uint8_t expected[] = {
        0x12, 0x00, 0x10, 0x7b, 0x22, 0x66, 0x75, 0x6e, 0x6e, 0x79,
        0x22, 0x3a, 0x22, 0x62, 0x72, 0x75, 0x68, 0x22, 0x7d,
    };
    size_t expected_size = sizeof expected / sizeof expected[0];
    StatusResponse::serialize(out, value);
    cr_assert_eq(out.size(), expected_size);
    cr_assert_arr_eq(expected, out.data(), expected_size);
}

#endif
