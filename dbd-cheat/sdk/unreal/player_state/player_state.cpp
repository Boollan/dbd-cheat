#include <pch.h>

sdk::e_game_state sdk::a_player_state::get_player_state() {
	struct {
		sdk::e_game_state return_value;
	} params{};

	const auto flags = sdk::get_player_state->flags;
	sdk::get_player_state->flags |= 0x00000400;

	sdk::process_event(this, sdk::get_player_state, &params);
	sdk::get_player_state->flags = flags;

	return params.return_value;
}

void sdk::a_player_state::set_player_state(sdk::e_game_state game_state, bool hatch_escape) {
	struct {
		sdk::e_game_state game_state;
		bool hatch_escape;
	} params{};

	params.game_state = game_state;
	params.hatch_escape = hatch_escape;

	const auto flags = sdk::set_player_state->flags;
	sdk::set_player_state->flags |= 0x00000400;

	sdk::process_event(this, sdk::set_player_state, &params);
	sdk::set_player_state->flags = flags;

}