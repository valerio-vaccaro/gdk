#ifndef GDK_NETWORK_PARAMETERS_HPP
#define GDK_NETWORK_PARAMETERS_HPP
#pragma once

#include <memory>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "include/gdk.h"

namespace ga {
namespace sdk {

    class network_parameters final {
    public:
        static void add(const std::string& name, const nlohmann::json& details);
        static nlohmann::json get_all();
        static nlohmann::json get(const std::string& name);

        explicit network_parameters(const nlohmann::json& details);

        ~network_parameters();

        network_parameters(const network_parameters&) = default;
        network_parameters& operator=(const network_parameters&) = default;

        network_parameters(network_parameters&&) = default;
        network_parameters& operator=(network_parameters&&) = default;

        const nlohmann::json& get_json() const { return m_details; }

        std::string network() const { return m_details.at("network"); }
        std::string gait_wamp_url() const { return m_details.at("wamp_url"); }
        std::vector<std::string> gait_wamp_cert_pins() const { return m_details.at("wamp_cert_pins"); }
        std::vector<std::string> gait_wamp_cert_roots() const { return m_details.at("wamp_cert_roots"); }
        std::string block_explorer_address() const { return m_details.at("address_explorer_url"); }
        std::string block_explorer_tx() const { return m_details.at("tx_explorer_url"); }
        std::string chain_code() const { return m_details.at("service_chain_code"); }
        std::string pub_key() const { return m_details.at("service_pubkey"); }
        std::string gait_onion() const { return m_details.at("wamp_onion_url"); }
        std::vector<std::string> default_peers() const { return m_details.at("default_peers"); }
        std::string bech32_prefix() const { return m_details.at("bech32_prefix"); }
        unsigned char btc_version() const { return m_details.at("p2pkh_version"); }
        unsigned char btc_p2sh_version() const { return m_details.at("p2sh_version"); }
        bool main_net() const { return m_details.at("mainnet"); }
        bool liquid() const { return m_details.at("liquid"); }
        std::string get_connection_string(bool use_tor) const
        {
            return use_tor ? gait_onion() : gait_wamp_url();
        }

    private:
        nlohmann::json m_details;
    };
} // namespace sdk
} // namespace ga

#endif
