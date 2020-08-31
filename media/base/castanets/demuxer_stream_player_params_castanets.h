// Copyright 2020 Samsung Electronics Inc. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_BASE_CASTANETS_DEMUXER_STREAM_PLAYER_PARAMS_CASTANETS_H_
#define MEDIA_BASE_CASTANETS_DEMUXER_STREAM_PLAYER_PARAMS_CASTANETS_H_

#include <vector>

#include "base/memory/shared_memory_handle.h"
#include "media/base/audio_decoder_config.h"
#include "media/base/decrypt_config.h"
#include "media/base/demuxer_stream.h"
#include "media/base/media_export.h"
#include "media/base/video_decoder_config.h"
#include "ui/gfx/geometry/size.h"

namespace media {

struct MEDIA_EXPORT DemuxerConfigs {
  DemuxerConfigs();
  ~DemuxerConfigs();

  int duration_ms;
  DemuxerStream::Type type;

  AudioCodec audio_codec;
  int audio_channels;
  int audio_sampling_rate;
  int audio_bit_rate;
  bool is_audio_encrypted;
  std::vector<uint8_t> audio_extra_data;

  VideoCodec video_codec;
  gfx::Size video_size;
  bool is_video_encrypted;
  std::vector<uint8_t> video_extra_data;

  int framerate_num;
  int framerate_den;
  std::string hdr_info;
};

struct MEDIA_EXPORT DemuxedBufferMetaData {
  DemuxedBufferMetaData();
  ~DemuxedBufferMetaData();

  int Release() const;

  unsigned int size;
  bool end_of_stream;
  base::TimeDelta timestamp;
  base::TimeDelta time_duration;
  DemuxerStream::Type type;
  DemuxerStream::Status status;
};

struct MEDIA_EXPORT DemuxedFrameData {
  DemuxedFrameData();
  DemuxedFrameData(DemuxedBufferMetaData meta, base::SharedMemoryHandle shm);

  void ReleaseData() const;

  DemuxedBufferMetaData meta;
  base::SharedMemoryHandle shm;
};

}  // namespace media
#endif  // MEDIA_BASE_CASTANETS_DEMUXER_STREAM_PLAYER_PARAMS_CASTANETS_H_
