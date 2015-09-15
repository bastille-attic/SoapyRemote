// Copyright (c) 2015-2015 Josh Blum
// SPDX-License-Identifier: BSL-1.0

#pragma once
#include "SoapyRemoteConfig.hpp"
#include <cstddef>
#include <string>

struct sockaddr;

/*!
 * Split a URL into component parts
 * scheme://node:service
 * return true for good URL
 */
SOAPY_REMOTE_API bool splitURL(
    const std::string &url,
    std::string &scheme,
    std::string &node,
    std::string &service
);

//! Create a URL from component parts
SOAPY_REMOTE_API std::string combineURL(
    const std::string &scheme,
    const std::string &node,
    const std::string &service);

/*!
 * Utility to parse and lookup a URL string.
 */
SOAPY_REMOTE_API bool lookupURL(const std::string &url,
    int &af, int &type, int &prot,
    struct sockaddr &addr, int &addrlen,
    std::string &errorMsg);

/*!
 * Convert a socket structure into a URL string.
 */
SOAPY_REMOTE_API std::string sockaddrToURL(const struct sockaddr &addr);

/*!
 * Get a unique identification string for this process.
 * This is usually the combination of a locally-unique
 * process ID and a globally unique host/network ID.
 */
SOAPY_REMOTE_API std::string uniqueProcessId(void);
