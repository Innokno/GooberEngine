#include "./Game.cpp"

int main() {
	
	Game game = Game("Hello World", "../settings/config.yaml"); 	
	
	game.Run();

	return 0;
}
