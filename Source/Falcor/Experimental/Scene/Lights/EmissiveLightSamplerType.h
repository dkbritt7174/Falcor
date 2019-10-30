/***************************************************************************
# Copyright (c) 2019, NVIDIA CORPORATION. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#  * Neither the name of NVIDIA CORPORATION nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
# OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***************************************************************************/
#pragma once
#include "Data/HostDeviceData.h"

/** This enum is shared between CPU/GPU.
    It enumerates the different emissive light samplers that are available.
*/
enum class EmissiveLightSamplerType
// TODO: Remove the ifdefs and the include when Slang supports enum type specifiers.
#ifdef HOST_CODE
    : uint32_t
#endif
{
    Uniform     = 0,
};

// For shader specialization in EmissiveLightSampler.slang we can't use the enums.
// TODO: Find a way to remove this workaround.
#define EMISSIVE_LIGHT_SAMPLER_UNIFORM      0

#ifdef HOST_CODE
static_assert((uint32_t)EmissiveLightSamplerType::Uniform == EMISSIVE_LIGHT_SAMPLER_UNIFORM);
#endif

// Define to_string() for EmissiveLightSamplerType for use in serialization.
#ifdef HOST_CODE
#define str(a) case EmissiveLightSamplerType::a: return #a
inline std::string to_string(EmissiveLightSamplerType type)
{
    switch (type)
    {
        str(Uniform);
    default:
        should_not_get_here();
        return "";
    }
}
#undef str
#endif
