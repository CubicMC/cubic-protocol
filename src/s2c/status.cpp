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
