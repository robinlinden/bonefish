#ifndef BONEFISH_IDENTIFIERS_WAMP_SESSION_ID_HPP
#define BONEFISH_IDENTIFIERS_WAMP_SESSION_ID_HPP

#include <bonefish/identifiers/wamp_random_id.hpp>

#include <functional>

namespace bonefish {

class wamp_session_id : public wamp_random_id
{
public:
    wamp_session_id();
    explicit wamp_session_id(uint64_t id);
};

inline wamp_session_id::wamp_session_id()
    : wamp_random_id()
{
}

inline wamp_session_id::wamp_session_id(uint64_t id)
    : wamp_random_id(id)
{
}

} // namespace bonefish

namespace std {

template<> struct hash<bonefish::wamp_session_id>
{
    size_t operator()(const bonefish::wamp_session_id& id) const
    {
        return hash<uint64_t>()(id.id());
    }
};

} // namespace std

#endif // BONEFISH_IDENTIFIERS_WAMP_SESSION_ID_HPP
