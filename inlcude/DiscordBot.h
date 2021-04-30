#pragma once

#include <iostream>
#include "sleepy_discord/sleepy_discord.h"

class BotClientClass : public SleepyDiscord::DiscordClient {
public:
	using SleepyDiscord::DiscordClient::DiscordClient;

	void onMessage(SleepyDiscord::Message message) override {
		if (message.startsWith("@"))
			sendMessage(message.channelID, "Hello " + message.author.username);
	}
};