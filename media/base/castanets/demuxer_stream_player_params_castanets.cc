// Copyright 2020 Samsung Electronics Inc. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/base/castanets/demuxer_stream_player_params_castanets.h"

#include "base/memory/shared_memory.h"
#include "media/base/decoder_buffer.h"

namespace media {

DemuxerConfigs::DemuxerConfigs()
    : duration_ms(0),
      type(DemuxerStream::UNKNOWN),
      audio_codec(kUnknownAudioCodec),
      audio_channels(0),
      audio_sampling_rate(0),
      audio_bit_rate(0),
      is_audio_encrypted(false),
      video_codec(kUnknownVideoCodec),
      is_video_encrypted(false),
      framerate_num(0),
      framerate_den(0) {}

DemuxerConfigs::~DemuxerConfigs() {}

DemuxedBufferMetaData::DemuxedBufferMetaData()
    : size(0),
      end_of_stream(false),
      type(DemuxerStream::UNKNOWN),
      status(DemuxerStream::kAborted) {}

DemuxedBufferMetaData::~DemuxedBufferMetaData() {}

DemuxedFrameData::DemuxedFrameData() {}

DemuxedFrameData::DemuxedFrameData(DemuxedBufferMetaData meta,
                                   base::SharedMemoryHandle shm)
    : meta{meta}, shm{shm} {}

void DemuxedFrameData::ReleaseData() const {
  if (base::SharedMemory::IsHandleValid(shm))
    base::SharedMemory::CloseHandle(shm);
}

}  // namespace media
