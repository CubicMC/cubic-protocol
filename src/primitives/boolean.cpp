#include <cassert>
#include <cstddef>

#include "cubic-protocol/primitives/boolean.hpp"

namespace cubic::protocol::primitives::boolean {

auto serialize(std::vector<uint8_t> &out, bool value) -> void
{
    size_t current_size = out.size();
    out.resize(out.size() + 1);
    serialize(out.data() + current_size, value);
}

auto serialize(uint8_t *out, bool value) -> void
{
    // Magic pointer conversion bs
    *out = *(uint8_t *) &value;
}

auto parse(const uint8_t *data, uint32_t available_bytes, bool *value) -> uint32_t
{
    if (available_bytes < 1)
        return 0;
    if (*data != 0 && *data != 1)
        return 0;
    auto *casted_value = (uint8_t *) value;
    *casted_value = *data;
    return 1;
}

} // namespace cubic::protocol::primitives::boolean

#ifdef UNIT_TESTS

#include <criterion/criterion.h>

TestSuite(primitives_boolean, .timeout = 1);

Test(primitives_boolean, parse_false)
{
    using namespace cubic::protocol::primitives::boolean;
    uint8_t data[] = { 0x00 };
    bool value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 1);
    cr_assert_eq(value, false);
}

Test(primitives_boolean, ser_false)
{
    using namespace cubic::protocol::primitives::boolean;
    uint8_t expected[] = { 0x00 };
    size_t expected_size = sizeof expected / sizeof expected[0];
    bool value = false;
    std::vector<uint8_t> out;
    serialize(out, value);
    cr_assert_eq(out.size(), expected_size);
    cr_assert_arr_eq(expected, out.data(), expected_size);
}

Test(primitives_boolean, parse_true)
{
    using namespace cubic::protocol::primitives::boolean;
    uint8_t data[] = { 0x01 };
    bool value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 1);
    cr_assert_eq(value, true);
}

Test(primitives_boolean, ser_true)
{
    using namespace cubic::protocol::primitives::boolean;
    uint8_t expected[] = { 0x01 };
    size_t expected_size = sizeof expected / sizeof expected[0];
    bool value = true;
    std::vector<uint8_t> out;
    serialize(out, value);
    cr_assert_eq(out.size(), expected_size);
    cr_assert_arr_eq(expected, out.data(), expected_size);
}

Test(primitives_boolean, parse_oob)
{
    using namespace cubic::protocol::primitives::boolean;
    uint8_t data[] = { 0x42 };
    bool value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 0);
}

#endif
