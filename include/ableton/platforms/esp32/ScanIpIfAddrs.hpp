

#pragma once

#include <ableton/platforms/asio/AsioWrapper.hpp>
#include <ableton/platforms/asio/Util.hpp>
// #include <arpa/inet.h>
// #include <net/if.h>
//#include <vector>
#include <tcpip_adapter.h>

namespace ableton
{
namespace platforms
{
namespace esp32
{

struct ScanIpIfAddrs
{
  // Scan active network interfaces and return corresponding addresses
  // for all ip-based interfaces.
  std::vector<::asio::ip::address> operator()()
  {
    std::vector<::asio::ip::address> addrs;

    tcpip_adapter_ip_info_t info;

    auto err = tcpip_adapter_get_ip_info(TCPIP_ADAPTER_IF_STA, &info);
    if (err == ESP_OK)
    {
      addrs.emplace_back(asio::makeAddress<::asio::ip::address_v4>(ip4addr_ntoa(&info.ip)));
    }

    err = tcpip_adapter_get_ip_info(TCPIP_ADAPTER_IF_AP, &info);
    if (err == ESP_OK)
    {
      addrs.emplace_back(asio::makeAddress<::asio::ip::address_v4>(ip4addr_ntoa(&info.ip)));
    }

    return addrs;
  }
};

} // namespace esp32
} // namespace platforms
} // namespace ableton
