#ifndef CUBIC_PROTOCOL_PRIMITIVES_USHORT_
#define CUBIC_PROTOCOL_PRIMITIVES_USHORT_

#include <cstdint>

namespace cubic::protocol::primitives::ushort {

/**
 * Tries to parse an unsigned short
 *
 * If the parsing fails then the content of the given value is undefined
 *
 * @param data Raw incoming data from a client
 * @param available_bytes Number of bytes available in the incoming data
 * @param value Mapping that the function will try to fill
 * @return The number of bytes used to parse the primitive
 */
auto parse(const uint8_t *data, uint32_t available_bytes, uint16_t *value) -> uint32_t;

/**
 * Tries to parse an unsigned short with bounds
 *
 * If the parsing fails then the content of the given value is undefined
 *
 * @param data Raw incoming data from a client
 * @param available_bytes Number of bytes available in the incoming data
 * @param value Mapping that the function will try to fill
 * @param min Minimum value that the parsing should accept from the value
 * @param mam Maximum value that the parsing should accept from the value
 * @return The number of bytes used to parse the primitive
 */
auto parse(
    const uint8_t *data, uint32_t available_bytes, uint16_t *value, uint16_t min, uint16_t max
) -> uint32_t;

} // namespace cubic::protocol::primitives::ushort

#endif // CUBIC_PROTOCOL_PRIMITIVES_USHORT_
