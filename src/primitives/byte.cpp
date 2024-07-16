#include <cassert>
#include <cstddef>

#include "cubic-protocol/primitives/byte.hpp"

namespace cubic::protocol::primitives::byte {

auto serialize(std::vector<uint8_t> &out, int8_t value) -> void
{
    size_t current_size = out.size();
    out.resize(out.size() + 1);
    serialize(out.data() + current_size, value);
}

auto serialize(uint8_t *out, int8_t value) -> void
{
    // Magic pointer conversion bs
    *out = *(uint8_t *) &value;
}

auto parse(const uint8_t *data, uint32_t available_bytes, int8_t *value) -> uint32_t
{
    if (available_bytes < 1)
        return 0;
    auto *casted_value = (uint8_t *) value;
    *casted_value = *data;
    return 1;
}

auto parse(const uint8_t *data, uint32_t available_bytes, int8_t *value, int8_t min, int8_t max)
    -> uint32_t
{
    uint32_t parsed = parse(data, available_bytes, value);

    if (parsed == 0 || *value < min || *value > max)
        return 0;
    return parsed;
}

} // namespace cubic::protocol::primitives::byte

#ifdef UNIT_TESTS

#include <criterion/criterion.h>

TestSuite(primitives_byte, .timeout = 1);

Test(primitives_byte, parse_0)
{
    using namespace cubic::protocol::primitives::byte;
    uint8_t data[] = { 0x00 };
    int8_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 1);
    cr_assert_eq(value, 0);
}

Test(primitives_byte, ser_0)
{
    using namespace cubic::protocol::primitives::byte;
    uint8_t expected[] = { 0x00 };
    size_t expected_size = sizeof expected / sizeof expected[0];
    int8_t value = 0;
    std::vector<uint8_t> out;
    serialize(out, value);
    cr_assert_eq(out.size(), expected_size);
    cr_assert_arr_eq(expected, out.data(), expected_size);
}

Test(primitives_byte, parse_1)
{
    using namespace cubic::protocol::primitives::byte;
    uint8_t data[] = { 0x01 };
    int8_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 1);
    cr_assert_eq(value, 1);
}

Test(primitives_byte, ser_1)
{
    using namespace cubic::protocol::primitives::byte;
    uint8_t expected[] = { 0x01 };
    size_t expected_size = sizeof expected / sizeof expected[0];
    int8_t value = 1;
    std::vector<uint8_t> out;
    serialize(out, value);
    cr_assert_eq(out.size(), expected_size);
    cr_assert_arr_eq(expected, out.data(), expected_size);
}

Test(primitives_byte, parse_127)
{
    using namespace cubic::protocol::primitives::byte;
    uint8_t data[] = { 0x7f };
    int8_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 1);
    cr_assert_eq(value, 127);
}

Test(primitives_byte, ser_127)
{
    using namespace cubic::protocol::primitives::byte;
    uint8_t expected[] = { 0x7f };
    size_t expected_size = sizeof expected / sizeof expected[0];
    int8_t value = 127;
    std::vector<uint8_t> out;
    serialize(out, value);
    cr_assert_eq(out.size(), expected_size);
    cr_assert_arr_eq(expected, out.data(), expected_size);
}

Test(primitives_byte, parse_m1)
{
    using namespace cubic::protocol::primitives::byte;
    uint8_t data[] = { 0xff };
    int8_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 1);
    cr_assert_eq(value, -1);
}

Test(primitives_byte, ser_m1)
{
    using namespace cubic::protocol::primitives::byte;
    uint8_t expected[] = { 0xff };
    size_t expected_size = sizeof expected / sizeof expected[0];
    int8_t value = -1;
    std::vector<uint8_t> out;
    serialize(out, value);
    cr_assert_eq(out.size(), expected_size);
    cr_assert_arr_eq(expected, out.data(), expected_size);
}

Test(primitives_byte, parse_m2)
{
    using namespace cubic::protocol::primitives::byte;
    uint8_t data[] = { 0xfe };
    int8_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 1);
    cr_assert_eq(value, -2);
}

Test(primitives_byte, ser_m2)
{
    using namespace cubic::protocol::primitives::byte;
    uint8_t expected[] = { 0xfe };
    size_t expected_size = sizeof expected / sizeof expected[0];
    int8_t value = -2;
    std::vector<uint8_t> out;
    serialize(out, value);
    cr_assert_eq(out.size(), expected_size);
    cr_assert_arr_eq(expected, out.data(), expected_size);
}

#endif
