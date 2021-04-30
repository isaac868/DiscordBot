#include "..\inlcude\DiscordBot.h"

int main() {
	BotClientClass client("NTUyMDA1MjMwNTk5MDc3ODk5.XHy87g.gMa1lvVBQrGm42E46cEpcBcesXk", SleepyDiscord::USER_CONTROLED_THREADS);
	client.setIntents(
		SleepyDiscord::Intent::SERVER_MESSAGES,
		SleepyDiscord::Intent::DIRECT_MESSAGES);
	client.run();
}