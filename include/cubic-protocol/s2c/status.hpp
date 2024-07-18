#ifndef CUBIC_PROTOCOL_S2C_STATUS_
#define CUBIC_PROTOCOL_S2C_STATUS_

#include <cstdint>
#include <string_view>
#include <vector>

namespace cubic::protocol::s2c::status {

/**
 * Represents the packet ids used in the status state
 */
enum class packet_id : int32_t {
    StatusResponse = 0,
};

/**
 * Represents a 1:1 mapping of the StatusResponse packet
 *
 * https://wiki.vg/Protocol#Status_Response
 */
struct StatusResponse {
    std::string_view json_response;

    /**
     * Serializes the StatusResponse packet to a byte buffer
     *
     * @param out The output byte buffer
     * @param data The data to serialize
     */
    static auto serialize(std::vector<uint8_t> &out, const StatusResponse &data) -> void;

    constexpr static auto p_id() -> int32_t
    {
        return (int32_t) packet_id::StatusResponse;
    }
};

} // namespace cubic::protocol::s2c::status

#endif // CUBIC_PROTOCOL_S2C_STATUS_
