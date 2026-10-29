// Copyright 2026 The Android Open Source Project
// SPDX-License-Identifier: Apache-2.0
#pragma once

#include <memory>

#include "host-common/GoldfishMediaDefs.h"

namespace android {
namespace emulation {
class MediaVideoEncoder {
 public:
  MediaVideoEncoder();
  ~MediaVideoEncoder();
  // Bit 0: AVC, bit 1: HEVC. Only advertise encoders actually usable here.
  static uint32_t supportedCodecs();
  void handlePing(MediaCodecType codec, MediaOperation op, void* memory);

 private:
  struct Impl;
  std::unique_ptr<Impl> mImpl;
};
}  // namespace emulation
}  // namespace android
