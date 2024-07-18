#ifndef CUBIC_PROTOCOL_UTILS_
#define CUBIC_PROTOCOL_UTILS_

#include <array>
#include <cassert>

#include "cubic-protocol/primitives/varint.hpp"

#define CUBIC_PPARSE(type, target)                                                     \
    parsed = type::parse(data + total_parsed, available_bytes - total_parsed, target); \
    if (parsed == 0)                                                                   \
        return 0;                                                                      \
    total_parsed += parsed

#define CUBIC_PPARSE_RANGE(type, target, min, max)                                               \
    parsed = type::parse(data + total_parsed, available_bytes - total_parsed, target, min, max); \
    if (parsed == 0)                                                                             \
        return 0;                                                                                \
    total_parsed += parsed

#define CUBIC_INIT_BASIC_PACKET_PARSER()         \
    using namespace cubic::protocol::primitives; \
    uint32_t parsed;                             \
    uint32_t total_parsed = 0

#define CUBIC_END_BASIC_PACKET_PARSER() return total_parsed

#define CUBIC_INIT_BASIC_PACKET_SER()            \
    using namespace cubic::protocol::primitives; \
    out.clear();                                 \
    varint::serialize(out, p_id())

#define CUBIC_PSER(type, target) type::serialize(out, target)

#define CUBIC_END_BASIC_PACKET_SER()                                                       \
    std::array<uint8_t, 5> size_placeholder;                                               \
    const uint8_t size_size = varint::get_num_bytes((int32_t) out.size());                 \
    assert(size_size <= size_placeholder.size());                                          \
    varint::serialize(size_placeholder.data(), (int32_t) out.size());                      \
    out.insert(out.begin(), size_placeholder.data(), size_placeholder.data() + size_size); \
    return

#endif // CUBIC_PROTOCOL_UTILS_
