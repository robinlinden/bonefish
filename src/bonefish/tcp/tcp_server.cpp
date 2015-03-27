#include <bonefish/tcp/tcp_server.hpp>
#include <bonefish/identifiers/wamp_session_id_generator.hpp>
#include <bonefish/router/wamp_routers.hpp>
#include <bonefish/serialization/wamp_serializers.hpp>
#include <bonefish/tcp/tcp_server_impl.hpp>

namespace bonefish {

tcp_server::tcp_server(boost::asio::io_service& io_service,
        const std::shared_ptr<wamp_routers>& routers,
        const std::shared_ptr<wamp_serializers>& serializers,
        const std::shared_ptr<wamp_session_id_generator>& generator)
    : m_impl(new tcp_server_impl(io_service, routers, serializers, generator))
{
}

tcp_server::~tcp_server()
{
}

void tcp_server::start(const boost::asio::ip::address& ip_address, uint16_t port)
{
    m_impl->start(ip_address, port);
}

void tcp_server::shutdown()
{
    m_impl->shutdown();
}

} // namespace bonefish
