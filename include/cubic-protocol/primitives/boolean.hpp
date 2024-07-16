#ifndef CUBIC_PROTOCOL_PRIMITIVES_BOOLEAN_
#define CUBIC_PROTOCOL_PRIMITIVES_BOOLEAN_

#include <cstdint>
#include <vector>

namespace cubic::protocol::primitives::boolean {

/**
 * Tries to serialize the given value to a byte buffer
 *
 * @param out Byte buffer where the data will be appended to
 * @param value Value to be serialized
 */
auto serialize(std::vector<uint8_t> &out, bool value) -> void;

/**
 * Tries to serialize the given value to a byte buffer
 *
 * @param out Byte buffer where the data will be written to
 * @param value Value to be serialized
 */
auto serialize(uint8_t *out, bool value) -> void;

/**
 * Tries to parse a byte
 *
 * If the parsing fails then the content of the given value is undefined
 *
 * @param data Raw incoming data from a client
 * @param available_bytes Number of bytes available in the incoming data
 * @param value Mapping that the function will try to fill
 * @return The number of bytes used to parse the primitive
 */
auto parse(const uint8_t *data, uint32_t available_bytes, bool *value) -> uint32_t;

} // namespace cubic::protocol::primitives::boolean

#endif // CUBIC_PROTOCOL_PRIMITIVES_BOOLEAN_
