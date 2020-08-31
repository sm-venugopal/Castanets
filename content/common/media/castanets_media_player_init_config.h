// Copyright 2018 Samsung Electronics Inc. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_MEDIA_CASTANETS_MEDIA_PLAYER_INIT_CONFIG_H_
#define CONTENT_COMMON_MEDIA_CASTANETS_MEDIA_PLAYER_INIT_CONFIG_H_

#include <string>

#include "content/common/media/castanets_media_player_messages_enums.h"
#include "url/gurl.h"

namespace content {

struct MediaPlayerInitConfig {
  MediaPlayerInitConfig();
  ~MediaPlayerInitConfig();

  MediaPlayerHostMsg_Initialize_Type type;
  GURL url;
  std::string mime_type;
  int demuxer_client_id;
  bool has_encrypted_listener_or_cdm;
  bool is_audio;
  uint64_t node_id;
};

}  // namespace content

#endif  // CONTENT_COMMON_MEDIA_CASTANETS_MEDIA_PLAYER_INIT_CONFIG_H_
