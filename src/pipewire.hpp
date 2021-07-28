#pragma once

#include <pipewire/pipewire.h>
#include <spa/param/video/format-utils.h>

struct pipewire_state {
	struct pw_loop *loop;
	struct pw_context *context;
	struct pw_core *core;
	bool running;

	struct pw_stream *stream;
	uint32_t stream_node_id;
	bool streaming;
	struct spa_video_info_raw video_info;
	int stride;
	uint64_t seq;
};

struct pipewire_buffer {
	struct pw_buffer *buffer;
	struct spa_video_info_raw video_info;
	int stride;
	uint8_t *data;
};

bool init_pipewire(void);
struct pipewire_buffer *dequeue_pipewire_buffer(void);
void push_pipewire_buffer(struct pipewire_buffer *buffer);