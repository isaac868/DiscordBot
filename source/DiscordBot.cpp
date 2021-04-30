#include "DiscordBot.h"

int main(int argc, char* argv[]) 
{
	BotClientClass client(argv[1], SleepyDiscord::USER_CONTROLED_THREADS);
	client.setIntents(
		SleepyDiscord::Intent::SERVER_MESSAGES,
		SleepyDiscord::Intent::DIRECT_MESSAGES);
	client.run();
}