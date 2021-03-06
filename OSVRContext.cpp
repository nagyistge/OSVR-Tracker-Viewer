/** @file
    @brief Implementation

    @date 2014

    @author
    Sensics, Inc.
    <http://sensics.com/osvr>
*/

// Copyright 2014 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Internal Includes
#include "OSVRContext.h"
#include "OSVRInterfaceData.h"

// Library/third-party includes
#include <osvr/ClientKit/Context.h>

// Standard includes
// - none

OSVRContext::OSVRContext(std::string const &appId) : m_ctx(appId.c_str()) {}

osg::ref_ptr<OSVRInterfaceData>
OSVRContext::getInterface(std::string const &path) {
    osg::ref_ptr<OSVRInterfaceData> data = new OSVRInterfaceData(*this, path);
    return data;
}

osvr::clientkit::ClientContext &OSVRContext::getContext() { return m_ctx; }

void OSVRContext::update() { m_ctx.update(); }

OSVRContext::~OSVRContext() {}
