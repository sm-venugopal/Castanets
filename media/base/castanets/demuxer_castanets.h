// Copyright 2020 Samsung Electronics Inc. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_BASE_CASTANETS_DEMUXER_EFL_H_
#define MEDIA_BASE_CASTANETS_DEMUXER_EFL_H_
#include <vector>

#include "base/memory/shared_memory_handle.h"
#include "media/base/castanets/demuxer_stream_player_params_castanets.h"
#include "media/base/ranges.h"

namespace media {

// Defines the client callback interface.
class MEDIA_EXPORT DemuxerEflClient {
 public:
  // Called when the demuxer has initialized.
  virtual void OnDemuxerConfigsAvailable(const DemuxerConfigs& params) = 0;

  // Called in response to RequestDemuxerData().
  virtual void OnDemuxerDataAvailable(
      base::SharedMemoryHandle foreign_memory_handle,
      const media::DemuxedBufferMetaData& meta_data) = 0;

  virtual void OnDemuxerDataAvailable(
      const std::vector<media::DemuxedFrameData>& frames) = 0;

  // Called when the demuxer started waiting for cdm.
  virtual void OnDemuxerWaitingForCdm() = 0;

  // Called whenever data buffered by the demuxer has changed.
  virtual void OnDemuxerBufferedChanged(
      const media::Ranges<base::TimeDelta>& ranges) = 0;

  // Called whenever demuxer has flushed.
  virtual void OnDemuxerFlushed() = 0;

  // Called to inform demuxer seek completion.
  virtual void OnDemuxerSeekDone(
      const base::TimeDelta& actual_browser_seek_time,
      const base::TimeDelta& video_key_frame) = 0;

  // Called whenever the demuxer has detected a duration change.
  virtual void OnDemuxerDurationChanged(base::TimeDelta duration) = 0;
};

// Defines a demuxer with asynchronous operations.
class MEDIA_EXPORT DemuxerEfl {
 public:
  virtual ~DemuxerEfl() {}

  // Initializes this demuxer with |client| as the callback handler.
  // Must be called prior to calling any other methods.
  virtual void Initialize(DemuxerEflClient* client) = 0;

  // Called to request demuxer seek.
  virtual void RequestDemuxerSeek(const base::TimeDelta& time_to_seek) = 0;

  // Called to request additional data from the demuxer.
  virtual void RequestDemuxerData(media::DemuxerStream::Type type) = 0;
};

}  // namespace media

#endif  // MEDIA_BASE_CASTANETS_DEMUXER_EFL_H_
